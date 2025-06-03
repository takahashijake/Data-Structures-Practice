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
        //throw std::logic_error("No node exists with the specified value!");
    }
    //Case 0: The node to delete is the root 

    //The node is the root and both children are null
    else if (deleteNode == root && deleteNode->left == nullptr && deleteNode->right == nullptr){
        root = nullptr;
        delete deleteNode;
    }
    //The node is the root and only the right children is not null
    else if (deleteNode == root && deleteNode->left == nullptr && deleteNode->right != nullptr){
        deleteNode->right->parent = nullptr;
        root = deleteNode->right;
        delete deleteNode;
    }
    else if (deleteNode == root && deleteNode->left != nullptr && deleteNode->right == nullptr){
        deleteNode->left->parent = nullptr;
        root = deleteNode->left;
        delete deleteNode;
    }
    //The node to delete is the root and both of the children are not null;
    else if (deleteNode == root && deleteNode->left != nullptr && deleteNode->right != nullptr){
        Node* successor = HelperFunctions::findSuccessor(deleteNode->right);
        std::cout << "Value of successor is: " << successor->value << std::endl;
        HelperFunctions::swapNodes(deleteNode, successor);
        BST::deleteNode(successor);
        /*if (successor->parent == deleteNode){
            if (deleteNode->left == successor){
                if (successor->left == nullptr && successor->right == nullptr){
                    delete successor;
                    deleteNode->left = nullptr;
                }
                else if (successor->left == nullptr && successor->right != nullptr){
                    successor->parent->left = successor->right;
                    successor->right->parent = successor->parent;
                    delete successor; 
                }
            }
            else if (deleteNode->right == successor){
                if (successor->left == nullptr && successor->right == nullptr){
                    delete successor;
                    deleteNode->right = nullptr;
                }
                else if (successor->left == nullptr && successor->right != nullptr){
                    successor->parent->right = successor->right;
                    successor->right->parent = successor->parent;
                    delete successor; 
                }
            }
        }
        if (successor->left == nullptr && successor->right == nullptr){
            if (successor->parent->left == successor){
                Node* temp = successor->parent;
                delete successor;
                successor->parent->left = nullptr;
            }
            else if (successor->parent->right == successor){
                Node* temp = successor->parent;
                delete successor;
                successor->parent->right = nullptr;
            }
        }
        else if (successor->left == nullptr && successor->right != nullptr){
            if (successor->parent->left == successor){
                successor->parent->left = successor->right;
                successor->right->parent = successor->parent;
                delete successor; 
            }
            else if (successor->parent->right == successor){
                successor->parent->right = successor->right;
                successor->right->parent = successor->right;
                delete successor;
            }
        }
        else if (successor->left != nullptr && successor->right == nullptr){
            if (successor->parent->left == successor){
                successor->parent->left = successor->left;
                successor->left->parent = successor->parent;
                delete successor;
            }
            else if (successor->parent->right == successor){
                successor->parent->right = successor->left;
                successor->left->parent = successor->parent;
                delete successor;
            }
        }
    }
        */
    }
     //Case 1: deleteNode has no children 
    else if (deleteNode->left == nullptr && deleteNode->right == nullptr && deleteNode->parent->right == deleteNode){
        deleteNode->parent->right = nullptr;
        delete deleteNode;
    }
    else if (deleteNode->left == nullptr && deleteNode->right == nullptr && deleteNode->parent->left == deleteNode){
        deleteNode->parent->left = nullptr;
        delete deleteNode;
    }
            //Case 2: deleteNode has 1 child
    else if (deleteNode->left == nullptr && deleteNode->right != nullptr && deleteNode->parent->right == deleteNode){
        deleteNode->parent->right = deleteNode->right;
        deleteNode->right->parent = deleteNode->parent;
        delete deleteNode;
    }
    else if (deleteNode->left != nullptr && deleteNode->right == nullptr && deleteNode->parent->right == deleteNode){
        deleteNode->parent->right = deleteNode->left;
        deleteNode->left->parent = deleteNode->parent;
        delete deleteNode;
    }
    else if (deleteNode->left == nullptr && deleteNode->right != nullptr && deleteNode->parent->left == deleteNode){
        deleteNode->parent->left = deleteNode->right;
        deleteNode->right->parent = deleteNode->parent;
        delete deleteNode;
    }
    else if (deleteNode->left != nullptr && deleteNode->right == nullptr && deleteNode->parent->left == deleteNode){
        deleteNode->parent->left = deleteNode->left;
        deleteNode->left->parent = deleteNode->parent;
        delete deleteNode;
    }
    //Case 2: deleteNode has 2 children
    else if (deleteNode->left != nullptr && deleteNode->right != nullptr){
        Node* successor = HelperFunctions::findSuccessor(deleteNode->right);
        BST::deleteNode(successor);
    }
}

void BST::deleteValue(int value){
    Node* deleteNode = HelperFunctions::deleteNodeSearch(root, value);
    BST::deleteNode(deleteNode);
}

void BST::inOrderTraversal(){
    HelperFunctions::inOrderTraversalHelper(root);
    std::cout << std::endl;
}

void BST::search(int value){
    HelperFunctions::searchHelper(root, value);
}

BST::~BST(){
    HelperFunctions::deleteBST(root);
    std::cout << "Deconstructor called successfully!" << std::endl;
}