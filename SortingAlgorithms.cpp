#include <iostream> 

//Accumulation of all of my sorting algorithms into one class for quick access 

class SortingAlgorithms{

    private:

        int size;
        int* arr;
        int getArraySize(){
            std::cout << "What is the size of the array: ";
            int x;
            std::cin >> x;
            return x;
        }
        void arrayFill(int* arr, int size){
            for (int i = 0; i < size; i++){
                int y;
                std::cin >> y;
                arr[i] = y;
            }
        }
        void printArray(int* arr, int size){
            std::cout << "Contents of array: ";
            for (int j = 0; j < size; j++){
                std::cout << arr[j] << " ";
            }
            std::cout << std::endl;
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

        void SelectionSortHelper(int* arr, int size){
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

        void QuickSortHelper(int* arr, int low, int high, int arraySize){
        
            if (low >= high){
                return;
            }
        
            int pivotIndex = partition(arr, low, high);
            QuickSortHelper(arr, low, pivotIndex - 1, arraySize);
            QuickSortHelper(arr, pivotIndex + 1, high, arraySize);
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
        
        
        void MergeSortHelper(int* arr, int low, int high){
            if (low < high){
                int middle = ((low + high) / 2);
                MergeSortHelper(arr, low, middle);
                MergeSortHelper(arr, middle + 1, high);
                Merge(arr, low, middle, high);
            }
        }
        

    public:
        SortingAlgorithms(){
            size = getArraySize();
            arr = new int[size];
        }

        void fillArray(){
            arrayFill(arr, size);
        }

        void arrayPrint(){
            printArray(arr, size);
        }

        void SelectionSort(){
            SelectionSortHelper(arr, size);
        }

        void QuickSort(){
            QuickSortHelper(arr, 0, size - 1, size);
        }

        void InsertionSort(){
            InsertionSort1(arr, size);
        }

        void MergeSort(){
            MergeSortHelper(arr, 0, size - 1);
        }



        ~SortingAlgorithms(){
            delete arr;
        }
};

int main(){


    return 0;
}