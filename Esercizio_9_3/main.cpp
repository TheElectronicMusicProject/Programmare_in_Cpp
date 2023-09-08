/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    08/09/2023
 * @brief   Program to count the number of times a number appears in an array.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

static int count(int number, int array[], int length);

/**
 * @brief   Main function
 * @par     Description
 * The program generates an array with a certain number of elements.
 * Then it calls `count()` to search the number in the array and prints how
 * many times it appears in the array.
 * @return  Always 0 (success).
 */
int
main ()
{
    int in_len(0);
    int in_num(0);

    std::srand(std::time(nullptr));

    std::cout << "Insert the desired number of elements in the array ";
    std::cin >> in_len;
    std::cout << "Insert the number you are searching for [0-10] ";
    std::cin >> in_num;

    assert(in_len > 0);
    assert((in_num >= 0) && (in_num <= 10));

    int in_array[in_len] = {0};

    std::cout << "Printing the generated array:\n";
    for (int idx = 0; idx < in_len; ++idx)
    {
        int rand_val = std::rand();
        rand_val %= 11;
        in_array[idx] = rand_val;
        std::cout << rand_val << '\t';
    }

    std::cout << '\n';

    int n_count = count(in_num, in_array, in_len);

    std::cout << "Found " << n_count << " occurrences!\n";

    return 0;
}   /* main() */

/**
 * @brief   Detect if a string begins another one.
 * @par     Description
 * The function uses a recursive method to count the number of times
 * `number` appears in the given array `array[]`.
 * @param[in]   number  The number that will be searched
 * @param[in]   array   The input array
 * @param[in]   length  The length of the input array
 * @return  The number of times `number` appears in the array
 */
static int
count (int number, int array[], int length)
{
    int n_times(0);
    --length;

    if (length < 0)
    {
        return 0;
    }
    else
    {
        if (number == array[length])
        {
            ++n_times;
        }
    }

    return (n_times + count(number, array, length));
}   /* count() */

/*** End of file ***/
