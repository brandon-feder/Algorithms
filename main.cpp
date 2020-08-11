#include <iostream>
#include "linked-list.cpp"

void printList(LinkedList<int> list);

int main( void )
{
    // Initialize the list
    LinkedList<int> linkedList;

    // Add elements to the list
    linkedList.append(2);
    linkedList.append(0);
    linkedList.append(6);
    linkedList.append(7);
    linkedList.append(3);
    linkedList.append(8);
    linkedList.append(4);
    linkedList.append(9);
    linkedList.append(1);
    linkedList.append(5);

    std::cout << "\nHere is the original list: \n";
    printList(linkedList);

    // Sort the list
    linkedList.sort();

    std::cout << "\nHere is the list after undergoing selection sort: \n";
    printList(linkedList);

    // Removing first three elements
    linkedList.remove(0);
    linkedList.remove(0);
    linkedList.remove(0);

    std::cout << "\nHere is the list after removing the first three elements: \n";
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

void printList(LinkedList<int> list) {
    std::cout << "[ " << list.get(0);
    for(int i = 1; i < list.getSize(); i++) {
        std::cout << ", " << list.get(i);
    }
    std::cout << " ]\n";
}
