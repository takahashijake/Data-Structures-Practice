#include "BST.h"

int main(){


    BST tree;
tree.addNode(50);
tree.inOrderTraversal();
tree.deleteValue(50);
tree.inOrderTraversal();

    return 0;
}
