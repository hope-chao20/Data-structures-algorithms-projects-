#include <iostream>
using namespace std;

// Structure for a node
struct Node {
    int data;
    Node* next;
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << value << " inserted successfully.\\n";
    }

    void display() {
        if (head == nullptr) {
            cout << "Linked list is empty.\\n";
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\\n";
    }

    void search(int value) {
        Node* temp = head;
        int position = 1;

        while (temp != nullptr) {
            if (temp->data == value) {
                cout << value << " found at position "
                     << position << ".\\n";
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << value << " not found.\\n";
    }

    void deleteNode(int value) {
        Node* temp = head;
        Node* previous = nullptr;

        if (head == nullptr) {
            cout << "Linked list is empty.\\n";
            return;
        }

        while (temp != nullptr && temp->data != value) {
            previous = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << value << " not found.\\n";
            return;
        }

        if (previous == nullptr) {
            head = temp->next;
        } else {
            previous->next = temp->next;
        }

        delete temp;
        cout << value << " deleted successfully.\\n";
    }

    ~LinkedList() {
        Node* temp;

        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\\n===== LINKED LIST MENU =====\\n";
        cout << "1. Insert Node\\n";
        cout << "2. Display List\\n";
        cout << "3. Search Node\\n";
        cout << "4. Delete Node\\n";
        cout << "5. Exit\\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\\n";
            return 1;
        }

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                if (!(cin >> value)) return 1;
                list.insert(value);
                break;

            case 2:
                list.display();
                break;

            case 3:
                cout << "Enter value to search: ";
                if (!(cin >> value)) return 1;
                list.search(value);
                break;

            case 4:
                cout << "Enter value to delete: ";
                if (!(cin >> value)) return 1;
                list.deleteNode(value);
                break;

            case 5:
                cout << "Exiting program...\\n";
                break;

            default:
                cout << "Invalid choice!\\n";
        }
    } while (choice != 5);

    return 0;
}
