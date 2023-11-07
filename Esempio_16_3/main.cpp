/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    07/11/2023
 * @brief   Write on file.
 */

#include <iostream>
#include <iomanip>

/**
 * @brief   Main function
 * @par     Description
 * Program to test log_message().
 * @return  Always 0 (success).
 */
int
main ()
{
    int number(12);
    float real(12.34);

    std::cout << "123456789012345678901234567890\n";
    std::cout << number << "<-\n";
    std::cout << std::setw(5) << number << "<-\n";
    std::cout << std::setw(5) << std::setfill('*') << number << "<-\n";
    std::cout << std::setiosflags(std::ios::showpos | std::ios::left) <<
                 std::setw(5) << number << "<-\n";

    std::resetiosflags(std::ios::showpos | std::ios::left);

    std::cout << real << "<-\n";
    std::cout << std::setprecision(1) << std::setiosflags(std::ios::fixed) <<
                 std::resetiosflags(std::ios::showpos | std::ios::left) <<
                 real << "<-\n";
    std::cout << std::setiosflags(std::ios::scientific) <<
                 std::resetiosflags(std::ios::fixed) << real << "<-\n";
    
    return 0;
}   /* main() */


/*** End of file ***/
