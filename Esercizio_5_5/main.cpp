/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    26/08/2023
 * @brief   Simple program to calculate the total minutes.
 */

#include <iostream>

/**
 * @brief   Main function
 * @par     Description
 * The program prints the total minutes given hours and minutes.
 * @return  Always 0 (success).
 */
int
main ()
{
    unsigned int hours(0);
    unsigned int minutes(0);
    unsigned int total_minutes(0);

    std::cout << "Insert the hours and minutes in the following format [hh mm] ";
    std::cin >> hours >> minutes;

    total_minutes = minutes + hours * 60;

    std::cout << "Total minutes " << total_minutes << '\n';

    return 0;
}   /* main() */

/*** End of file ***/
