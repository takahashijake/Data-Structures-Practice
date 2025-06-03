#include "BST.h"

int main(){


    BST BinaryTree;
    BinaryTree.addNode(1);
    BinaryTree.addNode(5);
    BinaryTree.addNode(2);
    BinaryTree.addNode(4);
    BinaryTree.inOrderTraversal();
    BinaryTree.deleteNode(1);
    BinaryTree.deleteNode(2);
    BinaryTree.inOrderTraversal();
}
