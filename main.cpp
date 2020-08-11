#include <iostream>
#include "linked-list.cpp"

void printList(LinkedList<int> list);

int main( void )
{
    LinkedList<int> L_List;

    L_List.append(2);
    L_List.append(0);
    L_List.append(6);
    L_List.append(7);
    L_List.append(3);
    L_List.append(8);
    L_List.append(4);
    L_List.append(9);
    L_List.append(1);
    L_List.append(5);

    printList(L_List);

    L_List.sort();

    std::cout << "==============================\n";
    printList(L_List);
}

void printList(LinkedList<int> list) {
    for(int i = 0; i < list.getSize(); i++) {
        std::cout << list.get(i) << "\n";
    }
}
