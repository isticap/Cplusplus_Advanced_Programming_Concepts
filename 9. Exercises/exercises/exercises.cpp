#include <iostream>
#include "Date.h"
using namespace std;


int main()
{
    Date a;
    Date b(1,2,3); // implying to use the compiler supplied constructor
    cout << "address of a is: " << &a << endl;
    cout << "address of b is: " << &b << endl;
    cout << "\nShowDate a" << endl;
    a.ShowDate();
    cout << "\nShowDate b" << endl;
    b.ShowDate();
    cout << "\n" << Date::GetColor() << endl; //GOOD style for statics!
    //cout << a.GetColor() << endl; // BAD style for statics!
}
