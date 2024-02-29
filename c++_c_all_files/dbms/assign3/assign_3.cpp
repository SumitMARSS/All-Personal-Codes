#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
if g++ assign_3.cpp -o assign_3; then
    ./assign_3
fi

using namespace std;

set<char> find_closure(set<char> attributes, vector<pair<set<char>, set<char>>>& fds) {
    set<char> closure = attributes;
    bool changed = true;

    while (changed) {
        changed = false;
        for (const auto& fd : fds) {
            if (includes(fd.first.begin(), fd.first.end(), closure.begin(), closure.end()) &&
                !includes(fd.second.begin(), fd.second.end(), closure.begin(), closure.end())) {
                closure.insert(fd.second.begin(), fd.second.end());
                changed = true;
            }
        }
    }

    return closure;
}

set<char> compute_key(set<char> attributes, vector<pair<set<char>, set<char>>>& fds) {
    set<char> key = attributes;
    set<char> closure;

    do {
        closure = find_closure(key, fds);

        for (char attribute : attributes) {
            if (key.find(attribute) == key.end()) {
                set<char> temp_key = key;
                temp_key.insert(attribute);
                set<char> temp_closure = find_closure(temp_key, fds);

                if (temp_closure == closure) {
                    key = temp_key;
                    break;
                }
            }
        }
    } while (closure != key);

    return key;
}

vector<set<char>> bcnf_decomposition(set<char> relation, vector<pair<set<char>, set<char>>>& fds) {
    vector<set<char>> result;

    set<char> closure;

    for (const auto& fd : fds) {
        set<char> key = compute_key(fd.first, fds);
        set<char> new_relation = key;
        new_relation.insert(fd.second.begin(), fd.second.end());
        result.push_back(new_relation);

        closure = find_closure(new_relation, fds);
        relation.erase(closure.begin(), closure.end());
    }

    if (!relation.empty()) {
        result.push_back(relation);
    }

    return result;
}

int main() {
    set<char> relation = {'C', 'S', 'J', 'D', 'P', 'Q', 'V'};
    vector<pair<set<char>, set<char>>> fds = {
        {{'C'}, {'C', 'S', 'J', 'D', 'P', 'Q', 'V'}},
        {{'S', 'D'}, {'P'}},
        {{'J', 'P'}, {'C'}},
        {{'J'}, {'S'}}
    };

    vector<set<char>> decomposition = bcnf_decomposition(relation, fds);

    cout << "Input Relation:";
    for (char attribute : relation) {
        cout << attribute << " ";
    }
    cout << endl;

    cout << "Functional Dependencies:" << endl;
    for (const auto& fd : fds) {
        for (char attribute : fd.first) {
            cout << attribute;
        }
        cout << " -> ";
        for (char attribute : fd.second) {
            cout << attribute;
        }
        cout << endl;
    }

    cout << "\nBCNF Decomposition:" << endl;
    for (int i = 0; i < decomposition.size(); ++i) {
        cout << "R" << i + 1 << ": ";
        for (char attribute : decomposition[i]) {
            cout << attribute << " ";
        }
        cout << endl;
    }

    return 0;
}
