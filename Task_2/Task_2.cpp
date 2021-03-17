#include <iostream>

using namespace std;

//РАЗРЯДЫ. Разработайте функцию, которая "переворачивает" переданное ей целое число, например: 1234 -> 4321

int enter(int number);
int flipPositive(int number);
int flipNegative(int number);

int main()
{
    int number = 0, inverted = 0;


    number = enter(number);

    if (number >= 0)
    {
        inverted = flipPositive(number);
    }
    else
    {
        inverted = flipNegative(number);
    }

    cout << "\nInverted number: " << inverted << endl;

    return 0;
}

int enter(int number)
{
    cout << "Enter number: ";
    cin >> number;

    return number;
}

int flipPositive(int number)
{
    int flip = 0;

    while (number > 0)
    {
        flip = (flip * 10) + (number % 10);

        number /= 10;
    }

    return flip;
}

int flipNegative(int number)
{
    int flip = 0;

    while (number < 0)
    {
        flip = (flip * 10) + (number % 10);

        number /= 10;
    }

    return flip;
}