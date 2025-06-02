#include "BST.h"
#include "helper.h"

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
            addNodeHelper(root->right, newNode);
        }
    }
    else if (newNode->value <= root->value){
        if (root->left == nullptr){
            root->left = newNode;
            newNode->parent = root;
        }
        else{
            addNodeHelper(root->left, newNode);
        }
    }
}

void deleteNode(int value){
            Node* deleteNode = deleteNodeSearch(root, value);
            if (deleteNode == nullptr){
                std::cout << "Current node is a nullptr" << std::endl;
                //throw std::logic_error("No node exists with the specified value!");
            }
            //Case 0?: deleteNode is the root
            else if (deleteNode == root && deleteNode->left == nullptr && deleteNode->right == nullptr){
                root = nullptr;
                delete deleteNode;
            }
            else if (deleteNode == root && deleteNode->left == nullptr && deleteNode->right != nullptr){
                deleteNode->right->parent = nullptr;
                root = deleteNode->right;
                delete deleteNode;
            }
            else if (deleteNode == root && deleteNode->left != nullptr && deleteNode->right != nullptr){
                Node* successor = findSuccessor(deleteNode->right);
                
            }
            //Case 1: deleteNode has no children 
            else if (deleteNode->left == nullptr && deleteNode->right == nullptr && value > deleteNode->parent->value){
                deleteNode->parent->right = nullptr;
                delete deleteNode;
            }
            else if (deleteNode->left == nullptr && deleteNode->right == nullptr && value <= deleteNode->parent->value){
                deleteNode->parent->left = nullptr;
                delete deleteNode;
            }
            //Case 2: deleteNode has 1 child
            else if (deleteNode->left == nullptr && deleteNode->right != nullptr && value > deleteNode->parent->value){
                deleteNode->parent->right = deleteNode->right;
                deleteNode->right->parent = deleteNode->parent;
                delete deleteNode;
            }
            else if (deleteNode->left != nullptr && deleteNode->right == nullptr && value > deleteNode->parent->value){
                deleteNode->parent->right = deleteNode->left;
                deleteNode->left->parent = deleteNode->parent;
            }
            else if (deleteNode->left == nullptr && deleteNode->right != nullptr && value <= deleteNode->parent->value){

            }
        }