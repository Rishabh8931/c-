#include <iostream>
#include <memory>

/*
    LINKED LIST
    ===========
    A linked list stores nodes connected by pointers. Nodes do not need to be
    adjacent in memory, so inserting after a known node does not move others.

    This is a singly linked list: each node points only to its next node.

    Complexity:
    - Access by index: O(n)
    - Search: O(n)
    - Insert/remove at the front or after a known node: O(1)
    - Extra space: O(n) for nodes and links

    unique_ptr owns each next node, so destruction is automatic.
*/

struct Node {
    int value;
    std::unique_ptr<Node> next;
};

class LinkedList {
public:
    void push_front(int value) {
        auto node = std::make_unique<Node>();
        node->value = value;
        node->next = std::move(head);
        head = std::move(node);
    }

    void insert_after(int target, int value) {
        for (Node* current = head.get(); current != nullptr; current = current->next.get()) {
            if (current->value == target) {
                auto node = std::make_unique<Node>();
                node->value = value;
                node->next = std::move(current->next);
                current->next = std::move(node);
                return;
            }
        }
    }

    void print() const {
        for (const Node* current = head.get(); current != nullptr; current = current->next.get()) {
            std::cout << current->value << " -> ";
        }
        std::cout << "null\n";
    }

private:
    std::unique_ptr<Node> head;
};

int main() {
    LinkedList list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.insert_after(2, 99);
    list.print();
}

