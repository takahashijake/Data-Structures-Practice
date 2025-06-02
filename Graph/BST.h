#ifndef BST_H
#define BST_H

#include <iostream>

class BST : public HelperFunctions{

    public:
        struct Node{
            int value;
            Node* left;
            Node* right;
            Node* parent;
        };

    private:

        Node* root; 

    public:

        BST();
        void addNode(int value);
        void deleteNode(int value);
        void inOrderTraversal();
        void search(int value);
       ~BST();
        
        

};

#endif 
