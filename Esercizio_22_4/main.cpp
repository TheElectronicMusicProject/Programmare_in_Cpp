/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    30/01/2024
 * @brief   Write a funzion `count_letter` which accept a character.
 *          This funcion will count the number of vowels and consonants.
 *          When there is something different from this, it returns an
 *          exception.
 */

#include <iostream>
#include <fstream>
#include <string>

static unsigned int count_letter(char val);

class check_err
{
    public:
        const std::string what;

        check_err (const std::string& str) : what(str)
        {
            /* Do nothing */
        }
};

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created class works.
 * @param[in]   argc    The number of strings pointed by `argv`.
 * @param[in]   argv    Vector of input string commands.
 * @return  Always 0 (success).
 */
int
main (int argc, char * argv[])
{
    char temp_char(0);

    if (2 != argc)
    {
        std::cerr << "Usage is: main <filename>\n";
        exit(8);
    }

    std::ifstream h_file(argv[1]);

    if (h_file.bad() || h_file.fail())
    {
        std::cerr << "Error: cannot open " << argv[1] << "\n";
        exit(8);
    }

    try
    {
        while (h_file.get(temp_char))
        {
            unsigned int total = count_letter(temp_char);

            std::cout << "Number of symbols: " << total << "\n";
        }
    }
    catch (const check_err& err)
    {
        std::cerr << err.what << '\n';
        h_file.close();
        exit(8);
    }
    catch (...)
    {
        std::cerr << "Unknown error\n";
        h_file.close();
        exit(8);
    }

    h_file.close();

    return 0;
}   /* main() */

/**
 * @brief   Counts the number of symbols
 * @par     Description
 * The function increments a counter, that is returned as its output, when it
 * encounters a vowel, a consonant or a number.
 * @param[in]   val The input character
 * @return  The number of recognized symbols.
 */
static unsigned int
count_letter (char val)
{
    static unsigned int count(0);

    if (((val >= '0') && (val <= '9')) || ((val >= 'A') && (val <= 'Z')) ||
        ((val >= 'a') && (val <= 'z')))
    {
        ++count;
    }
    else
    {
        throw check_err("The character " + std::string(1, val) +
                        " is not recognized!");
    }

    return (count);
}   /* count_letter() */


/*** End of file ***/
