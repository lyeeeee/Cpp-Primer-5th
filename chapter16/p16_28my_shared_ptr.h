#ifndef __P16_28MY_SHARED_PTR_H__
#define __P16_28MY_SHARED_PTR_H__
#include "p16_21DebugDelete.h"


template <typename>
class MySharedPtr;

template <typename T>
void swap(MySharedPtr<T> &p1, MySharedPtr<T> &p2) {
    using std::swap;
    swap(p1.ref_cnt, p2.ref_cnt);
    swap(p1.obj, p2.obj);
    swap(p1.deleter, p2.deleter);
}
template <typename T>
class MySharedPtr {
public:
    // 默认构造
    MySharedPtr(): obj(nullptr), ref_cnt(new std::size_t(1)), deleter{DeleteDebug()} {}

    // 有参构造
    explicit MySharedPtr(T *p): obj(p), ref_cnt(new std::size_t(1)), deleter{DeleteDebug()} {

    }
    // 拷贝构造
    MySharedPtr(const MySharedPtr<T> &spt): obj(spt.obj), ref_cnt(spt.ref_cnt), deleter{DeleteDebug()}  {
        (*ref_cnt)++;
    }
    // 移动构造
    MySharedPtr(const MySharedPtr<T> &&spt): obj(spt.obj), ref_cnt(spt.ref_cnt), deleter{std::move(other.deleter)} {
        spt.ref_cnt = nullptr;
        spt.deleter = nullptr;
    }

    // 拷贝赋值
    MySharedPtr &operator=(const MySharedPtr<T> &other) {
        (*other.ref_cnt)++;
        decrement_n_destory();
        obj = other.obj;
        deleter = other.deleter;
        ref_cnt = other.ref_cnt;
        return *this;
    }
    // 移动赋值
    MySharedPtr &operator=(const MySharedPtr<T> &&other) noexcept{
        decrement_n_destory();
        obj = other.obj;
        deleter = other.deleter;
        ref_cnt = other.ref_cnt;
        (*ref_cnt)++;
        other.ref_cnt = other.obj = other.deleter = nullptr;
    }

    operator bool() const {
        return obj ? true:false;
    }

    T* operator->() const {
        return &*obj;
    }

    T& operator*() const {
        return *obj;
    }

    size_t count() const {
        return *ref_cnt;
    }

    auto get() const {
        return obj;
    }

    void unique() const {
        return 1 == *ref_cnt;
    }

    void swap(MySharedPtr &p) {
        swap(*this, p);
    }

    void reset(T* p) {
        if (obj != p) {
            decrement_n_destory();
            ref_cnt = new size_t(1);
            obj = p;
        }
    }

    void reset(T *p, const std::function<void(T*)> &d) {
        reset(p);
        deleter = d;
    }

    ~MySharedPtr(){
        decrement_n_destory();
    }
private:
    T *obj;
    std::size_t *ref_cnt;
    std::function<void(T*)> deleter;

    void decrement_n_destory() {
        (*ref_cnt)--;
        if ((0 == *ref_cnt) && obj) {
            delete ref_cnt;
            deleter(obj);
        }else if (!obj) {
            delete ref_cnt;
        }
        ref_cnt = nullptr;
        obj = nullptr;
    }
};

#endif