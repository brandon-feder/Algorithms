#include <iostream>
#include "linked-list.cpp"
#include "stack.cpp"
#include "queue.cpp"

void printList(LinkedList<int> list);

void linkedListTest();
void stackTest();
void queueTest();

int main( void )
{
    linkedListTest();
    std::cout << "\n=============================\n\n";
    stackTest();
    std::cout << "\n=============================\n\n";
    queueTest();
    std::cout << "\n=============================\n\n";
}


void linkedListTest() {
    // Initialize the list
    LinkedList<int> linkedList;

    // Add elements to the list at the start and front
    linkedList.append_front(2);
    linkedList.append(0);
    linkedList.append_front(6);
    linkedList.append(7);
    linkedList.append_front(3);
    linkedList.append(8);
    linkedList.append_front(4);
    linkedList.append(9);
    linkedList.append_front(1);
    linkedList.append(5);

    std::cout << "\nHere is the original list: \n";
    printList(linkedList);

    // Sort the list
    linkedList.sort();

    std::cout << "\nHere is the list after undergoing selection sort: \n";
    printList(linkedList);

    // Removing some elements
    std::cout << "\nHere is the list after removing some elements: \n";
    std::cout << "Removing: " << linkedList.remove(0) << "\n";
    std::cout << "Removing: " << linkedList.remove(2) << "\n";
    std::cout << "Removing: " << linkedList.remove(7) << "\n";
    printList(linkedList);

    // Set each remaing element to a random x where 0 <= x <= 10
    for(int i = 0; i < linkedList.getSize(); i++) {
        linkedList.set(i, rand()%91);
    }
    std::cout << "\nHere is the list after using the set() function to set each element to a random integer between 0 and 100:\n";
    printList(linkedList);

    linkedList.bubbleSort();

    std::cout << "\nHere is the list after sorting using bubble sort: \n";
    printList(linkedList);
}

void stackTest() {
    Stack<char> stack;

    std::cout << "Pushing to stack:\n";
    stack.push('!');
    stack.push('n');
    stack.push('o');
    stack.push('d');
    stack.push('n');
    stack.push('a');
    stack.push('r');
    stack.push('b');

    std::cout << "Popping from stack:\n";
    for(int i = 0; i < 8; i++) {
        std::cout << "Popped: " << stack.pop() << "\n";
    }
}

void queueTest() {
    Queue<float> queue;

    std::cout << "Pushing to queue:\n";
    queue.push(3.1);
    queue.push(4);
    queue.push(1);
    queue.push(5);
    queue.push(9);

    std::cout << "Popping from queue:\n";
    for(int i = 0; i < 5; i++) {
        std::cout << "Popped: " << queue.pop() << "\n";
    }
}

void printList(LinkedList<int> list) {
    std::cout << "[ " << list.get(0);
    for(int i = 1; i < list.getSize(); i++) {
        std::cout << ", " << list.get(i);
    }
    std::cout << " ]\n";
}
