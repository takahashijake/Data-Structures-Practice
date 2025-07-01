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

        Node* findSuccessor(Node* current){
            if (current->leftNode == nullptr){
                return current;
            }
            else{
                return findSuccessor(current->leftNode.get());
            }
            return nullptr;
        }

        void swapNodes(Node* firstNode, Node* secondNode){
            int temp = firstNode->value;
            firstNode->value = secondNode->value;
            secondNode->value = temp;
        }

    public:

        BST(){
            root = nullptr;
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

        void deleteNodeHelper(Node* deleteNode){
            if (root.get() == nullptr){
                throw std::logic_error("Cannot delete an empty BST");
            } 
            if (deleteNode->leftNode == nullptr && deleteNode->rightNode == nullptr){
                if (root.get() == deleteNode){
                    root = nullptr;
                }
                else if (deleteNode->parentNode->rightNode.get() == deleteNode){
                    deleteNode->parentNode->rightNode = nullptr;
                    deleteNode->parentNode = nullptr;
                }
                else if (deleteNode->parentNode->leftNode.get() == deleteNode){
                    deleteNode->parentNode->leftNode = nullptr;
                    deleteNode->parentNode = nullptr;
                }
            }
            else if (deleteNode->leftNode != nullptr && deleteNode->rightNode == nullptr){
                if (root.get() == deleteNode){
                    root = deleteNode->leftNode;
                    deleteNode->leftNode->parentNode = nullptr;
                }
                //The node to delete has only a left child, and is the right child of a parent node 
                else if (deleteNode->parentNode->rightNode.get() == deleteNode){ 
                    deleteNode->parentNode->rightNode = deleteNode->leftNode;
                    deleteNode->leftNode->parentNode = deleteNode->parentNode;

               
                }
                //The node to delete has only a left child, and is the left child of a parent node 
                else if (deleteNode->parentNode->leftNode.get() == deleteNode){
                    deleteNode->parentNode->leftNode = deleteNode->leftNode;
                    deleteNode->leftNode->parentNode = deleteNode->parentNode;

    
                }
            }
            else if (deleteNode->leftNode == nullptr && deleteNode->rightNode != nullptr){
                if (root.get() == deleteNode){
                    root = deleteNode->rightNode;
                    deleteNode->rightNode->parentNode = nullptr;
                }
                //The node to delete only has a right child, and is the right child of a parent node 
                else if (deleteNode->parentNode->rightNode.get() == deleteNode){
                    deleteNode->parentNode->rightNode = deleteNode->rightNode;
                    deleteNode->rightNode->parentNode = deleteNode->parentNode;

        
                }
                else if (deleteNode->parentNode->leftNode.get() == deleteNode){
                    deleteNode->parentNode->leftNode = deleteNode->rightNode;
                    deleteNode->rightNode->parentNode = deleteNode->parentNode;

                }
            }
            else if (deleteNode->leftNode != nullptr && deleteNode->rightNode != nullptr){
                Node* successor = findSuccessor(deleteNode->rightNode.get());
                swapNodes(deleteNode, successor);
                deleteNodeHelper(successor);
            }
        }

        void deleteNode(T value){
            if (root == nullptr){
                throw std::logic_error("cannot delete from an empty tree!");
            }
            Node* Node = nodeSearchHelper(value, root);
            deleteNodeHelper(Node);
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
            if (root == nullptr){
                std::cout << "BST is empty!" << std::endl;
            }
            else{
                inOrderTraversalHelper(root);
                std::cout << std::endl;
            }
        }
        ~BST(){
   
        }
    
};

int main(){

    BST<int> myGraph;

    myGraph.addNode(1);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(1);
    myGraph.inOrderTraversal();

    std::cout << std::endl;

    try{
        myGraph.deleteNode(1);
    }
    catch (std::logic_error){
        std::cout << "Empty BST delete exception works!" << std::endl;
        std::cout << std::endl;
    }
    

    myGraph.addNode(1);
    myGraph.addNode(2);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(2);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(1);
    myGraph.inOrderTraversal();

    std::cout << std::endl;

    myGraph.addNode(8);
    myGraph.addNode(7);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(7);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(8);
    myGraph.inOrderTraversal();

    std::cout << std::endl;

    myGraph.addNode(8);
    myGraph.addNode(7);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(8);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(7);
    myGraph.inOrderTraversal();

    std::cout << std::endl;

    myGraph.addNode(1);
    myGraph.addNode(5);
    myGraph.addNode(3);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(5);
    myGraph.inOrderTraversal();;
    myGraph.deleteNode(3);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(1);
    myGraph.inOrderTraversal();

    std::cout << std::endl;

    myGraph.addNode(5);
    myGraph.addNode(4);
    myGraph.addNode(3);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(4);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(3);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(5);
    myGraph.inOrderTraversal();

    std::cout << std::endl;

    myGraph.addNode(3);
    myGraph.addNode(4);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(3);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(4);
    myGraph.inOrderTraversal();

    std::cout << std::endl;

    myGraph.addNode(3);
    myGraph.addNode(4);
    myGraph.addNode(5);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(4);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(5);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(3);
    myGraph.inOrderTraversal();

    std::cout << std::endl;

    myGraph.addNode(5);
    myGraph.addNode(3);
    myGraph.addNode(4);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(3);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(4);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(5);
    myGraph.inOrderTraversal();
   
    std::cout << std::endl;

    myGraph.addNode(5);
    myGraph.addNode(4);
    myGraph.addNode(6);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(5);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(6);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(4);
    myGraph.inOrderTraversal();

    std::cout << std::endl;

    myGraph.addNode(8);
    myGraph.addNode(5);
    myGraph.addNode(6);
    myGraph.addNode(4);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(5);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(6);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(4);
    myGraph.inOrderTraversal();
    myGraph.deleteNode(8);
    myGraph.inOrderTraversal();
    return 0;
}