// DiceGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int value, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;
int roll();
int targetRoll(int x);
char rollScript();
void odds();
void diceValues(int d1, int d2, int sum);
void gameInfo(int win, int loss, int score);

int main() 
{
    //allows user to select a seed value, if negative, set to system time
    double seedValue;
    while (true)
    {
        cout << "Hello user, please enter a seed value: ";
        cin >> seedValue;
        if (seedValue < 0)
        {
            cout << "negative value entered, using system time for seed";
            seedValue = time(NULL);
            break;
        }
        else
        {
            break;
        }
    }
    srand((double)seedValue);

    int score = 0;
    int win = 0;
    int loss = 0;
    int target = 0;


    while (true)
    {
        char input = rollScript();
        if (input == 'r')
        {
            int d1 = roll();
            int d2 = roll();
            int sum = d1 + d2;
            diceValues(d1, d2, sum);
            
            switch (sum)
            {
            case 7:
                if (sum == 7)
                {
                    score++;
                }
            case 11:
                win++;
                score += 9;
                gameInfo(win, loss, score);
                break;
            case 2:
            case 3:
            case 10:
            case 12:
                loss++;
                score -= 10;
                gameInfo(win, loss, score);
                break;
            default:
                while (true)
                {
                    target = sum;
                    cout << "\ntarget = " << target;
                    cout << "\nroll for target value(r to roll, q to quit): ";
                    cout << "\n";
                    cin >> input;
                    cout << input << "\n";
                    if (input == 'r')
                    {
                        int d1 = roll();
                        int d2 = roll();
                        int sum = d1 + d2;
                        diceValues(d1, d2, sum);
                        if (sum == target)
                        {
                            win++;
                            score += 9;
                            gameInfo(win, loss, score);
                            break;
                        }
                        if (sum == 7)
                        {
                            loss++;
                            score -= 9;
                            gameInfo(win, loss, score);
                            break;
                        }
                        
                    }
                    if (input == 'q')
                    {
                        break;
                    }
                }
            }
        }
        if (input == 'q')
        {
            cout << "\n---------------------------------------------\n";
            cout << "\ncurrent score = " << score;
            odds();
            break;
        }

    }
}
//fucntion to roll a value from 1-6
int roll() 
{
    return (rand() % 6) + 1;
}

int targetRoll(int x)
{
    int target = x;
    return 0;
}
char rollScript()
{
    char input;
    cout << "\nEnter r to roll the die or q to quit: ";
    cout << "\n";
    cin >> input;
    cout << input << "\n";
    return input;
}

void odds()
{
    
    cout << "\ndoing 50,000 rolls and then displaying number of times for each value\n";
    for (int i = 0; i < 50000; i++)
    {
        value = roll();
        if (value == 1)
        {
            one++;
        }
        if (value == 2)
        {
            two++;
        }
        if (value == 3)
        {
            three++;
        }
        if (value == 4)
        {
            four++;
        }
        if (value == 5)
        {
            five++;
        }
        if (value == 6)
        {
            six++;
        }
    }
    cout << "\none = " << one;
    cout << "\ntwo = " << two;
    cout << "\nthree = " << three;
    cout << "\nfour = " << four;
    cout << "\nfive = " << five;
    cout << "\nsix = " << six;
}

void diceValues(int d1, int d2, int sum)
{
    cout << "\ndice 1 = " << d1;
    cout << "\ndice 2 = " << d2;
    cout << "\nsum of dice = " << sum;
}

void gameInfo(int win, int loss, int score)
{
    cout << "\ntotal wins = " << win;
    cout << "\ntotal losses = " << loss;
    cout << "\ntotal score = " << score;
    cout << "\n---------------------------------------------\n";
}