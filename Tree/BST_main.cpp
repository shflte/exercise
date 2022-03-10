#include <iostream>
#include <string>
#include "BST.h"
#include "TreeNode.h" 
using std::cout;
using std::cin;

enum operation {
    i, d, it, lt, q, iv
};

int main() {
    cout << "---BST---\n";
    int data;
    std::string op; //operation
    operation oprt;
    bool quit = false;
    BST T;

    while (!quit) {
        cout << "Operation list: \n" << "i <data>: insert <data>\n" << "d <data>: delete <data>\n" 
         << "it: in-order traversal\n" << "lt: level-order traversal\n" << "q: quit\n" << "operation: ";
        cin >> op;
        if (op == "i" || op == "d") cin >> data;

        if (op == "i") oprt = i;
        else if (op == "d") oprt = d;
        else if (op == "it") oprt = it;
        else if (op == "lt") oprt = lt;
        else if (op == "q") oprt = q;
        else oprt = iv;

        switch (oprt) {
        case i:
            T.insertNode(data);
            break;
        case d:
            T.deleteNode(T.search(data));
            break;
        case it:
            T.in_order();
            break;
        case lt:
            T.level_order();
            break;
        case q:
            quit = true;
            break;
        case iv:
            cout << "Invalid input: " << op << "\n";
            break;
        default:
            break;
        }
    }
    return 0;
}