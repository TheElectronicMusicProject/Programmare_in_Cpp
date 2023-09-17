/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    17/09/2023
 * @brief   Simple program to manage a cheque book.
 */

#include <iostream>
#include <cassert>
#include <limits>

class check
{
    private:
        int total_amount;
    public:
        void add_item(int amount);
        int total();
        check();
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
    check cheque_book;

    for (int idx = 1; idx < 10; ++idx)
    {
        cheque_book.add_item(idx * 100);
    }

    std::cout << "Should return 4500: " << cheque_book.total() << '\n';

    return 0;
}   /* main() */

/**
 * @brief   Adds a value to `total_amount`
 * @par     Description
 * The function increments the class variable `total_amount` with the given
 * value `amount`.
 * @param[in]   amount  The amount that the user wants to add to the total.
 * @return  Nothing.
 */
inline void
check::add_item (int amount)
{
    assert(amount >= 0);
    total_amount += amount;
    assert(amount <= INT32_MAX);
}   /* check::add_item() */

/**
 * @brief   Returns the total amount
 * @par     Description
 * This function returns the value inside `total_amount`.
 * @return  The total value.
 */
inline int
check::total ()
{
    return (total_amount); 
}   /* check::total() */

/**
 * @brief   Constructor for class `check`
 * @par     Description
 * The class variabile `total_amount` is initialized to zero.
 * @return  Always nothing.
 */
check::check ()
{
    total_amount = 0;
}   /* check::check() */


/*** End of file ***/
