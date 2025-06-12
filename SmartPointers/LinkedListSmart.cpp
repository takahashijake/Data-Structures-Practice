#include <memory>
#include <iostream>

template <typename T>
class LinkedList{

    private:
        struct Node{
            std::unique_ptr<Node> next;
            T value;
        };

        std::unique_ptr<Node> root;
        Node* tail;

    public:
        
        LinkedList() : root(nullptr), tail(nullptr) {
            std::cout << "Linked List class successfully created!" << std::endl;
        }
 
        void addNode(T value){

            std::unique_ptr<Node> newNode = std::make_unique<Node>();
            newNode->value = value;
            newNode->next = nullptr;
            if (root == nullptr){
                root = std::move(newNode);
            }
            else{
                tail->next = std::move(newNode);
                tail = tail->next.get();
            }
        }

        void printList() const {
            
        }
};

int main(){

    return 0;
}