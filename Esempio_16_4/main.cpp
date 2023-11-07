/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    07/11/2023
 * @brief   Program to test that Unix trets binary and ASCII files in the same
 *          way.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>

/**
 * @brief   Main function
 * @par     Description
 * Program to test the put() funtcion when opening a ASCII file.
 * @return  Always 0 (success).
 */
int
main ()
{
    int cur_char(0);
    std::ofstream h_out_file;

    h_out_file.open("test.out", std::ios::out);

    if (h_out_file.bad())
    {
        std::cerr << "Cannot open output file\n";
        exit(EXIT_FAILURE);
    }

    for (cur_char = 0; cur_char < 128; ++cur_char)
    {
        h_out_file.put(cur_char);
    }
    
    return 0;
}   /* main() */


/*** End of file ***/
