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

void MaxHeapify(int* arr, int index, int arraySize){

    int leftIndex = (2 * index) + 1;
    int rightIndex = (2 * index) + 2; 
    int maxIndex = index;
    if (leftIndex < arraySize && arr[leftIndex] > arr[maxIndex]){
        maxIndex = leftIndex;
    }
    if (rightIndex < arraySize && arr[rightIndex] > arr[maxIndex]){
        maxIndex = rightIndex;
    }

    if (maxIndex != index){
        std::swap(arr[maxIndex], arr[index]);
        MaxHeapify(arr, maxIndex, arraySize);
    }
}

void BuildMaxHeap(int* arr, int size){
    int lastLeafNode = (size / 2);
    for (int i = lastLeafNode - 1; i >= 0; i--){
        MaxHeapify(arr, i, size);
    }
}

void HeapSort(int* arr, int size){
    BuildMaxHeap(arr, size);
    int counter = size - 1;
    while (counter >= 1){
        std::swap(arr[0], arr[counter]);
        counter--;
        MaxHeapify(arr, 0, counter + 1);
    }
}

int main(){

    int arraySize = ArraySize();
    int arr[arraySize];
    arrayFill(arr, arraySize);
    HeapSort(arr, arraySize);
    printArray(arr, arraySize);
    
}