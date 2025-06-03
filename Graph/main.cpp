#include "BST.h"

int main(){


    BST tree;
tree.addNode(10);
tree.addNode(5);
tree.addNode(15);
tree.addNode(12);
tree.addNode(17);
tree.addNode(16);
tree.addNode(18);
tree.deleteValue(15);  // Should replace 15 with 16
tree.inOrderTraversal();
    tree.inOrderTraversal();

    return 0;
}
