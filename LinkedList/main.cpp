#include <iostream>
#include "LinkedList.h"

int main(){

    LinkedList LL;
    LL.addNode(1);
    LL.addNode(2);
    LL.addNode(3);
    LL.addNode(2);
    LL.printList();
    LL.getSize();

    return 0;
}