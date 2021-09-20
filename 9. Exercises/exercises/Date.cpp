#include "Date.h"
#include <iostream>

using namespace std;
int Date::color = 26;

Date::Date(int m, int d, int y) //function stub
{
    cout << "Date default constructor" << endl;
    month = m;
    day = d;
    year = y;
    //this->year = y;
}

//behind the scenes, the address of the object is passed in.
void Date::ShowDate()
{
    cout << "address of pointer inside here:" << this << endl;
    cout << month << "/" << day << "/" << year << endl;
}

Date::~Date()
{
    //cout << "destructor" << endl;
    cout << "about to be deleted: " << month << "/" << day << "/" << year << endl;
}

int Date::GetColor() //no object passed into here
{
    if (color > 25)
    {
        color = 1;
    }
    return color;
}