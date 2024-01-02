/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    02/01/2024
 * @brief   Class of fixed point numbers with the format DDDDD,D where there is
 *          only one numbers after the decimal point.
 *          This exercise is a modification of the `Esempio_18_2`.
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
    std::cout << "Expect 1.2 " << fixed_pt::fixed_pt(1.23) << std::endl;
    std::cout << "Expect 1.0 " << fixed_pt::fixed_pt(1.00) << std::endl;
    std::cout << "Expect 1.0 " << fixed_pt::fixed_pt(1.02) << std::endl;
    std::cout << "Expect 1.2 " << fixed_pt::fixed_pt(1.20) << std::endl;

    fixed_pt::fixed_pt f1(1.23 + 0.05);
    fixed_pt::fixed_pt f2(4.56 + 0.05);

    std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl;
    std::cout << f1 << " - " << f2 << " = " << f1 - f2 << std::endl;
    std::cout << f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
    std::cout << f1 << " / " << f2 << " = " << f1 / f2 << std::endl;
    
    return (0);
}   /* main() */


/*** End of file ***/
