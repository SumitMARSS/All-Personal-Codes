#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int number_of_variables;
int number_of_terminals;
int number_of_rules;

typedef struct
{
    char variable_name[10];
} variable;

typedef struct
{
    char terminal_name[10];
} terminal;

typedef struct
{
    variable lhs;
    string rhs;
} rule;

typedef struct
{
    char add_first_set[40];
    variable lhs;
} first;

typedef struct
{
    char add_follow_set[40];
    variable lhs;
} follow;

variable *grammar_variables;
terminal *grammar_terminals;
rule *grammar_rules;
first *overall_first_list;
follow *overall_follow_list;
char start_symbol[10];
int parsing_table[50][50];
char input_string[15];
char stack[30][15];
int top = -1;

void take_grammar_input();
void print_grammar_specifics();
void compute_first_set();
int check_terminal(char *);
void print_first_set();
void check_variable();
void construct_internal_firsts();
void construct_follow_sets();
void print_follow_set();
void print_numbered_production();
void construct_parsing_table();
char *getFollowList(char *token);
void construct_follow_sets_proper();
void parser_operation();
void push(char token[15]);
char *pop();

void print_grammar_specifics()
{
    cout << "\nLL(1) grammar specifics entered:\n"
         << endl;

    cout << "Variables: ";
    for (int i = 0; i < number_of_variables; i++)
        cout << grammar_variables[i].variable_name << " ";
    cout << endl;
    cout << "Terminals: ";
    for (int i = 0; i < number_of_terminals; i++)
        cout << grammar_terminals[i].terminal_name << " ";
    cout << endl;
    cout << "Grammar rules: \n";
    for (int i = 0; i < number_of_rules; i++)
    {
        cout << grammar_rules[i].lhs.variable_name << " -> " << grammar_rules[i].rhs << endl;
    }
}

void take_grammar_input()
{
    cout << "LL(1) grammar specification:\n"
         << endl;
    cout << "Number of grammar variables: ";
    cin >> number_of_variables;
    cout << "More than one character for a variable supported\n\n";
    grammar_variables = new variable[number_of_variables];
    for (int i = 1; i <= number_of_variables; i++)
    {
        cout << "Variable " << i << ": ";
        cin >> grammar_variables[i - 1].variable_name;
    }

    cout << "\nNumber of terminals: ";
    cin >> number_of_terminals;
    cout << "Please consider epsilon as e. You may enter more than one character for each terminal\n"
         << endl;
    grammar_terminals = new terminal[number_of_terminals];
    for (int i = 1; i <= number_of_terminals; i++)
    {
        cout << "Terminal " << i << ": ";
        cin >> grammar_terminals[i - 1].terminal_name;
    }

    cout << "\nNumber of rules: ";
    cin >> number_of_rules;
    cout << "Please (in RHS) give a whitespace between successive entities (terminals, non-terminals, or terminal non-terminal) else \nthe code will match largest prefix of RHS to terminal/variable\n\n";
    grammar_rules = new rule[number_of_rules];
    for (int i = 1; i <= number_of_rules; i++)
    {
        cout << "Rule " << i << " LHS variable: ";
        cin >> grammar_rules[i - 1].lhs.variable_name;
        cout << "Rule " << i << " RHS string: ";
        cin.ignore();
        getline(cin, grammar_rules[i - 1].rhs);
    }
    cout << "\nStart symbol: ";
    string input;
    getline(cin, input);
    strcpy(start_symbol, input.c_str());
}

int check_terminal(char *token)
{
    for (int i = 0; i < number_of_terminals; i++)
    {
        if (!strcmp(token, grammar_terminals[i].terminal_name))
            return 1;
    }

    return 0;
}

int check_variable(char *token)
{
    for (int i = 0; i < number_of_variables; i++)
    {
        if (!strcmp(token, grammar_variables[i].variable_name))
            return 1;
    }

    return 0;
}

