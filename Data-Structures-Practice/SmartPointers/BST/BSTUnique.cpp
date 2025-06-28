#include <iostream>
#include <memory>

template <typename T>
class BST{

    private:
        struct Node{
            std::shared_ptr<Node> leftNode;
            std::shared_ptr<Node> rightNode;
            std::shared_ptr<Node> parentNode;
            T value;

            Node(std::shared_ptr<Node> leftNodeArgument, std::shared_ptr<Node> rightNodeArgument, std::shared_ptr<Node> parentNodeArgument, T valueArgument){
                leftNode = leftNodeArgument;
                rightNode = rightNodeArgument;
                parentNode = parentNodeArgument;
                value = valueArgument;
            }
        };

        std::shared_ptr<Node> root;


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
                    addNode->parentNode = currentNode;
                    return;
                }
                else{
                    addNodeHelper(addNode, currentNode->rightNode);
                }
            }
            else if (addNode->value < currentNode->value){
                if (currentNode->leftNode == nullptr){
                    currentNode->leftNode = std::move(addNode);
                    addNode->parentNode = currentNode;
                    return;
                }
                else{
                    addNodeHelper(addNode,currentNode->leftNode);
                }
            }
        }

        void getSizeHelper(const std::shared_ptr<Node>& current, int& count){
            if (current != nullptr){
                count++;
                getSizeHelper(current->leftNode, count);
                getSizeHelper(current->rightNode, count);
            }
        }

        Node* nodeSearchHelper(T value, const std::shared_ptr<Node>& current){
            if (current->value == value){
                Node* currentNode = current.get();
                return currentNode;
            }
            else if (value > current->value){
                if (current->rightNode == nullptr){
                    return nullptr;
                }
                else{
                    return nodeSearchHelper(value, current->rightNode);
                }
            }
            else if (value < current->value){
                if (current->leftNode == nullptr){
                    return nullptr;
                }
                else{
                    return nodeSearchHelper(value, current->leftNode);
                }
            }
            return nullptr;
        }

    public:

        BST(){
            root = nullptr;
            std::cout << "BST successfully initalized!" << std::endl;
        }

        void addNode(T value){
            std::shared_ptr<Node> newNode = std::make_shared<Node>(nullptr, nullptr, nullptr, value);
            if (root == nullptr){
                root = std::move(newNode);
            }
            else{
                addNodeHelper(newNode, root);
            }
        }

        void deleteNode(T value){
            Node* deleteNode = nodeSearchHelper(value, root);
            std:: cout << "value of delete node is: " << deleteNode->value << std::endl;
            if (deleteNode->rightNode == nullptr && deleteNode->leftNode == nullptr){
                if (deleteNode == root.get()){
                    root.reset();
                }
                else if (deleteNode->parentNode->leftNode.get() == deleteNode){
                    Node* deleteNodeParent = deleteNode->parentNode.get();
                    deleteNodeParent->leftNode = nullptr;
                }
                else if (deleteNode->parentNode->rightNode.get() == deleteNode){
                    Node* deleteNodeParent = deleteNode->parentNode.get();
                    deleteNodeParent->rightNode = nullptr;
                }
            }
            else if (deleteNode->rightNode == nullptr && deleteNode->leftNode != nullptr){
                if (deleteNode == root.get()){
                    std::cout << "deleteNode has no children and is the root!" << std::endl;
                    root = std::move(deleteNode->leftNode);
                    root->parentNode.reset();

                }
                else if (deleteNode->parentNode->rightNode.get() == deleteNode){
                    std::cout << "This else " << std::endl;
                    deleteNode->leftNode->parentNode = (deleteNode->parentNode);
                    deleteNode->parentNode->rightNode = (deleteNode->leftNode);

                    deleteNode->leftNode = nullptr;
                    deleteNode->parentNode = nullptr;


                }
        }
    }
        int getSize(){
            int count = 0;
            getSizeHelper(root, count);
            return count;
        }

        bool isEmpty() const{
            if (root == nullptr){
                return true;
            }
            return false;
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
    myGraph.addNode(5);
    myGraph.addNode(3);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(5);
    myGraph.inOrderTraversal();



    return 0;
}