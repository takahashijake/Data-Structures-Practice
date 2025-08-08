#include <iostream>
#include "ArrayList.h"
int main(){

    ArrayList<int> myArray;

    for (int i = 0; i < 10; i++){
        myArray.append(i);
    }
    ArrayList<int> newArray = std::move(myArray);
    myArray.print();
    for (int i = 0; i < 10; i++){
        myArray.append(i);
    }
    myArray.print();
    ArrayList<int> practiceArray;
    for (int k = 20; k >= 8; k--){
        practiceArray.append(k);
    }
    practiceArray.print();
    myArray = practiceArray;
    myArray.print();
    myArray.append(4);
    myArray.append(5);
    myArray.print();
}