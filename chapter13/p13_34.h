#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>
#include <sstream>
#include <cstring>

using std::string;
using std::set;

class Folder;

class Message{

public:
    friend void swap(Message &m1, Message &m2);
    explicit Message(const string &c = ""): content(c) {}
    Message(const Message &m);
    Message& operator=(const Message &m);
    void save(Folder &f);
    void remove(Folder &f);

    ~Message();


private:
    string content;
    set<Folder*> folders;

    void add_to_Folders(const Message&);
    void remove_from_Folders();

    void addFolder(Folder *f) {
        folders.insert(f);
    }
    void removeFolder(Folder *f) {
        folders.erase(f);
    }
};

void swap(Message &m1, Message &m2);

class Folder{
public:
    friend Message;
    Folder() = default;
    Folder(const Folder &f);
    Folder& operator=(const Folder &);
    ~Folder();
private:
    set<Message*> messages;

    void add_Message(Message *m);
    void remove_Message(Message *m);

    void add_to_Message(const Folder &f);
    void remove_from_Message();
};