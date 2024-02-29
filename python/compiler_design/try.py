import copy
from tabulate import tabulate


# calculation of first
# epsilon is denoted by 'e'
# pass rule in first function
def first(rule):
    global rules,nonterm_userdef,term_userdef,separatedRules,firsts
    # recursion base condition (for terminal or epsilon)
    if len(rule) != 0 and (rule is not None):
        if rule[0] in term_userdef:
            return rule[0]
        elif rule[0] == 'e':
            return 'e'
 
    # condition for Non-Terminals
    if len(rule) != 0:
        if rule[0] in list(separatedRules.keys()):
            # fres temporary list of result
            fres = []
            rhs_rules = separatedRules[rule[0]]
            # call first on each rule of RHS fetched (& take union)
            for itr in rhs_rules:
                indivRes = first(itr)
                if type(indivRes) is list:
                    for i in indivRes:
                        fres.append(i)
                else:
                    fres.append(indivRes)
 
            # if no epsilon in result received, return fres
            if 'e' not in fres:
                return fres
            else:
                # apply epsilon rule => f(ABC)=f(A)-{e} U f(BC)
                newList = []
                fres.remove('e')
                if len(rule) > 1:
                    ansNew = first(rule[1:])
                    if ansNew != None:
                        if type(ansNew) is list:
                            newList = fres + ansNew
                        else:
                            newList = fres + [ansNew]
                    else:
                        newList = fres
                    return newList
                # if result is not already returned control reaches here
                # lastly if eplison still persists keep it in result of first
                fres.append('e')
                return fres


def computeAllFirsts():
    global nonterm_userdef,term_userdef,separatedRules,firsts
 
    # calculate first for each rule (call first() on all RHS)
    for y in list(separatedRules.keys()):
        t = set()
        for sub in separatedRules.get(y):
            res = first(sub)
            if res != None:
                if type(res) is list:
                    for u in res:
                        t.add(u)
                else:
                    t.add(res)
 
        # save result in 'firsts' list
        firsts[y] = t
 
    print("\n\nFIRSTS : ")
    key_list = list(firsts.keys())
    index=0
    for gg in firsts:
        print(f"first({key_list[index]}) => {firsts[gg]}")
        index+=1


def follow(nt):
    global start_symbol,rules,nonterm_userdef,term_userdef,separatedRules,firsts,follows
    # for start symbol return $ (recursion base case)
 
    solset = set()
    if nt == start_symbol:
        # return '$'
        solset.add('$')
 
    # check all occurrences
    # solset - is result of computed 'follow' so far
 
    # For input, check in all rules
    for curNT in separatedRules:
        rhs = separatedRules[curNT]
        # go for all productions of NT
        for subrule in rhs:
            if nt in subrule:
                # call for all occurrences on non-terminal in subrule
                while nt in subrule:
                    index_nt = subrule.index(nt)
                    subrule = subrule[index_nt + 1:]
                    # empty condition - call follow on LHS
                    if len(subrule) != 0:
                        # compute first if symbols on RHS of target Non-Terminal exists
                        res = first(subrule)
                        # if epsilon in result apply rule (A->aBX) - follow(B)=(first(X)-{ep}) U follow(A)
                        if 'e' in res:
                            newList = []
                            res.remove('e')
                            ansNew = follow(curNT)
                            if ansNew != None:
                                if type(ansNew) is list:
                                    newList = res + ansNew
                                else:
                                    newList = res + [ansNew]
                            else:
                                newList = res
                            res = newList
                    else:
                        # when nothing in RHS, go circular and take follow of LHS only if (NT in LHS)!=curNT
                        if nt != curNT:
                            res = follow(curNT)
 
                    # add follow result in set form
                    if res is not None:
                        if type(res) is list:
                            for g in res:
                                solset.add(g)
                        else:
                            solset.add(res)
    return list(solset)


def computeAllFollows():
    global start_symbol,rules,nonterm_userdef,term_userdef,separatedRules,firsts,follows
    for NT in separatedRules:
        solset = set()
        sol = follow(NT)
        if sol is not None:
            for g in sol:
                solset.add(g)
        follows[NT] = solset
 
    print("\n\nFOLLOWS : ")
    key_list = list(follows.keys())
    index=0
    for gg in follows:
        print(f"follow({key_list[index]}) => {follows[gg]}")
        index+=1


