#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Dog{
    private:
        int health;    
    public:
        string name;
        int age;
        int friendliness;
        string hairColour;

        Dog(){
            // cout << "Creating unknown Dog object." << endl;
            name = "Unknown";
            age = 0;
            friendliness = 0;
            hairColour = "Unknown";
            health = 0;
        }

        Dog(string aName, int aAge, int aFriendliness, string aHairColour, int aHealth){
            // cout << "Creating Dog object with parameters." << endl;
            name = aName;
            age = aAge;
            friendliness = aFriendliness;
            hairColour = aHairColour;
            setHealth(aHealth);
        } 

        void sayHello(){
            if(friendliness >= 4){
                cout << "Woof woof! My name is " << name << ", do you want to play?" << endl;
            } else {
                cout << "Bark bark, go away. I will bite you!" << endl;
            }
        }

        void fetchBall(){
            cout << "Here is the ball!" << endl;
        }

        void setHealth(int aHealth){
            if(aHealth <= 5 && aHealth > 0){
                health = aHealth;
            } else {
                health = 0;
            }
        }

        int getHealth(){
            return health;
        }
};

class Westie : public Dog{
    using Dog::Dog;

    public:
        void fetchBall(){
            cout << "Couldn't find the ball." << endl;
        }
};

int main(){
    Dog luigi("Luigi", 9, 10, "White", 5);
    // luigi.age = 10;

    Dog lucky("Lucky", 2, 5, "Black", 4);

    // cout << "Woof Woof! My name is " << luigi.name << " and I am " << luigi.age << " years old." << endl;

    // Dog stray;
    // cout << stray.name;

    // luigi.sayHello();
    // lucky.sayHello();

    // cout << lucky.getHealth();

    Westie mario("Mario", 9, 10, "White", 5);

    lucky.fetchBall();
    mario.fetchBall();

    return 0;
}