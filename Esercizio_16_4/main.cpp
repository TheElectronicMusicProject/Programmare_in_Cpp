/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    10/11/2023
 * @brief   The program reads a file reads ASCII and writes binary.
 */

#include <iostream>
#include <fstream>

/**
 * @brief   Main function
 * @par     Description
 * The program reads an ASCII file and writes its contents in a binary file.
 * @return  Always 0 (success).
 */
int
main ()
{
    std::string in_file_name = "";
    std::cout << "Enter input file name: ";
    std::getline(std::cin, in_file_name, '\n');

    std::ifstream in_data(in_file_name);
    
    if ((0 != in_data.bad()) || (0 != in_data.fail()))
    {
        std::cerr << "Error: could not open " << in_file_name << '\n';
        exit(EXIT_FAILURE);
    }

    std::string out_file_name = "";
    std::cout << "Enter output file name: ";
    std::getline(std::cin, out_file_name, '\n');
    std::ofstream out_data;
    out_data.open(out_file_name, std::ios::out | std::ios::binary);

    if ((0 != out_data.bad()) || (0 != out_data.fail()))
    {
        std::cerr << "Error: could not open" << out_file_name << '\n';
        exit(EXIT_FAILURE);
    }

    char temp(0);

    while (in_data.get(temp))
    {
        out_data << temp;
    }

    // Not mandatory.
    //
    in_data.close();
    out_data.close();
    
    return 0;
}   /* main() */


/*** End of file ***/