def createParseTable():
    global separatedRules,firsts,follows,term_userdef

    rows = list(separatedRules.keys())
    cols = copy.deepcopy(term_userdef)
    cols=cols+['$']

    table=[]
    for _ in rows:
        row = []
        for _ in cols:
            row.append('')
        # of $ append one more col
        table.append(row)

    for lhs in separatedRules:
        rhs = separatedRules[lhs]
        for y in rhs:
            res = first(y)
            # epsilon is present, take union with follow
            if 'e' in res:
                if type(res) == str:
                    firstFollow = []
                    fol_op = follows[lhs]
                    if fol_op is str:
                        firstFollow.append(fol_op)
                    else:
                        for u in fol_op:
                            firstFollow.append(u)
                    res = firstFollow
                else:
                    res.remove('e')
                    res = list(res) + list(follows[lhs])
            # add rules to table
            ttemp = []
            if type(res) is str:
                ttemp.append(res)
                res = copy.deepcopy(ttemp)
            for c in res:
                x = rows.index(lhs)
                yt = cols.index(c)
                table[x][yt] = f"{lhs} -> {' '.join(y)}"

    return [table,rows,cols]


#-------------------------------------------------------------------------------------------


#                             *********MAIN function*********** 

#example
rules = ['E -> T E\'','E\' -> + T E\' | e','T -> F T\'','T\' -> * F T\' | e','F -> ( E ) | id']
nonterm_userdef = ['E','E\'','T','T\'','F']
term_userdef = ['id','+','*','(',')']
start_symbol = nonterm_userdef[0]

print("\nOriginal grammar input : ")
for y in rules:
	print(y)

separatedRules={}
for rule in rules:
        k = rule.split("->")
        # remove un-necessary spaces
        k[0] = k[0].strip()
        k[1] = k[1].strip()
        rhs = k[1]
        multirhs = rhs.split('|')
        # remove un-necessary spaces
        for i in range(len(multirhs)):
            multirhs[i] = multirhs[i].strip()
            multirhs[i] = multirhs[i].split()
        separatedRules[k[0]] = multirhs

firsts = {}
follows = {}
 
# computes all FIRSTs for all non terminals
computeAllFirsts()

# assuming first rule has start_symbol
start_symbol = list(separatedRules.keys())[0]

# computes all FOLLOWs for all occurrences
computeAllFollows()

# generate formatted first and follow table, then generate parse table 
[table,rows,cols] = createParseTable()
Table=copy.deepcopy(table)

# print LL(1) parsing table
index=0
for i in rows:
    Table[index]=[i]+Table[index]
    index+=1
Table=[['']+cols]+Table
print('\n\nLL(1) PARSING TABLE : \n'+tabulate(Table,headers='firstrow',tablefmt='fancy_grid'))

flag = 0
# taking screenshot of stack status and storing in the below table for verification
LL1_parsing=[['Stack','Input','Action']]
# input string
str = input("\n\nEnter a string(NOTE : Separate each terminal with a single space) : ")
# splitting string using space and forming a list out of it 
str = str.split()
# adding the '$' symbol for generating table for end of input string
str+=['$']
# initializing stack
stack=['$',start_symbol]

while(True):
    # if input symbol not present in terminals, then break out from loop
    if str[0] not in cols:
        break
    # if stack is empty, break from loop
    if(len(stack)==0):
        break
    # if the top of stack contains some terminals 
    if stack[len(stack)-1] in cols:
        # if the symbol pointed by input pointer and top of stack is same, then pop from stack and move i/p
        if stack[len(stack)-1]==str[0]:
            LL1_parsing.append([''.join(stack),''.join(str),f'POP OUT ({stack[len(stack)-1]}) FROM STACK, MOVE INPUT POINTER FORWARD TO NEXT INPUT SYMBOL'])
            stack.pop()
            str.remove(str[0])
            # if both stack and input string has been empty at same time, string is accepted
            if len(stack)==0 and len(str)==0:
                LL1_parsing[len(LL1_parsing)-1][2]='ACCEPT'
                flag=1
                break
            continue
        else:
            break
    # if the top of stack contains some non-terminals 
    else:
        top=rows.index(stack[len(stack)-1])
        index=cols.index(str[0])
    # if the table maps to a particular rule
    if table[top][index]!='':
        rhs=table[top][index].split('->')
        rhs=rhs[1].strip().split()
        # if epsilon is not in the rule mapped by table, then just push rule to stack
        if 'e' not in rhs:
            LL1_parsing.append([''.join(stack),''.join(str),f'POP OUT ({stack[len(stack)-1]}) FROM STACK, PUSH THE RULE ({table[top][index]}) IN THE STACK'])
            stack.pop()
            for i in range(len(rhs)-1,-1,-1):
                stack.append(rhs[i])
        # if epsilon present, just pop the top of the stack
        else:
            LL1_parsing.append([''.join(stack),''.join(str),f'POP OUT ({stack[len(stack)-1]}) FROM STACK'])
            stack.pop()
    # if table maps to empty cell, then string rejected and break out of loop
    else:
        break

if flag==0:
    LL1_parsing.append([''.join(stack),''.join(str),f'REJECTED'])
print('\n'+tabulate(LL1_parsing,headers='firstrow',tablefmt='fancy_grid'))

#if flag==1 , ie, string is accepted else string is rejected to follow the given grammar
if flag == 1:
	print("\nRESULT : String Accepted.\n")
else:
	print("\nRESULT : String Rejected.\n")
        