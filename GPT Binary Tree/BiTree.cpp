#include "BiTree.h"
#include "Node.h"
#include <iostream>

using namespace std;

// constructor
// post: root is initialized to NULL
BiTree::BiTree() {
    root = NULL;
}

//destructor
// post: all nodes in the tree are deleted
BiTree::~BiTree() {
    deleteTree(root);
}

// add
// pre: s is a valid string
// post: a new node containing s is added to the tree
void BiTree::add(string s) {
    Node* node = new Node(s);
    if (root == NULL) {
        root = node;
    }
    else {
        insert(root, node);
    }
}

// print
// post: all elements in the tree are printed in sorted order
void BiTree::print() {
    inOrder(root);
    cout << endl;
}

// tprint
// post: all elements in the tree are printed in tree form
void BiTree::tprint() {
    tOrder(root, 0);
    cout << endl;
}

// rprint
// post: all elements in the tree are printed in reverse sorted order
void BiTree::rprint() {
    rOrder(root);
    cout << endl;
}

// remove
// pre: s is a valid string
// post: the node containing s is removed from the tree
void BiTree::remove(string s) {
    Node* node = root;
    Node* parent = NULL;
    while (node != NULL && node->data != s) {
        parent = node;
        if (s < node->data) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    if (node == NULL) {
        return;
    }
    else if (node->left == NULL && node->right == NULL) {
        if (parent == NULL) {
            root = NULL;
        }
        else {
            if (parent->left == node) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
        }
        delete node;
    }
    else if (node->left == NULL || node->right == NULL) {
        Node* child;
        if (node->left == NULL) {
            child = node->right;
        }
        else {
            child = node->left;
        }
        if (parent == NULL) {
            root = child;
        }
        else {
            if (parent->left == node) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }
        delete node;
    }
    else {
        Node* minNode = findMin(node->right);
        node->data = minNode->data;
        deleteNode(minNode);
    }
}

// deleteTree
// post: all nodes in the tree are deleted
void BiTree::deleteTree(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// insert
// pre: parent and node are valid nodes
// post: node is inserted into the tree
void BiTree::insert(Node* parent, Node* node) {
    if (node->data < parent->data) {
        if (parent->left == NULL) {
            parent->left = node;
        }
        else {
            insert(parent->left, node);
        }
    }
    else {
        if (parent->right == NULL) {
            parent->right = node;
        }
        else {
            insert(parent->right, node);
        }
    }
}

// inOrder
// post: all elements of the tree are printed in sorted order
void BiTree::inOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

// tOrder
// post: all elements of the tree are printed in tree form
void BiTree::tOrder(Node* node, int level) {
    if (node == NULL) {
        return;
    }
    tOrder(node->right, level + 1);
    for (int i = 0; i < level; i++) {
        cout << "   ";
    }
    cout << node->data << endl;
    tOrder(node->left, level + 1);
}

// rOrder
// post: all elements of the tree are printed in reverse sorted order
void BiTree::rOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    rOrder(node->right);
    cout << node->data << " ";
    rOrder(node->left);
}

// findMin
// post: returns the minimum node in the tree
Node* BiTree::findMin(Node* node) {
    if (node->left == NULL) {
        return node;
    }
    else {
        return findMin(node->left);
    }
}

// deleteNode
// post: the node is deleted
void BiTree::deleteNode(Node* node) {

    Node* parent = node->right;
    Node* curr = node->right;
    if (curr != NULL) {
        while (curr->left != NULL) {
            parent = curr;
            curr = curr->left;
        }
    }
    if (parent == node) {
        parent->right = curr->right;
    }
    else {
        parent->left = curr->right;
    }
    node->data = curr->data;
    delete curr;
}