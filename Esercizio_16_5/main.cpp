/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    09/11/2023
 * @brief   The program reads a file converts the tab symbols into spaces.
 */

#include <iostream>
#include <fstream>

/**
 * @brief   Main function
 * @par     Description
 * The program reads a file called file.txt and writes its contents on
 * copy.txt. In the meanwhile, it converts every tab symbol into 8 spaces.
 * @return  Always 0 (success).
 */
int
main ()
{
    std::ifstream in_data("in.txt");
    
    if ((0 != in_data.bad()) || (0 != in_data.fail()))
    {
        std::cerr << "Error: could not open in.txt\n";
        exit(EXIT_FAILURE);
    }

    std::ofstream out_data;
    out_data.open("out.txt", std::ios::out);

    if ((0 != out_data.bad()) || (0 != out_data.fail()))
    {
        std::cerr << "Error: could not open out.txt\n";
        exit(EXIT_FAILURE);
    }

    char temp_char(0);

    while (in_data.get(temp_char))
    {
        if (0 == (0x80 & temp_char))
        {
            out_data << temp_char;
        }
    }

    in_data.close();
    out_data.close();
    
    return 0;
}   /* main() */


/*** End of file ***/
