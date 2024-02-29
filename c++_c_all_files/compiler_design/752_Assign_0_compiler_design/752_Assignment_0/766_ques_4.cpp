#include <bits/stdc++.h>
using namespace std;

// Function for the removal of comments line
string removeComments(string& line) {
    string result;
    bool single_line_comment = false;
    bool multi_line_comment = false;

    for (int i = 0; i < line.length(); ++i) {
        if (single_line_comment) {
            break; // Ignore the rest of the line as it's a single-line comment
        }
        if (multi_line_comment) {
            if (i + 1 < line.length() && line[i] == '*' && line[i + 1] == '/') {
                multi_line_comment = false;
                ++i; // Skip the second character of "*/"
            }
        } 
        else {
            if (i + 1 < line.length() && line[i] == '/' && line[i + 1] == '/') {
                break; // Ignore the rest of the line as it's a single-line comment
            } else if (i + 1 < line.length() && line[i] == '/' && line[i + 1] == '*') {
                multi_line_comment = true;
                ++i; // Skip the second character of "/*"
            } else {
                result += line[i];
            }
        }
    }
    return result;
}

int main() {
    ifstream inputFile("input.cpp");
    ofstream outputFile("output.cpp");
    string line;
    while (getline(inputFile, line)) {
        string codeWithoutComments = removeComments(line);
        outputFile << codeWithoutComments << endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
