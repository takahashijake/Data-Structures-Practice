#include <iostream>
#include "LinkedList.h"

int main(){

    LinkedList<int> newList;
    LinkedList<int> oldList;

    for (int i = 0; i < 5; i++){
        newList.Append(i);
        oldList.Append(i + 4);
    }

    
    LinkedList<int> addList = newList + oldList;
    return 0;
}