#pragma once
//разработчик: Самаев Антон ИВТ-21

#include <iostream>
#include "AbstractIterator.h"

// класс узла списка
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    // конструктор с параметром
    Node(const T& data1) {
        this->data = data1;
        next = nullptr;
    }
};

// класс односвязного списка
template <typename T>
class LinkedList {
private:
    // указатель на начало списка
    Node<T>* head;

public:
    // конструктор без параметров
    LinkedList() {
        head = nullptr;
    }

    // деструктор
    // удаляются все узлы в списке
    ~LinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // добавление узла в конец списка
    void addNode(const T& data);
    // Удаление узла по значению
    void removeNode(T& data);
    // поиск узла по значению
    // true если узел найден, иначе false
    bool searchNode(T& data) const;
    // вывод списка в консоль
    void printList() const;

    /*
    * Для бинарных деревьев, хешированных таблиц и словарей процесс прохождения списка более сложен.
    * Например, прохождение дерева является рекурсивным и должно выполняться рекурсивным методом.
    * Рекурсивные методы не позволяют клиенту остановить процесс прохождения, выполнить другую задачу
    * и продолжить итерацию.
    * С итератором клиенту даётся средство прохождения списка, не требующее сохранения внутренних
    * индексов или указателей.
    */
    // класс итератора для LinkedList
    template<typename T>
    class LinkedListIterator : public AbstractIterator<T> {
    private:
        Node<T>* current;  // Текущий узел

    public:
        // конструктор с параметром
        LinkedListIterator(Node<T>* x) {
            current = x;
        }

        // операторы сравнения
        // равенство
        bool operator==(const AbstractIterator<T>& o) const override {
            // dynamic_cast преобразует операнд o в объект типа const LinkedListIterator<T>&
            return current == dynamic_cast<const LinkedListIterator<T>&>(o).current;
        }

        // неравенство
        bool operator!=(const AbstractIterator<T>& o) const override {
            // dynamic_cast преобразует операнд o в объект типа const LinkedListIterator<T>&
            return !(current == dynamic_cast<const LinkedListIterator<T>&>(o).current);
        }

        // оператор доступа к данным
        T& operator*() const override {
            //возвращает данные текущего узла
            return current->data;
        }

        // оператор pre-increment: перехода на следующий узел
        LinkedListIterator& operator++() override {
            //если текущий не равен nullptr
            if (current != nullptr) {
                //переходим к следующему узлу
                current = current->next;
            }
            //возвращаем ссылку на текущий объект
            return *this;
        }


    };

    // методы begin и end возвращают итератор на начало списка и на nullptr соответственно
    LinkedListIterator<T> begin() const {
        return LinkedListIterator<T>(head);
    }

    LinkedListIterator<T> end() const {
        return LinkedListIterator<T>(nullptr);
    }

};


// добавление узла в список
template<typename T>
void LinkedList<T>::addNode(const T& data) {
    Node<T>* newNode = new Node<T>(data);

    // если список пустой, то создаём первый элемент
    if (head == nullptr) {
        head = newNode;
    }
    // находим последний узел списка и добавляем новый узел после него
    else {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Удаление узла по значению
template<typename T>
void LinkedList<T>::removeNode(T& data) {
    // если список не пустой
    if (head != nullptr) {

        // если нужно удалить узел из начала
        if (head->data == data) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;

        }
        // если удаляемый узел не в начале
        // ищем узел на удаление
        else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                // если нужный узел найден
                // удаляем его и меняем указатели
                if (current->next->data == data) {
                    Node<T>* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    return;
                }
                current = current->next;
            }
        }
    }
}

// поиск узла
// true, если есть узел
// иначе false
template<typename T>
bool LinkedList<T>::searchNode(T& data) const {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// вывод списка в консоль
template<typename T>
void LinkedList<T>::printList() const {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

