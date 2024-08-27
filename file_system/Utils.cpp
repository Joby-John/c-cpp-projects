#include "Utils.h"
#include <iostream>

using namespace std;

string getInput(const string& prompt) {
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}
