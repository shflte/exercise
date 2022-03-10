#include <iostream>
#include <queue>
#include "BST.h"
#include "TreeNode.h"

using std::cout;

TreeNode* BST::leftmost(TreeNode* current) {
    while (current->leftchild != NULL) {
        current = current->leftchild;
    }
    return current;
}

TreeNode* BST::rightmost(TreeNode* current) {
    while (current->rightchild != NULL) {
        current = leftmost(current);
        current = current->rightchild;
    }
        return current;
}
    
TreeNode* BST::successor(TreeNode* current) {
    if (current->rightchild == NULL && current->parent == NULL) //current == root && root has no right child
        return NULL;
    else if (current->rightchild != NULL) //right child exist
        return leftmost(current->rightchild);
    else //right child doesn't exist
    {
        bool found = false;
        while (!found) {
            if (current->parent == NULL) return NULL;
            else if (current->parent->leftchild == NULL) {
                current = current->parent;
                continue;
            }
            else if (current->parent->leftchild->data == current->data) {
                current = current->parent;
                found = true;
                continue;
            }
            else {
                current = current->parent;
                continue;
            }
        }
        return current;
    }
}

TreeNode* BST::predecessor(TreeNode* current) {
    if (current->leftchild == NULL && current->parent == NULL) //current == root && root has no left child
        return NULL;
    else if (current->leftchild != NULL) //left child exist
        return rightmost(current->leftchild);
    else //left child doesn't exist
    {
        bool found = false;
        while (!found) {
            if (current->parent == NULL) return NULL;
            else if (current->parent->rightchild == NULL) {
                current = current->parent;
                continue;
            }
            else if (current->parent->rightchild->data == current->data) {
                current = current->parent;
                found = true;
                continue;
            }
            else {
                current = current->parent;
                continue;
            }
        }
        return current;
    }
}

void BST::visit(TreeNode* current) {
    cout << current->data << " ";
}

void BST::insertNode(int data) {
    TreeNode* temp = new TreeNode(data);
    TreeNode* guide = root;
    bool inserted = false;
    while (!inserted) {
        if (root == NULL) {
            root = temp;
            inserted = true;
        }
        else if (data > guide->data && guide->rightchild != NULL) 
            guide = guide->rightchild;
        else if (data < guide->data && guide->leftchild != NULL)
            guide = guide->leftchild;
        else if (data > guide->data) {
            temp->parent = guide;
            guide->rightchild = temp;
            inserted = true;
        }
        else {
            temp->parent = guide;
            guide->leftchild = temp;
            inserted = true;
        }
    }
}

TreeNode* BST::search(int data) {
    TreeNode* guide = root;
    if (root == NULL) return NULL;
    bool found = false;
    while (!found) {
        if (data > guide->data && guide->rightchild != NULL) 
            guide = guide->rightchild;
        else if (data < guide->data && guide->leftchild != NULL)
            guide = guide->leftchild;
        else if (data > guide->data || data < guide->data)
            break;
        else if (data == guide->data) {
            found = true;
            break;
        }
    }
    if (found) return guide;
    else return NULL;
}

void BST::deleteNode(TreeNode* data_ptr) {
    if (data_ptr == NULL) 
       cout << "data not found\n";
    else {
        if (data_ptr->leftchild == NULL && data_ptr->rightchild == NULL) {
            if (data_ptr->parent == NULL) root = NULL;
            else if (data_ptr->parent->leftchild == data_ptr) data_ptr->parent->leftchild = NULL;
            else data_ptr->parent->rightchild = NULL;
            delete data_ptr; 
        }
        else if (data_ptr->leftchild == NULL) {
            if (data_ptr->parent == NULL) {
                root = data_ptr->rightchild;
                root->parent = NULL;
                delete data_ptr;
            }
            else {
                data_ptr->rightchild->parent = data_ptr->parent;
                data_ptr->parent->rightchild = data_ptr->rightchild;
            }
        }
        else if (data_ptr->rightchild == NULL) {
            if (data_ptr->parent == NULL) {
                root = data_ptr->leftchild;
                root->parent = NULL;
                delete data_ptr;
            }
            else {
                data_ptr->leftchild->parent = data_ptr->parent;
                data_ptr->parent->leftchild = data_ptr->leftchild;
            }
        }
        else {
            data_ptr->data = successor(data_ptr)->data;
            deleteNode(successor(data_ptr));
        }
    }
    return;
}

void BST::in_order() {
    if (root == NULL) {
        cout << "BST is empty\n";
        return;
    }
    cout << "In-order traversal: ";
    TreeNode* current = leftmost(root);
    visit(current);
    while (successor(current) != NULL) {
        current = successor(current);
        visit(current);
    }
    cout << "\n";
}

void BST::level_order() {
    if (root == NULL) {
        cout << "BST is empty\n";
        return;
    }
    cout << "Level-order traversal: ";
    std::queue<TreeNode*> q;
    q.push(root);
    TreeNode* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        visit(temp);
        if (temp->leftchild != NULL) q.push(temp->leftchild);
        if (temp->rightchild != NULL) q.push(temp->rightchild);
    }
    cout << "\n";
}