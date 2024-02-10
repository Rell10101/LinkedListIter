#pragma once
//�����������: ������ ����� ���-21

template <typename T>
// ����������� ����� ���������
class AbstractIterator
{
public:
    // �������� �������� �� ��������� �������
    virtual AbstractIterator<T>& operator++() = 0;
    // �������� ��������� ������ �� ��������
    virtual T& operator*() const = 0;
    // ��������� ���������
    virtual bool operator==(const AbstractIterator<T>& o) const = 0;
    virtual bool operator!=(const AbstractIterator<T>& o) const = 0;

};