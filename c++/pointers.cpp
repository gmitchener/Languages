#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int age = 23;
    int *pAge = &age;
    double gpa = 3.9;
    double *pGpa = &gpa;
    string name = "Georgia";
    string *pName = &name;

    // cout << pAge << endl;
    // cout << *pAge;

    cout << *&gpa;

    return 0;
}