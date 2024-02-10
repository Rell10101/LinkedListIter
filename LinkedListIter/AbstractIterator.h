#pragma once
//разработчик: Самаев Антон ИВТ-21

template <typename T>
// абстрактный класс итератора
class AbstractIterator
{
public:
    // оператор перехода на следующий элемент
    virtual AbstractIterator<T>& operator++() = 0;
    // оператор получения данных из элемента
    virtual T& operator*() const = 0;
    // операторы сравнения
    virtual bool operator==(const AbstractIterator<T>& o) const = 0;
    virtual bool operator!=(const AbstractIterator<T>& o) const = 0;

};