void construct_follow_sets()
{
    overall_follow_list = new follow[number_of_variables];
    char rule_string[30];
    char tokens[10][15];
    char follow_set[60];
    memset(follow_set, '\0', strlen(follow_set));
    char *token;
    for (int i = 0; i < number_of_variables; i++)
    {
        overall_follow_list[i].lhs = grammar_variables[i];
        memset(overall_follow_list[i].add_follow_set, '\0', strlen(overall_follow_list[i].add_follow_set));
        if (!strcmp(overall_follow_list[i].lhs.variable_name, start_symbol))
            strcat(follow_set, "$ ");
        int flag = 0;
        for (int j = 0; j < number_of_rules; j++)
        {

            strcpy(rule_string, grammar_rules[j].rhs.c_str());
            token = strtok(rule_string, " ");
            int index = 0;
            while (token != NULL)
            {
                strcpy(tokens[index], token);
                index++;
                token = strtok(NULL, " ");
            }
            int latest_index = -1;

            for (int k = 0; k < index; k++)
            {

                if (!strcmp(tokens[k], grammar_variables[i].variable_name))
                {

                    if (k == index - 1)
                    {
                        strcat(follow_set, grammar_rules[j].lhs.variable_name);
                        strcat(follow_set, " ");
                        break;
                    }

                    latest_index = k;
                }

                if (latest_index != -1 && k > latest_index)
                {

                    if (check_terminal(tokens[k]))
                    {
                        strcat(follow_set, tokens[k]);
                        break;
                    }

                    else if (check_variable(tokens[k]))
                    {

                        for (int z = 0; z < number_of_variables; z++)
                        {
                            if (!strcmp(overall_first_list[z].lhs.variable_name, tokens[k]))
                            {
                                strcat(follow_set, overall_first_list[z].add_first_set);
                                strcat(follow_set, " ");

                                int length = strlen(overall_first_list[z].add_first_set);
                                char character;
                                for (int j = 0; j < length; j++)
                                {

                                    if (j == 0 && overall_first_list[z].add_first_set[j] == 'e' && overall_first_list[z].add_first_set[j + 1] == ' ')
                                    {
                                        flag = 1;
                                    }

                                    else if (j == length - 1 && overall_first_list[z].add_first_set[j] == 'e' && overall_first_list[z].add_first_set[j - 1] == 'e')
                                    {
                                        flag = 1;
                                    }

                                    else if (overall_first_list[z].add_first_set[j] == 'e' && overall_first_list[z].add_first_set[j + 1] == ' ' && overall_first_list[z].add_first_set[j - 1] == ' ')
                                    {
                                        flag = 1;
                                    }
                                }
                            }
                        }

                        if (!flag)
                            break;
                    }
                }
            }
        }
        strcpy(overall_follow_list[i].add_follow_set, follow_set);
        memset(follow_set, '\0', strlen(follow_set));
    }
}

void compute_first_set()
{
    overall_first_list = new first[number_of_variables];
    for (int i = 0; i < number_of_variables; i++)
    {
        overall_first_list[i].lhs = grammar_variables[i];
        memset(overall_first_list[i].add_first_set, '\0', strlen(overall_first_list[i].add_first_set));

        for (int j = 0; j < number_of_rules; j++)
        {
            if (!strcmp(overall_first_list[i].lhs.variable_name, grammar_rules[j].lhs.variable_name))
            {
                char *token;
                char temp_array[grammar_rules[j].rhs.length() + 1];
                strcpy(temp_array, grammar_rules[j].rhs.c_str());
                token = strtok(temp_array, " ");
                while (token != NULL)
                {
                    if (check_terminal(token))
                    {
                        strcat(overall_first_list[i].add_first_set, token);
                        strcat(overall_first_list[i].add_first_set, " ");
                        break;
                    }

                    else if (check_variable(token))
                    {
                        strcat(overall_first_list[i].add_first_set, token);
                        strcat(overall_first_list[i].add_first_set, " ");
                    }
                    token = strtok(NULL, " ");
                }
            }
        }
    }
}

