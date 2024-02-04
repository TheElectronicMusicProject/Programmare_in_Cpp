/**
 * @file    ia.h
 * @author  Filippo Graziani
 * @date    04/02/2024
 * @brief   Definitions of the class of the infinite array.
 * An infinite array is an array which has a dimension that could increase in a
 * dynamic fashion. Adding more elements makes larger its dimension.
 */

#include <stdint.h>
#include <string.h>

#ifndef IA_H
#   define IA_H
const uint32_t  g_block_size(10);

class infinite_array
{
    private:
        // Data of this block.
        //
        int32_t data[g_block_size];

        // Pointer to the next array.
        //
        class infinite_array * p_next;
    public:
        // Predefined constructor
        //
        infinite_array ()
        {
            p_next = NULL;
            memset(data, '\0', sizeof(data));
        }

            // Predefined destructor
            //
            ~infinite_array();

            // Returns the reference to an element of the array.
            //
            int& operator[](const uint32_t index);
};
#endif /* IA_H */


/*** End of file ***/
