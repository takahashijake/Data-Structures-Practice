#include "helper.h"
#include "BST.h"
#include <iostream>

BST::BST(){

    root = nullptr;
}

void BST::addNode(int value){

    Node* newNode = new Node;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = nullptr;
    newNode->value = value;

    if (root == nullptr){
        root = newNode;
    }
    else if (newNode->value > root->value){ //If value is greater than root, go in right subtree
        if (root->right == nullptr){
            root->right = newNode;
            newNode->parent = root;
        }
        else{
            HelperFunctions::addNodeHelper(root->right, newNode);
        }
    }
    else if (newNode->value <= root->value){
        if (root->left == nullptr){
            root->left = newNode;
            newNode->parent = root;
        }
        else{
            HelperFunctions::addNodeHelper(root->left, newNode);
        }
    }
}

void BST::deleteNode(Node* deleteNode){
    if (deleteNode == nullptr){
        std::cout << "Current node is a nullptr" << std::endl;
        return;
    }
    //Case 0: The node to delete is the root 
    if (deleteNode->left == nullptr && deleteNode->right == nullptr){
        if (deleteNode == root){
            delete deleteNode;
            root = nullptr;
        }
        else if (deleteNode->parent->left == deleteNode){
            deleteNode->parent->left = nullptr;
            delete deleteNode;
        }
        else if (deleteNode->parent->right == deleteNode){
            deleteNode->parent->right = nullptr;
            delete deleteNode;
        }
    }
    else if (deleteNode->left == nullptr && deleteNode->right != nullptr){
        Node* child = deleteNode->right;
        if (deleteNode == root){
            root = child;
            child->parent = nullptr;
            delete deleteNode;
        }
        else if (deleteNode->parent->left == deleteNode){
            deleteNode->parent->left = child;
            child->parent = deleteNode->parent;
            delete deleteNode;
        }
        else if (deleteNode->parent->right == deleteNode){
            deleteNode->parent->right = child;
            child->parent = deleteNode->parent;
            delete deleteNode;
        }
    }
    else if (deleteNode->left != nullptr && deleteNode->right == nullptr){
        Node* child = deleteNode->left;
        if (deleteNode == root){
            root = child;
            child->parent = nullptr;
            delete deleteNode;
        }
        else if (deleteNode->parent->left == deleteNode){
            deleteNode->parent->left = child;
            child->parent = deleteNode->parent;
            delete deleteNode;
        }
        else if (deleteNode->parent->right == deleteNode){
            deleteNode->parent->right = child;
            child->parent = deleteNode->parent;
            delete deleteNode;
        }
    }
    else if (deleteNode->left != nullptr && deleteNode->right != nullptr){
        Node* successor = HelperFunctions::findSuccessor(deleteNode->right);
        HelperFunctions::swapNodes(deleteNode, successor);
        BST::deleteNode(successor);
        return;
    }
}

void BST::deleteValue(int value){
    Node* deleteNode = HelperFunctions::deleteNodeSearch(root, value);
    BST::deleteNode(deleteNode);
}

void BST::inOrderTraversal(){
    if (root == nullptr){
        std::cout << "Tree is empty!" << std::endl;
    }
    else{
        HelperFunctions::inOrderTraversalHelper(root);
        std::cout << std::endl;
    }
}

void BST::search(int value){
    HelperFunctions::searchHelper(root, value);
}

void BST::ReverseOrderTraversal(){

    HelperFunctions::ReverseOrderTraversalHelper(root);
    std::cout << std::endl;
}

BST::~BST(){
    HelperFunctions::deleteBST(root);
    std::cout << "Deconstructor called successfully!" << std::endl;
}