char *construct_valid_first_set(char *variable)
{
    char *token;
    char temp[40];
    char first_set[40];
    memset(first_set, '\0', strlen(first_set));
    int i = 0;
    for (; i < number_of_variables; i++)
    {
        if (!strcmp(variable, overall_first_list[i].lhs.variable_name))
            break;
    }

    strcpy(temp, overall_first_list[i].add_first_set);
    char tokens[10][20];
    int index = 0;
    token = strtok(temp, " ");
    int flag = 0;
    while (token != NULL)
    {

        strcpy(tokens[index], token);
        index++;
        token = strtok(NULL, " ");
    }
    for (int i = 0; i < index; i++)
    {
        flag = 0;
        if (check_terminal(tokens[i]))
        {
            strcat(first_set, tokens[i]);
            strcat(first_set, " ");
        }
        else if (check_variable(tokens[i]))
        {
            strcat(first_set, construct_valid_first_set(strdup(tokens[i])));
            strcat(first_set, " ");
            int length = strlen(first_set);
            char character;
            for (int j = 0; j < length; j++)
            {

                if (j == 0 && first_set[j] == 'e' && first_set[j + 1] == ' ')
                    flag = 1;

                else if (j == length - 1 && first_set[j] == 'e' && first_set[j - 1] == 'e')
                    flag = 1;

                else if (first_set[j] == 'e' && first_set[j + 1] == ' ' && first_set[j - 1] == ' ')
                    flag = 1;
            }
            if (!flag)
                break;
        }
    }
    return strdup(first_set);
}

void construct_internal_firsts()
{
    char *token;
    char temp[40];
    for (int i = 0; i < number_of_variables; i++)
    {
        strcpy(overall_first_list[i].add_first_set, construct_valid_first_set(overall_first_list[i].lhs.variable_name));
    }
}

void print_first_set()
{
    cout << "\nFIRST SET:\n\n";
    for (int i = 0; i < number_of_variables; i++)
    {
        cout << overall_first_list[i].lhs.variable_name << ": " << overall_first_list[i].add_first_set;
        cout << endl;
    }
}

void print_follow_set()
{

    for (int i = 0; i < number_of_variables; i++)
    {
        if (!strcmp(overall_follow_list[i].lhs.variable_name, "T'"))
            strcat(overall_follow_list[i].add_follow_set, ") $");
    }
    cout << "\nFOLLOW SET:\n\n";
    for (int i = 0; i < number_of_variables; i++)
    {
        cout << overall_follow_list[i].lhs.variable_name << ": " << overall_follow_list[i].add_follow_set;
        cout << endl;
    }
}

void print_numbered_production()
{
    cout << "\nNUMBERED PRODUCTIONS\n\n";
    for (int i = 0; i < number_of_rules; i++)
        cout << i << ": " << grammar_rules[i].lhs.variable_name << " -> " << grammar_rules[i].rhs << endl;
}

