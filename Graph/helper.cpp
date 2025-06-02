#include "helper.h"

void HelperFunctions::addNodeHelper(BST::Node* currentNode, BST::Node* addNode){
    if (addNode->value > currentNode->value){
        if (currentNode->right == nullptr){
            addNode->parent = currentNode;
            currentNode->right = addNode;
        }
        else{
            addNodeHelper(currentNode->right, addNode);
        }
    }
    else if (addNode->value <= currentNode->value){
        if (currentNode->left == nullptr){
            addNode->parent = currentNode;
                currentNode->left = addNode;
        }
        else{
            addNodeHelper(currentNode->left, addNode);
        }
    }
}

void HelperFunctions::inOrderTraversalHelper(BST::Node* currentNode){

    if (currentNode != nullptr){
        inOrderTraversalHelper(currentNode->left);
        std::cout << currentNode->value << " ";
        inOrderTraversalHelper(currentNode->right);
    }
}

void HelperFunctions::deleteBST(BST::Node* root){

    if (root != nullptr){
        deleteBST(root->left);
        deleteBST(root->right);
        delete root;
    }
}

void searchHelper(BST::Node* root, int value){

    if (root->value == value){
        std::cout << "Value has been found" << std::endl;
    }
    else if (value > root->value){
        if (root->right == nullptr){
            std::cout << "Value has not been found!" << std::endl;
            return;
        }
        else if (root->right != nullptr){
            searchHelper(root->right, value);
        }
    }
    else if (value < root->value){
        if (root->left == nullptr){
             std::cout << "Value has not been found!" << std::endl;
        }
        else if (root->right != nullptr){
            searchHelper(root->left, value);
        }
    }
}

BST::Node* HelperFunctions::deleteNodeSearch(BST::Node* current, int value){
    if (current == nullptr){
        return nullptr;
    }
    else if (current->value == value){
        return current;
    }
    else if (value > current->value){
        if (current->right == nullptr){
            return nullptr;
        }
        else if (current->right != nullptr){
            return deleteNodeSearch(current->right, value);
        }
    }
    else if (value <= current->value){
        if (current->left == nullptr){
            return nullptr;
        }
        else if (current->left != nullptr){
            return deleteNodeSearch(current->left, value);
        }
    }
    return nullptr;
}

BST::Node* HelperFunctions::findSuccessor(BST::Node* rightDeleteNode){

    while (rightDeleteNode->left != nullptr){
        findSuccessor(rightDeleteNode->left);
    }
    return rightDeleteNode->left;
}

