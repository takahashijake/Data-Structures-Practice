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

void InsertionSort1(int* arr, int size){
    for (int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void InsertionSort2(int* arr, int size){
    for (int i = 1; i < size; i++){
        int value = arr[i];
        int key = i - 1;
        for (int j = i - 1; j >= 0; j--){
            if (arr[j] > value){
                arr[j+1] = arr[j];
                key--;
            }
        }
        arr[key + 1] = value;
   }
}

int main(){

   
    int arraySize = ArraySize();
    int array[arraySize];
    arrayFill(array, arraySize);
    InsertionSort1(array, arraySize);
    printArray(array, arraySize);


    return 0;
}