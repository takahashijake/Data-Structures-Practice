#ifndef ArrayList_H
#define ArrayList_H

template <typename T>
class ArrayList{

    private:
        int capacity;
        int count;
        T* arr;

    public:

        ArrayList(){
            capacity = 10;
            count = 0;
            arr = new T[capacity];
        }

        void append(T value){
            arr[count] = value;
            count++;
            if (count == capacity){
                inflate();
            }
        }

        void deleteBeginning(){
            for (int i = 0; i < count; i++){
                arr[i] = arr[i + 1];
            }
            count--;
        }

        void deleteEnd(){
            count--;
        }

        void prepend(T value){
            if (count + 1 == capacity){
                inflate();
            }
            for (int i = count; i >= 0; i--){
                arr[i + 1] = arr[i];
            }
            count++;
            if (count == capacity){
                inflate();
            }
            arr[0] = value;
        }

        void inflate(){
            capacity = capacity * 2;
            T* temp = new T[capacity];
            for (int i = 0; i < count; i++){
                temp[i] = arr[i];
            }
            delete arr;
            arr = temp;
            std::cout << "Inflated successfully! " << std::endl;
        }

        void insertAtIndex(int index, T value){
            if (index > capacity){
                throw std::logic_error("Given index is greater than capacity!");
            }
            if (count + 1 == capacity){
                inflate();
            }
            for (int i = count; i >= index; i--){
                arr[i + 1] = arr[i];
            }
            arr[index] = value;
            count++;
        }

        void deleteAtIndex(int index){
            if (index > capacity){
                throw std::logic_error("Given index is greater than capacity!");
            }
            if (count + 1 == capacity){
                inflate();
            }
            for (int i = index; i < count; i++){
                arr[i] = arr[i + 1];
            }
            count--;
        }

        void print(){
            for (int i = 0; i < count; i++){
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }

        bool LinearSearch(T value){
            for (int i = 0; i < count; i++){
                if (arr[i] == value){
                    return true;
                }
            }
            return false;
        }

        void reverseArray(){
            int topPointer = count - 1;
            int lowPointer = 0;
            while (lowPointer < topPointer){
                std::swap(arr[lowPointer], arr[topPointer]);
                print();
                lowPointer++;
                topPointer--;
            }
        }

        ~ArrayList(){
            delete arr;
            std::cout << "Deconstructor called successfully!" << std::endl;
        }
};

#endif 