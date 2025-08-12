#include <iostream>
#include "LinkedList.h"

int main(){

    LinkedList<int> newList;
    LinkedList<int> oldList;
    LinkedList<int> testList;

    for (int i = 0; i < 5; i++){
        newList.Append(i);
        oldList.Append(i + 4);
        testList.Append(i * 4);
    }

    std::cout << "-----Testing add overload-----" << std::endl;
    std::cout << "newList print: ";
    newList.printList();
    std::cout << "oldList print: ";
    oldList.printList();
    std::cout << "testList print: ";
    testList.printList();
    LinkedList<int> addList = newList + oldList + testList;
    std::cout << "addList print: ";
    addList.printList();

    std::cout << "-----Testing concacenation overload-----" << std::endl;
    LinkedList<int> sumList = newList * oldList * testList;
    sumList.printList();


    return 0;
}