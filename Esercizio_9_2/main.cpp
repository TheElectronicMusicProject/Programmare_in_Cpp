/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    08/09/2023
 * @brief   Program to detect if a string begins another string.
 */

#include <iostream>
#include <string>

static bool begins(std::string string1, std::string string2);

/**
 * @brief   Main function
 * @par     Description
 * The program tests if a string begins another string.
 * If it's true, it prints "true", "false" otherwise.
 * @return  Always 0 (success).
 */
int
main ()
{
    std::cout << "String 1 begins string 2? " <<
                 (begins("FILI", "FILIPPO") ? "true\n" : "false\n");

    return 0;
}   /* main() */

/**
 * @brief   Detect if a string begins another one.
 * @par     Description
 * Two strings are compared. If the string `string1` begins `string2` then
 * the boolean true is returned, false otherwise.
 * @param[in]   string1 The subtring pattern that will be searched
 * @param[in]   string2 The main string where the program looks at
 * @return  true if `string1` begins `string2`, false if `string1` doesn't
 *          begin `string2`.
 */
static bool
begins (std::string string1, std::string string2)
{
    bool ret = false;
    unsigned int str1_len = string1.length();

    if (string2.length() >= str1_len)
    {
        ret = true;

        for (unsigned int idx = 0; idx < str1_len; ++idx)
        {
            if (string1.at(idx) != string2.at(idx))
            {
                ret = false;
                break;
            }
        }
    }

    return ret;
}   /* begins() */

/*** End of file ***/
