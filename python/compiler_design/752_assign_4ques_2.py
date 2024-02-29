def custom_parser(grammar_rules):
    idx = 0
    valid = 1
    stack = []
    term_symbols = ['+', '*', '(', ')', 'v', '$']
    stack.append('$')
    stack.append('E')
    
    print("Enter the string to which must end with $ check : ")
    input_string = []
    while True:
        user_input = input()
        if user_input == '$':
            break
        input_string.append(user_input)

    input_string.append('$')
    
    while len(stack) != 0:
        stack_top = stack.pop()
        current_input = input_string[idx]
        
        if stack_top in term_symbols:
            if stack_top == current_input:
                idx += 1
            else:
                valid = 0
                break
        else:
            if (stack_top, current_input) not in grammar_rules:
                valid = 0
                break
            else:
                rule = grammar_rules[(stack_top, current_input)]
                rhs = rule[1]
                rhs = rhs[::-1]
                for j in range(len(rhs)):
                    if rhs[j] != '#':
                        stack.append(rhs[j])
        print("Stack: ", stack)

    if valid == 1:
        print("Strings gets accepted")
    else:
        print("Strings gets rejected")

grammar_rules = {
    ('E', '('): ('E', 'TD'),
    ('E', 'v'): ('E', 'TD'),
    ('T', '('): ('T', 'FU'),
    ('T', 'v'): ('T', 'FU'),
    ('F', '('): ('F', '(E)'),
    ('F', 'v'): ('F', 'v'),
    ('D', '+'): ('D', '+TD'),
    ('D', ')'): ('D', '#'),
    ('D', '$'): ('D', '#'),
    ('U', '+'): ('U', '#'),
    ('U', '*'): ('U', '*FU'),
    ('U', ')'): ('U', '#'),
    ('U', '$'): ('U', '#')
}

custom_parser(grammar_rules)
