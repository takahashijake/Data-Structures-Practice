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
    std::cout << "---Testing Copy Constructor---" << std::endl;
    LinkedList<int> newList = LL;
    newList.printList();
    std::cout << "---Testing Copy Assignment Operator---" << std::endl;
    LinkedList<int> List;
    List = LL;
    List.printList();
    List.Append(9);
    List.Prepend(12);
    List.Prepend(45);
    List.printList();
    std::cout << "---Testing Move Assignment Operator---" << std::endl;
    LinkedList<int> firstList;
    for (int i = 21; i >= 13; i--){
        firstList.Append(i);
    }
    LinkedList<int> secondList;
    secondList = std::move(firstList);
    std::cout << "Printing secondList content: ";
    secondList.printList();
    std::cout << "Printing firstList content: ";
    firstList.printList();
    
    std::cout << "---Testing Move Constructor---" << std::endl;
    LinkedList<int> printList = std::move(secondList);
    std::cout << "Printing printList content: ";
    printList.printList();
    std::cout << "Printing secondList content: ";
    secondList.printList();
    

    return 0;
}