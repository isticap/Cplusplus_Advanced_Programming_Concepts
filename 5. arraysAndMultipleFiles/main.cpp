#include <iostream>
#include "arraytools.h"
#include <ctime>
using namespace std;


int main()
{
    srand(time(NULL));
    //------------------------------------
    // Declare 2 arrays of short int
    while (true)
    {
        short int Arr1[] = { 7, 11, 22, 33, -10, 88, 99 };
        short int Arr2[] = { 9, 0, 1, 22, 333, 4, 555, 6, 1234 };

        short int* nptr;

        // Declare and assign pointers variables to each of the 2 arrays declared above
        short int* ar1 = Arr1, * ar2 = Arr2;   // TODO: assign these variables.
        // Display Arr1 and Arr2
        DisplayArray(ar1);

        DisplayArray(ar2);

        // Call the ConcatArray function pass in a pointer to Arr1 and
       // a pointer to Arr2 as parameters.  You can use nptr to accept the return value.

        nptr = ConcatArray(ar1, ar2);

        // Display the New Array
        DisplayArray(nptr);

        // Call GetArrayN with and display each array separately

        short int* suba1 = GetArrayN(nptr, 1);
        DisplayArray(suba1);
        delete[] suba1;
        suba1 = NULL;


        short int* suba2 = GetArrayN(nptr, 2);
        DisplayArray(suba2);
        delete[] suba2;
        suba2 = NULL;

        // Reverse the order


        ReverseArray(nptr);


        // Display the New Array (reverse order now)


        DisplayArray(nptr);
        // Display the Memory usages


        cout << ArrayMemUsage(ar1) << endl;
        cout << ArrayMemUsage(ar2) << endl;
        cout << ArrayMemUsage(nptr) << endl;
        delete[] nptr;
        nptr = NULL;

        short int sarray1[] = { 7, 11, 22, 33, 444, 88, 9999 };
        short int sarray2[] = { 7, 10, 20, 33, 444, 88, 99 };
        short int sarray3[] = { 7, 1111, 2222, 3333, 4444, 888, 9999 };

        ScrambleArray(sarray1);
        DisplayArray(sarray1);
        ScrambleArray(sarray2);
        DisplayArray(sarray2);
        ScrambleArray(sarray3);
        DisplayArray(sarray3);
        cout << "Enter y to run program again or n to quit: ";
        char userInput;
        cin >> userInput;
        if (userInput != 'y')
        {
            break;
        }
        cout << endl;
    }
}

//int main()
//{
//	while (true)
//	{
//	srand(time(NULL));
//	short int Arr1[] = { 8,1,2,3,4,5,6,7 }, Arr2[] = { 5,7,8,9,10 };
//	short int* arr1 = Arr1, *arr2 = Arr2;
//	ScrambleArray(arr1);
//	DisplayArray(arr1);
//	ReverseArray(arr1);
//	DisplayArray(arr1);
//	//cout << ArrayMemUsage(arr1) << endl;
//	//ReverseArray(arr1);
//	short int *ntpr = ConcatArray(arr1, arr2);
//	cout << "hmm" << endl;
//	DisplayArray(ntpr);
//	//short int* getArr = GetArrayN(arr1, 3);
//	//DisplayArray(getArr);
//	
//}
