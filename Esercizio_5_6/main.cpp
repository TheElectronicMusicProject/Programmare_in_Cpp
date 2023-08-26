/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    26/08/2023
 * @brief   Simple program to calculate hours and minutes.
 */

#include <iostream>

/**
 * @brief   Main function
 * @par     Description
 * The program prints the hours and minutes given the total minutes.
 * @return  Always 0 (success).
 */
int
main ()
{
    unsigned int hours(0);
    unsigned int minutes(0);
    unsigned int total_minutes(0);

    std::cout << "Insert the total minutes in the following format [mm] ";
    std::cin >> total_minutes;

    hours = total_minutes / 60;
    minutes = total_minutes - hours * 60;

    std::cout << "Hours " << hours << " and minutes " << minutes << '\n';

    return 0;
}   /* main() */

/*** End of file ***/
