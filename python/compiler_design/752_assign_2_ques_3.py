data_file = open("input.txt", "r")
transitions_list = []
line = data_file.readline()
terminals_list = (line.split())
line = data_file.readline()
non_terminals_list = line.split()

for line in data_file.readlines():
    x, y = line.split()
    transitions_list.append((x, y))

transitions_dict = {}

for nt_item in non_terminals_list:
    values_list = []
    for trans_item in transitions_list:
        if trans_item[0] == nt_item:
            values_list.append(trans_item[1])
    transitions_dict[nt_item] = values_list

tran_list = []
pred_pars_dict = {}

for nt_item in transitions_dict.keys():
    for value_item in transitions_dict[nt_item]:
        tran_list.append((nt_item, value_item))

first_list = []
follow_list = []
first_dict = {}
follow_dict = {}


def calculate_first(nt):
    trans = transitions_dict[nt]
    for value_item in trans:
        if value_item[0] not in terminals_list:
            calculate_first(value_item[0])
        else:
            first_list.append(value_item[0])
    return


for nt_item in non_terminals_list:
    first_dict[nt_item] = []
    follow_dict[nt_item] = []


def calculate_follow(nt):
    for item1 in transitions_dict.keys():
        for item2 in transitions_dict[item1]:
            for i in range(len(item2)):
                if item2[i] == nt:
                    if i != len(item2) - 1:
                        if item2[i + 1] in terminals_list:
                            follow_list.append(item2[i + 1])
                        else:
                            for j in first_dict[item2[i + 1]]:
                                if j == '#':
                                    for k in follow_dict[item2[i + 1]]:
                                        follow_list.append(k)
                                else:
                                    follow_list.append(j)
                    else:
                        for k in follow_dict[item1]:
                            follow_list.append(k)
    follow_dict[nt] = follow_list


for nt_item in non_terminals_list:
    first_list = []
    calculate_first(nt_item)
    first_dict[nt_item] = first_list

for nt_item in non_terminals_list:
    follow_list = []
    follow_list.append('$')
    calculate_follow(nt_item)
    follow_dict[nt_item] = set(follow_list)

temp_list = []
for item in tran_list:
    if item[1][0] in non_terminals_list:
        for item2 in first_dict[item[1][0]]:
            if item2 == '#':
                for item3 in follow_dict[item[1][0]]:
                    pred_pars_dict[(item[0], item3)] = item
            else:
                pred_pars_dict[(item[0], item2)] = item
    else:
        if item[1][0] == '#':
            for item3 in follow_dict[item[0]]:
                pred_pars_dict[(item[0], item3)] = item
        else:
            pred_pars_dict[(item[0], item[1][0])] = item

print("According to input :  \nParser Table is ->>> \n")
print(pred_pars_dict)
print("\n")


def check_string(pred_pars):
    terminal_list = ['+', '*', '(', ')', 'v', '$']
    stack = []
    stack.append('$')
    stack.append('E')
    print("Give your string ->>\n")
    example_list = []
    inp = input()
    while inp != '$':
        example_list.append(inp)
        inp = input()

    example_list.append('$')
    i = 0
    flag = 1
    while len(stack) != 0:
        x = stack.pop()
        a = example_list[i]
        if x in terminal_list:
            if x == a:
                i += 1
            else:
                flag = 0
                break
        else:
            if (x, a) not in pred_pars.keys():
                flag = 0
                break
            else:
                temp_item = pred_pars_dict[(x, a)]
                string = temp_item[1]
                string = string[::-1]
                for j in range(len(string)):
                    if string[j] != '#':
                        stack.append(string[j])
        print("Stack as followed: ", stack)

    if flag == 1:
        print("Strings gets accepted")
    else:
        print("Strings gets rejected")


check_string(pred_pars_dict)
