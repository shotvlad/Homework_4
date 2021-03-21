#include <iostream>

using namespace std;

//РАЗРЯДЫ. Разработайте функцию, которая "переворачивает" переданное ей целое число, например: 1234 -> 4321

int enter(int number);
int flip(int number);

int main()
{
    int number = 0, inverted = 0;

    number = enter(number);

    inverted = flip(number);

    cout << "Inverted number: " << inverted << endl;

    return 0;
}

int enter(int number)
{
    cout << "Enter number: ";
    cin >> number;

    return number;
}

int flip(int number)
{
    int flip = 0;

    while (abs(number) > 0)
    {
        flip = (flip * 10) + (abs(number) % 10);

        number /= 10;
    }

    if (number > 0)
    {
        return flip;
    }
    else
    {
        return -flip;
    }
}