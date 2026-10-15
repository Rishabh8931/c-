#include<iostream>
#include<string>
using namespace std;

int main() {
    string name;
    int userAge;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your age: ";
    cin >> userAge;
    cout << "Hello, " << name << "! You are " << userAge << " years old." << endl;
    return 0;
}