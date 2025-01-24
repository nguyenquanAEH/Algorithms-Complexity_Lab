#include <iostream>
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int length;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    ~DoublyLinkedList() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            Node<T>* tempNext = temp->next;
            delete temp;
            temp = tempNext;
        }
    }

    void addAtBeginning(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void addAtEnd(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void removeFirst() {
        if (head == nullptr) {
            std::cout << "List is empty, nothing to remove" << std::endl;
            return;
        }
        Node<T>* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }

    void removeLast() {
        if (tail == nullptr) {
            std::cout << "List is empty, nothing to remove" << std::endl;
            return;
        }
        Node<T>* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void display() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    int getLength() const {
        return length;
    }
};
