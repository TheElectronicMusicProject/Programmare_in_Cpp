/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    09/09/2023
 * @brief   Simple program to detect a fatal error.
 */

#include <iostream>

#define RETURN_STATUS   int
#define RETURN_SUCCESS  (0)
#define RETURN_WARNING  (1)
#define RETURN_ERROR    (2)

#define CHECK_RETURN_FATAL(in_status)       ({                                      \
                                                bool b_ret_macro = false;           \
                                                if (RETURN_ERROR == (in_status))    \
                                                {                                   \
                                                    b_ret_macro = true;             \
                                                }                                   \
                                                b_ret_macro;                        \
                                            })

/**
 * @brief   Main function
 * @par     Description
 * The program tests if RETURN_STATUS generates a fatal error.
 * @return  Always 0 (success).
 */
int
main ()
{
    RETURN_STATUS val = RETURN_SUCCESS;

    for (int idx = 0; idx < 3; ++idx)
    {
        if (true == CHECK_RETURN_FATAL(val))
        {
            std::cout << "FATAL ERROR\n";
        }
        else
        {
            std::cout << "NOT AN ERROR\n";
        }

        ++val;
    }

    return 0;
}   /* main() */

/*** End of file ***/
