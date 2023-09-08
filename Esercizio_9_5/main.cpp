/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    08/09/2023
 * @brief   Program to search the maximum number in an array.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

static void max_num(int& max, int array[], int length);

/**
 * @brief   Main function
 * @par     Description
 * The program generates an array with a certain number of elements.
 * Then it calls `max_num()` to search the maximum number in the array and
 * prints it.
 * @return  Always 0 (success).
 */
int
main ()
{
    int in_len(0);
    int num_max(0);

    std::srand(std::time(nullptr));

    std::cout << "Insert the desired number of elements in the array ";
    std::cin >> in_len;

    assert(in_len > 0);

    int in_array[in_len] = {0};

    std::cout << "Printing the generated array:\n";
    for (int idx = 0; idx < in_len; ++idx)
    {
        in_array[idx] = std::rand();
        std::cout << in_array[idx] << '\t';
    }

    std::cout << '\n';

    max_num(num_max, in_array, in_len);

    std::cout << "Max number is " << num_max << '\n';

    return 0;
}   /* main() */

/**
 * @brief   Detects the maximum number in an array.
 * @par     Description
 * The function searches the maximum number that appears in the given array
 * `array[]`.
 * @param[out]  max     The maximum number in the array
 * @param[in]   array   The input array
 * @param[in]   length  The length of the input array
 * @return  Nothing.
 */
static void
max_num (int& max, int array[], int length)
{
    max = array[0];

    for (int idx = 1; idx < length; ++idx)
    {
        if (array[idx] > max)
        {
            max = array[idx];
        }
    }
}   /* max_num() */

/*** End of file ***/
