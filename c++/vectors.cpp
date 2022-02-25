#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std; 

void printVector(vector<int> inputVector){
    for (int i = 0; i < inputVector.size(); i++){
        cout << inputVector[i] << endl;
    }
}

void printVector2(vector<int> inputVector){
    for (auto itr = inputVector.begin(); itr != inputVector.end(); itr++){
        cout << *itr << endl; // This iterator is a memory address so needs to be dereferenced
    }
}

int main(){
    vector<int> vector1 = {1, 2, 3, 4, 5};

    // COMMON VECTOR METHODS // 

    // cout << vector1[0] << endl;
    // cout << vector1.front() << endl;
    // cout << vector1.back() << endl;
    // cout << vector1.size() << endl; // Number of elements the vector is actually holding
    // vector1.push_back(6);
    // cout << vector1.capacity() << endl; // Number of elements the vector could hold, when an element is appended using push_back, if the capacity < size then the capacity of the vector will double 
    // vector1.pop_back();
    // cout << vector1.back() << endl; // The capacity will not decrease when you remove elements
    // vector1.pop_back();
    // vector1.pop_back();
    // cout << vector1.capacity() << endl;
    // vector1.shrink_to_fit(); // Shrink the capacity to fit the current size of the vector array
    // cout << vector1.capacity() << endl;

    // INSERTING AND ERASING ELEMENTS // 

    vector1.insert(vector1.begin(), 0); // .begin() gives a memory address/pointer to tell C++ where to insert the element 
    vector1.insert(vector1.begin() + 1, -1); 
    vector1[6] = -5;
    // cout << vector1.front() << endl;
    printVector(vector1);
    cout << " " << endl;
    printVector2(vector1);

    return 0;
}