#include <iostream>

int ArraySize(){

    int x;
    std::cin >> x;

    return x;
}

void arrayFill(int* arr, int size){
    for (int i = 0; i < size; i++){
        int y;
        std::cin >> y;
        *(arr + i) = y;
    }
}

void printArray(int* arr, int size){
    for (int i = 0; i < size; i++){
        std::cout << *(arr + i) << ";";
    }
}

void SelectionSort(int* arr, int size){
    for (int i = 0; i < size; i++){
        int minimum = i;
        for (int j = i + 1; j < size; j++){
            if (arr[j] < arr[minimum]){
                minimum = j;
                
            }
        }
        std::swap(arr[i], arr[minimum]);
    }
}

int main(){

    int arraySize = ArraySize();
    int array[arraySize];

    arrayFill(array, arraySize);
    SelectionSort(array, arraySize);
    printArray(array, arraySize);


    
}