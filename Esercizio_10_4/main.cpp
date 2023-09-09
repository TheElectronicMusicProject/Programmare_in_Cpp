/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    09/09/2023
 * @brief   Simple program to invert the value of two variables.
 */

#include <iostream>

#define INVERT_INT(in_val1, in_val2)    {                       \
                                            in_val1 ^= in_val2; \
                                            in_val2 ^= in_val1; \
                                            in_val1 ^= in_val2; \
                                        }

/**
 * @brief   Main function
 * @par     Description
 * The program tests if two integres have their values inverted after calling
 * the macro INVERT_INT. The macro doesn't use any temporary variable.
 * @return  Always 0 (success).
 */
int
main ()
{
    int test1(-12);
    int test2(40);

    std::cout << "test1 = " << test1 << " test2 = " << test2 << '\n';

    INVERT_INT(test1, test2);

    std::cout << "test1 = " << test1 << " test2 = " << test2 << '\n';

    return 0;
}   /* main() */

/*** End of file ***/
