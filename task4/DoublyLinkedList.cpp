#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> list;

    // Add elements at the beginning and end
    list.addAtBeginning(10);
    list.addAtBeginning(20);
    list.addAtEnd(30);
    list.addAtEnd(40);

    // Display the list
    std::cout << "List after adding elements: ";
    list.display();

    // Remove the first and last elements
    list.removeFirst();
    list.removeLast();

    // Display the list again
    std::cout << "List after removing elements: ";
    list.display();

    // Get and display the length of the list
    std::cout << "Length of the list: " << list.getLength() << std::endl;

    return 0;
}
