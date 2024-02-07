/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    07/02/2024
 * @brief   Test of a template function.
 */

#include <iostream>
#include <cstring>

// Template for `max()` function.
//
template<typename kind>
kind
max (kind d1, kind d2)
{
    if (d1 > d2)
    {
        return d1;
    }

    return d2;
}   /* max() */

// Specialization for `max()` function.
//
const char *
max (const char * const d1, const char * const d2)
{
    if (std::strcmp(d1, d2) > 0)
    {
        return d1;
    }

    return d2;
}   /* max() */

int
main ()
{
    std::cout << "max(1, 2) " << max(1, 2) << std::endl;
    std::cout << "max(2, 1) " << max(2, 1) << std::endl;
    std::cout << "max(\"able\", \"baker\") " << max("able", "baker")
              << std::endl;
    std::cout << "max(1.45, -2.654) " << max(1.45, -2.654) << std::endl;
    std::cout << "max(\"baker\", \"able\") " << max("baker", "able")
              << std::endl;
    return (0);
}   /* main() */


/*** End of file ***/
