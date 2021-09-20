#include <iostream>
#include "stringtools.h"
using namespace std;

int main()
{
 /* I love Pep9 more than bacon.
    42 + 8 is not 1008.
    A cat loves her owner.*/

    char* ptrArr[3];

    GetInput(ptrArr); //gets input from user.
    DisplayStrings(ptrArr); // displays the entered strings
    cout << endl; //spacing
    
    Search(ptrArr, "love"); //searches for love, prints out strings which contain the word and the number of times it was found. 
    cout << endl; //spacing

    Sort(ptrArr); //sorts strings

    DisplayStrings(ptrArr);
    cout << endl << "displaying lengths of each string: \n";
    
    ShowLens(ptrArr);

    cout << "\ndisplaying total alpha characters found: \n";
    cout << AlphaChars(ptrArr) << endl; //cool, this works.
}
