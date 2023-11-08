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
    int answer(0);

    answer = 2 + 2;

    std::printf("The answer is %d\n");
    
    return 0;
}   /* main() */


/*** End of file ***/
