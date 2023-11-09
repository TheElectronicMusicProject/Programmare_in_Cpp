/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    09/11/2023
 * @brief   The program reads a file and counts the number of lines.
 */

#include <iostream>
#include <fstream>
#include <string>

#define ARRAY_SIZE  100

/**
 * @brief   Main function
 * @par     Description
 * The program asks for the name of a file.
 * Then the file is scanned an the number of lines is returned.
 * @return  Always 0 (success).
 */
int
main ()
{
    std::string file_name = "";
    std::cout << "Insert the name of the file: ";
    std::getline(std::cin, file_name);

    std::ifstream in_data(file_name);
    std::string file_line = "";
    
    if ((0 != in_data.bad()) || (0 != in_data.fail()))
    {
        std::cerr << "Error: could not open " << file_name << '\n';
    }

    unsigned int cnt_row(0);

    while (std::getline(in_data, file_line, '\n'))
    {
        ++cnt_row;
    }

    std::cout << "Number of lines is: " << cnt_row << '\n';

    in_data.close();
    
    return 0;
}   /* main() */


/*** End of file ***/
