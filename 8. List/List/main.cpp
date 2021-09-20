#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    int enterednumber;
    char enteredIDnumber[100];
    int printnumber;
    Rec myRec;
    char idBuff[100];
    while (true)
    {
        cout << "\nWhat would you like to do?  [1]Add Item  [2]Delete Item  [3]Print List  [0]Quit: ";
        cin >> enterednumber;
        
        if (enterednumber == 1)
        {
            cout << "Enter ID number: ";
            cin >> idBuff;
            myRec.id = idBuff;
            
            cout << "Enter firstname: ";
            cin >> myRec.firstname;
            
            cout << "Enter lastname: ";
            cin >> myRec.lastname;
            
            AddItem(myRec);
        }
        
        if (enterednumber == 2)
        {
            cout << "enter ID # you would like deleted: ";
            cin >> enteredIDnumber;
            DeleteItem(enteredIDnumber);
        }
        
        if (enterednumber == 3)
        {
            cout << "Enter 0 for ascending or 1 for descending: ";
            cin >> printnumber;
            if (printnumber)
            {
                PrintList(1);
            }
            else
            {
                PrintList(0);
            }
            
            
        }
        
        if (enterednumber == 0)
        {
            break;
        }
    }
    

}

