#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <memory>

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob();
    StrBlob(std::initializer_list<std::string> li);

    size_type size() const {
        return data->size();
    }

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

