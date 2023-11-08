/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    08/11/2023
 * @brief   An error while printing.
 */

#include <cstdio>

/**
 * @brief   Main function
 * @par     Description
 * A test for an error in printf().
 * @return  Always 0 (success).
 */
int
main ()
{
    float result(0);

    result = 21.0 / 7.0;

    std::printf("The answer is %d\n", result);
    
    return 0;
}   /* main() */


/*** End of file ***/
