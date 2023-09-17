/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    16/09/2023
 * @brief   Simple program to test my first class.
 */

#include <iostream>
#include <cassert>
#include <limits>

class parity
{
    private:
        unsigned int n_calls;
    public:
        void put();
        bool test();
        parity();
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
    parity parity_user;

    for (int idx = 0; idx < 10; ++idx)
    {
        if (true == parity_user.test())
        {
            std::cout << "Parity is even\n";
        }
        else
        {
            std::cout << "Parity is odd\n";
        }

        parity_user.put();
    }

    return 0;
}   /* main() */

/**
 * @brief   Increments the class variable `n_calls`
 * @par     Description
 * The function increments the variable `n_calls` testing if it hits the
 * maximum number of an unsigned integer.
 * @return  Nothing.
 */
inline void
parity::put ()
{
    ++n_calls;
    assert(n_calls <= UINT32_MAX);
}   /* parity::put() */

/**
 * @brief   Test the parity of the calls of the function `put()`
 * @par     Description
 * Tests if the number of the calls of the class function `put()` is even or
 * odd.
 * @return  true if the number of calls is even, false if it's odd.
 */
inline bool
parity::test ()
{
    return (0 == (n_calls % 2) ? true : false); 
}   /* parity::test() */

/**
 * @brief   Constructor for class `parity`
 * @par     Description
 * The class variabile `n_calls` is initialized to zero.
 * @return  Always nothing.
 */
parity::parity ()
{
    n_calls = 0;
}   /* parity::parity() */


/*** End of file ***/
