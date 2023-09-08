/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    08/09/2023
 * @brief   Program to replace a symbol in a string
 */

#include <iostream>
#include <string>
#include <cassert>

static void change_sym(std::string& in_string);

/**
 * @brief   Main function
 * @par     Description
 * The program generates asks for a string as an input.
 * Then it calls `change_sym()` to replace "-" with "_".
 * @return  Always 0 (success).
 */
int
main ()
{
    std::string input = "";

    std::cout << "Insert a string ";
    std::getline(std::cin, input);

    assert(input.length() > 0);

    change_sym(input);

    std::cout << "Modified string " << input << '\n';

    return 0;
}   /* main() */

/**
 * @brief   Modify a symbol in a string
 * @par     Description
 * The function searches for every symbol "-" in the string `in_string` and
 * replace it with "_".
 * @param[in,out]   in_string   The input string
 * @return  Nothing.
 */
static void
change_sym (std::string& in_string)
{
    for (unsigned int idx = 0; idx < in_string.length(); ++idx)
    {
        if ('-' == in_string.at(idx))
        {
            in_string.at(idx) = '_';
        }
    }
}   /* change_sym() */

/*** End of file ***/
