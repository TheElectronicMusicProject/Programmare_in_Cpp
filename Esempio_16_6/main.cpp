/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    08/11/2023
 * @brief   Count the character in a file.
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

const char g_file_name[] = "input.txt";

/**
 * @brief   Main function
 * @par     Description
 * A text file named "input.txt" must exist.
 * The number of characters will be read.
 * @return  Always 0 (success).
 */
int
main ()
{
    int count(0);
    std::FILE * p_in_file(NULL);
    int chr(0);

    p_in_file = std::fopen(g_file_name, "rb");

    if (NULL == p_in_file)
    {
        std::cerr << "Can not open " << g_file_name << '\n';
        exit(EXIT_FAILURE);
    }

    while (true)
    {
        chr = std::fgetc(p_in_file);

        if (EOF == chr)
        {
            break;
        }

        ++count;
    }

    std::cout << "Number of characters in " << g_file_name << " is "
              << count << '\n';

    std::fclose(p_in_file);
    
    return 0;
}   /* main() */


/*** End of file ***/
