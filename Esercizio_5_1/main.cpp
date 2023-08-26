/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    26/08/2023
 * @brief   Simple program to convert from Celsius to Fahrenheit.
 */

#include <iostream>

/**
 * @brief   Main function
 * @par     Description
 * The program prints the converted value in Fahrenheit.
 * @return  Always 0 (success).
 */
int
main ()
{
    float t_cels = 0.0;
    float t_fahr = 0.0;

    std::cout << "Insert a value in Celsius: ";
    std::cin >> t_cels;

    t_fahr = 9.0 * t_cels / 5.0 + 32.0;

    std::cout << "The converted value is " << t_fahr << " Fahrenheit \n";

    return 0;
}   /* main() */

/*** End of file ***/
