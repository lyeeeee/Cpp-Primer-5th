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
#include "p13_49Message.h"

using std::string;
using std::set;

Message::Message(const Message &m) {
    content = m.content;
    folders = m.folders;
    add_to_Folders(m);
}
Message& Message::operator=(const Message &m) {
    content = m.content;
    remove_from_Folders();
    folders = m.folders;
    add_to_Folders(m);
    return *this;
}

void Message::move_Folders(Message *m) {
    folders = std::move(m->folders);
    for (auto f: folders) {
        f->remove_Message(m);
        f->add_Message(this);
    }
    m->folders.clear();// 确保销毁m是无害的，为什么要clear一下？
}

Message::Message(Message &&m) noexcept{
    content = std::move(m.content);
    move_Folders(&m);
}

Message &Message::operator=(Message &&m) noexcept{
    if (&m != this) {
        content = std::move(m.content);
        remove_from_Folders();
        move_Folders(&m);
    }
    return *this;
}
void Message::save(Folder &f) {
    f.add_Message(this);
}
void Message::remove(Folder &f) {
    f.remove_Message(this);
}

Message::~Message() {
    remove_from_Folders();
}

void Message::add_to_Folders(const Message& m) {
    for (auto f:m.folders) {
        f->add_Message(this);
    }
}
void Message::remove_from_Folders() {
    for (auto f: folders) {
        f->remove_Message(this);
    }
}

Folder::Folder(const Folder &f) {
    messages = f.messages;
    add_to_Message(f);
}
Folder& Folder::operator=(const Folder &f) {
    messages = f.messages;
    remove_from_Message();
    add_to_Message(f);
    return *this;
}

Folder::~Folder() {
    remove_from_Message();
}

void Folder::add_Message(Message *m) {
    messages.insert(m);
}
void Folder::remove_Message(Message *m) {
    messages.erase(m);
}

void Folder::add_to_Message(const Folder &f) {
    for (auto m: f.messages) {
        m->save(*this);
    }
}
void Folder::remove_from_Message() {
    for (auto m: messages) {
        m->remove(*this);
    }
}