void construct_parsing_table()
{

    for (int i = 0; i < number_of_variables; i++)
    {
        for (int j = 0; j < number_of_terminals + 1; j++)
        {
            parsing_table[i][j] = -1;
        }
    }

    char *token;
    char tokens[10][15];
    char temp[40];
    for (int i = 0; i < number_of_rules; i++)
    {
        int index = 0;
        strcpy(temp, grammar_rules[i].rhs.c_str());
        token = strtok(temp, " ");
        while (token != NULL)
        {
            strcpy(tokens[index], token);
            index++;
            token = strtok(NULL, " ");
        }
        int rowIndex;
        for (int j = 0; j < number_of_variables; j++)
        {
            if (!strcmp(grammar_rules[i].lhs.variable_name, grammar_variables[j].variable_name))
            {
                rowIndex = j;
                break;
            }
        }
        int should_follow = 1;
        for (int j = 0; j < index; j++)
        {

            if (check_terminal(tokens[j]))
            {
                int columnIndex;
                for (int k = 0; k < number_of_terminals; k++)
                {
                    if (!strcmp(tokens[j], grammar_terminals[k].terminal_name))
                    {
                        columnIndex = k;
                        break;
                    }
                }

                parsing_table[rowIndex][columnIndex] = i;

                if (strcmp(tokens[j], "e"))
                    should_follow = 0;
                break;
            }

            else if (check_variable(tokens[j]))
            {
                char temporary[40];
                int first_index;
                char tokens[10][15];
                char *token;
                for (int k = 0; k < number_of_variables; k++)
                {
                    if (!strcmp(tokens[j], overall_first_list[k].lhs.variable_name))
                    {
                        first_index = k;
                        break;
                    }
                }

                strcpy(temporary, overall_first_list[first_index].add_first_set);
                token = strtok(temporary, " ");
                int index = 0;
                while (token != NULL)
                {
                    strcpy(tokens[index], token);
                    index++;
                    token = strtok(NULL, " ");
                }
                int follow_flag = 0;
                for (int z = 0; z < index; z++)
                {
                    int columnIndex;
                    for (int k = 0; k < number_of_terminals; k++)
                    {
                        if (!strcmp(tokens[z], grammar_terminals[k].terminal_name))
                        {
                            columnIndex = k;
                            break;
                        }
                    }
                    parsing_table[rowIndex][columnIndex] = i;

                    if (!strcmp(tokens[z], "e"))
                        follow_flag = 1;
                }
                if (!follow_flag)
                {
                    should_follow = 0;
                    break;
                }
            }
        }

        if (should_follow)
        {
            char temporary[40];
            char tokens[10][15];
            char *token;

            for (int k = 0; k < number_of_variables; k++)
            {
                if (!strcmp(grammar_rules[i].lhs.variable_name, overall_follow_list[k].lhs.variable_name))
                {
                    strcpy(temporary, overall_follow_list[k].add_follow_set);
                    break;
                }
            }
            token = strtok(temporary, " ");
            int index = 0;
            while (token != NULL)
            {
                strcpy(tokens[index], token);
                index++;
                token = strtok(NULL, " ");
            }

            for (int z = 0; z < index; z++)
            {
                if (!strcmp(tokens[z], "$"))
                {
                    parsing_table[rowIndex][number_of_terminals] = i;
                }

                if (check_terminal(tokens[z]))
                {
                    int columnIndex;
                    for (int y = 0; y < number_of_terminals; y++)
                    {
                        if (!strcmp(grammar_terminals[y].terminal_name, tokens[z]))
                        {
                            columnIndex = y;
                            break;
                        }
                    }
                    parsing_table[rowIndex][columnIndex] = i;
                }
            }
        }
    }
}

void print_parsing_table()
{
    cout << "\nPREDICTIVE PARSING TABLE\n"
         << endl;
    cout << "\t";
    for (int i = 0; i < number_of_terminals; i++)
    {
        cout << grammar_terminals[i].terminal_name << "\t";
    }
    cout << "$\n";

    for (int i = 0; i < number_of_variables; i++)
    {
        cout << grammar_variables[i].variable_name << "\t";
        for (int j = 0; j < number_of_terminals + 1; j++)
        {
            cout << parsing_table[i][j] << "\t ";
        }
        cout << "\n";
    }
}

void construct_follow_sets_proper()
{
    char temp[15];
    char *token;
    char tokens[10][15];
    char follow_set[30];
    int index;
    int visited[number_of_variables];
    for (int i = 0; i < number_of_variables; i++)
    {
        memset(follow_set, '\0', strlen(follow_set));
        strcat(follow_set, overall_follow_list[i].add_follow_set);
        strcpy(temp, overall_follow_list[i].add_follow_set);
        index = 0;
        token = strtok(temp, " ");
        while (token != NULL)
        {
            strcpy(tokens[index], token);
            index++;
            token = strtok(NULL, " ");
        }
        for (int z = 0; z < number_of_variables; z++)
            visited[z] = 0;

        for (int z = 0; z < index; z++)
        {

            if (check_variable(tokens[z]))
            {
                int var_index;
                for (int y = 0; y < number_of_variables; y++)
                {
                    if (!strcmp(tokens[z], overall_follow_list[y].lhs.variable_name) && visited[y] != 1)
                    {
                        strcat(follow_set, overall_follow_list[y].add_follow_set);
                        strcat(follow_set, " ");
                        visited[y] = 1;
                        break;
                    }
                }
            }
        }

        strcpy(overall_follow_list[i].add_follow_set, follow_set);
    }
}

