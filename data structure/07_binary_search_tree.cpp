#include <iostream>
#include <memory>

/*
    BINARY SEARCH TREE (BST)
    ========================
    For every node:
    - values in the left subtree are smaller
    - values in the right subtree are larger

    In-order traversal visits values in sorted order.

    Complexity:
    - Search/insert/remove: O(log n) average for a balanced tree
    - Search/insert/remove: O(n) worst case when the tree becomes a chain
    - Traversal: O(n)

    Production code often uses a self-balancing tree (std::map/std::set)
    when predictable O(log n) performance is required.
*/

struct Node {
    int value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
};

void insert(std::unique_ptr<Node>& root, int value) {
    if (!root) {
        root = std::make_unique<Node>(Node{value, nullptr, nullptr});
    } else if (value < root->value) {
        insert(root->left, value);
    } else if (value > root->value) {
        insert(root->right, value);
    }
}

void in_order(const std::unique_ptr<Node>& root) {
    if (!root) {
        return;
    }
    in_order(root->left);
    std::cout << root->value << ' ';
    in_order(root->right);
}

int main() {
    std::unique_ptr<Node> root;
    for (int value : {50, 30, 70, 20, 40, 60, 80}) {
        insert(root, value);
    }
    std::cout << "sorted order: ";
    in_order(root);
    std::cout << '\n';
}
