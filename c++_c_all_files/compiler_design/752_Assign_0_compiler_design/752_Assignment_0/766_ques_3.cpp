#include <bits/stdc++.h>
using namespace std;

// Function to check if a word is a C++ keyword
bool isKeyword(string& word) {
    unordered_set<string> keywords = {
        "if", "auto", "bool", "break", "case", "char", "class", "const",
         "continue", "default", "delete", "do", "double","else","false", "float", "for",
        "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace",
        "new", "operator", "private", "protected", "public", "register", "reinterpret_cast",
        "return", "short", "signed", "sizeof", "static", "static_cast", "struct", "switch",
        "template", "this", "throw", "true"
    };
    return keywords.find(word) != keywords.end();
}

int main() {
    ifstream inputFile("input.cpp");
    string word;
      while (inputFile >> word) {
        if (isKeyword(word)) {
            std::cout << "Keyword found: " << word << std::endl;
        }
    }
    inputFile.close();
    return 0;
}
