#include <iostream>
#include <queue>
#include "BT.h"

void BT::visit(TreeNode* current) {
    std::cout << current->data << " ";
}

TreeNode* BT::leftmost(TreeNode* current) {
    while (current->leftchild != NULL) {
        current = current->leftchild;
    }
    return current;
}

//VLR
void BT::pre_order_traverse(TreeNode* current) {
    if (current == NULL) return;
    visit(current);
    pre_order_traverse(current->leftchild);
    pre_order_traverse(current->rightchild);
}

//LRV
void BT::post_order_traverse(TreeNode* current) {
    if (current == NULL) return;
    post_order_traverse(current->leftchild);
    post_order_traverse(current->rightchild);
    visit(current);
}

//LVR
void BT::in_order_traverse(TreeNode* current) {
    if (current == NULL) return;
    in_order_traverse(current->leftchild);
    visit(current);
    in_order_traverse(current->rightchild);
}

//level
void BT::level_order_traverse(TreeNode* current) {
    std::queue<TreeNode*> q;
    TreeNode* temp = NULL;
    q.push(current);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        visit(temp);
        if (temp->leftchild != NULL) q.push(temp->leftchild);
        if (temp->rightchild != NULL) q.push(temp->rightchild);
    }
}

TreeNode* BT::successor(TreeNode* current) {
    if (current->rightchild == NULL && current->parent == NULL)
        return NULL;
    //case 1: right child exist
    //successor is the leftmost of the right child
    else if (current->rightchild != NULL) {
        return leftmost(current->rightchild);
    }
    //case 2: right child does not exist
    else {
        bool found = false;
        while (!found) {
            if (current->parent == NULL) return NULL;
            else if (current->parent->leftchild == NULL) {
                current = current->parent;
                continue;
            }
            else if (current->parent->leftchild->data == current->data) {
                found = true;
                current = current->parent;
            }
            else 
                current = current->parent;
        }
        return current;
    }
}

void BT::in_order_traverse_using_parent(TreeNode* current) {
    current = leftmost(current);
    visit(current);
    while (current != NULL) {
        current = successor(current);
        if (current != NULL) visit(current);
    }
}

