#ifndef _P18_7BLOB_H_
#define _P18_7BLOB_H_
#include <stdexcept>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <memory>



template <typename> class BlobPtr;

template <typename T>
class Blob {

public:
    friend class BlobPtr<T>;
public:
    typedef typename std::vector<T>::size_type size_type;

    Blob<T>();
    Blob<T>(std::initializer_list<T> li);

    BlobPtr<T> begin();

    BlobPtr<T> end();

    // size_type size() const {
    //     return data->size();
    // }

    size_type size() const;

    bool empty() const {
        return data->empty();
    }

    void push_back(T &t) {
        data->push_back(t);
    }

    void pop_back() {
        check(0, "no data in Blob");
        data->pop_back();
    }

    T& front() {
        check(0, "no data in Blob");
        return data->front();
    }

    T& back() {
        check(0, "no data in Blob");
        return data->back();
    }

    const T& front() const {
        check(0, "no data in Blob");
        return data->front();
    }

    const T& back() const {
        check(0, "no data in Blob");
        return data->back();
    }

    T &operator[](size_type idx);

    const T &operator[](size_type idx) const;

private:
    std::shared_ptr<std::vector<T>> data;

    void check(size_type idx, const T &msg) const {
        if (idx >= data->size()) {
            throw std::out_of_range(msg);
        }
    }
};

template <typename T>
Blob<T>::Blob() try : data(std::make_shared<std::vector<T>>()){


} catch (std::bad_alloc &ba) {

}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> li) try : data(std::make_shared<std::vector<T>>(li)) {


} catch (std::bad_alloc &ba) {

}

template <typename T>
class BlobPtr {

public:
    friend bool operator==(const BlobPtr<T> &p1,const BlobPtr<T> &p2) {
        return p1.curr == p2.curr;
    }
    friend bool operator!=(const BlobPtr<T> &p1,const BlobPtr<T> &p2) {
        return !(p1 == p2);
    }
    BlobPtr<T>() : curr(0){}
    BlobPtr<T>(Blob<T> &blob, size_t sz = 0) : wptr(blob.data), curr(sz) {}

    T& dref() const;
    BlobPtr<T>& incr();



private:
    std::shared_ptr<std::vector<T>> check(std::size_t sz, const T& msg) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;

};



template <typename T>
T& BlobPtr<T>::dref() const {
    auto p = check(curr, "dref pass");
    return (*p)[curr];
}
template <typename T>
BlobPtr<T>& BlobPtr<T>::incr() {
    check(curr, "incr pass");
    ++curr;
    return *this;
}
template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t sz, const T& msg) const {
    auto ret = wptr.lock();

    if (!ret) {
        throw std::runtime_error("unbonded ptr");
    }
    if (sz >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

template <typename T>
BlobPtr<T> Blob<T>::begin() {
    return BlobPtr<T>(*this);
}

template <typename T>
BlobPtr<T> Blob<T>::end() {
    return BlobPtr<T>(*this, data->size());
}


template<typename T>
T& Blob<T>::operator [](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
const T& Blob<T>::operator [](size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}
#endif