#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front, rear, currSize, maxSize;

public:
    // Default constructor with default size of 16
    Queue() {
        maxSize = 16;
        arr = new int[maxSize];
        front = rear = -1;
        currSize = 0;
    }

    // Constructor with specified size
    Queue(int maxSize) {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        front = rear = -1;
        currSize = 0;
    }

    // Push an element into the queue
    void push(int element) {
        if (currSize == maxSize) {
            cout << "Queue is full\n";
            return;
        }
        if (rear == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % maxSize;
        }
        arr[rear] = element;
        currSize++;
        cout << "Pushed element: " << element << endl;
    }

    // Pop an element from the queue
    int pop() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return -1;
        }
        int poppedElement = arr[front];
        if (currSize == 1) {
            front = rear = -1;
        } else {
            front = (front + 1) % maxSize;
        }
        currSize--;
        return poppedElement;
    }

    // Get the front element of the queue
    int top() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Get the current size of the queue
    int size() {
        return currSize;
    }

    // Destructor to free memory
    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);

    cout << "Front element before any deletion: " << q.top() << endl;
    cout << "Queue size before deletion: " << q.size() << endl;

    cout << "Element popped: " << q.pop() << endl;

    cout << "Front element after deletion: " << q.top() << endl;
    cout << "Queue size after deletion: " << q.size() << endl;

    return 0;
}
