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
                if (deleteNode->next == nullptr){
                    root == nullptr;
                }
                else{
                    std::shared_ptr<Node> rootNodeNextParent = root->next->parent.lock();
                    std::shared_ptr<Node> rootNodeNext = std::move(root->next);
                    std::shared_ptr<Node> rootNode = std::move(root);
                    rootNodeNextParent = nullptr;
                    root = std::move(rootNodeNext);
                }
            }
            else if (deleteNode->value == tail->value){
                std::shared_ptr<Node> tailNode = std::move(tail);
                std::shared_ptr<Node> tailParent = tailNode->parent.lock();
                tailParent->next = nullptr;
                tail = std::move(tailParent);
            }
            else{
                std::shared_ptr<Node> deleteNodeParent = deleteNode->parent.lock();
                deleteNodeParent->next = deleteNode->next;
                deleteNode->next->parent = deleteNode->parent;
                deleteNode->next = nullptr;
                deleteNodeParent = nullptr;
            }
        }

        void deleteBeginning(){
            std::shared_ptr<Node> rootNode = std::move(root);
            root = std::move(rootNode->next);
            rootNode->next = nullptr;
            std::shared_ptr<Node> rootParent = rootNode->parent.lock();
            rootParent = nullptr;
        }

        void deleteEnd(){
            std::shared_ptr<Node> tailNode = std::move(tail);
            std::shared_ptr<Node> tailParent = tailNode->parent.lock();
            tail = std::move(tailParent);
            tailParent = nullptr;
            tail->next = nullptr;
        }

        void append(T value){

            std::shared_ptr<Node> newNode = std::make_shared<Node>(std::weak_ptr<Node>(), nullptr, value);
            tail->next = newNode;
            newNode->parent = tail;
            tail = std::move(newNode);
        }

        void prepend(T value){
            std::shared_ptr<Node> newNode = std::make_shared<Node>(std::weak_ptr<Node>(), nullptr, value);
            std::shared_ptr<Node> rootParent = root->parent.lock();
            rootParent = newNode;
            newNode->next = root;
            root = std::move(newNode);
        }

        void printList(){
            Node* current = root.get();
            while (current != nullptr){
                std::cout << current->value << " ";
                current = current->next.get();
            }
            std::cout << std::endl;
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


};

int main(){

    LinkedList<int> myList;
    myList.addNode(1);
    myList.addNode(2);
    myList.addNode(3);
    myList.addNode(4);
    myList.printList();
    myList.append(5);
    myList.printList();
    myList.append(6);
    myList.printList();

    myList.deleteEnd();
    myList.printList();
    myList.deleteEnd();
    myList.printList();
    myList.prepend(1);
    myList.printList();
    myList.prepend(2);
    myList.printList();
    myList.prepend(3);
    myList.printList();


    return 0;
}