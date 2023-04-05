#include "node.h"

//pre: a node doesn't exist
//post: a node now exists and it has the value called for s and null for the pointers left and right
Node::Node(std::string s) {
    data = s;
    left = NULL;
    right = NULL;
}