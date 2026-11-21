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

    cout << value << " has been enqueued.\n";
}

// Delete an element from the queue
int dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!\n";
        front = rear = -1;
        return -1;
    }

    int x = queue[front];

    front++;

    if (front > rear) {
        front = rear = -1;
    }

    cout << x << " has been dequeued.\n";

    return x;
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
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    return 0;
}
