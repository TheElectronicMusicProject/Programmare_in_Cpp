/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    08/09/2023
 * @brief   Program to count the number of words in a string.
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * My own namespace for all regarding the string.
 */
namespace in_string
{
    string val;
    int len;
    unsigned int word_count;
}

/**
 * @brief   Main function
 * @par     Description
 * The program requires an input string, written from the terminal, and detects
 * how many words are composing the string.
 * Double space is not counted as word.
 * @return  Always 0 (success).
 */
int
main ()
{
    in_string::val = "";

    while (1)
    {
        cout << "Insert a string: ";
        getline(cin, in_string::val);

        in_string::len = in_string::val.length();
        in_string::word_count = 0;

        if (in_string::len <= 0)
        {
            break;
        }
        else
        {
            for (int idx = 0; idx < in_string::len; ++idx)
            {
                if (' ' == in_string::val.at(idx))
                {
                    if ((idx > 0) && (' ' != in_string::val.at(idx - 1)))
                    {
                        ++in_string::word_count;
                    }
                }
            }

            if (' ' != in_string::val.at(in_string::len - 1))
            {
                ++in_string::word_count;
            }

            cout << "The number of words is: " << in_string::word_count << '\n';
        }
    }

    return 0;
}   /* main() */

/*** End of file ***/
