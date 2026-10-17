#include <deque>
#include <iostream>

/*
    DEQUE (DOUBLE-ENDED QUEUE)
    ==========================
    A deque supports insertion and removal at both the front and back.

    - push_front / pop_front: O(1)
    - push_back / pop_back: O(1)
    - random access with []: O(1)
    - inserting in the middle: O(n)

    It is useful when a program must process either end, such as a sliding
    window or a work-stealing scheduler.
*/

int main() {
    std::deque<int> values;
    values.push_back(2);
    values.push_front(1);
    values.push_back(3);

    std::cout << "front = " << values.front()
              << ", back = " << values.back() << '\n';
    values.pop_front();
    values.pop_back();
    std::cout << "remaining = " << values.front() << '\n';
}
