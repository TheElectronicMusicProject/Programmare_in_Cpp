/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    09/11/2023
 * @brief   The program reads a file converts the tab symbols into spaces.
 */

#include <iostream>
#include <fstream>
#include <string>

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
    std::ifstream in_data("numbers.txt");
    
    if ((0 != in_data.bad()) || (0 != in_data.fail()))
    {
        std::cerr << "Error: could not open numbers.txt\n";
        exit(EXIT_FAILURE);
    }

    std::ofstream out_data_1("div3.txt", std::ios::out);

    if ((0 != out_data_1.bad()) || (0 != out_data_1.fail()))
    {
        std::cerr << "Error: could not open div3.txt\n";
        exit(EXIT_FAILURE);
    }

    std::ofstream out_data_2("no_div3.txt", std::ios::out);

    if ((0 != out_data_2.bad()) || (0 != out_data_2.fail()))
    {
        std::cerr << "Error: could not open no_div3.txt\n";
        exit(EXIT_FAILURE);
    }

    int temp(0);

    while (in_data >> temp)
    {
        if (0 == (temp % 3))
        {
            out_data_1 << temp << '\n';
        }
        else
        {
            out_data_2 << temp << '\n';
        }
    }

    in_data.close();
    out_data_1.close();
    out_data_2.close();
    
    return 0;
}   /* main() */


/*** End of file ***/
