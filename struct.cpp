#include <iostream>

void printArr(int* arr, int arraySize){

    for (int i = 0; i < arraySize; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(){

    struct testStruct{

        int x;
        int y;
        int* arr;
    };

    struct testStruct structTest;

    structTest.x = 5; 
    structTest.y = 10;
    structTest.arr = new int[structTest.y];

    for (int i = 0; i < structTest.y; i++){
        structTest.arr[i] = i;
    }
    printArr(structTest.arr, structTest.y);
    
}