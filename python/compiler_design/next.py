class PredictiveParser:
    def __init__(self, grammar):
        self.grammar = grammar
        self.parse_table = self.construct_parse_table()

    def construct_parse_table(self):
        parse_table = {}
        for non_terminal, productions in self.grammar.parse_rules.items():
            parse_table[non_terminal] = {}
            for terminal, production in productions.items():
                parse_table[non_terminal][terminal] = production
        return parse_table

    def parse(self, input_string):
        stack = ['$']
        stack.append(self.grammar.start_symbol)

        i = 0
        while i < len(input_string):
            if stack[-1] in {'$', 'ε'}:
                break

            top_of_stack = stack[-1]
            current_input = input_string[i]

            if top_of_stack == current_input:
                stack.pop()
                i += 1
            else:
                if top_of_stack in self.parse_table and current_input in self.parse_table[top_of_stack]:
                    production = self.parse_table[top_of_stack][current_input]
                    if production == '':
                        return False
                    stack.pop()
                    production_symbols = production.split()[::-1]
                    stack.extend(production_symbols)
                else:
                    return False

        if stack[-1] == '$' and i == len(input_string):
            return True
        else:
            return False

# Example usage:
class Grammar:
    def __init__(self):
        self.start_symbol = 'E'  # Replace with your start symbol
        self.parse_rules = {
            'E': {'(': 'TE\'', 'id': 'TE\''},
            'E\'': {'+': '+TE\'', ')': '', '$': ''},
            'T': {'(': 'FT\'', 'id': 'FT\''},
            'T\'': {'*': '*FT\'', '+': '', ')': '', '$': ''},
            'F': {'(': '(E)', 'id': 'id'}
        }

if __name__ == "__main__":
    input_grammar = Grammar()
    parser = PredictiveParser(input_grammar)
    
    input_string = "id * id * id $"
    print("Input String:", input_string)
    
    if parser.parse(input_string):
        print("Input string belongs to L(G)")
    else:
        print("Input string does not belong to L(G)")
