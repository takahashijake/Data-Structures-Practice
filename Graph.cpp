#include <iostream> 

class BST{

    private:
        struct Node{
            Node* left;
            Node* right;
            int value;
        };

        Node* root; 

        void addNodeHelper(Node* currentNode, Node* addNode){
            if (addNode->value > currentNode->value){
                if (currentNode->right == nullptr){
                    currentNode->right = addNode;
                }
                else{
                    addNodeHelper(currentNode->right, addNode);
                }
            }
            else if (addNode->value < currentNode->value){
                if (currentNode->left == nullptr){
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
            else if (value > current->value){
                if (current->right == nullptr){
                    return nullptr;
                }
                else if (current->right != nullptr){
                    deleteNodeSearch(current->right, value);
                }
            }
            else if (value < current->value){
                if (current->left == nullptr){
                    return nullptr;
                }
                else if (current->left != nullptr){
                    deleteNodeSearch(current->left, value);
                }
            }
        }

        void deleteNode(int value){
            //If a node has no children
            
        }



    public:

        BST(){
            root = nullptr;
        }

        void addNode(int value){
            Node* newNode = new Node;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->value = value;

            if (root == nullptr){
                root = newNode;
            }
            else if (newNode->value > root->value){ //If value is greater than root, go in right subtree
                if (root->right == nullptr){
                    root->right = newNode;
                }
                else{
                    addNodeHelper(root->right, newNode);
                }
            }
            else if (newNode->value < root->value){
                if (root->left == nullptr){
                    root->left = newNode;
                }
                else{
                    addNodeHelper(root->left, newNode);
                }
            }
        }   

        void deleteNode(int value){
            Node* deleteNode = deleteNodeSearch(root, value);
            
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
    for (int i = 0; i < 10; i++){
        int x;
        std::cin >> x;
        BinaryTree.addNode(x);
    }
    BinaryTree.inOrderTraversal();
    BinaryTree.search(-1);
}