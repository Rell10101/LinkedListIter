//разработчик: Самаев Антон ИВТ-21

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> l;
    l.addNode(5);
    l.addNode(10);
    l.printList();
    std::cout << "\n";


    // цикл с использованием итераторов
    for (LinkedList<int>::LinkedListIterator<int> t = l.begin(); t != l.end(); ++t) {
        cout << *t << " ";
    }

    std::cout << "\n";

}