#include <iostream>
using namespace std;

// Step 1: Define the Node structure
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Step 2: Define the Linked List class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Insert a new node at the end (Append)
    void append(int val) {
        Node* newNode = new Node(val);
        
        // If the list is empty, make the new node the head
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Otherwise, traverse to the last node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert a new node at the beginning (Prepend)
    void prepend(int val) {
        Node* newNode = new Node(val);
        newNode->next = head; // Point new node to current head
        head = newNode;       // Update head to be the new node
    }

    // Delete the first occurrence of a value
    void deleteNode(int val) {
        if (head == nullptr) return;

        // Case 1: If head is the node to be deleted
        if (head->data == val) {
            Node* temp = head;
            head = head->next; // Shift head to next node
            delete temp;       // Free memory
            return;
        }

        // Case 2: Search for the node to delete
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }

        // If found, unlink the node and delete it
        if (temp->next != nullptr) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    // Display all elements in the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

// Main function to test the Linked List
int main() {
    LinkedList list;

    // Adding elements
    list.append(10);
    list.append(20);
    list.append(30);
    list.prepend(5);

    cout << "Initial Linked List: ";
    list.display();

    // Deleting an element
    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.display();

    return 0;
}
