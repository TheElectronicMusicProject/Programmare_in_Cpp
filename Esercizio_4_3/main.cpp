/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    23/08/2023
 * @brief   Simple program to calculate the area and perimeter of a rectangle.
 */

#include <iostream>

/**
 * @brief   Main function
 * @par     Description
 * The program prints the area and perimeter of the considered rectangle.
 * @return  Always 0 (success).
 */
int
main ()
{
    const float length = 7.0;
    const float height = 12.0;

    std::cout << "Area is " << length * height << "\n";
    std::cout << "Perimeter is " << 2 * (length + height) << "\n";

    return 0;
}   /* main() */

/*** End of file ***/