#include <iostream>
using namespace std;

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = nullptr;
    }
};

// Linked list class
class LinkedList {
private:
    Node* head;

    // Private helper functions
    Node* createNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        return newNode;
    }

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Destructor
    ~LinkedList() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Attach data at the beginning of the list
    void attachBegin(int data) {
        Node* newNode = createNode(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Attach data at the end of the list
    void attachEnd(int data) {
        Node* newNode = createNode(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Detach data from the beginning of the list
    Node* detachBegin() {
        if (head == nullptr) {
            return nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            return temp;
        }
    }

    // Detach data from the end of the list
    Node* detachEnd() {
        if (head == nullptr) {
            return nullptr;
        } else if (head->next == nullptr) {
            Node* temp = head;
            head = nullptr;
            return temp;
        } else {
            Node* current = head;
            Node* prev = nullptr;
            while (current->next != nullptr) {
                prev = current;
                current = current->next;
            }
            prev->next = nullptr;
            return current;
        }
    }

    // Traverse the list and print data
    void traverse() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Search for data in the list
    Node* search(int data) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};

// Main function
int main() {
    LinkedList list;
    int choice, data, searchData;
    Node* detachedNode;

    while (true) {
        cout << "1. Attach at the beginning\n"
             << "2. Attach at the end\n"
             << "3. Detach from the beginning\n"
             << "4. Detach from the end\n"
             << "5. Traverse the list\n"
             << "6. Search for data\n"
             << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to attach at the beginning: ";
                cin >> data;
                list.attachBegin(data);
                break;

            case 2:
                cout << "Enter data to attach at the end: ";
                cin >> data;
                list.attachEnd(data);
                break;

            case 3:
                detachedNode = list.detachBegin();
                if (detachedNode != nullptr) {
                    cout << "Detached node from the beginning: " << detachedNode->data << endl;
                    delete detachedNode;
                } else {
                    cout << "List is empty, cannot detach from beginning" << endl;
                }
                break;

            case 4:
                detachedNode = list.detachEnd();
                if (detachedNode != nullptr) {
                    cout << "Detached node from the end: " << detachedNode->data << endl;
                    delete detachedNode;
                } else {
                    cout << "List is empty, cannot detach from end" << endl;
                }
                break;

            case 5:
                cout << "Traversing the list: ";
                list.traverse();
                break;

            case 6:
                cout << "Enter data to search: ";
                cin >> searchData;
                if (list.search(searchData) != nullptr) {
                    cout << "Data found in the list" << endl;
                } else {
                    cout << "Data not found in the list" << endl;
                }
                break;

            case 7:
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
