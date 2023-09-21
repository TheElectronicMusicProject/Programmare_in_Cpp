/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    21/09/2023
 * @brief   Simple program to initialize an array with the specified input
 *          value.
 */

#include <iostream>
#include <stddef.h>

#define SIZE    (10)

static bool fill_array(int * const p_in_arr, int size, int num_fill);

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the array can be correctly initialized.
 * @return  0 in case of success of the array initialization, 1 otherwise.
 */
int
main ()
{
    int array[SIZE] = {
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10
    };

    for (int index = 0; index < SIZE; ++index)
    {
        std::cout << "Element #" << index << " is " << *(array + index)
                  << '\n';
    }

    std::cout << '\n';

    if (true == fill_array(array, sizeof(array) / sizeof(array[0]), 0))
    {
        for (int index = 0; index < SIZE; ++index)
        {
            std::cout << "Element #" << index << " is " << *(array + index)
                      << '\n';
        }
    }
    else
    {
        return 1;
    }
    
    return 0;
}   /* main() */

/**
 * @brief   Initialize the array elements
 * @par     Description
 * This functions returns the input array `p_in_arr` filled with `num_fill`
 * for the specified size `size`.
 * @param[in,out]   p_in_arr    The array to be filled.
 * @param[in]       size        Size of the array.
 * @param[in]       num_fill    The filling value.
 * @return  true if the array has been correctly filled, false in case of
 *          errors.
 */
static bool
fill_array (int * const p_in_arr, int size, int num_fill)
{
    if ((NULL == p_in_arr) || (size <= 0))
    {
        return false;
    }

    for (int idx = 0; idx < size; ++idx)
    {
        *(p_in_arr + idx) = num_fill;
    }

    return true;
}   /* fill_array() */


/*** End of file ***/
