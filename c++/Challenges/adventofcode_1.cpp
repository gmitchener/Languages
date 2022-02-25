#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>

using namespace std; 

void printVector(vector<int> inputVector){
    for (int i = 0; i < inputVector.size(); i++){
        cout << inputVector[i] << endl;
    }
}

vector<int> createIncreaseVector(vector<int> inputVector){
    vector<int> increaseVector = {0};

    for(int i=1; i < inputVector.size(); i++){
        int v0 = inputVector[i-1];
        int v1 = inputVector[i];
        if(v1 > v0){
            increaseVector.push_back(1);
        } else {
            increaseVector.push_back(0);
        }
    }

    return increaseVector;
}

int countIncrease(vector<int> inputIncreaseVector){
    int count = 0;
    for(int i=0; i < inputIncreaseVector.size(); i++){
        count += inputIncreaseVector[i];
    }
    return count;
}

vector<int> fileToVector(string fileName){
    ifstream file(fileName);
    string str;
    vector<int> fileVector;
    while (getline(file, str)) {
        int line = stoi(str);
        fileVector.push_back(line);
    }
    return fileVector;
}

vector<int> createSummedVector(vector<int> inputVector){
    vector<int> summedVector;
    for(int i=0; i < (inputVector.size()-2); i++){
        int v0 = inputVector[i];
        int v1 = inputVector[i+1];
        int v2 = inputVector[i+2];
        summedVector.push_back(v0+v1+v2);
    }
    return summedVector;
}

int main(){
    vector<int> testReport = {199, 200, 208, 210, 200, 207, 240, 269, 260, 263};
    vector<int> testIncreaseVector = createIncreaseVector(testReport);
    int testCount = countIncrease(testIncreaseVector);

    vector<int> report;
    report = fileToVector("adventofcode_1.txt");
    vector<int> increaseVector = createIncreaseVector(report);
    int count = countIncrease(increaseVector);

    vector<int> testSummedReport = createSummedVector(testReport);
    vector<int> testSummedIncreaseVector = createIncreaseVector(testSummedReport);
    int testSummedCount =  countIncrease(testSummedIncreaseVector);

    vector<int> summedReport = createSummedVector(report);
    vector<int> summedIncreaseVector = createIncreaseVector(summedReport);
    int summedCount =  countIncrease(summedIncreaseVector);

    cout << summedCount;

    return 0;
}