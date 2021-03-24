#ifndef __P13_44_H__
#define __P13_44_H__
#include <memory>

using std::allocator;
using std::pair;
class String {
public:
    String(): String("") { }
    String(const char *);
    String(const String &);

    String(String &&) noexcept;
    String& operator=(String &&) noexcept;

    String& operator=(const String &);
    ~String();

    const char * c_str() const { return elements;}
    size_t size() const { return end - elements;}
    size_t length() const { return end - elements + 1; }

private:
    pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initialize(const char*, const char*);
    void free();

private:
    char *elements;
    char *end;
    std::allocator<char> alloc;
};
#endif