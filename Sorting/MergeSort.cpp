#include <iostream>
#include <climits> 

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

void Merge(int* arr, int low, int middle, int high) {
    int firstSize = middle - low + 1;
    int secondSize = high - middle; // Corrected calculation for secondSize

    int* firstArr = new int[firstSize];  // Use dynamic allocation for temporary arrays
    int* secondArr = new int[secondSize]; // Use dynamic allocation for temporary arrays

    for (int i = 0; i < firstSize; i++) {
        firstArr[i] = arr[low + i];
    }
    for (int j = 0; j < secondSize; j++) {
        secondArr[j] = arr[middle + 1 + j]; // Corrected index for secondArr
    }

    int i = 0; // Initial index of first sub-array
    int j = 0; // Initial index of second sub-array
    int k = low; // Initial index of merged array

    while (i < firstSize && j < secondSize) {
        if (firstArr[i] <= secondArr[j]) { // Changed to <= for stable sort
            arr[k] = firstArr[i];
            i++;
        } else {
            arr[k] = secondArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of firstArr, if any
    while (i < firstSize) {
        arr[k] = firstArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of secondArr, if any
    while (j < secondSize) {
        arr[k] = secondArr[j];
        j++;
        k++;
    }

    delete[] firstArr;  // Deallocate memory
    delete[] secondArr; // Deallocate memory
}


void MergeSort(int* arr, int low, int high){
    if (low < high){
        int middle = ((low + high) / 2);
        MergeSort(arr, low, middle);
        MergeSort(arr, middle + 1, high);
        Merge(arr, low, middle, high);
    }
}
//arr] [7,6,5,4,3,2,1] 7 /2  = 3

int main(){

    int arraySize = ArraySize();
    int arr[arraySize];

    arrayFill(arr, arraySize);
    MergeSort(arr, 0, arraySize - 1);
    printArray(arr, arraySize);



    return 0;
}