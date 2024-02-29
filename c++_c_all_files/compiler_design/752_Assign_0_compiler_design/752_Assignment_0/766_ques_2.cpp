#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("input.cpp");
    string line;
    int lineNum = 1; // To keep track of the line number
    while (getline(inputFile, line)) {
        if (line.find("cin") != string::size_type(-1)) {
            cout << "Input statement found in line " << lineNum << ": " << line << endl;
        }
        if (line.find("cout") != string::size_type(-1)) {
           cout << "Output statement found in line " << lineNum << ": " << line << endl;
        }
        lineNum++;
    }
    inputFile.close();
    return 0;
}
