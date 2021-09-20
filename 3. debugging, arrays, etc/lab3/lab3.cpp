// lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int otherGrades[5];

void f1(int num[])
{
	for (int i = 0; i <= 5; ++i)
	{

	}
}
int main()
{
	/*for (int i = 1; i <= 5; ++i)
	{*/
	int grades[5] = { 3,4,5,6,7 }; //stack would be used for this
	static int moreGrades[] = { 3,4,5,6,7,8,9,10 }; //fixed spot in memory --- heap data

	cout << "otherGrades address: " << otherGrades << endl;
	cout << "moreGrades address: " << moreGrades << endl;
	cout << "grades address: " << grades << endl << endl;
	/*}*/
	cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
