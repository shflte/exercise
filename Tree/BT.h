#ifndef BINARYTREE
#define BINARYTREE

#include <iostream>
#include "TreeNode.h"

class BT {
private:
    TreeNode* leftmost(TreeNode* current);
    TreeNode* successor(TreeNode* current);  
    void visit(TreeNode* current);
public:
    TreeNode* root;
    BT():root(0) {}
 
    void pre_order_traverse(TreeNode* current);
    void in_order_traverse(TreeNode* current);
    void post_order_traverse(TreeNode* current);
    void level_order_traverse(TreeNode* current);
    void in_order_traverse_using_parent(TreeNode* current);
};

#endif