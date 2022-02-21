#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    // VARIABLES
    char grade = 'A';
    string university = "Bristol";
    int age = 23;
    float percentage = 71.77;
    double pi = 3.1415;
    // double has 2x more precision than a float, in general a double has 15 decimal digits of precision and a float has 7
    bool passed = true;

    // printf("%f gave grade %c at %s University", percentage, grade, university);

    // STRINGS
    cout << university.length();

    cout << university;

    // cout << university.find('s');

    // cout << university.substr(0, 4); // .substr(starting_index, length)

    // NUMBERS
    int wnum = 5;
    double dnum = 5.5;

    wnum++; 
    wnum += 10;
    // printf("%d", wnum);

    //printf("%d", 10/3); // maths with integers returns an integer

    // printf("%f \n", pow(2,3));
    // printf("%f \n", sqrt(13.5));
    // cmath functions: round(), ceil(), fmax(x1, x2), fmin(x1, x2), 
    

    return 0;
}