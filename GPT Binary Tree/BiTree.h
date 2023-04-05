#ifndef BITREE_H
#define BITREE_H

#include <string>
#include "Node.h"

using namespace std;


class BiTree {
private:
    Node* root;
public:
    // constructor
    // post: root is initialized to NULL
    BiTree();

    // destructor
    // post: all nodes in the tree are deleted
    ~BiTree();

    // add
    // pre: s is a valid string
    // post: a new node containing s is added to the tree
    void add(string s);

    // print
    // post: all elements in the tree are printed in sorted order
    void print();

    // tprint
    // post: all elements in the tree are printed in tree form
    void tprint();

    // rprint
    // post: all elements in the tree are printed in reverse sorted order
    void rprint();

    // remove
    // pre: s is a valid string
    // post: the node containing s is removed from the tree
    void remove(string s);

private:
    // deleteTree
    // post: all nodes in the tree are deleted
    void deleteTree(Node* node);

    // insert
    // pre: parent and node are valid nodes
    // post: node is inserted into the tree
    void insert(Node* parent, Node* node);

    // inOrder
    // post: all elements of the tree are printed in sorted order
    void inOrder(Node* node);

    // tOrder
    // post: all elements of the tree are printed in tree form
    void tOrder(Node* node, int level);

    // rOrder
    // post: all elements of the tree are printed in reverse sorted order
    void rOrder(Node* node);

    // findMin
    // post: returns the minimum node in the tree
    Node* findMin(Node* node);

    // deleteNode
    // post: the node is deleted
    void deleteNode(Node* node);
};

#endif