/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    05/02/2024
 * @brief   Routine serch and open a file.
 * Write a module called `search_open` which receives an array of file names,
 * searches the file and opens it.
 */

#include "search_open.h"
#include <iostream>
#include <fstream>

int
main (int argc, char * argv[])
{
    std::ifstream h_in_file;
    file_open_t my_file;
    std::string temp_str;

    if (2 != argc)
    {
        std::cerr << "Error: wrong number of arguments\n";
        std::cerr << "Usage is\n";
        std::cerr << "\tmain <data-file>\n";
        exit(8);
    }

    h_in_file.open(argv[1], std::ios::binary);

    if (h_in_file.bad() || h_in_file.fail())
    {
        std::cerr << "Error: cannot open file " << argv[1] << std::endl;
        exit(8);
    }

    while (h_in_file >> temp_str)
    {
        my_file.add_list(temp_str);
    }

    std::string find_str = "hello.txt";

    if (1 == my_file.search_open(find_str))
    {
        std::ifstream h_new_file(find_str, std::ios::binary);

        if (h_new_file.bad() || h_new_file.fail())
        {
            std::cerr << "Error: cannot open file " << find_str << std::endl;
            exit(8);
        }
        else
        {
            std::cout << "File found!\n";
        }
    }
    else
    {
        std::cout << "File NOT found!\n";
    }

    return (0);
}   /* main() */


/*** End of file ***/
