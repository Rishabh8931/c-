#include <iostream>
#include <iterator>
#include <list>
#include <vector>

/*
    ITERATORS
    =========
    An iterator behaves like a generalized pointer and lets algorithms work
    with many container types without knowing their internal representation.

    Common iterator operations:
    - *it: access the current element
    - ++it: move forward
    - begin/end: first element and one-past-the-end sentinel
    - rbegin/rend: reverse traversal

    Categories provide different abilities:
    input/output, forward, bidirectional, and random-access.
    vector iterators support random jumps; list iterators do not.
*/

int main() {
    std::vector<int> values{1, 2, 3, 4};
    std::cout << "forward: ";
    for (auto it = values.begin(); it != values.end(); ++it) {
        std::cout << *it << ' ';
    }

    std::cout << "\nreverse: ";
    for (auto it = values.rbegin(); it != values.rend(); ++it) {
        std::cout << *it << ' ';
    }

    auto middle = std::next(values.begin(), 2);
    std::cout << "\nthird value: " << *middle << '\n';

    // std::back_inserter turns assignment into push_back.
    std::list<int> copy;
    std::copy(values.begin(), values.end(), std::back_inserter(copy));
    std::cout << "copied values: " << copy.size() << '\n';
}
