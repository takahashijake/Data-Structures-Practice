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
            int* temp = new int[capacity];
            for (int i = 0; i < count; i++){
                temp[i] = arr[i];
            }
            delete arr;
            arr = temp;
            std::cout << "Inflated successfully! " << std::endl;
        }

        void print(){
            for (int i = 0; i < count; i++){
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
};

#endif 