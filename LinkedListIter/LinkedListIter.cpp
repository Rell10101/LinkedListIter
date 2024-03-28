//разработчик: Самаев Антон ИВТ-21

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> l;
    l.addNode(5);
    l.addNode(10);
    l.addNode(15);
    l.printList();
    std::cout << "\n";


    // цикл с использованием итераторов
    for (LinkedList<int>::LinkedListIterator<int> t = l.begin(); t != l.end(); ++t) {
        cout << *t << " ";
    }
    std::cout << "\n";


    cout << l.ListSize();

    std::cout << "\n";


    // автоматически создаётся 2 итератора на начало и конец
    // совпадает с циклом выше, но реализация короче
    for (auto it2 : l) {
        cout << it2 << " ";
    }
}