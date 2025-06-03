#ifndef BST_H
#define BST_H

#include <iostream>

class BST{

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
        void deleteNode(Node* deleteNode);
        void deleteValue(int value);
        void inOrderTraversal();
        void ReverseOrderTraversal();
        void search(int value);
       ~BST();
        
        

};

#endif 
