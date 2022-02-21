#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int exponenet(int num, int power){
    int result = 1;
    for(int i = 0; i < power; i++){
        result = result*num;
    }
    return result;
}

int main(){
    // for(int i = 0; i <= 5; i++){
    //     printf("%d\n", i);
    // }

    // int nums[] = {1, 2, 3, 5, 8, 13, 21, 34};

    // int numsLength = sizeof(nums)/sizeof(nums[0]);

    // for(int i = 0; i < numsLength; i++){
    //     printf("%d\n", nums[i]);
    // }

    // printf("%d", exponenet(3,4));

    int numberGrid[2][3] = {
        {0, 2, 4},
        {1, 3, 5}
    };

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cout << numberGrid[i][j]<< endl;
        }
    }

    return 0;
}