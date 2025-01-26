#include <iostream>
#include <stdexcept> // For exception handling

// Node structure for the linked list
template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

// Queue implementation using a linked list with head and tail pointers
template <typename T>
class Queue {
private:
    Node<T>* head; // Pointer to the front of the queue
    Node<T>* tail; // Pointer to the end of the queue
    int count;     // Number of elements in the queue

public:
    // Constructor
    Queue() : head(nullptr), tail(nullptr), count(0) {}

    // Checks if the queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Adds an element to the end of the queue
    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode; // First element
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    // Removes and returns the element from the front of the queue
    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty!");
        }
        Node<T>* oldHead = head;
        T data = oldHead->data;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr; // If queue becomes empty
        }
        delete oldHead;
        count--;
        return data;
    }

    // Returns the front element without removing it
    T peek() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty!");
        }
        return head->data;
    }

    // Returns the number of elements in the queue
    int size() {
        return count;
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// Test the Queue implementation
int main() {
    Queue<int> q;

    // Enqueue some elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Display the size of the queue
    std::cout << "Queue size: " << q.size() << std::endl;

    // Peek the front element
    std::cout << "Front element: " << q.peek() << std::endl;

    // Dequeue all elements
    while (!q.isEmpty()) {
        std::cout << "Dequeued: " << q.dequeue() << std::endl;
    }

    // Check if the queue is empty
    std::cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
