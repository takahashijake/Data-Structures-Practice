#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>

template <typename T>
class LinkedList{

    private:

        struct Node{
            T value;
            Node* next; 
            Node* parent;
        };

        Node* root;

    public:

        LinkedList(){
            root = nullptr;
        }

        LinkedList(const LinkedList& other){
            std::cout << "Copy constructor called! " << std::endl;
            root = nullptr;
            Node* current = other.root;
            while (current != nullptr){
                T value = current->value;
                Append(value);
                current = current->next;
            }
        }

        LinkedList& operator=(const LinkedList& other){
            std::cout << "Copy assignment operator called! " << std::endl;
            if (this != &other){
                
            }
        }
        void Append(T value){
            Node* newNode = new Node;
            newNode->value = value;
            newNode->next = nullptr;
            newNode->parent = nullptr;
            if (root == nullptr){
                root = newNode;
            }
            else{ 
                Node* current = root;
                while (current->next != nullptr){
                    current = current->next;
                }
                current->next = newNode;
                newNode->parent = current;
            }   
        }

        void Prepend(T value){
            Node* newNode = new Node;
            newNode->value = value;
            newNode->next = nullptr;
            newNode->parent = nullptr;
            if (root == nullptr){
                root = newNode;
            }
            else{
                newNode->next = root;
                root = newNode;
                newNode->next->parent = newNode;
            }
        }

        void printList(){
            if (root == nullptr){
                std::cout << "Cannot print an empty list!" << std::endl;
                return;
            }
            Node* current = root; 
            while (current != nullptr){
                std::cout << current->value << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }

        int getSize(){
            int count = 0;
            Node* current = root;
            while (current != nullptr){
                count++;
                current = current->next;
            }       
            std::cout << "The linked list is " << count << " elements long!" << std::endl;

            return count;
        }

        void reverseList(){
            if (root == nullptr){
                throw std::logic_error("Cannot reverse an empty list!");
            }
            Node* current = root;
            Node* newRoot = nullptr;
            while (current != nullptr){
                Node* next = current->next;
                Node* parent= current->parent;
                current->next = parent;
                current->parent = next;
                newRoot = current;
                current = next;
            }
            root = newRoot;
        }

        Node* searchHelper(T value){
             Node* current = root;
            while (current != nullptr){
                if (current->value == value){
                    return current;
                }
            }
            return nullptr;
            std::cout << "Value of found Node is: " << current->value << std::endl;
            return current;
        }

        void search(T value){
            searchHelper(value);
        }

        void deleteNode(T value){
            Node* deleteNode = LinkedList::searchHelper(value);
            if (deleteNode == nullptr){
                std::cout << "The value does not exist!" << std::endl;
            }
            if (deleteNode == root){
                deleteNode->next->parent = nullptr;
                root = deleteNode->next;
                delete deleteNode;
            }
            else if (deleteNode == root && deleteNode->next == nullptr){
                delete deleteNode;
                root = nullptr;
            }
            else if (deleteNode->next == nullptr){
                deleteNode->parent->next = nullptr;
                delete deleteNode;
            }
            else{
                Node* temp = deleteNode;
                deleteNode->parent->next = deleteNode->next;
                deleteNode->next->parent = deleteNode->parent;
                delete temp;
            }
        }

        void deleteBeginning(){
             if (root == nullptr){
                throw std::logic_error("Cannot delete from an empty list!");
            }
            else if (root != nullptr && root->next == nullptr){
                delete root;
                root = nullptr;
            }
            else{
                root->next->parent = nullptr;
                Node* temp = root->next;
                delete root;
                root = temp;
            }       
        }

        void deleteEnd(){
            if (root == nullptr){
                throw std::logic_error("Cannot delete from an empty list!");
            }
            else if (root != nullptr && root->next == nullptr){
                delete root;
                root = nullptr;
            }
            else{
                Node* current = root;
                while (current->next != nullptr){
                    current = current->next;
                }
                std::cout << "Value of last node is: " << current->value << std::endl;
                current->parent->next = nullptr;
                delete current;
            }
        }

        ~LinkedList(){
            Node* current = root;
            while (current != nullptr){
                Node* temp = current->next;
                delete current;
                current = temp;
            }
            std::cout << "Destructor called successfully!" << std::endl;
        }

};


#endif