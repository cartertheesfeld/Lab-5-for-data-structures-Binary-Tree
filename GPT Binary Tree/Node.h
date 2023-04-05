#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    std::string data;
    Node* left;
    Node* right;
    //pre: a node doesn't exist
    //post: a node now exists and it has the value called for x and null for the pointers left and right
    Node(std::string s);
};

#endif#pragma once
