#include <iostream>
#include "queue.h"
using namespace std;
//
//int Mynum = 0;
//
//int main()
//{
//    cout << "(testing IsEmpty) should return 1: " << IsEmpty() << endl;
//    cout << "(testing Enqueue) should return 0: " << Enqueue(1) << endl;
//    Enqueue(1);
//    Enqueue(2);
//    Enqueue(3);
//    Enqueue(4);
//    Enqueue(5);
//    Enqueue(6);
//    Enqueue(7);
//    Enqueue(8);
//    Enqueue(9);
//    Enqueue(10);
//    cout << "should return -58: " << Enqueue(11) << endl;
//    cout << "numbers which are currently in queue below:" << endl;
//    Print();
//    cout << "(testing IsEmpty) should be 0: " << IsEmpty() << endl;
//    cout << "(testing Exists) should be 1: " << Exists(2) << endl;
//    cout << "(testing Exists) should be 0: " << Exists(11) << endl;
//    Clear();
//    cout << "the queue has been cleared..." << endl;
//    Enqueue(1);
//    Enqueue(4);
//    Enqueue(87);
//    cout << "(testing Enqueue) should return -62: " << Enqueue(87) << endl;
//    Print();
//    Duplicate();
//    Duplicate();
//    Duplicate();
//    Duplicate();
//    Duplicate();
//    Duplicate();
//    cout << Mul() << endl;
//    Print();
//    Reverse();
//    Print();
//    Peek(Mynum);
//    cout << Mynum << endl;
//    Dequeue(Mynum);
//    cout << Mynum << endl;
//    Print();
//    Dequeue(Mynum);
//    Dequeue(Mynum);
//    Dequeue(Mynum);
//    Dequeue(Mynum);
//    Dequeue(Mynum);
//    Dequeue(Mynum);
//    Dequeue(Mynum);
//    Dequeue(Mynum);
//    cout << Dequeue(Mynum) << endl;
//    Print();
//    cout << Reverse() << endl;
//}

int main()
{
	int a;
	int testNum = 1;
	int retVal;
	Print();

	Clear();


	retVal = Exists(5);
	cout << "Test " << testNum << " " << retVal << endl;
	testNum++;

	retVal = Duplicate();
	cout << "Test " << testNum << " " << retVal << endl;
	testNum++;

	retVal = Dequeue(a);
	cout << "Test " << testNum << " " << retVal << endl;
	testNum++;

	retVal = Enqueue(5);
	cout << "Test " << testNum << " " << retVal << endl;
	testNum++;

	retVal = Enqueue(6);
	cout << "Test " << testNum << " " << retVal << endl;
	testNum++;

	retVal = Enqueue(7);
	cout << "Test " << testNum << " " << retVal << endl;
	testNum++;

	retVal = Peek(a);
	cout << "Test " << testNum << " " << retVal << "  " << a << endl;
	testNum++;

	retVal = IsEmpty();
	cout << "Test " << testNum << " " << retVal << endl;
	testNum++;

	retVal = Enqueue(5);
	cout << "Test " << testNum << " " << retVal << endl;
	testNum++;

	retVal = Enqueue(20);
	cout << "Test " << testNum << " " << retVal << endl;
	testNum++;

	retVal = Enqueue(5);
	cout << "Test " << testNum << " " << retVal << endl;
	testNum++;

	Print();

	retVal = Reverse();
	cout << "Test " << testNum << " " << retVal << endl;
	testNum++;

	Print();

	retVal = Dequeue(a);
	cout << "Test " << testNum << " " << retVal << "  " << a << endl;
	testNum++;

	retVal = Mul();
	cout << "Test " << testNum << " " << retVal << "  " << a << endl;
	testNum++;

	Print();

	retVal = Mul();
	cout << "Test " << testNum << " " << retVal << "  " << a << endl;
	testNum++;

	Print();

	return 0;
}