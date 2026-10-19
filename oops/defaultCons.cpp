#include <iostream>

using namespace std;

class Chai
{
public:
    string teaName;
    int servings;
    vector<string> ingredients;

    // default constructor
    Chai()
    {
        teaName = "Default Chai";
        servings = 1;
        ingredients = {"Tea Leaves", "Milk", "Water"};
    }

    // parameterized constructor
    Chai(string name, int numServings, vector<string> listIngredients)
    {
        teaName = name;
        servings = numServings;
        ingredients = listIngredients;
    }

    // destructor
    ~Chai()
    {
        cout << "Destructor called for " << teaName << endl;
    }

    void displayChaiDetails()
    {
        cout << "Tea Name: " << teaName << endl;
        cout << "Servings: " << servings << endl;
        cout << "Ingredients: ";
        for (const auto &ingredient : ingredients)
        {
            cout << ingredient << " ";
        }
        cout << endl;
    }
};

int main()
{

    Chai defaultChai;
    defaultChai.displayChaiDetails();

    cout << "======================================" << endl;

    Chai masalaChai("Mas ala Chai", 2, {"Tea Leaves", "Milk", "Water", "Sugar", "Spices"});
    masalaChai.displayChaiDetails();

    // copy objects

    Chai copiedChai = masalaChai; // copy constructor is called
    cout << "==============Copied Chai Details==========" << "\n";
    copiedChai.displayChaiDetails();

    return 0;
}