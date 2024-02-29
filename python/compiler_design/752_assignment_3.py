from tabulate import tabulate
operators = ['+', '-', '*', '/', '^', '(', ')', 'id','$']
precedence_table = {}
for op1 in operators:
    precedence_table[op1] = {}
    for op2 in operators:
        if op1 == '(' and op2 == ')':
            precedence_table[op1][op2] = '='
        elif op1 == '$' and op2 == '$':
            precedence_table[op1][op2] = 'acc'  
        elif (op1=='+'or op1=='*' or op1=='-' or op1=='/' or op1=='^') and op2=='id':
            precedence_table[op1][op2]='<'    
        elif (op1=='+' or op1=='*' or op1=='-' or op1=='/' or op1=='^' or op1==')' or op1=='id')and op2=='$':
            precedence_table[op1][op2]='>'    
        elif (op1=='+' or op1=='*' or op1=='-' or op1=='/' or op1=='^' or op1=='(' or op1=='$') and (op2=='(' or op2=='id' ):
            precedence_table[op1][op2]='<'    
        elif (op1=='+' or op1=='*' or op1=='-' or op1=='/' or op1=='^' or op1==')' or op1=='id') and op2==')':
            precedence_table[op1][op2]='>'    
        elif (op1=='+' or op1=='*' or op1=='-' or op1=='/' or op1=='^' or op1=='(' or op1=='$') and op2=='^':
            precedence_table[op1][op2]='<'    
        elif (op1=='+' or op1=='-'or op1=='(' or op1=='$') and op2=='/':
            precedence_table[op1][op2]='<'    
        elif (op1==')' or op1=='id') and op2=='^':
            precedence_table[op1][op2]='<'    
        elif (op1=='*' or op1=='/'or op1=='^' or op1==')' or op1=='id') and (op2=='/' or op2=='*'):
            precedence_table[op1][op2]='>'    
        elif (op1=='+' or op1=='-'or op1=='$' or op1=='(') and op2=='*':
             precedence_table[op1][op2]='<'    
        elif (op1=='+' or op1=='-'or op1=='*' or op1=='/' or op1=='^' or op1 == ')' or op1=='id') and (op2=='+' or op2=='-'):
            precedence_table[op1][op2]='>'    
        elif (op1=='(' or op1=='$') and (op2=='+' or op2=='-'):
             precedence_table[op1][op2]='<'    
        else :
             precedence_table[op1][op2]='none' 
table_data = [[op1] + [precedence_table[op1][op2] for op2 in operators] for op1 in operators]
headers = [''] + operators
table = tabulate(table_data, headers=headers, tablefmt='grid')
print(table)
stack, str = ['$'],[]
print(" --  Enter your string (end $):->>> ")
while True:
    str.append(input())
    if str[-1] == '$':break
a, b = len(stack) - 1,0
print("\n...STACK..."," \t \t \t \t \t ","...INPUT...\n")
while True:
    print(stack," \t \t \t \t  ",str[b:])
    if stack[a] == '$' and str[b] == '$':
        print("\n\n\n\t...............Your Strings gets ACCEPTED.................\n\n")
        break
    elif precedence_table[stack[a]][str[b]] == '=' or precedence_table[stack[a]][str[b]] == '<':
        stack.append(str[b])
        a,b=a+1,b+1
    elif precedence_table[stack[a]][str[b]] == '>':
        while True:
            print(stack," \t \t \t \t  ",str[b:])
            top,a = stack.pop(),a-1
            if precedence_table[stack[a]][top] == '<': break
    else:
        print("\n\n\n\t...............Your Strings gets REJECTED.................;\n\n")
        break

