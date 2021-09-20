#pragma once

class Date
{
private:
    int month;
    int day;
    int year;
    static int color; //you cannot initialize color here
public:
    Date(int m = 7, int d = 1, int y = 2000);
    void ShowDate();
    ~Date();
    static int GetColor();
};