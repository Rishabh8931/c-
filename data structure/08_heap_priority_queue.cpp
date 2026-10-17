#include <functional>
#include <iostream>
#include <queue>
#include <vector>

/*
    HEAP AND PRIORITY QUEUE
    =======================
    A binary heap is a complete binary tree commonly stored in an array.
    In a max-heap, every parent is >= its children; the largest item is at
    the root. A min-heap reverses that rule.

    Complexity:
    - top: O(1)
    - push/pop: O(log n), because an item moves up/down the heap
    - build from n items: O(n)

    priority_queue defaults to a max-heap. Supplying std::greater makes it a
    min-heap. It is useful for scheduling and shortest-path algorithms.
*/

int main() {
    std::priority_queue<int> max_heap;
    for (int value : {4, 1, 9, 2}) {
        max_heap.push(value);
    }

    std::cout << "max-heap order: ";
    while (!max_heap.empty()) {
        std::cout << max_heap.top() << ' ';
        max_heap.pop();
    }
    std::cout << '\n';

    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    for (int value : {4, 1, 9, 2}) {
        min_heap.push(value);
    }
    std::cout << "min-heap top: " << min_heap.top() << '\n';
}
