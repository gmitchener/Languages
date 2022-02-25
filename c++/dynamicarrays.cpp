#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void printArray(int inputArray[], int length){
    for(int i=0; i < length; i++){
        cout << inputArray[i] << " ";
    }
}

int main(){
    int size = 10;

    int * dynamicArray = new int [size];

    int staticArray[5] = {0, 1, 2, 3, 4};

    for(int i=0; i < size; i++){
        dynamicArray[i] = i+1;
    }

    printArray(dynamicArray, size);    

    return 0;
}