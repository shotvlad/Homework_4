#include <iostream>

using namespace std;

//ЧИСЛО СУДЬБЫ. Цифры полной даты рождения суммируются, пока не получится одна цифра. Разработайте функцию и вычислите свое число судьбы)
#define MIN_YEAR 0
#define MAX_YEAR 2021
#define MIN_MONTH 1
#define MAX_MONTH 12

int enter(int number, string str);
bool isCheckData(int number, int min, int max);
bool isCheckDay(int d, int m, int y);
int numberOfFate(int d, int m, int y);

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
    else{}

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
    if (min == 1 and number == 0) {}
    else if (number >= min and number <= max)
    {
        return false;
    }
    else {}
}

bool isCheckDay(int d, int m, int y)
{
    if (m == 2 and (d < 1 or d > 28 + (((y % 4) == 0) && (((y % 100) != 0) || (y % 400)) ? 1 : 0)))
    {
        return false;
    }
    else if ((m == 1, 3, 5, 7, 8, 10, 12) and (d < 1 or d > 31))
    {
        return false;
    }
    else if ((m == 4, 6, 9, 11) and (d < 1 or d > 30))
    {
        return false;
    }
    else {}
}

int numberOfFate(int d, int m, int y)
{
    int number = 0, sum = 0;

    number = d + m * 100 + y * 10000;

    while (number > 0)
    {
        sum += number % 10;

        sum = sum % 10 + sum / 10;

        number /= 10;
    }

    return sum;
}