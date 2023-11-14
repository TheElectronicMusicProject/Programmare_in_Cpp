/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    13/11/2023
 * @brief   Test for the class fixed_pt.
 */

#include <iostream>
#include "fixed_pt.h"

/**
 * @brief   Main function
 * @par     Description
 * Test for the class fixed_pt, printing its values.
 * @return  Always 0 (success).
 */
int
main ()
{
    std::cout << "Expect 1.23 " << fixed_pt::fixed_pt(1.23) << std::endl;
    std::cout << "Expect 1.00 " << fixed_pt::fixed_pt(1.00) << std::endl;
    std::cout << "Expect 1.02 " << fixed_pt::fixed_pt(1.02) << std::endl;
    std::cout << "Expect 1.20 " << fixed_pt::fixed_pt(1.20) << std::endl;

    fixed_pt::fixed_pt f1(1.23 + 0.005);
    fixed_pt::fixed_pt f2(4.56 + 0.005);

    std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl;
    std::cout << f1 << " - " << f2 << " = " << f1 - f2 << std::endl;
    std::cout << f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
    std::cout << f1 << " / " << f2 << " = " << f1 / f2 << std::endl;
    
    return (0);
}   /* main() */


/*** End of file ***/
