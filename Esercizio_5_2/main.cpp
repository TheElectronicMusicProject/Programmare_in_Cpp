/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    26/08/2023
 * @brief   Simple program to calculate the volume of a sphere.
 */

#include <iostream>

/**
 * @brief   Main function
 * @par     Description
 * The program prints the total volume of the sphere, given the radius.
 * @return  Always 0 (success).
 */
int
main ()
{
    const float pi_constant = 3.141;
    float volume = 0.0;     /* V = 4 * pi * r^3 / 3 */
    float radius = 0.0;

    std::cout << "Insert the radius of the sphere [m] ";
    std::cin >> radius;

    volume = pi_constant * 4.0 * (radius * radius * radius) / 3.0;

    std::cout << "The volume is " << volume << " m3 \n";

    return 0;
}   /* main() */

/*** End of file ***/
