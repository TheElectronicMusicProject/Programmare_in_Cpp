/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    23/08/2023
 * @brief   Simple program to print a giant E.
 */

#include <iostream>

/**
 * @brief   Main function
 * @par     Description
 * The program prints a letter E made of asterisks.
 * @return  Always 0 (success).
 */
int
main ()
{
    int line = 0;

    for (line = 0; line < 7; ++line)
    {
        if ((0 == line) || (3 == line) || (6 == line))
        {
            std::cout << "*****" << "\n";
        }
        else
        {
            std::cout << "*" << "\n";
        }
    }
    return 0;
}   /* main() */

/*** End of file ***/
