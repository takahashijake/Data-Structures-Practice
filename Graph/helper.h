#ifndef HELPER_H
#define HELPER_H
#include <iostream>
#include "BST.h"

class HelperFunctions{

    public:

        static void addNodeHelper(BST::Node* currentNode, BST::Node* addNode);
        static void inOrderTraversalHelper(BST::Node* currentNode);
        static void deleteBST(BST::Node* currentNode);
        static void searchHelper(BST::Node* root, int value);
        static BST::Node* deleteNodeSearch(BST::Node* current, int value);
        static BST::Node* findSuccessor(BST::Node* rightDeleteNode);
        static void swapNodes(BST::Node* firstNode, BST::Node* secondNode);

};

#endif