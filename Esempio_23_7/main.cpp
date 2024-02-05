/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    04/02/2024
 * @brief   Generates an histogram of an array of numbers.
 *      `main <file>`
 *      where file is the name of the used file.
 */

#include "ia.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <assert.h>

// Number of lines in the result.
//
static const int32_t g_number_of_lines(50);

// Lower number.
//
static const int32_t g_low_bound(0);

// Upper number.
//
static const int32_t g_high_bound(99);

// Step between two near points in the histogram.
//
static const int32_t g_factor((g_high_bound - g_low_bound + 1) /
                              g_number_of_lines);

// Size of histogram, in characters.
//
static const int32_t g_width(60);

// Array to store data.
//
static infinite_array g_data_array;

// Number of elements in the array.
//
static int32_t g_data_items(0);

/**
 * @brief   Reads data from the input file, writing into `g_data_array`.
 * @param[in]   p_name  Name of the file to be read.
 * @return  Nothing.
 */
static void read_data(const char * const p_name);

/**
 * @brief   Prints the output of the histogram.
 * @return  Nothing.
 */
static void print_histogram();

int
main (int argc, char * argv[])
{
    if (2 != argc)
    {
        std::cerr << "Error: wrong number of arguments\n";
        std::cerr << "Usage is\n";
        std::cerr << "\tmain <data-file>\n";
        exit(8);
    }

    read_data(argv[1]);
    print_histogram();

    return (0);
}   /* main() */

static void
read_data (const char * const p_name)
{
    std::ifstream h_in_file(p_name);
    int32_t data(0);

    if (h_in_file.bad() || h_in_file.fail())
    {
        std::cerr << "Error: unable to open " << p_name << std::endl;
        exit(8);
    }

    while (!h_in_file.eof())
    {
        h_in_file >> data;

        // If it receives EOF then the data is worn out in the last read.
        //
        if (h_in_file.eof())
        {
            break;
        }

        g_data_array[g_data_items] = data;
        ++g_data_items;
    }
}   /* read_data() */

static
void print_histogram ()
{
    // Upper limit to print.
    //
    int32_t counters[g_number_of_lines]{0};

    // Lower limit to print.
    //
    int32_t low(0);

    // Number of elements out of the limits.
    //
    int32_t out_of_range(0);

    // Greater counter.
    //
    int32_t max_count(0);

    // Scale factor to print points.
    //
    float scale(0.0);

    // Index of data.
    //
    int32_t index(0);

    memset(counters, '\0', sizeof(counters));

    for (index = 0; index < g_data_items; ++index)
    {
        int32_t data(g_data_array[index]);

        if ((data < g_low_bound) || (data > g_high_bound))
        {
            ++out_of_range;
        }
        else
        {
            // Normalization to fit the `data` into an array.
            //
            int32_t count_index = static_cast<int32_t>(
                            static_cast<float>(data - g_low_bound) / g_factor);

            assert(count_index >= 0);
            assert(count_index < (sizeof(counters) / sizeof(counters[0])));
            ++counters[count_index];

            if (counters[count_index] > max_count)
            {
                max_count = counters[count_index];
            }
        }
    }

    scale = float(max_count) / float(g_width);
    low = g_low_bound;

    for (index = 0; index < g_number_of_lines; ++index)
    {
        int32_t char_index(0);
        int32_t number_of_dots(0);

        std::cout << std::setw(2) << index << " "
                  << std::setw(3) << low << "-"
                  << std::setw(3) << (low + g_factor) << " ("
                  << std::setw(4) << counters[index] << "): ";

        number_of_dots = int(float(counters[index]) / scale);

        for (char_index = 0; char_index < number_of_dots; ++char_index)
        {
            std::cout << "*";
        }

        std::cout << "\n";
        low += g_factor;
    }

    std::cout << out_of_range << " items out of range\n";
}   /* print_histogram() */


/*** End of file ***/
