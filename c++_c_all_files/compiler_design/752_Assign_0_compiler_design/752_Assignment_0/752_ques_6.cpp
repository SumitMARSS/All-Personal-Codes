#include <bits/stdc++.h>
using namespace std;

// Function to check if a given string is a valid identifier
bool isValid(const string& id) {
    int currentState = 0;
    int automaton[2][3] = {
        {1, -1, 1},  // Transition table for the initial state (0)
        {1, 1, 1},    // Transition table for the accepting state (1)
    };
    for (char ch : id) {
        int inputType = 0;
        if (isalpha(ch))
            inputType = 0; // Input is an alphabet
        else if (isdigit(ch))
            inputType = 1; // Input is a digit
        else if (ch == '_')
            inputType = 2; // Input is an underscore
        int nextState = automaton[currentState][inputType];
        if (nextState == -1)
            return false; // Invalid transition, reject the identifier
        currentState = nextState;
    }
    return currentState == 1; // Return true if the final state is an accepting state
}

int main() {
    // Test the automaton with examples
    string exampleSet[] = {
        "sum",
        "efjhviu",
        "_jeh",
        "4hrjv",
        "heghkelh_",
        "fsjhcfe123"
    };
    for (const string& id : exampleSet) {
        bool result = isValid(id);
        cout << id << ": ";
        if (result) {
            cout << "Valid identifier" << endl;
        } 
        else {
            cout << "Invalid identifier" << endl;
        }
    }
    return 0;
}
