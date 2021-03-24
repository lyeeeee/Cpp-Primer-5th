#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>
#include <sstream>
#include "p12_27.h"
#include <cstring>


class TreeNode {
public:
    TreeNode(): value(string()), count(new int(1)), left(nullptr), right(nullptr){}


    TreeNode(const TreeNode & t) {
        (*t.count)++;
        value = t.value;
        left = t.left;
        right = t.right;
        count = t.count;
    }

    TreeNode& TreeNode::operator=(const TreeNode &t) {
        (*t.count)++;
        (*count)--;
        if (*count == 0) {
            if (left) {
                delete left;
                left = nullptr;
            }
            if (right) {
                delete right;
                left = nullptr;
            }
            delete count;
        }
        value = t.value;
        count = t.count;
        left = t.left;
        right = t.right;
        return *this;
    }

    ~TreeNode() {
        (*count)--;
        if (*count == 0) {
            if (left) {
                delete left;
                left = nullptr;
            }
            if (right) {
                delete right;
                left = nullptr;
            }
            delete count;
        }
    }
private:
    std::string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};


class BinStrTree {
public:
    BinStrTree(): root(new TreeNode()){}

    BinStrTree(const BinStrTree & b) {
        root = new TreeNode(*b.root);
    }

    BinStrTree& BinStrTree::operator=(const BinStrTree &b) {
        TreeNode *new_root = new TreeNode(*b.root);
        delete root;
        root = new_root;
        return *this;
    }

    ~BinStrTree(){
        delete root;
    }
private:
    TreeNode *root;
};