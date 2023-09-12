/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    12/09/2023
 * @brief   Simple program to print an integer as hex values.
 */

#include <iostream>

/**
 * @brief   Main function
 * @par     Description
 * The program separates an integer number, writing it as 8 numbers of 4 bits
 * each.
 * @return  Always 0 (success).
 */
int
main ()
{
    int num(0);
    unsigned int array_num[8] = {0};

    std::cout << "Insert a number: ";
    std::cin >> num;

    for (unsigned int idx = 0; idx < (8 * sizeof(int)); idx += 4)
    {
        array_num[idx / 4] = (num >> idx) & 0xF;
    }

    for (unsigned int idx = 0; idx < 8; ++idx)
    {
        std::cout << "@" << std::dec << idx << ' ' << std::hex << array_num[idx] << '\n';
    }

    return 0;
}   /* main() */

/*** End of file ***/
