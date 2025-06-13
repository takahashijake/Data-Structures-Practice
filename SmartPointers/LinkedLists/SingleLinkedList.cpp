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
                throw std::logic_error("Cannot delete from an empty list");
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
                else{
                    std::unique_ptr<Node> tailDelete;
                    Node* current = root.get();
                    while (true){
                        if (current->next->value == tail->value){
                            tailDelete.reset(current);
                            break;
                        }
                        current = current->next.get();
                    }
                    tailDelete->next = nullptr;
                    tail = tailDelete.get();
                    tailDelete.release();
                }
            }
            else{  
                Node* parent = root.get();
                while (true){
                    if (parent->next->value == value){
                        break;               
                    }
                    parent = parent->next.get();
                }
                std::unique_ptr<Node> nodeToDelete = std::move(parent->next);
                parent->next = std::move(nodeToDelete->next);
                nodeToDelete->next = nullptr;
            }
        }

        int getSize() const{
            Node* current = root.get();
            int count = 0;
            while (current != nullptr){
                count++;
                current = current->next.get();
            }
            return count;
        }

        bool isEmpty() const{
            if (root == nullptr){
                return true;
            }
            return false;
        }

        void append(T value){
            std::unique_ptr<Node> newNode = std::make_unique<Node>();
            newNode->value = value;
            newNode->next = nullptr;
            
            //What to do? Want to make the unique_ptr's next pointer point to the newNode, then make tail point to the newNode;
            tail->next = std::move(newNode);
            tail = tail->next.get();
        }

        void prepend(T value){
            std::unique_ptr<Node> newNode = std::make_unique<Node>();
            newNode->value = value;
            newNode->next = nullptr;

            newNode->next = std::move(root);
            root = std::move(newNode);
        }

        void deleteBeginning(){
            std::unique_ptr<Node> rootNode = std::move(root);
            root = std::move(rootNode->next);
            rootNode->next = nullptr;
        }

        void deleteEnd(){
            //Finding parent of tail pointer 
            Node* tailParent = root.get();
            while (true){
                if (tailParent->next->value == tail->value){
                    break;
                }
                tailParent = tailParent->next.get();
            }
            tailParent->next = nullptr;
            tail = tailParent;
        }

        ~LinkedList(){
            std::cout << "Deconstructor called successfully!" << std::endl;
        }
};

int main(){

    LinkedList<int> myList;
    myList.addNode(1);
    myList.addNode(2);
    myList.addNode(3);
    myList.addNode(4);
    myList.printList();
    myList.deleteEnd();
    myList.printList();
    myList.deleteEnd();
    myList.printList();


    return 0;

}