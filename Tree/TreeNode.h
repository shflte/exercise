#ifndef TREENODE
#define TREENODE

#include <iostream>

class BT;
class BST;
class TreeNode {
private:
public:
    TreeNode* parent;
    TreeNode* leftchild;
    TreeNode* rightchild;
    int data;

    TreeNode():parent(0), leftchild(0), rightchild(0), data(-1) {}
    TreeNode(int _data):parent(0), leftchild(0), rightchild(0), data(_data){}

    friend class BT;
    friend class BST;
};

#endif