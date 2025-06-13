#include <memory>
#include <iostream>

//Implementations are all made with the assumption that all elements are unique 
template <typename T>
class LinkedList{

    private:
        struct Node{
            std::unique_ptr<Node> next;
            T value;
        };

        std::unique_ptr<Node> root;
        Node* tail;

        Node* nodeSearchHelper(T value){
            Node* current = root.get();
            while (current != nullptr){
                if (current->value == value){
                    return current;
                }
                current = current->next.get();
            }
            return nullptr;
        }

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
                std::cout << "List is empty!" << std::endl;
            }
            Node* current = root.get();
            while (current != nullptr){
                std::cout << current->value << " ";
                current = current->next.get();
            }
            std::cout << std::endl;
        }

        void deleteNode(T value){
            Node* deleteNode = nodeSearchHelper(value);
            if (deleteNode == nullptr){
                std::cout << "List is empty!" << std::endl;
            }
            if (root->value == value){
                std::unique_ptr<Node> rootDelete = std::move(root);
                root = std::move(rootDelete->next);
                rootDelete->next = nullptr;
            }
            else if (tail->value == value){
                if (root->value == tail->value){
                    std::unique_ptr<Node> tailDelete = std::move(root);
                    root = nullptr;
                }
            }
        }
};

int main(){

    LinkedList<int> myList;
    myList.addNode(1);
    myList.printList();
    myList.deleteNode(1);
    myList.printList();
    return 0;

}