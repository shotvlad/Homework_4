#include <iostream>

using namespace std;

//ЧИСЛО СУДЬБЫ. Цифры полной даты рождения суммируются, пока не получится одна цифра. Разработайте функцию и вычислите свое число судьбы)
#define MIN_YEAR 0
#define MAX_YEAR 2021
#define MIN_MONTH 1
#define MAX_MONTH 12
#define MIN_DAY 1
#define MAX_DAY 31

int enter(int number, string str);
bool isCheckData(int number, int min, int max);
bool isCheckDay(int day, int month, int year);
int checkDays(int month, int day, int leapYear);
int checkMonth(int month);
int leapYear(int year);
int numberOfFate(int day, int month, int year);

int main()
{
    int year = 0, month = 0, day = 0;

    cout << "Enter date of birth: " << endl;

    year = enter(year, "Year");
    if (isCheckData(year, MIN_YEAR, MAX_YEAR))
    {
        cout << "There is no such date." << endl;

        return -1;
    }
    else {}

    month = enter(month, "Month");
    if (isCheckData(month, MIN_MONTH, MAX_MONTH))
    {
        cout << "There is no such date." << endl;

        return -1;
    }
    else {}

    day = enter(day, "Day");
    if (isCheckDay(day, month, year))
    {
        cout << "Number of fate: " << numberOfFate(day, month, year) << endl;
    }
    else
    {
        cout << "There is no such date." << endl;

        return -1;
    }

    return 0;
}

int enter(int number, string str)
{
    cout << str << ": ";
    cin >> number;

    return number;
}

bool isCheckData(int number, int min, int max)
{
    return number < min or number > max;
}

bool isCheckDay(int day, int month, int year)
{
    return checkDays(checkMonth(month), day, leapYear(year)) == -1;
}

int checkDays(int monthDays, int day, int leapYear)
{
    if (monthDays == 0 and (day < MIN_DAY or day > MAX_DAY))
    {
        return 0;
    }
    else if  (monthDays == 1 and (day < MIN_DAY or day > MAX_DAY - 1))
    {
        return 0;
    }
    else if (monthDays == 2 and (day < MIN_DAY or day > MAX_DAY - 3 + leapYear))
    {
        return 0;
    }
    else return -1;
}

int checkMonth(int month)
{
    if (month == 2)
    {
        return 2;
    }
    else if (month == 4 or month == 6 or month == 9 or month == 11)
    {
        return 1;
    }
    else return 0;
}

int leapYear(int year)
{
    if ((year % 4 == 0) or ((year % 100 != 0) and (year % 400 == 0)))
    {
        return 1;
    }
    else return 0;
}



int numberOfFate(int day, int month, int year)
{
    int number = 0, sum = 0;

    number = day + month * 100 + year * 10000;

    while (number > 0)
    {
        sum += number % 10;

        sum = sum % 10 + sum / 10;

        number /= 10;
    }

    return sum;
}