/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    11/11/2023
 * @brief   The program reads a file containing a vector of numbers and sums
 *          its contents.
 */

#include <iostream>
#include <fstream>
#include <chrono>

static inline long int sum_elem(const long int * const p_array,
                                unsigned int size);

/**
 * @brief   Main function
 * @par     Description
 * The program opens a file for scanning its elements, copies them in an array,
 * calls a function to sum them (calculating the elapsed time) and write some
 * data in an output file.
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

    unsigned int n_elems(0);
    long int temp(0);

    while (h_in_file >> temp)
    {
        ++n_elems;
    }

    // Clears EOF flag (it's a failing state), and request a seek to the
    // beginning of the file.
    //
    h_in_file.clear();
    h_in_file.seekg(0, std::ios::beg);

    long int array[n_elems]{0};
    unsigned int idx(0);

    while (h_in_file >> temp)
    {
        *(array + idx) = temp;
        ++idx;
    }

    std::cout << "There are " << n_elems << " elements" << '\n';

    // I could write auto instead of std::chrono::system_clock::time_point.
    //
    const std::chrono::steady_clock::time_point time_start =
                                            std::chrono::steady_clock::now();
    
    long int sum = sum_elem(array, n_elems);

    const std::chrono::steady_clock::time_point time_end =
                                            std::chrono::steady_clock::now();


    std::ofstream h_out_file;
    h_out_file.open("output.txt", std::ios::out);

    if (true == h_out_file.fail())
    {
        std::cerr << "Impossible to open output.txt\n";
        exit(EXIT_FAILURE);
    }

    h_out_file << "There are: " << n_elems << " elements and their sum is "
               << sum << std::endl;

    h_in_file.close();
    h_out_file.close();

    // Print the required execution time.
    //
    const std::chrono::duration<double> elapsed_seconds{time_end - time_start};
    std::cout << "Time required: " << elapsed_seconds.count() << " seconds\n";
    
    return 0;
}   /* main() */

/**
 * @brief       Optimized function to sum the elements of an array.
 * @param[in]   p_array Pointer to the first element of the array.
 * @param[in]   size    Size of the array (its number of elements).
 * @return      The sum of all the elements.
 */
static inline long int
sum_elem (const long int * p_array,
          unsigned int size)
{
    unsigned int idx(0);
    long int sum(0);

    for (idx = 0; idx < size; ++idx)
    {
        sum += *(p_array + idx);
    }

    return sum;
}   /* sum_elem() */


/*** End of file ***/
