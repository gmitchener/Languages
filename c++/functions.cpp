#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void say_hi(string name, int age); // can declare functions without its value, just like you can for variables

double cube(double x){
    return  x*x*x;
}

int main(){

    string name = "Georgia";
    int age = 23;

    // say_hi(name, age);
    // printf("\n");
    // say_hi("Mike", 33);

    double x = 3; 
    printf("%f cubed is %f", x, cube(x));

    return 0;
}

void say_hi(string name, int age){
    cout << "Hello " << name << ", you are " << age;
}