#ifndef LinkedList_H
#define LinkedList_H

class LinkedList{

    public:

        struct Node{
            int value;
            Node* next; 
        };

    private:
        Node* root;

    public:
        LinkedList();
        void addNode(int value);
        void printList();

};

#endif