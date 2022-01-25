#include <iostream>

using namespace std;

const char variable[] = "This is a null terminated string.";

int count()
{
    int count = 0;
    
    for(count = 0; variable[count]; ++count)
    /* statement 1: executed one time before the execution block,
    statement 2: defines condition for executing the block of code 
    statement 3: executed after the code block */ 
    {
        /* block of code to be executed */ 
    };
    
    printf("The number of characters is %d", count);

    return 0;
}

/* for loop practice */ 

int natural_numbers()
{
    int total = 0;
    int iter = 0;
    
    for(iter = 0; iter < 11; iter++){
        total += iter;
    };
    
    printf("%d",total);

    return 0;
}

/* printing perfect numbers under 500 */ 

int perfect_number(int number)
{
    int divisors = 0;
    int d = 1;
    
    for(d=1; d<(number); d++){
        if(number%d==0){
            divisors = divisors + d;
        };
    };
    
    if(divisors==number){
        return number;
    };

    return 0;
}

int main () 
{
    int iter = 0;
    
    for(iter=1; iter<501; iter++){
        int test = perfect_number(iter);
        if(test>0){
            printf("Perfect number: %d \n", test);
        };
    };
    
    return 0;
}

