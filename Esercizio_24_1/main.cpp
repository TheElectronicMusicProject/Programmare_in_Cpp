/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    08/02/2024
 * @brief   Create a template `min` to return the minimum value of two values.
 *          Style C strings must be correctly managed.
 */

#include <iostream>
#include <cstring>
#include <limits>

/**
 * @brief   Returns the minimum value between the input numbers.
 * @tparam  kind    The type of the input number.
 * @param[in]   val1    First number.
 * @param[in]   val2    Second number.
 * @return  The smaller between `val1` and `val2`. 
 */
template<typename kind>
kind
min (kind val1, kind val2)
{
    return (val1 < val2 ? val1 : val2);
}   /* min() */

/**
 * @brief   Returns the minimum "value" between the input strings.
 * @param[in]   p_str1  First string.
 * @param[in]   p_str2  Second string.
 * @return  The smaller between `p_str1` and `p_str2`.
 * @note    This is a template specialization function.
 */
const char *
min (const char * const p_str1, const char * const p_str2)
{
    return (std::strcmp(p_str1 , p_str2) < 0 ? p_str1 : p_str2);
}   /* min() */

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created template works.
 * @return  Always 0 (success).
 */
int
main ()
{
    std::cout << "min(1, 2) " << min(1, 2) << std::endl;
    std::cout << "min(2, 1) " << min(2, 1) << std::endl;
    std::cout << "min(\"able\", \"baker\") " << min("able", "baker")
              << std::endl;
    std::cout << "min(1.45, -2.654) " << min(1.45, -2.654) << std::endl;
    std::cout << "min(\"baker\", \"able\") " << min("baker", "able")
              << std::endl;

    return 0;
}   /* main() */


/*** End of file ***/
