#include <iostream>
#include "ArrayList.h"
int main(){

    ArrayList<int> myArray;

    for (int i = 0; i < 30; i++){
        myArray.append(i);
    }
    myArray.print();
    myArray.prepend(69);
    myArray.print();

}