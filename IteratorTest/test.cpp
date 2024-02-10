//разработчик: Самаев Антон ИВТ-21

#include "pch.h"

#include "../LinkedListIter/LinkedList.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

// тестирование метода begin
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

// тестирование оператора *
TEST(TestListIterator, TestData) {

	LinkedList<int> l;
	l.addNode(2);
	l.addNode(5);
	l.addNode(12);
	l.addNode(-3);
	l.addNode(8);

	LinkedList<int>::LinkedListIterator<int> iter = l.begin();

	std::vector<int> arr, arr1 = { 2 , 5, 12, -3, 8 };

	for (LinkedList<int>::LinkedListIterator<int> iter = l.begin(); iter != l.end(); ++iter) {
		arr.push_back(*iter);
	}


	EXPECT_EQ(arr, arr1);
}

// тестирование оператора ==
TEST(TestListIterator, TestEqual) {

	LinkedList<int> l;
	l.addNode(2);
	l.addNode(5);
	l.addNode(12);
	l.addNode(-3);
	l.addNode(8);

	LinkedList<int>::LinkedListIterator<int> iter1 = l.begin();
	LinkedList<int>::LinkedListIterator<int> iter2 = l.begin();

	EXPECT_TRUE(iter1 == iter2);
	++iter1;
	++iter2;
	EXPECT_TRUE(iter1 == iter2);
}

// тестирование оператора !=
TEST(TestListIterator, TestNotEqual) {

	LinkedList<int> l;
	l.addNode(2);
	l.addNode(5);
	l.addNode(12);
	l.addNode(-3);
	l.addNode(8);

	LinkedList<int>::LinkedListIterator<int> iter1 = l.begin();
	LinkedList<int>::LinkedListIterator<int> iter2 = l.begin();

	EXPECT_TRUE(!(iter1 != iter2));
	++iter1;

	EXPECT_TRUE(iter1 != iter2);

}

// тестирование оператора ++
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