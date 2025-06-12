
#include <iostream>
#include <memory>   // For unique_ptr, shared_ptr, weak_ptr, make_unique, make_shared
#include <vector>   // For std::vector
#include <string>   // For std::string
#include <map>      // For std::map (Exercise 4)
#include <optional> // For std::optional (Exercise 5)

// --- Helper class to track object lifetime ---
class MyObject {
public:
    int id;
    std::string name;

    MyObject(int i, const std::string& n = "Unnamed") : id(i), name(n) {
        std::cout << "  MyObject " << id << " ('" << name << "') created.\n";
    }

    ~MyObject() {
        std::cout << "  MyObject " << id << " ('" << name << "') destroyed.\n";
    }

    void doSomething() const {
        std::cout << "  MyObject " << id << " ('" << name << "') is doing something.\n";
    }
};

void processObject(std::shared_ptr<MyObject> object){
    std::cout << "Object use count: " << object.use_count() << std::endl;
    std::shared_ptr<MyObject> local_copy = object;
    std::cout << "Local copy use count: " << local_copy.use_count() << std::endl;
}

void inspectObject(const std::shared_ptr<MyObject>& thisObject){
    std::cout << "This object use count: " << thisObject.use_count() << std::endl;
}

void createUniquePtrArray(){
    std::vector<std::unique_ptr<MyObject> > myObjects;
    for (int i = 0; i < 5; i++){
        myObjects.push_back(std::make_unique<MyObject>(i, "Item"));
    }
    for (int i = 0; i < 5; i++){
        myObjects[i]->doSomething();
    }
}

int main(){

    std::shared_ptr<MyObject> sharedObject = std::make_shared<MyObject>(1, "thisObject");
    processObject(sharedObject);
    std::cout << std::endl;
    inspectObject(sharedObject);
    std::cout << std::endl;
    processObject(sharedObject);


    return 0;
}