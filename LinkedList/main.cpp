#include <iostream>
#include "LinkedList.h"

int main(){

    LinkedList LL;
    LL.addNode(1);
    LL.addNode(2);
    LL.addNode(3);
    LL.addNode(4);
    LL.printList();
    LL.reverseList();
    LL.printList();
    LL.searchHelper(3);
    LL.getSize();

    return 0;
}