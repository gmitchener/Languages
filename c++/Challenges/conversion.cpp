#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double metersToFeetConversion(double measurement, bool meters){
    double conversion = 3.28084;

    if(!meters){
        conversion = 1/conversion;
    }

    return measurement*conversion;
}

double celciusToFahrenheitConversion(double temperature, bool celcius){
    if(celcius){
        return temperature*9/5 + 32;
    } else {
        temperature -= 32;
        return temperature*5/9;
    }
}

int main(){

    cout << celciusToFahrenheitConversion(100, false);

    return 0;
}