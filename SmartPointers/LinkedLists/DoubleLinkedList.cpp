#include <memory>
#include <iostream>

template <typename T>
class LinkedList{

    private:
        struct Node : public std::enable_shared_from_this<Node>{
            std::weak_ptr<Node> parent;
            std::shared_ptr<Node> next; 
            T value;

            Node(std::weak_ptr<Node> parentArgument, std::shared_ptr<Node> nextArgument, T valueArgument){
                parent = parentArgument;
                next = nextArgument;
                value = valueArgument;
            }
        };

        std::shared_ptr<Node> root;
        std::shared_ptr<Node> tail;

        Node* nodeSearchHelper(T value){
            Node* current = root.get();
            while(current != nullptr){
                if (current->value == value){
                    return current;
                }
                current = current->next.get();
            }
            return nullptr;
        }

    public: 
        
        LinkedList(){
            root = nullptr;
        }

        void addNode(T value){
            std::shared_ptr<Node> newNode = std::make_shared<Node>(std::weak_ptr<Node>(), nullptr, value);
            if (root == nullptr){
                root = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                newNode->parent = tail;
                tail = std::move(newNode);
            }
        }

        void deleteNode(T value){
            Node* deleteNode = nodeSearchHelper(value);
            if (deleteNode == nullptr){
                throw std::logic_error("Cannot delete a node that doesn't exist!");
            }
            if (deleteNode->value == root->value){
                std::shared_ptr<Node> rootNodeNextParent = root->next->parent.lock();
                std::shared_ptr<Node> rootNodeNext = std::move(root->next);
                std::shared_ptr<Node> rootNode = std::move(root);
                rootNodeNextParent = nullptr;
                root = std::move(rootNodeNext);
            }
            else if (deleteNode->value == tail->value){
                std::shared_ptr<Node> tailNode = std::move(tail);
                std::shared_ptr<Node> tailParent = tailNode->parent.lock();
                tailParent->next = nullptr;
                tail = std::move(tailParent);

            }
            else{
                if (!deleteNode->parent.expired() && !deleteNode->next->parent.expired()){
                    std::shared_ptr<Node> deleteNodeParent = deleteNode->parent.lock();
                    deleteNodeParent->next = deleteNode->next;
                    deleteNode->next->parent = deleteNode->next;
                    deleteNode->next = nullptr;
                    deleteNodeParent = nullptr;
                }
            }
        }

        void printList(){
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
    myList.addNode(4);
    myList.printList();
    myList.deleteNode(4);
     myList.printList();
    myList.deleteNode(3);
    myList.printList();
    return 0;
}