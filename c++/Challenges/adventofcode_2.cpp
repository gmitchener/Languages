#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void printIntVector(vector<int> inputVector){
    for (int i = 0; i < inputVector.size(); i++){
        cout << inputVector[i] << endl;
    }
}

vector<string> fileToVector(string fileName){
    ifstream file(fileName);
    string str;
    vector<string> fileVector;
    while (getline(file, str)) {
        fileVector.push_back(str);
    }
    return fileVector;
}

vector<string> getStep(string pathString){
    vector<string> path;

    string delim = " ";
    string direction = pathString.substr(0, pathString.find(delim));
    string stepSizeString = pathString.erase(0, pathString.find(delim) + delim.length());

    path.push_back(direction);
    path.push_back(stepSizeString);
    return path;
}

vector<int> movePosition(vector<string> moveVector){
    vector<int> position = {0, 0, 0};

    for(int i=0; i < moveVector.size(); i++){
        vector<string> stepVector = getStep(moveVector[i]);
        string direction = stepVector[0];
        int x = stoi(stepVector[1]);

        if(direction == "forward"){
            position[0] += x;
            position[1] += position[2]*x;
        } else if(direction == "up"){
            position[2] -= x;
        } else {
            position[2] += x;
        }
    }
    return position;
}

int multiplyPosition(vector<int> positionVector){
    return positionVector[0]*positionVector[1];
}

int main(){
    vector<string> testReport = {"forward 5", "down 5", "forward 8", "up 3", "down 8", "forward 2"};
    vector<int> testEndPosition = movePosition(testReport);
    // cout << multiplyPosition(testEndPosition) << endl;

    vector<string> report = fileToVector("adventofcode_2.txt");
    vector<int> endPosition = movePosition(report);
    cout << multiplyPosition(endPosition);

    return 0;
}