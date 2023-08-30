/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    30/08/2023
 * @brief   Simple program to calculate the parallel resistance.
 */

#include <iostream>
#include <cassert>

/**
 * @brief   Main function
 * @par     Description
 * The program calculates the total parallel resistor, given (almost) any number of values.
 * @return  Always 0 (success).
 */
int
main ()
{
    const int max_n_res(100);
    int n_res(0);
    double tot_res(0);
    double val_res[max_n_res] = {0};

    while (true)
    {
        std::cout << "Insert the number of resistors in parallel: ";
        std::cin >> n_res;

        if (n_res > max_n_res)
        {
            std::cout << "Value too high, max is " << max_n_res << '\n';
        }
        else
        {
            if (n_res <= 0)
            {
                std::cout << "Error in the number inserted. Terminating...\n";
                exit(EXIT_FAILURE);
            }

            int idx(0);
            tot_res = 0;

            while (idx < n_res)
            {
                std::cout << "Resistor #" << idx + 1 << " = ";
                std::cin >> val_res[idx];

                if (val_res[idx] <= 0)
                {
                    std::cout << "Error in the number inserted. Terminating...\n";
                    exit(EXIT_FAILURE);
                }

                tot_res += 1 / val_res[idx];
                ++idx;
            }

            tot_res = 1 / tot_res;

            std::cout << "Parallel resistance is = " << tot_res << '\n';
        }
    }

    return 0;
}   /* main() */

/*** End of file ***/
