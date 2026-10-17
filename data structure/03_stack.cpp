#include <iostream>
#include <stack>
#include <vector>

/*
    STACK
    =====
    A stack is LIFO: Last In, First Out.
    Think of a stack of plates: the last plate placed is the first removed.

    Main operations:
    - push: add to the top
    - pop: remove the top (does not return it)
    - top: inspect the top
    - empty: check whether it has no elements

    All standard stack operations are O(1). A stack is useful for undo
    operations, function calls, depth-first search, and expression parsing.
*/

int main() {
    std::stack<int, std::vector<int>> undoHistory;
    undoHistory.push(10);
    undoHistory.push(20);
    undoHistory.push(30);

    std::cout << "top: " << undoHistory.top() << '\n';
    undoHistory.pop();
    std::cout << "top after pop: " << undoHistory.top() << '\n';

    while (!undoHistory.empty()) {
        std::cout << "removing " << undoHistory.top() << '\n';
        undoHistory.pop();
    }
}
