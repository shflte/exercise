#include <iostream>
#include "BT.h"

int main() {
    BT T;
    T.root = new TreeNode(7);
    T.root->leftchild = new TreeNode(4);
    T.root->leftchild->parent = T.root;
    T.root->rightchild = new TreeNode(3);
    T.root->rightchild->parent = T.root;
    T.root->leftchild->leftchild = new TreeNode(6);
    T.root->leftchild->leftchild->parent = T.root->leftchild;
    T.root->leftchild->rightchild = new TreeNode(2);
    T.root->leftchild->rightchild->parent = T.root->leftchild;
    T.root->leftchild->rightchild->leftchild = new TreeNode(5);
    T.root->leftchild->rightchild->leftchild->parent = T.root->leftchild->rightchild;
    T.root->rightchild->leftchild = new TreeNode(8);
    T.root->rightchild->leftchild->parent = T.root->rightchild;
    T.root->rightchild->leftchild->rightchild = new TreeNode(10);
    T.root->rightchild->leftchild->rightchild->parent = T.root->rightchild->leftchild;
    T.root->rightchild->leftchild->rightchild->rightchild = new TreeNode(17);
    T.root->rightchild->leftchild->rightchild->rightchild->parent = T.root->rightchild->leftchild->rightchild;

    std::cout << "Result of traversal: \n";
    std::cout << "In: ";
    T.in_order_traverse(T.root);
    std::cout << "\nPre: ";
    T.pre_order_traverse(T.root);
    std::cout << "\nPost: ";
    T.post_order_traverse(T.root);
    std::cout << "\nLevel: ";
    T.level_order_traverse(T.root);
    std::cout << "\nIn (using parent ptr): ";
    T.in_order_traverse_using_parent(T.root);
    std::cout << "\n";

    return 0;
}