#include "BST.h"

int main(){


    BST BinaryTree;
    BinaryTree.addNode(4);
    BinaryTree.addNode(2);
    BinaryTree.addNode(1);
    BinaryTree.addNode(5);
    BinaryTree.addNode(6);
    BinaryTree.inOrderTraversal();
    BinaryTree.deleteNode(4);
    BinaryTree.deleteNode(5);
    BinaryTree.inOrderTraversal();
}
