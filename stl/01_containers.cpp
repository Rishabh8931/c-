#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
    STL CONTAINERS
    ==============
    Containers own and organize collections of objects.

    SEQUENCE CONTAINERS:
    - array: fixed size, contiguous, O(1) indexing
    - vector: resizable contiguous storage, O(1) indexing
    - deque: efficient insertion/removal at both ends
    - list: doubly linked list; O(1) insertion after an iterator

    ASSOCIATIVE CONTAINERS:
    - set/map: sorted balanced trees, O(log n) search/insert/erase
    - unordered_set/unordered_map: hash tables, O(1) average operations

    ADAPTORS:
    - stack: LIFO
    - queue: FIFO
    - priority_queue: highest-priority item first
*/

int main() {
    std::vector<int> numbers{3, 1, 2};
    numbers.push_back(4);

    std::array<int, 3> fixed{10, 20, 30};
    std::deque<int> ends{2, 3};
    ends.push_front(1);
    ends.push_back(4);

    std::list<int> linked{1, 3};
    auto position = std::next(linked.begin());
    linked.insert(position, 2);

    std::set<int> sorted{3, 1, 2, 2};
    std::map<std::string, int> ages{{"Ada", 36}, {"Bjarne", 74}};
    std::unordered_set<std::string> languages{"C++", "C++", "Rust"};
    std::unordered_map<std::string, int> scores{{"Ada", 95}};

    std::stack<int> stack;
    stack.push(10);
    std::queue<std::string> queue;
    queue.push("first");
    std::priority_queue<int> priorities;
    priorities.push(9);
    priorities.push(3);

    std::cout << "vector size: " << numbers.size()
              << ", fixed[1]: " << fixed[1] << '\n'
              << "sorted set size: " << sorted.size()
              << ", Ada score: " << scores.at("Ada") << '\n'
              << "stack top: " << stack.top()
              << ", queue front: " << queue.front()
              << ", priority top: " << priorities.top() << '\n';
}
