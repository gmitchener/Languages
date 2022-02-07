#include <iostream>
#include <cmath>

using namespace std;

void bool_if_statement(bool male, bool tall){
    // && for 'and' || for 'or' 
    // ! - negation operator

    if(male && tall){
        printf("You are a tall male");
    } else if(male && !tall) {
        printf("You are a short male");
    } else {
        printf("You are not male");
    }
}

int comparison_if_statement(int x1, int x2, int x3){
    int result;

    // >, <, >=, <=, ==, != (= is for assingment, == is a comparison operator)
    if(x1 >= x2 && x1 >= x3){
        result = x1;
    } else if(x2 >= x1 && x2 >= x3) {
        result = x2;
    } else {
        result = x3;
    }

    return result;
}

int comparison_if_statement_2(int x1, int x2, int x3){
    int result = x1;

    if (x2 > result){
        result = x2;
    }
    if (x3 > result){
        result = x3;
    }

    return result;
}

int main(){
    bool male = false;
    bool tall = true;

    // bool_if_statement(male, tall);

    printf("%d", comparison_if_statement_2(111, 501, 891));

    return 0;
}