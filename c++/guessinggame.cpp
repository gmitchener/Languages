#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int secretNum = 7;
    int guess;
    int guessCount = 0;
    int guessLimit = 3;
    bool outOfGuesses = false;

    while(secretNum != guess && !outOfGuesses){
        if(guessCount < guessLimit){
            cout << "Enter guess: ";
            cin >> guess;
            guessCount++;
        } else {
            outOfGuesses = true;
        }
    }

    if(outOfGuesses == true){
        cout <<  "You loose!";
    } else {
        cout << "You win!";
    }

    return 0;
}