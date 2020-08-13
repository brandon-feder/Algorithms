#include <iostream>
#include "linked-list.cpp"
#include "unicode.cpp"
#include "dbl-linked-list.cpp"
#include "stack.cpp"
#include "queue.cpp"

void printList(LinkedList<int> list);
void printDList(DblLinkedList<UnicodeChar> list);

void linkedListTest();
void unicodeTest();
void dblLinkedListTest();
void stackTest();
void queueTest();

int main( void )
{

    linkedListTest();
    std::cout << "\n=============================\n\n";
    unicodeTest();
    std::cout << "\n=============================\n\n";
    dblLinkedListTest();
    std::cout << "\n=============================\n\n";
    stackTest();
    std::cout << "\n=============================\n\n";
    queueTest();
    std::cout << "\n=============================\n\n";
}


void linkedListTest()
{
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

void dblLinkedListTest()
{
    DblLinkedList<UnicodeChar> dLinkedList;

    UnicodeChar smile1 = UnicodeChar("\U0001F600");
    UnicodeChar sick = UnicodeChar("\U0001F922");
    UnicodeChar hot = UnicodeChar("\U0001F975");
    UnicodeChar blush = UnicodeChar("\U0001F60A");
    UnicodeChar halo = UnicodeChar("\U0001F607");
    UnicodeChar money = UnicodeChar("\U0001F911");
    UnicodeChar zip_lip = UnicodeChar("\U0001F910");
    UnicodeChar cold = UnicodeChar("\U0001F976");
    UnicodeChar evil = UnicodeChar("\U0001F60B");
    UnicodeChar skull = UnicodeChar("\U0001F480");
    UnicodeChar robot = UnicodeChar("\U0001F916");
    UnicodeChar cat = UnicodeChar("\U0001F63A");
    UnicodeChar alien = UnicodeChar("\U0001F470");

    std::cout << "Using append to create original list of emojis: \n";
    dLinkedList.append(smile1);
    dLinkedList.append(sick);
    dLinkedList.append(hot);
    dLinkedList.append(blush);
    dLinkedList.append(halo);
    dLinkedList.append(money);
    dLinkedList.append(zip_lip);
    dLinkedList.append(cold);

    printDList(dLinkedList);

    std::cout << "\nAding some emojis to the front using append_front(): \n";
    dLinkedList.append_front(evil);
    dLinkedList.append_front(skull);
    dLinkedList.append_front(robot);

    printDList(dLinkedList);

    std::cout << "\nChanging the emojis with the set function\n";
    dLinkedList.set(2, alien);
    dLinkedList.set(4, cat);

    printDList(dLinkedList);

    std::cout << "\nRemoving some emojis with remove()\n";
    dLinkedList.remove(2);
    dLinkedList.remove(0);
    dLinkedList.remove(8);

    printDList(dLinkedList);

    std::cout << "\nSorting the remaining emojis\n";

    dLinkedList.bubbleSort();

    printDList(dLinkedList);


}

void unicodeTest()
{
    UnicodeChar charA = UnicodeChar("\U0001F923");
    UnicodeChar charB = UnicodeChar("\U0001F600");

    std::cout << "You can compare unicode chars like any other primative using <, >, ==, etc:\n";
    std::cout << "Is A != B ?      " << (charA != charB) << "\n";
    std::cout << "Is A > B ?      " << (charA > charB) << "\n";
    std::cout << "Is A < B ?      " << (charA < charB) << "\n";
    std::cout << "Is A == B ?      " << (charA == charB) << "\n";
    std::cout << "Is A >= B ?      " << (charA >= charB) << "\n";
    std::cout << "Is A <= B ?      " << (charA <= charB) << "\n";
    std::cout << "Is A != A ?      " << (charA != charA) << "\n";
    std::cout << "Is B == B ?      " << (charB == charB) << "\n";

    std::cout << "\nYou can also print them out: \n";
    std::cout << "Char A: " << charA << "\n";
    std::cout << "Char B: " << charB << "\n";
}

void stackTest()
{
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

void queueTest()
{
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

void printList(LinkedList<int> list)
{
    std::cout << "[ " << list.get(0);
    for(int i = 1; i < list.getSize(); i++) {
        std::cout << ", " << list.get(i);
    }
    std::cout << " ]\n";
}

void printDList(DblLinkedList<UnicodeChar> list)
{
    std::cout << "[ " << list.get(0);
    for(int i = 1; i < list.getSize(); i++) {
        std::cout << ", " << list.get(i);
    }
    std::cout << " ]\n";
}
