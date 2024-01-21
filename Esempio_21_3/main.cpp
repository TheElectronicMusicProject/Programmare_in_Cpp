/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    21/01/2024
 * @brief   Mask derived classes - cannot compile.
 */

#include <iostream>

class simple
{
    public:
        int
        do_it (int i, int j)
        {
            return (i * j);
        }   /* do_it() */

        float
        do_it (float f)
        {
            return (f * 2.0);
        }   /* do_it() */
};

class derived: public simple
{
    public:
        int
        do_it (int i, int j)
        {
            return (i + j);
        }   /* do_it() */
};

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created derived class works.
 * @return  Always 0 (success).
 */
int
main ()
{
    class derived test;
    int var1(0);
    float var2(0.0);

    var1 = test.do_it(1, 3); // It's legal.
    std::cout << "var1 = " << var1 << std::endl;

    // It's not legal. C++ searches for all `do_it()` functions in the derived
    // class with one floating point input.
    //
    var2 = test.do_it(4.0);
    std::cout << "var2 = " << var2 << std::endl;

    return 0;
}   /* main() */


/*** End of file ***/
