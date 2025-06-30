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

int partition(int* arr, int low, int high){

    int pivot = arr[high];
    int lowPointer = low - 1;
    for (int i = low; i < (high); i++){
        if (arr[i] < pivot){
            lowPointer++;
            std::swap(arr[i], arr[lowPointer]);
        }
    }
    lowPointer++;
    std::swap(arr[lowPointer], arr[high]);
    return (lowPointer);


}
void QuickSort(int* arr, int low, int high, int arraySize){

    if (low >= high){
        return;
    }

    int pivotIndex = partition(arr, low, high);
    QuickSort(arr, low, pivotIndex - 1, arraySize);
    QuickSort(arr, pivotIndex + 1, high, arraySize);
}

int main(){

    int arraySize = ArraySize();
    int arr[arraySize];
    arrayFill(arr, arraySize);
    QuickSort(arr, 0, arraySize -1 , arraySize);
    printArray(arr, arraySize);



    return 0;
}