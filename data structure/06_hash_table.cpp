#include <iostream>
#include <string>
#include <unordered_map>

/*
    HASH TABLE
    ==========
    A hash table maps a key to a value. A hash function converts the key into
    a bucket index. If keys collide, the implementation stores multiple keys
    in one bucket and compares the complete keys.

    Average complexity:
    - insert, find, erase: O(1)
    Worst case: O(n), if many keys collide.

    The table resizes when its load factor becomes high. std::unordered_map
    is the standard hash-table implementation for key/value lookup.
*/

int main() {
    std::unordered_map<std::string, int> scores;
    scores["Ada"] = 95;
    scores["Grace"] = 98;
    scores.insert({"Linus", 91});

    if (auto found = scores.find("Grace"); found != scores.end()) {
        std::cout << "Grace's score: " << found->second << '\n';
    }

    scores.erase("Ada");
    std::cout << "entries: " << scores.size() << '\n';
}
