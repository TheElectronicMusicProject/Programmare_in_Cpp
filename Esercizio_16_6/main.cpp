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
    std::ifstream h_in_file;
    h_in_file.open("input.txt");

    if (true == h_in_file.fail())
    {
        std::cerr << "Impossible to open input.txt\n";
        exit(EXIT_FAILURE);
    }

    std::string read_val;
    std::string start = "Configuration file V";
    bool b_file_is_ok(false);

    // Description
    //
    std::getline(h_in_file, read_val, '\n');

    if ('1' == read_val.at(start.length()))
    {
        if ('.' == read_val.at(start.length() + 1))
        {
            if ('0' == read_val.at(start.length() + 2))
            {
                b_file_is_ok = true;
            }
        }
    }

    if (true == b_file_is_ok)
    {
        // Name
        //
        std::getline(h_in_file, read_val, ' ');
        std::cout << "Name is " << read_val << std::endl;
        std::getline(h_in_file, read_val, '\n');

        // Surname
        //
        std::getline(h_in_file, read_val, ' ');
        std::cout << "Surname is " << read_val << std::endl;
        std::getline(h_in_file, read_val, '\n');

        // Address
        //
        std::getline(h_in_file, read_val, ' ');
        std::cout << "Address is " << read_val << std::endl;
        std::getline(h_in_file, read_val, '\n');

        // Number
        //
        std::getline(h_in_file, read_val, ' ');
        std::cout << "Number is " << read_val << std::endl;
        std::getline(h_in_file, read_val, '\n');

        // City
        //
        std::getline(h_in_file, read_val, ' ');
        std::cout << "City is " << read_val << std::endl;
        std::getline(h_in_file, read_val, '\n');

        // Province
        //
        std::getline(h_in_file, read_val, ' ');
        std::cout << "Province is " << read_val << std::endl;
        std::getline(h_in_file, read_val, '\n');

        // State
        //
        std::getline(h_in_file, read_val, ' ');
        std::cout << "State is " << read_val << std::endl;
    }
    else
    {
        std::cerr << "Non compatible version\n";
    }

    h_in_file.close();
    
    return 0;
}   /* main() */


/*** End of file ***/
