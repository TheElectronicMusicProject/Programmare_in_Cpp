/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    21/09/2023
 * @brief   Simple program to print a string starting from a symbol different
 *          from space.
 */

#include <iostream>
#include <string>
#include <cstring>
#include <stddef.h>

static const char * search_first_non_sym(const char * p_string, char sym);

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the input string is returned with a pointer to the
 * first symbol different from space.
 * @return  Always 0.
 */
int
main ()
{
    const char * p_ret = NULL;
    std::string string = "";

    std::cout << "Insert a string: \n";
    std::getline(std::cin, string, '\n');

    p_ret = search_first_non_sym(string.c_str(), ' ');

    if (NULL != p_ret)
    {
        std::cout << "New string: " << p_ret << '\n';
    }

    return 0;
}   /* main() */

/**
 * @brief   Searches for the first character not equal to the given one
 * @par     Description
 * This functions scans the entire string. It return the pointer to the first
 * different symbol from `sym`.
 * @param[in]       p_string    Pointer to the input string.
 * @param[in]       sym         Symbol to be searched for.
 * @return  The pointer to the first element different from the `sym`.
 */
static const char *
search_first_non_sym (const char * p_string, char sym)
{
    static const char * p_elem = p_string;

    if (NULL != p_string)
    {
        while (NULL != p_elem)
        {
            if (sym != *p_elem)
            {
                break;
            }

            ++p_elem;
        }
    }

    return p_elem;
}   /* search_first_non_sym() */


/*** End of file ***/
