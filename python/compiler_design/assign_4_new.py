from tabulate import tabulate
terminals_list = []
non_terminals_list = []
transitions_list = []

with open(r'prac\python\compiler_design\assign4.txt', "r") as file:
    terminals_list = file.readline().split()
    non_terminals_list = file.readline().split()
    for line in file.readlines():
        x, y = line.split()
        transitions_list.append((x, y))        
transitions_dict = {transition: i for i, transition in enumerate((transitions_list))}

def is_terminal(symbol):
    return symbol in terminals_list

def is_non_terminal(symbol):
    return symbol in non_terminals_list

def first(terminals, non_terminals, transitions):
    first_dict = {}
    def first_for_symbol(symbol):
        if symbol in terminals:
            return set([symbol])
        
        elif symbol in non_terminals:
            if symbol not in first_dict:
                first_dict[symbol] = set()
                
                for x, y in transitions:
                    if x == symbol:
                        first_dict[symbol].update(first_for_symbol(y[0]))
        return first_dict[symbol]
    for symbol in non_terminals:
        first_for_symbol(symbol)
    return first_dict

def FIRST(beta, a):
    first_set = set()
    for symbol in beta:
        
        if is_terminal(symbol):
            first_set.add(symbol)
            return first_set
        
        elif is_non_terminal(symbol):
            first_set.update(first_dict[symbol])
            return first_set
        
    first_set.add(a)
    return first_set

first_dict = first(terminals_list, non_terminals_list, transitions_list)
#print( first_dict)
dict={}
def closure(I):
    while True:
        new_items = [] 
        for item in I:
            (A, beta), a = item[0], item[1]
            if len(beta) > (beta.index('.')+1) and not beta[beta.index('.') + 1].islower():
                B = beta[beta.index('.') + 1]
                first_beta_a = FIRST(beta[beta.index('.') + 2:], a)
                for x, y in transitions_list:
                    if x == B:
                        for b in first_beta_a:
                            new_item = [(B, ['.'] + list(y)), b]
                            if new_item not in I:
                                new_items.append(new_item)
        if not new_items:
            break
        
        for i in new_items:
            I.append(i)
    return I

def swap(new, pos):
    if pos < len(new) - 1:  
        new[pos], new[pos + 1] = new[pos + 1], new[pos]  
        return new
    else:
        return new 

def goto(I, X):
    J = []
    for item in I:
        (A, beta), a = item
        beta=[_ for _ in beta]
        if  beta[-1]=='.':
            continue
        B=beta[beta.index('.')+1]
        if B==X:
            new_item = [(A,  swap(beta, beta.index('.'))), a]
            J.append(new_item)   
    return closure(J)
     
k1 =  [[('X', ['.', 'S']), '$']]
cl = []
cl.append(closure(k1))
lr2_table = {}
for i, item_set in enumerate(cl):
    lr2_table[i]={}
    for symbol in non_terminals_list + terminals_list:
        goto_set = goto(item_set, symbol)
        if goto_set and goto_set not in cl:
               cl.append(goto_set)
               lr2_table[i][symbol]= len(cl)-1
        else:
            if goto_set:
                lr2_table[i][symbol]=cl.index(goto_set)
                
#print(lr2_table)

def print_lr0_item_set(item_set):
    for item in item_set:
        print(f"{item[0][0]} -> {item[0][1]}   [Look__ahead : {item[1]}]")
   



print("LR(1) items are:  \n")

# printing all items from the list

# def print_lr0_item_set(item_set):
#     for item in item_set:
#         print(f"  {item}")  # Adjust the formatting as needed

# def print_box(text):
#     box_width = len(text) + 4
#     border = '+' + '-' * box_width + '+'
#     content = f'|  {text}  |'

#     print(border)
#     print(content)
#     print(border)

# for i, item_set in enumerate(cl):
#     item_set_text = f"LR(1) Item Set {i} :"  # Replace this with your actual content
#     print_box(item_set_text)
#     print_lr0_item_set(item_set)
#     print("\n")

for i, item_set in enumerate(cl):
    print(f"Item {i}:")
    print_lr0_item_set(item_set)
    print("\n")


lr1_table={}
lr1_dict={}
for i, item_set in enumerate(cl):
    val=[]
    lr1_dict[i]={}
    lr1_table[i] = {}
    for j in item_set:
          (A, beta), a = j
          beta_str = ''.join(beta).replace(".", "")
          index = transitions_dict[(A, beta_str)]
          if beta[-1] == '.' and A == 'X' and a == '$'and beta[-2]=='S':
                lr1_table[i]['$'] = 'acc' 
          elif beta[-1] == '.':
                lr1_table[i][a] = 'R' + str(index)  
                lr1_dict[i][a]=(index)
          elif is_non_terminal(beta[beta.index('.') + 1]):
                lr1_table[i][beta[beta.index('.') + 1]] = 'goto' + str(lr2_table[i][beta[beta.index('.') + 1]])
                lr1_dict[i][beta[beta.index('.') + 1]]=(lr2_table[i][beta[beta.index('.') + 1]])
          elif is_terminal(beta[beta.index('.') + 1]):
                lr1_table[i][beta[beta.index('.') + 1]] = 'S' + str(lr2_table[i][beta[beta.index('.') + 1]])
                lr1_dict[i][beta[beta.index('.') + 1]]=(lr2_table[i][beta[beta.index('.') + 1]])
#print(lr1_table)

terminals_list = [symbol for symbol in terminals_list if symbol not in ["#", "X"]]
non_terminals_list = [symbol for symbol in non_terminals_list if symbol not in ["#", "X"]]
table_data = [['State'] + terminals_list + non_terminals_list]
for state, actions in lr1_table.items():
    row = [state] + [actions.get(symbol, '') for symbol in terminals_list + non_terminals_list]
    table_data.append(row)
table = tabulate(table_data, headers='firstrow', tablefmt='orgtbl')
print(table)
      
input_list=input("\n\nEnter your string : ").split()
input_list.append('$')
stack=[0]
s=stack[-1]
a=0  #ip pointer
while len(stack):
    s=stack[-1]
    print("\n","[",s,',',input_list[a],"]",input_list,"\t\t",a,'\t\t', stack,end="")    
    if input_list[a] not in lr1_table[s].keys():
        print("\n\n\t\tString gets rejected...........\n\n")
        break
    if lr1_table[s][input_list[a]].startswith('S'):
        stack.append(lr1_dict[s][input_list[a]])  
        a+=1
    elif lr1_table[s][input_list[a]][0].startswith('R'):
        j=lr1_dict[s][input_list[a]]             
        A,beta=transitions_list[j][0],transitions_list[j][1]
        for _ in range(len(beta)):stack.pop()
        s=stack[-1]
        stack.append(lr1_dict[s][A])
        print("\t\tProduction Rule : ",A,"-->",beta,end="")
    elif lr1_table[s][input_list[a]]=='acc':
        print("\n\n\t\t String gets accepted.............\n\n")
        break
