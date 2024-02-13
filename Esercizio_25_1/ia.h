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
#include <vector>

#ifndef IA_H
#   define IA_H

class infinite_array
{
    private:
        // Data of this block.
        //
        std::vector<int32_t> data;
    public:
        // Predefined constructor
        //
        infinite_array ()
        {
            if (0 == data.size())
            {
                data.resize(1);
            }
            
            data[0] = 0;
        }   /* infinite_array() */

        // Predefined destructor
        //
        ~infinite_array();

        // Returns the reference to an element of the array.
        //
        int& operator[](const uint32_t index);
};
#endif /* IA_H */


/*** End of file ***/
