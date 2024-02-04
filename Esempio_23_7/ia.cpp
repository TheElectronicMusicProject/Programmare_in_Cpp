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
 * It uses a trick: every bucket of the infinite array is an infinite array,
 * hence destroying the next element, the array will destroy alle the next
 * elements of the bucket until it reaches the NULL, making free the array.
 * @return  Always nothing.
 */
infinite_array::~infinite_array ()
{
    if (p_next != NULL)
    {
        delete p_next;
        p_next = NULL;
    }
}   /* infinite_array::~infinite_array() */

/**
 * @brief   Finds an element in an infinite array
 * @param[in]   index   Index of the array.
 * @return  The reference to the element of the array.
 */
int&
infinite_array::operator[] (const uint32_t index)
{
    // Pointer to current bucket.
    //
    class infinite_array * p_current = this;
    uint32_t current_index = index;

    while (current_index >= g_block_size)
    {
        if (NULL == p_current->p_next)
        {
            p_current->p_next = new infinite_array;

            if (NULL == p_current->p_next)
            {
                std::cerr << "Error: out of memory\n";
                exit(8);
            }
        }

        p_current = p_current->p_next;
        current_index -= g_block_size;
    }

    assert(current_index < (sizeof(p_current->data) /
                            sizeof(p_current->data[0])));

    return (p_current->data[current_index]);
}   /* infinite_array::operator[]() */


/*** End of file ***/
