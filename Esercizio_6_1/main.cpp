/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    26/08/2023
 * @brief   Simple program to convert a numeric vote into a literal one.
 */

#include <iostream>

/**
 * @brief   Main function
 * @par     Description
 * The program prints literal version of the vote.
 * @return  Always 0 (success).
 */
int
main ()
{
    int number = 0;
    char vote = 'F';

    while (true)
    {
        std::cout << "Put the vote: ";
        std::cin >> number;

        if (number < 0)
        {
            std::cout << "Closing the program\n";
            break;
        }

        if ((number >= 0) && (number <= 60))
        {
            vote = 'F';
        }
        else if ((number >= 61) && (number <= 70))
        {
            vote = 'D';
        }
        else if ((number >= 71) && (number <= 80))
        {
            vote = 'C';
        }
        else if ((number >= 81) && (number <= 90))
        {
            vote = 'B';
        }
        else if ((number >= 91) && (number <= 100))
        {
            vote = 'A';
        }
        else
        {
            std::cout << "Vote out of bounds\n";
            continue;
        }

        std::cout << "Vote: " << vote << '\n';
    }

    return 0;
}   /* main() */

/*** End of file ***/
