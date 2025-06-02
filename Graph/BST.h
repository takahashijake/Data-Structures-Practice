#ifndef BST_H
#define BST_H

#include <iostream> 

class BST : public HelperFunctions{

    public:
        struct Node{
            Node* parent;
            Node* left;
            Node* right;
            int value;
        };

    private:

        Node* root; 

        void addNodeHelper(Node* currentNode, Node* addNode){
            if (addNode->value > currentNode->value){
                if (currentNode->right == nullptr){
                    addNode->parent = currentNode;
                    currentNode->right = addNode;
                }
                else{
                    addNodeHelper(currentNode->right, addNode);
                }
            }
            else if (addNode->value <= currentNode->value){
                if (currentNode->left == nullptr){
                    addNode->parent = currentNode;
                    currentNode->left = addNode;
                }
                else{
                    addNodeHelper(currentNode->left, addNode);
                }
            }
        }
        
        void inOrderTraversalHelper(Node* currentNode){
            if (currentNode != nullptr){
                inOrderTraversalHelper(currentNode->left);
                std::cout << currentNode->value << " ";
                inOrderTraversalHelper(currentNode->right);
            }
        }

        void deleteBST(Node* rootNode){
            
            if (rootNode != nullptr){
                deleteBST(rootNode->left);
                deleteBST(rootNode->right);
                delete rootNode;
            }
        }

        void searchHelper(Node* root, int value){
            if (root->value == value){
                std::cout << "Value has been found" << std::endl;
            }
            else if (value > root->value){
                if (root->right == nullptr){
                    std::cout << "Value has not been found!" << std::endl;
                    return;
                }
                else if (root->right != nullptr){
                    searchHelper(root->right, value);
                }
            }
            else if (value < root->value){
                if (root->left == nullptr){
                    std::cout << "Value has not been found!" << std::endl;
                }
                else if (root->right != nullptr){
                    searchHelper(root->left, value);
                }
            }
        }

        Node* deleteNodeSearch(Node* current, int value){
            if (current == nullptr){
                return nullptr;
            }
            else if (current->value == value){
                return current;
            }
            else if (value > current->value){
                if (current->right == nullptr){
                    return nullptr;
                }
                else if (current->right != nullptr){
                    return deleteNodeSearch(current->right, value);
                }
            }
            else if (value <= current->value){
                if (current->left == nullptr){
                    return nullptr;
                }
                else if (current->left != nullptr){
                    return deleteNodeSearch(current->left, value);
                }
            }
            return nullptr;
        }

        Node* findSuccessor(Node* rightDeleteNode){
            while (rightDeleteNode->left != nullptr){
                findSuccessor(rightDeleteNode->left);
            }
            return rightDeleteNode->left;
        }

        void swapNodes(Node* firstNode, Node* secondNode){

            //The node I want to swap the secondNode with is the root
            if (firstNode == root){
                //Because the firstNode is the root, the secondNode is guaranteed to have a parent 
                if (secondNode->parent->left == secondNode){
                    Node* temp = secondNode;
                    secondNode->parent->left = nullptr;
                    secondNode->parent = nullptr;
                    secondNode->left->parent = nullptr;
                    secondNode->right->parent = nullptr;

                    secondNode = firstNode;

                    secondNode->parent->left = temp->parent->left;
                    secondNode->parent = temp->parent;
                    secondNode->left->parent = temp->left->parent;
                    secondNode->right->parent = temp->right->parent;
    

                    /*Node* secondTemp = firstNode;
                    firstNode = temp;
                    firstNode->parent = nullptr;
                    firstNode->left = secondTemp->left;
                    firstNode->right = secondTemp->right;

                    delete temp*/
                    delete temp;
                }
            
                else if (secondNode->parent->right == secondNode){
                    Node* temp = secondNode;
                    secondNode = firstNode;
                    secondNode->parent->right = temp->parent->right;
                    secondNode->right = temp->right;
                    secondNode->left = temp->left;
                    firstNode = temp;
                    delete temp;
                }
            }
        }


    public:

        BST(){
            root = nullptr;
        }

        void addNode(int value){
            Node* newNode = new Node;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->parent = nullptr;
            newNode->value = value;

            if (root == nullptr){
                root = newNode;
            }
            else if (newNode->value > root->value){ //If value is greater than root, go in right subtree
                if (root->right == nullptr){
                    root->right = newNode;
                    newNode->parent = root;
                }
                else{
                    addNodeHelper(root->right, newNode);
                }
            }
            else if (newNode->value <= root->value){
                if (root->left == nullptr){
                    root->left = newNode;
                    newNode->parent = root;
                }
                else{
                    addNodeHelper(root->left, newNode);
                }
            }
        }   

        void deleteNode(int value){
            Node* deleteNode = deleteNodeSearch(root, value);
            if (deleteNode == nullptr){
                std::cout << "Current node is a nullptr" << std::endl;
                //throw std::logic_error("No node exists with the specified value!");
            }
            //Case 0?: deleteNode is the root
            else if (deleteNode == root && deleteNode->left == nullptr && deleteNode->right == nullptr){
                root = nullptr;
                delete deleteNode;
            }
            else if (deleteNode == root && deleteNode->left == nullptr && deleteNode->right != nullptr){
                deleteNode->right->parent = nullptr;
                root = deleteNode->right;
                delete deleteNode;
            }
            else if (deleteNode == root && deleteNode->left != nullptr && deleteNode->right != nullptr){
                Node* successor = findSuccessor(deleteNode->right);
                
            }
            //Case 1: deleteNode has no children 
            else if (deleteNode->left == nullptr && deleteNode->right == nullptr && value > deleteNode->parent->value){
                deleteNode->parent->right = nullptr;
                delete deleteNode;
            }
            else if (deleteNode->left == nullptr && deleteNode->right == nullptr && value <= deleteNode->parent->value){
                deleteNode->parent->left = nullptr;
                delete deleteNode;
            }
            //Case 2: deleteNode has 1 child
            else if (deleteNode->left == nullptr && deleteNode->right != nullptr && value > deleteNode->parent->value){
                deleteNode->parent->right = deleteNode->right;
                deleteNode->right->parent = deleteNode->parent;
                delete deleteNode;
            }
            else if (deleteNode->left != nullptr && deleteNode->right == nullptr && value > deleteNode->parent->value){
                deleteNode->parent->right = deleteNode->left;
                deleteNode->left->parent = deleteNode->parent;
            }
            else if (deleteNode->left == nullptr && deleteNode->right != nullptr && value <= deleteNode->parent->value){

            }
        }

        void inOrderTraversal(){
            inOrderTraversalHelper(root);
            std::cout << std::endl;
        }

        void search(int value){
            searchHelper(root, value);
        }

        void nodeSwap(int firstValue, int secondValue){
            Node* firstNode = deleteNodeSearch(root, firstValue);
            Node* secondNode = deleteNodeSearch(root, secondValue);
            std::cout << "Value of firstNode is: " << firstNode->value << std::endl;
            std::cout << "Value of secondNode is: " << secondNode ->value << std::endl;

            swapNodes(firstNode, secondNode);
        }
    
       ~BST(){
            deleteBST(root);
            std::cout << "Deconstructor called successfully!" << std::endl;
       }
        
        

};

int main(){

    BST BinaryTree;
    BinaryTree.addNode(1);
    BinaryTree.addNode(3);
    BinaryTree.addNode(2);
    BinaryTree.inOrderTraversal();
    BinaryTree.nodeSwap(1, 3);
    BinaryTree.inOrderTraversal();
}

#endif 
