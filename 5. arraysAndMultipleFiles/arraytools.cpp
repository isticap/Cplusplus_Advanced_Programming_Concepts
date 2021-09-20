#include <iostream>
#include <new>
#include <ctime>
#include <cstdlib>

using namespace std;

void DisplayArray(short int* a)
{
	for (int i = 0; i < *a; i++)
	{
		cout << *(a + i) << " ";
	}
	cout << endl;
}

long int ArrayMemUsage(short int* a)
{
	return 2 * *a;
}

void ReverseArray(short int* arr)
{
	short int* temp = new short int[*arr];
	for (int i = (*arr - 1),j=0; i > 0; i--)
	{
		*(temp + j++) = *(arr + i);
	}
	for (int i = 1,j=0; i < *arr; i++,j++)
	{
		*(arr + i) = *(temp + j);
	}
}

short int* ConcatArray(short int* a1, short int* a2) //working... however, there is a memory error occurring when the program exits?
{
	int sizeOfArray = *a1 + *a2 + 1;
	short int* cArrayPtr = new short int[sizeOfArray];
	int i = 1;
	if (cArrayPtr == nullptr)
	{
		cout << "Error: memory could not be allocated";
	}
	else
	{
		*cArrayPtr = sizeOfArray;
		for (int j = 0; j < *a1; j++,i++) 
		{
			*(cArrayPtr + i) = *(a1 + j);
		}
		for (int j = 0; j < *a2; j++,i++)
		{
			*(cArrayPtr + i) = *(a2 + j);
		}	
	}
	return cArrayPtr;
}


short int* GetArrayN(short int* orig, int n)
{
	int arrNSize = 0;
	short int* ptr = orig + 1;
	for (int i = 0; i < n; i++)
	{
		ptr = ptr + arrNSize;
		arrNSize = *(orig + 1 + arrNSize);
	}
 	short int* arrN = new short int[arrNSize];
	if (arrN == nullptr)
	{
		cout << "Error: memory could not be allocated";
	}
	else
	{
		for (int i = 0; i < *(ptr); i++)
		{
			*(arrN + i) = *(ptr+i);
		}
	}
	return arrN;
}

void ScrambleArray(short int* a)
{
	/*short int* scrArr = new short int[*a];
	*scrArr = *a;*/
	int num1, num2;
	for (int i = 0; i < *a * 2; i++)
	{
		num1 = (rand() % ((*a)-1))+1 , num2 = (rand() % ((*a)-1))+1;
		short int temp = *(a + num1);
		*(a + num1) = *(a + num2);
		*(a + num2) = temp;
	}
}
	