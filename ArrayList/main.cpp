#include <iostream>
#include "ArrayList.h"
int main(){

    ArrayList<int> myArray;

    for (int i = 0; i < 10; i++){
        myArray.append(i);
    }
    myArray.print();
    myArray.insertAtIndex(3, 15);
    myArray.print();
    myArray.deleteAtIndex(3);
    myArray.print();
    myArray.deleteAtIndex(3);
    myArray.print();
}