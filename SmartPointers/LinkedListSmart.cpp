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
                tail = root.get();
            }
            else{
                tail->next = std::move(newNode);
                tail = tail->next.get();
            }
        }

        void printList() const {
            if (root == nullptr){
                throw std::logic_error("Cannot print an empty list!");
            }
            Node* current = root.get();
            while (current != nullptr){
                std::cout << current->value << " ";
                current = current->next.get();
            }
            std::cout << std::endl;
        }
};

int main(){

    LinkedList<int> myList;
    myList.addNode(1);
    myList.addNode(2);
    myList.addNode(3);
    myList.printList();

    return 0;
}