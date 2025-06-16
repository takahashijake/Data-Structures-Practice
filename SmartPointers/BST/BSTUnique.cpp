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

        Node* root;



    public:

        BST(){
            root == nullptr;
            std::cout << "BST successfully initalized!" << std::endl;
        }

        void printList(T value){
            
        }
        ~BST(){
            std::cout << "BST successfully deleted!" << std::endl;
        }
    
};

int main(){

    return 0;
}