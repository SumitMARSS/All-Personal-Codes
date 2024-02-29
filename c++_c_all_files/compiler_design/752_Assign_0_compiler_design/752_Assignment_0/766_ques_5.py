def epsilon_closure(nfa, states):  # Epsilon closure Algorithm
    closure = set(states)
    stack = list(states)
    while stack:
        state = stack.pop()
        if state in nfa and None in nfa[state]:
            for epsilon_state in nfa[state][None]:
                if epsilon_state not in closure:
                    closure.add(epsilon_state)
                    stack.append(epsilon_state)
    return closure


def move(nfa, states, symbol):  # Delta transition
    move_result = set()
    for state in states:
        if state in nfa and symbol in nfa[state]:
            move_result.update(nfa[state][symbol])
    return move_result


def nfa_to_dfa(nfa, start_state, final_states):
    dfa = {}
    queue = [epsilon_closure(nfa, {start_state})]
    processed_states = set()

    # Get all possible symbols from the NFA
    symbols = set()
    for state in nfa.values():
        symbols.update(state.keys())

    while queue:
        current_states = queue.pop()
        current_states_tuple = tuple(sorted(current_states))
        processed_states.add(current_states_tuple)

        for symbol in symbols:  # Iterate over all possible symbols
            if symbol is not None:
                move_result = move(nfa, current_states, symbol)
                epsilon_result = epsilon_closure(nfa, move_result)
                epsilon_result_tuple = tuple(sorted(epsilon_result))

                if epsilon_result_tuple not in processed_states:
                    queue.append(epsilon_result)
                    processed_states.add(epsilon_result_tuple)

                dfa[current_states_tuple, symbol] = epsilon_result_tuple

    # Determine which states in the DFA are final states based on the NFA's final states
    dfa_final_states = {state for state in dfa if any(state_element in final_states for state_element in state[0])}
    return dfa, dfa_final_states


def dfa_minimization(dfa, dfa_final_states):
    # Step 1: Split accepting and non-accepting states
    accepting_states = set()
    non_accepting_states = set()
    for state in dfa:
        if state in dfa_final_states:  # Check if state is a final state in the DFA
            accepting_states.add(state)
        else:
            non_accepting_states.add(state)

    # Step 2: Initialize partitions
    partitions = [accepting_states, non_accepting_states]

    # Step 3: Split the partitions iteratively
    while True:
        new_partitions = []
        for partition in partitions:
            if len(partition) <= 1:
                new_partitions.append(partition)
                continue

            # Group states by their transitions
            transition_groups = {}
            for state in partition:
                next_state = dfa[state]
                transition_groups.setdefault(next_state, set()).add(state)

            new_partitions.extend(transition_groups.values())

        if new_partitions == partitions:
            break
        partitions = new_partitions

    # Step 4: Create the minimized DFA
    minimized_dfa = {}
    for i, partition in enumerate(partitions):
        for state in partition:
            minimized_dfa[state] = i

    return minimized_dfa


def get_nfa_from_user():
    nfa = {}
    num_transitions = int(input("Enter the number of transitions: "))
    for i in range(num_transitions):
        print(f"\nTransition {i + 1}:")
        source_state = int(input("Source State: "))
        symbol = input("Symbol (Enter 'None' for epsilon): ")
        if symbol.lower() == 'none':
            symbol = None
        else:
            symbol = symbol.strip()
        destination_states = list(map(int, input("Destination State(s) (comma-separated): ").split(',')))
        nfa[source_state] = nfa.get(source_state, {})
        nfa[source_state][symbol] = nfa[source_state].get(symbol, []) + destination_states
    return nfa


if __name__== "__main__":
    nfa = get_nfa_from_user()
    start_state = int(input("Enter the start state of the NFA: "))
    start_state = 0
    final_states = [10]  # Add the final state(s) of the NFA here
    dfa, dfa_final_states = nfa_to_dfa(nfa, start_state, final_states)
    print("\nNFA transitions:")
    print(nfa)

    print("\nDFA transitions:")
    for state, transitions in dfa.items():
        state_str = '->*' if state[0] == start_state else '*' if state in dfa_final_states else ''
        print(f"{state_str}{state} --> {transitions}")

    minimized_dfa = dfa_minimization(dfa, dfa_final_states)
    print("\nMinimized DFA:")
    for state, group in minimized_dfa.items():
        state_str = '->*' if state[0] == start_state else '*' if state in dfa_final_states else ''
        print(f"{state_str}{state} --> Group {group}")