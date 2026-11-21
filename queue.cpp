#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Insert an element into the queue
void enqueue(int value) {
    if (rear == MAX - 1) {
        cout << "Queue is full!\n";
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = value;

    cout << value << " inserted into the queue.\n";
}

// Delete an element from the queue
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!\n";
        front = rear = -1;
        return;
    }

    int value = queue[front];

    front++;

    if (front > rear) {
        front = rear = -1;
    }

    cout << value << " deleted from the queue.\n";
}

// Display the queue
void display() {
    if (front == -1) {
        cout << "Queue is empty!\n";
        return;
    }

    cout << "Queue: ";

    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }

    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            return 1;
        }

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                if (!(cin >> value)) {
                    cout << "Invalid input!\n";
                    return 1;
                }
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
