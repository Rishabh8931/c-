#include <iostream>
#include <vector>

using namespace std;

class Chai
{

    // data members
    string name;
    int savings;

    vector<string> ingredients;

    // member functions
    void displayChaiDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Savings: " << savings << endl;
        cout << "Ingredients: ";
        for (const auto &ingredient : ingredients)
        {
            cout << ingredient << " ";
        }
        cout << endl;
    }
};