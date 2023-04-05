#include "BiTree.h"
#include <iostream>

using namespace std;

int main() {
    BiTree tree;
    tree.add("A");
    tree.add("C");
    tree.add("B");
    tree.add("E");
    tree.add("D");

    cout << "Inorder traversal:" << endl;
    tree.print();

    cout << "Tree traversal:" << endl;
    tree.tprint();

    cout << "Reverse order traversal:" << endl;
    tree.rprint();

    cout << "Removing node 'C'" << endl;
    tree.remove("C");
    tree.print();

    cout << "Removing node 'A'" << endl;
    tree.remove("A");
    tree.print();

    return 0;
}