#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include "TreeNode.h"

class BST {
private:
    TreeNode* root;
    TreeNode* leftmost(TreeNode* current);
    TreeNode* rightmost(TreeNode* current);
    TreeNode* successor(TreeNode* current);
    TreeNode* predecessor(TreeNode* current);

    void visit(TreeNode* current);

public:
    BST():root(0) {}
    TreeNode* search(int data);

    void insertNode(int data);
    void deleteNode(TreeNode* data_ptr);
    void in_order();
    void level_order();
};

#endif