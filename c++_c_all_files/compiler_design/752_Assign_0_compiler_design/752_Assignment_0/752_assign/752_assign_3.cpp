#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char *input;
int currentIndex = 0;
char lastReduction[6], stack[50], handles[][5] = {")E(", "E*E", "E+E", "i", "E^E"};

int top = 0, length;
char precedenceTable[9][9] = {
    // input -> stack -> + - * / ^ i ( ) $
    // +
    '>', '>', '<', '<', '<', '<', '<', '>', '>',
    // -
    '>', '>', '<', '<', '<', '<', '<', '>', '>',
    // *
    '>', '>', '>', '>', '<', '<', '<', '>', '>',
    // /
    '>', '>', '>', '>', '<', '<', '<', '>', '>',
    // ^
    '>', '>', '>', '>', '<', '<', '<', '>', '>',
    // i
    '>', '>', '>', '>', '>', 'e', 'e', '>', '>',
    // (
    '<', '<', '<', '<', '<', '<', '<', '>', 'e',
    // )
    '>', '>', '>', '>', '>', 'e', 'e', '>', '>',
    // $
    '<', '<', '<', '<', '<', '<', '<', '<', 'e',
};

int getPrecedenceIndex(char c)
{
    switch (c)
    {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    case '^':
        return 4;
    case 'i':
        return 5;
    case '(':
        return 6;
    case ')':
        return 7;
    case '$':
        return 8;
    }
    return -1; // Return an invalid index for unrecognized characters
}

int shift()
{
    stack[++top] = *(input + currentIndex++);
    stack[top + 1] = '\0';
    return 0;
}

int reduce()
{
    int len, found, t;
    for (int i = 0; i < 5; i++)
    {
        len = strlen(handles[i]);
        if (stack[top] == handles[i][0] && top + 1 >= len)
        {
            found = 1;
            for (t = 0; t < len; t++)
            {
                if (stack[top - t] != handles[i][t])
                {
                    found = 0;
                    break;
                }
            }
            if (found == 1)
            {
                stack[top - t + 1] = 'E';
                top = top - t + 1;
                strcpy(lastReduction, handles[i]);
                stack[top + 1] = '\0';
                return 1; // Successful reduction
            }
        }
    }
    return 0;
}

void displayStack()
{
    for (int j = 0; j <= top; j++){
        cout << stack[j];
    }
}

void displayInput()
{
    for (int j = currentIndex; j < length; j++){
        cout << input[j];
    }
}

int main()
{
    //int j;
    input = new char[50];
    cout << "Enter your string" << endl;
    cin >> input;
    strcat(input, "$");
    length = strlen(input);
    strcpy(stack, "$");
    cout << "\nSTACK\t     INPUT\t      ACTION" << endl;

    while (currentIndex <= length)
    {
        shift();
        cout << endl;
        displayStack();
        cout << "\t\t";
        displayInput();
        cout << "\t\t shift";
        if (precedenceTable[getPrecedenceIndex(stack[top])][getPrecedenceIndex(input[currentIndex])] == '>')
        {
            while (reduce())
            {
                cout << endl;
                displayStack();
                cout << "\t\t";
                displayInput();
                cout << "\t\tReduced: E->" << lastReduction;
            }
        }
    }

    if (strcmp(stack, "$E$") == 0){
        cout << "\n\n\n\tYour Strings gets ACCEPTED.................\n\n\n";
    }
    else{
        cout << "\n\n\n\tYour Strings gets REJECTED.................;\n\n\n";
    }
    delete[] input; // Free the allocated memory
    return 0;
}
