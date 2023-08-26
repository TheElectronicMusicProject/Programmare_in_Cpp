/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    26/08/2023
 * @brief   Simple program to find leap years.
 */

#include <iostream>

/**
 * @brief   Main function
 * @par     Description
 * The program shows if the given year is a leap year.
 * @return  Always 0 (success).
 */
int
main ()
{
    int year(0);
    bool b_is_leap(false);

    while (true)
    {
        std::cout << "Write your year: ";
        std::cin >> year;

        if (year < 0)
        {
            break;
        }

        if ((0 == year % 400) || ((0 == year % 4) && !(0 == year % 100)))
        {
                b_is_leap = true;
        }
        else
        {
            b_is_leap = false;
        }

        if (true == b_is_leap)
        {
            std::cout << "The year " << year << " is leap\n";
        }
        else
        {
            std::cout << "The year " << year << " is not leap\n";
        }
    }

    return 0;
}   /* main() */

/*** End of file ***/
