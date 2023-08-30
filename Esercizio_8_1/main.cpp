/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    29/08/2023
 * @brief   Simple program to print boring rectangles.
 */

#include <iostream>

/**
 * @brief   Main function
 * @par     Description
 * The program prints a grid 8x8.
 * @return  Always 0 (success).
 */
int
main ()
{
    const int height(8);
    const int length(8);
    const int n_line_hor(6);
    const int n_line_ver(4);

    int idx_l = 0;
    int idx_c = 0;

    int limit_l = (n_line_ver * height) + 1;
    int limit_c = (n_line_hor * length) + 1;

    while (idx_l < limit_l)
    {
        while (idx_c < limit_c)
        {
            if ((0 == (idx_l % n_line_ver)) &&
                (0 == (idx_c % n_line_hor)))
            {
                std::cout << '+';
            }
            else if (0 == (idx_c % n_line_hor))
            {
                std::cout << '|';
            }
            else if (0 == (idx_l % n_line_ver))
            {
                std::cout << '-';
            }
            else
            {
                std::cout << ' ';
            }

            ++idx_c;
        }

        std::cout << '\n';
        ++idx_l;
        idx_c = 0;
    }


    return 0;
}   /* main() */

/*** End of file ***/
