/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    12/09/2023
 * @brief   Program to draw a 10x10 bitmap sqaure.
 */

#include <iostream>
#include <assert.h>

#define SQUARE_SIZE     (10)

static inline void set_bit(const int x_coord, const int y_coord);
static inline void clear_bit(const int x_coord, const int y_coord);
static inline bool test_bit(const int x_coord, const int y_coord);
static void print_graphics();

const int g_x_size(40);
const int g_y_size(60);

char g_graphics[g_x_size / 8][g_y_size] = {0};

/**
 * @brief   Main function
 * @par     Description
 * The program creates a 10x10 square bitmap image.
 * @return  Always 0 (success).
 */
int
main ()
{
    for (int loc_x = 0; loc_x < g_x_size; ++loc_x)
    {
        for (int loc_y = 0; loc_y < g_y_size; ++loc_y)
        {
            if (((0 == loc_x) && (SQUARE_SIZE > loc_y)) ||
                ((0 == loc_y) && (SQUARE_SIZE > loc_x)) ||
                (((SQUARE_SIZE - 1) == loc_y) && (SQUARE_SIZE > loc_x)) ||
                (((SQUARE_SIZE - 1) == loc_x) && (SQUARE_SIZE > loc_y)))
            {
                set_bit(loc_x, loc_y);
            }
        }
    }

    print_graphics();

    return 0;
}   /* main() */

/**
 * @brief   Set a bit in the global array
 * @par     Description
 * The function identify the selected point in the global array `g_graphics`
 * and sets the corresponding coordinate.
 * @param[in]   x_coord     The X coordinate.
 * @param[in]   y_coord     The Y coordinate.
 * @return  Nothing.
 */
static inline void
set_bit (const int x_coord, const int y_coord)
{
    assert((x_coord >= 0) && (x_coord < g_x_size));
    assert((y_coord >= 0) && (y_coord < g_y_size));

    g_graphics[x_coord / 8][y_coord] |=
                            static_cast<char>(0x80 >> (x_coord % 8));
}   /* set_bit() */

/**
 * @brief   Clear a bit in the global array
 * @par     Description
 * The function identify the selected point in the global array `g_graphics`
 * and clears the corresponding coordinate.
 * @param[in]   x_coord     The X coordinate.
 * @param[in]   y_coord     The Y coordinate.
 * @return  Nothing.
 */
static inline void
clear_bit (const int x_coord, const int y_coord)
{
    assert((x_coord >= 0) && (x_coord < g_x_size));
    assert((y_coord >= 0) && (y_coord < g_y_size));

    g_graphics[x_coord / 8][y_coord] &=
                            ~static_cast<char>(0x80 >> (x_coord % 8));
}   /* clear_bit() */

/**
 * @brief   Test a bit in the global array
 * @par     Description
 * The function identify the selected point in the global array `g_graphics`
 * and tests the bit status in the corresponding coordinate.
 * @param[in]   x_coord     The X coordinate.
 * @param[in]   y_coord     The Y coordinate.
 * @return  True if the bit is 1, false otherwise.
 */
static inline bool
test_bit (const int x_coord, const int y_coord)
{
    bool b_is_set = false;

    assert((x_coord >= 0) && (x_coord < g_x_size));
    assert((y_coord >= 0) && (y_coord < g_y_size));

    if (0x80 == ((g_graphics[x_coord / 8][y_coord] << (x_coord % 8)) & 0x80))
    {
        b_is_set = true;
    }

    return b_is_set;
}   /* test_bit() */

/**
 * @brief   Prints the bitmap graphics
 * @par     Description
 * The function scans all the bits in all the coordinates.
 * Then it prints a `X` if it is a bit 1, a `.` if it's a 0.
 * @return  Nothing.
 */
static void
print_graphics ()
{
    int x_coord(0);
    int y_coord(0);
    int bit(0);

    for (y_coord = 0; y_coord < g_y_size; ++y_coord)
    {
        for (x_coord = 0; x_coord < g_x_size / 8; ++x_coord)
        {
            for (bit = 0x80; bit > 0; bit >>= 1)
            {
                assert((x_coord >= 0) && (x_coord < (g_x_size / 8)));
                assert((y_coord >= 0) && (y_coord < g_y_size));

                if (0 != (g_graphics[x_coord][y_coord] & bit))
                {
                    std::cout << 'X';
                }
                else
                {
                    std::cout << '.';
                }
            }
        }

        std::cout << '\n';
    }
}   /* print_graphics() */

/*** End of file ***/
