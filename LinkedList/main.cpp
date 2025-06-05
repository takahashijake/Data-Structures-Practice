#include <iostream>
#include "LinkedList.h"

int main(){

    LinkedList LL;
    LL.Append(1);
    LL.Append(2);
    LL.Append(3);
    LL.Append(4);
      LL.printList();
      LL.deleteEnd();
      LL.deleteEnd();
    LL.printList();
    

    return 0;
}