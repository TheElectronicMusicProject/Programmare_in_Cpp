/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    07/11/2023
 * @brief   Read 100 numbers and sums them.
 */

#include <iostream>
#include <cassert>
#include <fstream>
#include <cstdlib>

/**
 * @brief   Main function
 * @par     Description
 * The numbers must be inside the file "numbers.dat".
 * @warning Files with less than 100 characters won't be checked.
 * @return  Always 0 (success).
 */
int
main ()
{
    const int data_size(100);
    int data_array[data_size]{0};
    std::ifstream h_data_file("numbers.dat");
    long unsigned int idx(0);

    if (true == h_data_file.fail())
    {
        std::cerr << "Error: could not open numbers.dat\n";
        exit(EXIT_FAILURE);
    }

    for (idx = 0; idx < data_size; ++idx)
    {
        assert(idx >= 0);
        assert(idx < (sizeof(data_array) / sizeof(data_array[0])));

        // Write from file to array.
        //
        h_data_file >> data_array[idx];
    }

    int total(0);

    for (idx = 0; idx < data_size; ++idx)
    {
        assert(idx >= 0);
        assert(idx < (sizeof(data_array) / sizeof(data_array[0])));

        total += data_array[idx];
    }

    std::cout << "Total of all the numbers is " << total << '\n';
    
    return 0;
}   /* main() */


/*** End of file ***/
