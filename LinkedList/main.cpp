#include <iostream>
#include "LinkedList.h"

int main(){

    LinkedList LL;
    LL.Append(1);
    LL.Append(2);
    LL.Append(3);
    LL.Prepend(4);
    LL.Prepend(3);
    LL.deleteNode(1);
    LL.deleteNode(2);
    LL.printList();
    

    return 0;
}