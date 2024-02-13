/**
 * @file    ia.cpp
 * @author  Filippo Graziani
 * @date    04/02/2024
 * @brief   Routine to manage an infinite array.
 * An infinite array is an array which increases in a dynamic way. An index is
 * never too big for an infinite array, there is only a limitation in terms of
 * memory.
 */

#include "ia.h"
#include <iostream>
#include <cstdlib>
#include <assert.h>

/**
 * @brief   Destroys the infinite array
 * @return  Always nothing.
 */
infinite_array::~infinite_array ()
{
    data.clear();
}   /* infinite_array::~infinite_array() */

/**
 * @brief   Finds an element in an infinite array
 * @param[in]   index   Index of the array.
 * @return  The reference to the element of the array.
 */
int&
infinite_array::operator[] (const uint32_t index)
{
    uint32_t current_index = index;

    while (current_index >= data.size())
    {
        data.resize(data.size() + 1);
    }

    return data[current_index];
}   /* infinite_array::operator[]() */


/*** End of file ***/
