#ifndef LinkedList_H
#define LinkedList_H

class LinkedList{

    public:

        struct Node{
            int value;
            Node* next; 
            Node* parent;
        };

    private:
        Node* root;

    public:
        LinkedList();
        void Append(int value);
        void Prepend(int value);
        void printList();
        void getSize();
        void reverseList();
        Node* searchHelper(int value);
        void search(int value);
        void deleteNode(int value);

};

#endif