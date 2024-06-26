//�����������: ������ ����� ���-21

#include "pch.h"

#include "../LinkedListIter/LinkedList.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

// ������������ ������ begin
TEST(TestListIterator, TestBegin) {

	LinkedList<int> l;
	l.addNode(2);
	l.addNode(5);
	l.addNode(12);
	l.addNode(-3);
	l.addNode(8);

	LinkedList<int>::LinkedListIterator<int> iter = l.begin();

	EXPECT_EQ(*iter, 2);
}

//������������ ������ ������������� ������ ������
TEST(TestListIterator, TestListSize) {

	LinkedList<int> l;

	LinkedList<int>::LinkedListIterator<int> iter = l.begin();

	EXPECT_EQ(l.ListSize(), 0);
	l.addNode(2);
	EXPECT_EQ(l.ListSize(), 1);
	l.addNode(5);
	l.addNode(12);
	EXPECT_EQ(l.ListSize(), 3);
}

// ������������ ��������� *
TEST(TestListIterator, TestData) {

	LinkedList<int> l;
	LinkedList<int>::LinkedListIterator<int> iter = l.begin();
	
	std::vector<int> arr, arr1 = {};

	for (LinkedList<int>::LinkedListIterator<int> iter = l.begin(); iter != l.end(); ++iter) {
		arr.push_back(*iter);
	}
	//�������� ������� ������
	EXPECT_EQ(arr, arr1);

	
	l.addNode(2);
	arr1 = { 2 };
	for (LinkedList<int>::LinkedListIterator<int> iter = l.begin(); iter != l.end(); ++iter) {
		arr.push_back(*iter);
	}
	//�������� ������ �� ������ ��������
	EXPECT_EQ(arr, arr1);

	l.addNode(5);
	l.addNode(12);
	l.addNode(-3);
	l.addNode(8);

	

	arr1 = { 2 , 5, 12, -3, 8 };
	arr.clear();
	for (LinkedList<int>::LinkedListIterator<int> iter = l.begin(); iter != l.end(); ++iter) {
		arr.push_back(*iter);
	}

	EXPECT_EQ(arr, arr1);

}

// ������������ ��������� ==
TEST(TestListIterator, TestEqual) {

	LinkedList<int> l;

	LinkedList<int>::LinkedListIterator<int> iter1 = l.begin();
	LinkedList<int>::LinkedListIterator<int> iter2 = l.begin();
	//������ ������
	EXPECT_TRUE(iter1 == iter2);

	l.addNode(2);
	++iter1;
	++iter2;
	//���� ������� � ������
	EXPECT_TRUE(iter1 == iter2);


	l.addNode(5);
	l.addNode(12);
	l.addNode(-3);
	l.addNode(8);
	EXPECT_TRUE(iter1 == iter2);
	++iter1;
	++iter2;
	EXPECT_TRUE(iter1 == iter2);
}

// ������������ ��������� !=
TEST(TestListIterator, TestNotEqual) {

	LinkedList<int> l;
	l.addNode(2);
	l.addNode(5);
	l.addNode(12);
	l.addNode(-3);
	l.addNode(8);


	LinkedList<int>::LinkedListIterator<int> it1 = l.begin();
	LinkedList<int>::LinkedListIterator<int> it2 = l.begin();

	EXPECT_TRUE(!(it1 != it2));
	++it1;

	EXPECT_TRUE(it1 != it2);

}

// ������������ ��������� ++
TEST(TestListIterator, TestInc) {

	LinkedList<int> l;
	l.addNode(2);
	l.addNode(5);
	l.addNode(12);
	l.addNode(-3);
	l.addNode(8);

	LinkedList<int>::LinkedListIterator<int> iter1 = l.begin();

	EXPECT_EQ(*iter1, 2);
	++iter1;
	EXPECT_EQ(*iter1, 5);
	++iter1;
	EXPECT_EQ(*iter1, 12);
	++iter1;
	EXPECT_EQ(*iter1, -3);
	++iter1;
	EXPECT_EQ(*iter1, 8);
	++iter1;
	EXPECT_EQ(iter1, l.end());
}