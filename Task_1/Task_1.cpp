#include <iostream>

using namespace std;

//ЧИСЛО СУДЬБЫ. Цифры полной даты рождения суммируются, пока не получится одна цифра. Разработайте функцию и вычислите свое число судьбы)

int enter(int number, string str);
bool check(int y, int m, int d);
int numberOfFate(int y, int m, int d);

int main()
{
    int year = 0, month = 0, day = 0;

    cout << "Enter your birthday: " << endl;
    year = enter(year, "Year");
    month = enter(month, "Month");
    day = enter(day, "Day");

    if (check(year, month, day) != true)
    {
        cout << "\nThere is no such date." << endl;

        return -1;
    }
    else {}

    cout << "\nNumber of fate: " << numberOfFate(year, month, day) << endl;

    return 0;
}

int enter(int number, string str)
{
    cout << str << ": ";
    cin >> number;

    return number;
}

bool check(int y, int m, int d)
{
    if (y < 0)
    {
        return false;
    }
    else if (m < 1 or m > 12)
    {
        return false;
    }
    else if (m == 1 and (d < 1 or d > 31))
    {
        return false;
    }
    else if (m == 2 and (d < 1 or d > 28 + (((y % 4) == 0) && (((y % 100) != 0) || (y % 400)) ? 1 : 0)))
    {
        return false;
    }
    else if (m == 3 and (d < 1 or d > 31))
    {
        return false;
    }
    else if (m == 4 and (d < 1 or d > 30))
    {
        return false;
    }
    else if (m == 5 and (d < 1 or d > 31))
    {
        return false;
    }
    else if (m == 6 and (d < 1 or d > 30))
    {
        return false;
    }
    else if (m == 7 and (d < 1 or d > 31))
    {
        return false;
    }
    else if (m == 8 and (d < 1 or d > 31))
    {
        return false;
    }
    else if (m == 9 and (d < 1 or d > 30))
    {
        return false;
    }
    else if (m == 10 and (d < 1 or d > 31))
    {
        return false;
    }
    else if (m == 11 and (d < 1 or d > 30))
    {
        return false;
    }
    else if (m == 12 and (d < 1 or d > 31))
    {
        return false;
    }
    else return true;
}

int numberOfFate(int y, int m, int d)
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