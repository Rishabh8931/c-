#include <iostream>
#include <memory>

struct Node
{
    int data;
    std::unique_ptr<Node> next;

    Node(int value, std::unique_ptr<Node> nextNode = nullptr)
        : data(value), next(std::move(nextNode)) {}
};

class LinkedList
{
    std::unique_ptr<Node> head;

public:
    LinkedList() : head(nullptr) {}

    void push_back(int value)
    {
        if (!head)
        {
            head = std::make_unique<Node>(value);
            return;
        }

        Node *current = head.get();
        while (current->next)
        {
            current = current->next.get();
        }
        current->next = std::make_unique<Node>(value);
    };

    void print() const
    {
        const Node *current = head.get();
        while (current)
        {
            std::cout << current->data << " -> ";
            current = current->next.get();
        }
        std::cout << "null\n";
    };

    void push_front(int value)
    {
        head = std::make_unique<Node>(value, std::move(head));
    };
};

int main()
{

    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    list.print();

    return 0;
}