#ifndef _P12_19_H_
#define _P12_19_H_
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <memory>



template <typename T>class StrBlobPtr;

template <typename T>
class StrBlob {

public:
    friend class StrBlobPtr;
public:
    typedef std::vector<T>::size_type size_type;

    StrBlob();
    StrBlob(std::initializer_list<T> li);
    template <typename I> StrBlob(I it1, I it2) const;

    T& operator[](size_t n);

    const T& operator[](size_t n) const;


    StrBlobPtr<T> begin();

    StrBlobPtr<T> end();

    size_type size() const;

    bool empty() const {
        return data->empty();
    }

    void push_back(std::string &s) {
        data->push_back(s);
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

private:
    std::shared_ptr<std::vector<T>> data;

    void check(size_type idx, const std::string &msg) const {
        if (idx >= data->size()) {
            throw std::out_of_range(msg);
        }
    }
};
template <typename T>
StrBlob<T>::StrBlob() : data(std::make_shared<std::vector<T>>()){

}
template <typename T>
StrBlob<T>::StrBlob(std::initializer_list<T> li) : data(std::make_shared<std::vector<T>>(li)) {

}


template<typename T>
class StrBlobPtr {

public:
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
    StrBlobPtr() : curr(0){}
    StrBlobPtr(StrBlob &blob, size_t sz = 0) : wptr(blob.data), curr(sz) {}

    StrBlobPtr& operator++();
    StrBlobPtr operator++(int);

    StrBlobPtr& operator--();
    StrBlobPtr operator--(int);


    T& operator*() const {
        auto p = check(curr, "out of range");
        return (*p)[curr];
    }

    T* operator->() const {
        return  & this->operator*();
    }

    T& dref() const;
    StrBlobPtr& incr();
private:
    std::shared_ptr<std::vector<T>> check(std::size_t sz, const std::string& msg) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;

};
template<typename T>
T& StrBlobPtr<T>::dref() const {
    auto p = check(curr, "dref pass");
    return (*p)[curr];
}

template<typename T>
StrBlobPtr<T>& StrBlobPtr<T>::incr() {
    check(curr, "incr pass");
    ++curr;
    return *this;
}
template<typename T>
T& StrBlob<T>::operator[](size_t n) {
    check(n, "operator[]");
    return (*data)[n];
}
template<typename T>
const T& StrBlob<T>::operator[](size_t n) const{
    check(n, "operator[]  const");
    return (*data)[n];
}
template<typename T>
std::shared_ptr<std::vector<T>> StrBlobPtr<T>::check(std::size_t sz, const std::string& msg) const {
    auto ret = wptr.lock();

    if (!ret) {
        throw std::runtime_error("unbonded ptr");
    }
    if (sz >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

template<typename T>
StrBlobPtr<T> StrBlob<T>::begin() {
    return StrBlobPtr(*this);
}
template<typename T>
StrBlobPtr<T> StrBlob<T>::end() {
    return StrBlobPtr(*this, data->size());
}
template <typename T>
template <typename I>
StrBlob<T>::StrBlob(I it1, I it2): data(std::make_shared<std::vector<T>>(it1, it2)) {

}
template<typename T>
StrBlob<T>::size_type StrBlob<T>::size() const {
    return data->size();
}
template<typename T>
StrBlobPtr<T>& StrBlobPtr<T>::operator++() {
    check(curr, "out of range");
    ++curr;
    return *this;
}

template<typename T>
StrBlobPtr<T> StrBlobPtr<T>::operator++(int) {
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}
template<typename T>
StrBlobPtr<T>& StrBlobPtr<T>::operator--() {
    --curr;
    check(curr, "out of range");
    return *this;
}

template<typename T>
StrBlobPtr<T> StrBlobPtr<T>::operator--(int) {
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}


#endif