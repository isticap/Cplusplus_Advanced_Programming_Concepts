// Bank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void despenseBills(long double amount);

int main()
{
    long double amount;
    cout << "this program will calculate the minimum number of bills for the amount entered";
    while (true)
    {
        cout << "\nenter a dollar amount: ";
        cin >> amount;
        //cout << amount << endl;
        despenseBills(amount);
        cout << endl;
    }
}

void despenseBills(long double amount)
{
    long double value[] = { 100, 50, 20, 10, 5, 1, .25, .10, .05, .01 };
    int count[10];
    string names[10] = { "hundred(s)","fiftie(s)","twentie(s)", "ten(s)", "five(s)", "one(s)", "quarter(s)","dime(s)", "nickel(s)", "pennies(s)" };
    
    for (int i = 0; i < 10; i++)
    {
        count[i] = amount / value[i];
        amount = amount - count[i] * value[i];
        //cout << amount << " ";
        if (i==9 && amount > 0.001)
        {
            count[i]++;
        }
        cout << count[i] << ": " << names[i] << endl;
    }

}