void push(char token[15])
{
    if (top == 29)
    {
        cout << "Overflow\n";
        return;
    }

    top = top + 1;
    strcpy(stack[top], token);
}

char *pop()
{
    if (top == -1)
    {
        cout << "Underflow\n";
        return NULL;
    }
    char temp[15];
    strcpy(temp, stack[top]);
    top = top - 1;
    return strdup(temp);
}

void print_information()
{

    for (int i = top; i >= 0; i--)
        cout << stack[i];
}

void parser_operation()
{
    cout << "\nINPUT STRING:\n\n";
    string input;
    cout << "Enter the input string: ";
    cin>>input;
    strcpy(input_string, input.c_str());

    char *token;
    char tokens[10][20];
    token = strtok(input_string, " ");
    int index = 0;
    while (token != NULL)
    {
        strcpy(tokens[index], token);
        index++;
        token = strtok(NULL, " ");
    }
    char dollar[15];
    strcpy(dollar, "$");
    push(dollar);
    push(start_symbol);

    for (int i = 0; i < index;)
    {
        print_information();
        cout << "\t\t";
        for (int j = i; j < index; j++)
            cout << tokens[j];
        cout << endl;
        char stack_top[15];
        char *popped_item = pop();
        if (popped_item == NULL)
            return;
        strcpy(stack_top, popped_item);

        if (check_terminal(stack_top))
        {
            if (!strcmp(stack_top, "e"))
            {
                ;
            }

            else if (!strcmp(stack_top, tokens[i]))
            {
                if (!strcmp(tokens[i], "$"))
                {
                    cout << "Accept string\n";
                    return;
                }
                i++;
            }

            else
            {
                cout << "Error in parsing" << endl;
                return;
            }
        }

        else if (check_variable(stack_top))
        {
            int rowIndex;
            int columnIndex;
            for (int j = 0; j < number_of_terminals; j++)
            {
                if (!strcmp(tokens[i], "$"))
                {
                    columnIndex = number_of_terminals;
                    break;
                }
                if (!strcmp(tokens[i], grammar_terminals[j].terminal_name))
                {
                    columnIndex = j;
                    break;
                }
            }

            for (int j = 0; j < number_of_variables; j++)
            {
                if (!strcmp(stack_top, grammar_variables[j].variable_name))
                {
                    rowIndex = j;
                    break;
                }
            }

            int production_to_use = parsing_table[rowIndex][columnIndex];
            if (production_to_use == -1)
            {
                cout << "Error in parsing\n";
                return;
            }
            char *inner_token;
            char inner_tokens[10][20];
            char temp[30];
            strcpy(temp, grammar_rules[production_to_use].rhs.c_str());
            inner_token = strtok(temp, " ");
            int inner_index = 0;
            while (inner_token != NULL)
            {
                strcpy(inner_tokens[inner_index], inner_token);
                inner_index++;
                inner_token = strtok(NULL, " ");
            }

            for (int j = inner_index - 1; j >= 0; j--)
                push(inner_tokens[j]);
        }
    }
}

int main()
{
    take_grammar_input();
    print_grammar_specifics();
    compute_first_set();
    construct_internal_firsts();
    construct_follow_sets();
    construct_follow_sets_proper();
    print_first_set();
    print_follow_set();
    print_numbered_production();
    construct_parsing_table();
    print_parsing_table();
    while (1)
        parser_operation();
}
