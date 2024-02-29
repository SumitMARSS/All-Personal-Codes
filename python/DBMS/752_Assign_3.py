from itertools import combinations

def calculate_closure(attributes, functional_dependencies):
    closure = set(attributes)
    changed = True
    while changed:
        changed = False
        for fd in functional_dependencies:
            if set(fd[0]).issubset(closure) and not set(fd[1]).issubset(closure):
                closure.update(fd[1])
                changed = True
    return closure


def find_candidate_keys(attributes, functional_dependencies):
    candidate_keys = []
    for subset_size in range(1, len(attributes) + 1):
        for subset in combinations(attributes, subset_size):
            closure = calculate_closure(subset, functional_dependencies)
            if set(closure) == set(attributes):
                candidate_keys.append(set(subset))
    return candidate_keys


def lossless_decomposition(relation, functional_dependencies):
    candidate_keys = find_candidate_keys(relation["Relation"], functional_dependencies)
    printed_relations = set()

    for key in candidate_keys:
        remaining_attributes = set(relation["Relation"]) - key

        if not remaining_attributes:
            print("Lossless decomposition found:")
            print("Relation:", relation)
            print("Functional Dependencies:", functional_dependencies)
            print("New Relations:")

            for fd in functional_dependencies:
                closure = calculate_closure(fd[0], functional_dependencies)
                if set(fd[1]).issubset(key) and closure != set(fd[0]):
                    new_relation = tuple(sorted(list(closure)))
                    if new_relation not in printed_relations:
                        print("R{}: {}".format(len(fd[0]),list(closure)))
                        printed_relations.add(new_relation)
    return  printed_relations


# Take user input for relation and functional dependencies
relation_input = input("Enter the attributes of the relation (e.g., CSJDPQV): ")
relation_attributes = list(relation_input)

functional_dependencies = []
num_fds = int(input("Enter the number of functional dependencies: "))
print("Enter the functional dependencies:")
for i in range(num_fds):
    lhs_input = input(
        "Enter the left-hand side of functional dependency {}: ".format(i + 1)
    )
    rhs_input = input(
        "Enter the right-hand side of functional dependency {}: ".format(i + 1)
    )
    functional_dependencies.append((lhs_input, rhs_input))

# Run the program
relation=lossless_decomposition({"Relation": relation_attributes}, functional_dependencies)

print(relation)