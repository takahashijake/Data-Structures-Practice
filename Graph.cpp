#include <iostream> 

class BST{

    private:
        struct Node{
            Node* parent;
            Node* left;
            Node* right;
            int value;
        };

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

            else if (deleteNode == root && deleteNode->left == nullptr && deleteNode->right == nullptr){
                root = nullptr;
                delete deleteNode;
            }
            else if (deleteNode == root && deleteNode->left == nullptr && deleteNode->right != nullptr){
                deleteNode->right->parent = nullptr;
                root = deleteNode->right;
                delete deleteNode;
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
    
       ~BST(){
            deleteBST(root);
            std::cout << "Deconstructor called successfully!" << std::endl;
       }
        
        

};

int main(){

    BST BinaryTree;
    BinaryTree.addNode(1);
    BinaryTree.addNode(2);
    BinaryTree.inOrderTraversal();
    BinaryTree.deleteNode(1);
    BinaryTree.deleteNode(2);
    BinaryTree.inOrderTraversal();
}