/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    09/09/2023
 * @brief   Simple program to detect if a number is divisible by 10.
 */

#include <iostream>

#define CHECK_DIVISION_10(in_val)   ({                                                      \
                                        bool b_ret_macro = false;                           \
                                        b_ret_macro = (0 == (in_val) % 10 ? true : false);  \
                                    })

/**
 * @brief   Main function
 * @par     Description
 * The program tests if a number between 0 and 49 is divisible by 10.
 * @return  Always 0 (success).
 */
int
main ()
{
    for (int idx = 0; idx < 50; ++idx)
    {
        if (true == CHECK_DIVISION_10(idx))
        {
            std::cout << idx << " is divisible by 10\n";
        }
        else
        {
            std::cout << idx << " is NOT divisible by 10\n";
        }
    }

    return 0;
}   /* main() */

/*** End of file ***/
