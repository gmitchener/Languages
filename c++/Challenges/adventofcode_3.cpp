#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<string> fileToVector(string fileName){
    ifstream file(fileName);
    string str;
    vector<string> fileVector;
    while (getline(file, str)) {
        fileVector.push_back(str);
    }
    return fileVector;
}

void printVector(vector<string> inputVector){
    for(int i=0; i < inputVector.size(); i++){
        cout << inputVector[i] << endl;
    }
}

int findMostCommon(vector<string> inputVector, int iterationPosition){
    int zero = 0;
    int one = 0;

    for(int i=0; i < inputVector.size(); i++){
        string reportString = inputVector[i];
        char reportChar = reportString[iterationPosition];
        if(reportChar == '0'){
            zero += 1;
        } else {
            one += 1;
        }
    }

    if(zero > one){
        return 0;
    } else {
        return 1;
    }
}

vector<string> getGammaVector(vector<string> inputVector){
    vector<string> gammaVector;
    for(int i=0; i < inputVector[0].size(); i++){
        int mostCommon = findMostCommon(inputVector, i);
        if(mostCommon == 0){
            gammaVector.push_back("0");
        } else {
            gammaVector.push_back("1");
        }
    }
    return gammaVector;
}

vector<string> getEpsilonVector(vector<string> inputVector){
    vector<string> epsilonVector;
    for(int i=0; i < inputVector[0].size(); i++){
        int mostCommon = findMostCommon(inputVector, i);
        if(mostCommon == 0){
            epsilonVector.push_back("1");
        } else {
            epsilonVector.push_back("0");
        }
    }
    return epsilonVector;
}

int vectorBinaryConverter(vector<string> inputVector){
    int x = 0;
    int length = inputVector.size();
    for(int i=0; i < length; i++){
        int power = pow(2,(length-i-1));
        x += stoi(inputVector[i])*power;
    }
    return x;
}

int calculatePowerConsumption(vector<string> reportInputVector){
    vector<string> gammaVector = getGammaVector(reportInputVector);
    int gamma = vectorBinaryConverter(gammaVector);
    vector<string> epsilonVector = getEpsilonVector(reportInputVector);
    int epsilon = vectorBinaryConverter(epsilonVector);
    return gamma*epsilon;
}

int charToInt(char inputChar){
    return (int)inputChar-48;
}

int stringBinaryConverter(string inputString){
    int x = 0;
    int length = inputString.length();
    for(int i=0; i < length; i++){
        int power = pow(2, (length-i-1));
        x += charToInt(inputString[i])*power;
    }
    return x;
}

vector<string> oxygenBitCriteria(vector<string> inputVector, int iterationPosition){
    vector<string> oxygenVector0 = inputVector;
    vector<string> oxygenVector1 = {};

    int mostCommon = findMostCommon(oxygenVector0, iterationPosition);
    for(int i=0; i < oxygenVector0.size(); i++){
        if(charToInt(inputVector[i][iterationPosition]) == mostCommon){
            oxygenVector1.push_back(inputVector[i]);
        }
    }
    return oxygenVector1;
}

int calculateOxygenRating(vector<string> inputVector){
    vector<string> oxygenVector = inputVector;

    int i = 0;
    while(oxygenVector.size() > 1){
        oxygenVector = oxygenBitCriteria(oxygenVector, i);
        i++;
    }
    return stringBinaryConverter(oxygenVector[0]);
}

vector<string> carbonBitCriteria(vector<string> inputVector, int iterationPosition){
    vector<string> carbonVector0 = inputVector;
    vector<string> carbonVector1 = {};

    int mostCommon = findMostCommon(carbonVector0, iterationPosition);
    int leastCommon = pow((mostCommon-1), 2);
    for(int i=0; i < carbonVector0.size(); i++){
        if(charToInt(inputVector[i][iterationPosition]) == leastCommon){
            carbonVector1.push_back(inputVector[i]);
        }
    }
    return carbonVector1;
}

int calculateCarbonRating(vector<string> inputVector){
    vector<string> carbonVector = inputVector;

    int i = 0;
    while(carbonVector.size() > 1){
        carbonVector = carbonBitCriteria(carbonVector, i);
        i++;
    }
    return stringBinaryConverter(carbonVector[0]);
}

int calculateLifeRating(vector<string> inputVector){
    int oxygenRating = calculateOxygenRating(inputVector);
    int carbonRating = calculateCarbonRating(inputVector);
    return oxygenRating*carbonRating;
}

int main(){
    vector<string> testReport = {"00100", "11110", "10110", "10111", "10101", "01111", "00111", "11100", "10000", "11001", "00010", "01010"};
    // cout << calculatePowerConsumption(testReport);

    vector<string> report = fileToVector("adventofcode_3.txt");
    // cout << calculatePowerConsumption(report);

    // cout << calculateLifeRating(testReport);
    cout << calculateLifeRating(report);

    return 0;
}