#ifndef HELPER_H
#define HELPER_H
#include "BST.h"

class HelperFunctions{

    protected:

        static void addNodeHelper(BST::Node* currentNode, BST::Node* addNode);
        static void inOrderTraversalHelper(BST::Node* currentNode);
        static void deleteBST(BST::Node* currentNode);
        static void searchHelper(BST::Node* root, int value);
        static BST::Node* deleteNodeSearch(BST::Node* current, int value);
        static BST::Node* findSuccessor(BST::Node* rightDeleteNode);

};

#endif