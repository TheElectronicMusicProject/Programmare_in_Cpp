/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    30/01/2024
 * @brief   Add to class check of Esercizio_13_2 the exception when the amount
 *          becomes negative.
 */

#include <iostream>
#include <cassert>
#include <limits>

class check_err
{
    public:
        const std::string what;

        check_err (const std::string& str) : what(str)
        {
            /* Do nothing */
        }
};

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

    try
    {
        cheque_book.add_item(-100);
    }
    catch (const check_err& err)
    {
        std::cerr << err.what << '\n';
        exit(8);
    }
    catch (...)
    {
        std::cerr << "Unknown error\n";
        exit(8);
    }
    

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
    if (amount < 0)
    {
        throw check_err("Cannot accept a negative amount");
    }

    total_amount += amount;
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
