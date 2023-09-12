/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    12/09/2023
 * @brief   Simple program to count the binary ones in a number.
 */

#include <iostream>

/**
 * @brief   Main function
 * @par     Description
 * The program counts the number of bits which are set in the given number.
 * @return  Always 0 (success).
 */
int
main ()
{
    unsigned int num(0);
    unsigned int cnt(0);

    std::cout << "Insert a number: ";
    std::cin >> num;

    for (unsigned int idx = 0; idx < (8 * sizeof(unsigned int)); ++idx)
    {
        cnt += (num >> idx) & 0x1;
    }

    std::cout << "The decimal number " << std::dec << num <<
                 " hexadecimal "<< std::hex << num <<
                 " octal "<< std::oct << num <<
                 " has " << std::dec << cnt << " bits set\n";

    return 0;
}   /* main() */

/*** End of file ***/
