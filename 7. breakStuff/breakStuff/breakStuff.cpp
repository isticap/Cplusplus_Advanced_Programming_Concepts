#include <iostream>
using namespace std;

void f1()
{
	/*for (int i = 1; i < 1000; i++)
	{
		cout << i << endl;
	}*/
	char* ptr = NULL;
	*ptr = 20;
}

int main()
{
	cout << "Hello World!\n";
	char str1[] = "dog";
	char str[] = { 'a','b','c','d' };
	char str2[] = "cat";
	cout << str;
	cout << "here 1";
	cout.flush();
	f1();
	cout << "here 2";
	
	//int* ptr;
	//while (true)
	//{
	//	int x = 25;
	//	ptr = new int[999];
	//	if (ptr == NULL)
	//	{
	//		cout << "NULL";
	//	}
	//	x++;

	//	//delete[] ptr;
	//	//cout << x << endl;
	//}
}
