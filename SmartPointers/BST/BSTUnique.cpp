#include <iostream>
#include <memory>

template <typename T>
class BST{

    private:
        struct Node{
            std::shared_ptr<Node> leftNode;
            std::shared_ptr<Node> rightNode;
            T value;

            Node(std::shared_ptr<Node> leftNodeArgument, std::shared_ptr<Node> rightNodeArgument, T valueArgument){
                leftNode = leftNodeArgument;
                rightNode = rightNodeArgument;
                value = valueArgument;
            }
        };

        std::shared_ptr<Node> root;

        Node* nodeSearch(T value){
            Node* current = root;
            while (current != nullptr){
                if (current->value == value){
                    return current;
                }
                current = current->next.get();
            }
            return nullptr;
        }

        void inOrderTraversalHelper(const std::shared_ptr<Node>& current){
            if (current != nullptr){
                inOrderTraversalHelper(current->leftNode);
                std::cout << current->value << " ";
                inOrderTraversalHelper(current->rightNode);
            }
        }

        void addNodeHelper(const std::shared_ptr<Node>& addNode, const std::shared_ptr<Node>& currentNode){
            if (addNode->value > currentNode->value){
                if (currentNode->rightNode == nullptr){
                    currentNode->rightNode = std::move(addNode);
                    return;
                }
                else{
                    addNodeHelper(addNode, currentNode->rightNode);
                }
            }
            else if (addNode->value < currentNode->value){
                if (currentNode->leftNode == nullptr){
                    currentNode->leftNode = std::move(addNode);
                    return;
                }
                else{
                    addNodeHelper(addNode,currentNode->leftNode);
                }
            }
        }
    public:

        BST(){
            root = nullptr;
            std::cout << "BST successfully initalized!" << std::endl;
        }

        void addNode(T value){
            std::shared_ptr<Node> newNode = std::make_shared<Node>(nullptr, nullptr, value);
            if (root == nullptr){
                root = std::move(newNode);
            }
            else{
                addNodeHelper(newNode, root);
            }
        }

        void inOrderTraversal(){
            inOrderTraversalHelper(root);
            std::cout << std::endl;
        }
        ~BST(){
            std::cout << "BST successfully deleted!" << std::endl;
        }
    
};

int main(){

    BST<int> myGraph;

    myGraph.addNode(1);
    myGraph.addNode(2);
    myGraph.addNode(3);
    myGraph.inOrderTraversal();
    return 0;
}