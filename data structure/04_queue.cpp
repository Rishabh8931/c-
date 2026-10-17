#include <iostream>
#include <queue>

/*
    QUEUE
    =====
    A queue is FIFO: First In, First Out.
    The first item added is the first item processed.

    Main operations:
    - push: add at the back
    - pop: remove from the front
    - front/back: inspect either end

    Operations are O(1). Queues model print jobs, task scheduling, and
    breadth-first search.
*/

int main() {
    std::queue<std::string> tasks;
    tasks.push("compile");
    tasks.push("test");
    tasks.push("deploy");

    while (!tasks.empty()) {
        std::cout << "processing: " << tasks.front() << '\n';
        tasks.pop();
    }
}
