#include <iostream>
#include <cmath>
#include <string>
#include <tuple>

using namespace std;

// Tuples are different to arrays, except that it can handle/hold different data types. For an array, all of the data stored must be of the same type. 

int main(){
    tuple<int, string> person(23, "Georgia");
    // cout << "My name is " << get<1>(person) << " and I am " << get<0>(person) << " years old." << endl;
    get<1>(person) = "Matt";
    get<0>(person) = 25;
    // cout << "My name is " << get<1>(person) << " and I am " << get<0>(person) << " years old." << endl;

    tuple<string, int, string, float> luigi;
    luigi = make_tuple("Luigi", 9, "White", 8.89);
    // cout << get<0>(luigi) << endl;

    tuple<string, int, string, float> coco = make_tuple("Coco", 6, "Black", 7.65);
    // luigi.swap(coco);
    // cout << get<0>(coco) << endl;

    string luigiName, luigiHairColour;
    int luigiAge;
    float luigiFriendliness;

    tie(luigiName, luigiAge, luigiHairColour, luigiFriendliness) = luigi;
    // cout << luigiName << endl;

    tuple<char, char> DNA1 = make_tuple('A', 'T');
    tuple<char, char, int> DNA2 = make_tuple('U', 'G', 120);
    auto DNA = tuple_cat(DNA1, DNA2);

    return 0;
}