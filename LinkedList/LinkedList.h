#ifndef LinkedList_H
#define LinkedList_H

template <typename T>
class LinkedList{

    public:

        struct Node{
            T value;
            Node* next; 
            Node* parent;
        };

    private:
        Node* root;

    public:

        LinkedList();
        void Append(T value);
        void Prepend(T value);
        void printList();
        int getSize();
        void reverseList();
        Node* searchHelper(T value);
        void search(T value);
        void deleteNode(T value);
        void deleteBeginning();
        void deleteEnd();
        ~LinkedList();

};

#endif