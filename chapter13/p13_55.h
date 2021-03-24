#ifndef _P12_19_H_
#define _P12_19_H_
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <memory>



class StrBlobPtr;

class StrBlob {

public:
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob();
    StrBlob(std::initializer_list<std::string> li);

    StrBlobPtr begin();

    StrBlobPtr end();

    size_type size() const;

    bool empty() const {
        return data->empty();
    }

    void push_back(std::string &s) {
        data->push_back(s);
    }

    void push_back(std::string &&s) {
        data->push_back(std::move(s));
    }

    void pop_back() {
        check(0, "no data in Blob");
        data->pop_back();
    }

    std::string& front() {
        check(0, "no data in Blob");
        return data->front();
    }

    std::string& back() {
        check(0, "no data in Blob");
        return data->back();
    }

    const std::string& front() const {
        check(0, "no data in Blob");
        return data->front();
    }

    const std::string& back() const {
        check(0, "no data in Blob");
        return data->back();
    }

private:
    std::shared_ptr<std::vector<std::string>> data;

    void check(size_type idx, const std::string &msg) const {
        if (idx >= data->size()) {
            throw std::out_of_range(msg);
        }
    }
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()){

}

StrBlob::StrBlob(std::initializer_list<std::string> li) : data(std::make_shared<std::vector<std::string>>(li)) {

}


class StrBlobPtr {

public:
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
    StrBlobPtr() : curr(0){}
    StrBlobPtr(StrBlob &blob, size_t sz = 0) : wptr(blob.data), curr(sz) {}

    std::string& dref() const;
    StrBlobPtr& incr();
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t sz, const std::string& msg) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;

};
std::string& StrBlobPtr::dref() const {
    auto p = check(curr, "dref pass");
    return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "incr pass");
    ++curr;
    return *this;
}
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t sz, const std::string& msg) const {
    auto ret = wptr.lock();

    if (!ret) {
        throw std::runtime_error("unbonded ptr");
    }
    if (sz >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}


StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

StrBlob::size_type StrBlob::size() const {
    return data->size();
}
#endif