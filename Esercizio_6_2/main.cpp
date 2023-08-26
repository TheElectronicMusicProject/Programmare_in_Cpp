/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    26/08/2023
 * @brief   Simple program to convert a numeric vote into a literal one (with mod).
 */

#include <iostream>

/**
 * @brief   Main function
 * @par     Description
 * The program prints literal version of the vote, with symbol.
 * @return  Always 0 (success).
 */
int
main ()
{
    int number = 0;
    int symb = 0;
    char vote = 'F';
    char symb_vote = 0;

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
            symb = 5;
        }
        else if ((number >= 61) && (number <= 70))
        {
            vote = 'D';
            symb = number - 60;
        }
        else if ((number >= 71) && (number <= 80))
        {
            vote = 'C';
            symb = number - 70;
        }
        else if ((number >= 81) && (number <= 90))
        {
            symb = number - 80;
        }
        else if ((number >= 91) && (number <= 100))
        {
            vote = 'A';
            symb = number - 90;
        }
        else
        {
            std::cout << "Vote out of bounds\n";
            continue;
        }

        if ((symb >= 1) && (symb <= 3))
        {
            symb_vote = '-';
        }
        else if ((symb >= 4) && (symb <= 7))
        {
            symb_vote = ' ';
        }
        else
        {
            symb_vote = '+';
        }

        std::cout << "Vote: " << vote << symb_vote << '\n';
    }

    return 0;
}   /* main() */

/*** End of file ***/
