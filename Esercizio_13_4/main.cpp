/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    17/09/2023
 * @brief   Simple program to manage a FIFO queue.
 */

#include <iostream>
#include <cassert>
#include <limits>

#define SET_SIZE    (100)

class small_set
{
    private:
        int n_items;
        int set_array[SET_SIZE];
    public:
        void set(int item);
        void clear(int item);
        int test(int item);
        small_set();
};

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created class works.
 * @return  Always 0 (success).
 */
int
main ()
{
    small_set my_set;

    my_set.set(3);
    my_set.set(5);
    my_set.set(5);
    my_set.set(8);
    my_set.set(5);

    std::cout << "1) Set test\n";
    std::cout << "Test the 3: " << my_set.test(3) << '\n';
    std::cout << "Test the 5: " << my_set.test(5) << '\n';
    std::cout << "Test the 8: " << my_set.test(8) << '\n';
    std::cout << "Test the 31: " << my_set.test(31) << '\n';

    my_set.clear(5);

    std::cout << "2) Clear 5 test\n";
    std::cout << "Test the 3: " << my_set.test(3) << '\n';
    std::cout << "Test the 5: " << my_set.test(5) << '\n';
    std::cout << "Test the 8: " << my_set.test(8) << '\n';
    std::cout << "Test the 31: " << my_set.test(31) << '\n';

    my_set.clear(3);

    std::cout << "3) Clear 3 test\n";
    std::cout << "Test the 3: " << my_set.test(3) << '\n';
    std::cout << "Test the 5: " << my_set.test(5) << '\n';
    std::cout << "Test the 8: " << my_set.test(8) << '\n';
    std::cout << "Test the 31: " << my_set.test(31) << '\n';

    my_set.clear(6);

    std::cout << "4) Clear 8 test\n";
    std::cout << "Test the 3: " << my_set.test(3) << '\n';
    std::cout << "Test the 5: " << my_set.test(5) << '\n';
    std::cout << "Test the 8: " << my_set.test(8) << '\n';
    std::cout << "Test the 31: " << my_set.test(31) << '\n';

    return 0;
}   /* main() */

/**
 * @brief   Adds an item to list
 * @par     Description
 * The function inserts the given item `item` in the list only if it isn't
 * already present.
 * @attention The `item` must be between 0 and 31, otherwise the number
 * won't be added.
 * @param[in]   item    The value that the user wants to add.
 * @return  Nothing.
 */
inline void
small_set::set (int item)
{
    if ((item < 0) || (item > 31))
    {
        return;
    }

    if (0 == test(item))
    {
        set_array[n_items] = item;
        ++n_items;
    }

    assert(n_items < SET_SIZE);
}   /* small_set::set() */

/**
 * @brief   Returns the first element in the queue
 * @par     Description
 * This function first inserted item in the queue.
 * @return  The first element in the queue.
 */
inline void
small_set::clear (int item)
{
    int idx(0);

    if ((item < 0) || (item > 31))
    {
        return;
    }

    for (idx = 0; idx < n_items; ++idx)
    {
        if (item == set_array[idx])
        {
            for (int val = idx; val < (n_items - 1); ++val)
            {
                set_array[val] = set_array[val + 1];
            }

            break;
        }
    }

    --n_items;
}   /* small_set::clear() */

/**
 * @brief   Searches for the given `item`
 * @par     Description
 * This function returns the first inserted item in the queue.
 * @param[in]   item    The value that must be searched
 * @return  1 if found, 0 otherwise.
 */
inline int
small_set::test (int item)
{
    int ret(0);

    for (int idx = 0; idx < n_items; ++idx)
    {
        if (item == set_array[idx])
        {
            ret = 1;
            break;
        }
    }

    return ret;
}   /* small_set::test() */


/**
 * @brief   Constructor for class `small_set`
 * @par     Description
 * The class variabile `n_items` is initialized to zero.
 * @return  Always nothing.
 */
small_set::small_set ()
{
    n_items = 0;
}   /* small_set::small_set() */


/*** End of file ***/
