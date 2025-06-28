#include <iostream>
#include "LinkedList.h"

int main(){

    LinkedList<int> LL;
    LL.Append(1);
    LL.Append(2);
    LL.Append(3);
    LL.Append(4);
    LL.reverseList();
    LL.reverseList();
    LL.reverseList();
    LL.printList();
    

    return 0;
}