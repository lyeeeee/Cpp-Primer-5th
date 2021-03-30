#ifndef __P16_28MY_UNIQUE_PTR_H__
#define __P16_28MY_UNIQUE_PTR_H__
#include <iostream>
#include "p16_21DebugDelete.h"


template <typename, typename> class my_unique_ptr;

template <typename T, typename D>
void swap(my_unique_ptr<T, D>  &p1, my_unique_ptr<T, D> &p2) {
    using std::swap;
    swap(p1.ptr, p2.ptr);
    swap(p1.deleter, p2.deleter);
}


template<typename T, typename D = DeleteDebug>
class my_unique_ptr {
public:
    my_unique_ptr(const my_unique_ptr &) = delete;
    my_unique_ptr &operator=(const my_unique_ptr &) = delete;

    my_unique_ptr() = default;
    explicit my_unique_ptr(T *p): ptr(p) { }

    my_unique_ptr(const my_unique_ptr &&other) noexcept :ptr(other.ptr){
        other.ptr = nullptr;
    }

    my_unique_ptr &operator=(const my_unique_ptr &&other) noexcept{
        if (this->ptr != other.ptr){
            deleter(ptr);
            ptr = nullptr;
            swap(*this, other);
        }
    }

    my_unique_ptr &operator=(std::nullptr_t &np);

    T& operator*() const {return (*ptr);}

    T *operator->() const { return &(this->operator*());}

    operator bool() const {return ptr ? true:false;}

    T *get() const {return ptr;}

    void swap(my_unique_ptr<T, D> &other) {
        swap(*this, other);
    }
    void reset() noexcept {
        delete ptr;
        ptr = nullptr;
    }

    void reset(T *p) noexcept {
        deleter(ptr);
        ptr = p;
    }

    T* release();

    ~my_unique_ptr() {
        deleter(ptr);
        ptr = nullptr;
    }
private:
    T* ptr;
    D deleter = D();
};

template <typename T, typename D>
my_unique_ptr<T, D> &my_unique_ptr<T, D>::operator=(std::nullptr_t &np) {
    if (np == nullptr) {
        deleter(ptr);
        ptr = nullptr;
    }
    return *this;
}

template <typename T, typename D>
T* my_unique_ptr<T, D>::release() {
    T* ret = ptr;
    ptr = nullptr;
    return ret;
}

#endif