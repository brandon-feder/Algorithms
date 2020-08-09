#include <iostream>
#include "linked-list.cpp"

int main( void )
{
    LinkedList<int> L_List;

    L_List.append(1);
    L_List.append(2);
    L_List.append(3);
    //
    std::cout << L_List.get(0) << "\n";
    std::cout << L_List.get(1) << "\n";
    std::cout << L_List.get(2) << "\n";
}
