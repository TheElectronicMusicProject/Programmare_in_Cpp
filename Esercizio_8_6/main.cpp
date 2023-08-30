/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    30/08/2023
 * @brief   Simple program to convert a number in letters.
 */

#include <iostream>
#include <string>

/**
 * @brief   Main function
 * @par     Description
 * The program converts a number in symbols into a sequence of letters.
 * @return  Always 0 (success).
 */
int
main ()
{
    std::string number_sym = "";

    while (true)
    {
        std::cout << "Insert a sequence of numbers: ";
        std::getline(std::cin, number_sym);

        unsigned int idx(0);

        if (0 == number_sym.length())
        {
            break;
        }

        while (idx < number_sym.length())
        {
            if ('0' == number_sym.at(idx))
            {
                std::cout << "zero";
            }
            else if ('1' == number_sym.at(idx))
            {
                std::cout << "one";
            }
            else if ('2' == number_sym.at(idx))
            {
                std::cout << "two";
            }
            else if ('3' == number_sym.at(idx))
            {
                std::cout << "three";
            }
            else if ('4' == number_sym.at(idx))
            {
                std::cout << "four";
            }
            else if ('5' == number_sym.at(idx))
            {
                std::cout << "five";
            }
            else if ('6' == number_sym.at(idx))
            {
                std::cout << "six";
            }
            else if ('7' == number_sym.at(idx))
            {
                std::cout << "seven";
            }
            else if ('8' == number_sym.at(idx))
            {
                std::cout << "eight";
            }
            else if ('9' == number_sym.at(idx))
            {
                std::cout << "nine";
            }
            else
            {
                /* Do nothing */
            }

            std::cout << ' ';

            ++idx;
        }

        std::cout << '\n';
    }

    return 0;
}   /* main() */

/*** End of file ***/
