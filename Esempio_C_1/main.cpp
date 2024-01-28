/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    28/01/2024
 * @brief   Calculates the value of the sine funcion by using simple arithmetic
 *          functions in floating point math.
 * 
 *          Use: `./main <value>`, where `value` is the angle in radiants.
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>

static char * float_2_ascii(float number);
static float fix_float(float number);
static float factorial(float number);

/**
 * @brief   Main function
 * @par     Description
 * The format is `f.fffe+X`;
 * - `f.fff` is a 4 digits fraction
 * - `+` is the sign (+ or -)
 * - `X` is the single digit exponent value
 * 
 * @attention   This program is used to demonstrate some probles related to
 *              floating point arithmentics. It must not be used to produce the
 *              exact sine value.
 * @note    Although there is a single digit exponent, 2 digits are used for
 *          calculations. This is due to a limitation in `printf()` that hasn't
 *          a format for a single digit.
 * @param[in]   argc    The number of strings pointed by `argv`.
 * @param[in]   argv    Vector of input string commands.
 * @return  Always 0 (success).
 */
int
main (int argc, char ** argv)
{
    float   total(0.0);         /** Progressive total of the series */
    float   new_total(0.0);     /** Last version of the total */
    float   term_top(0.0);      /** Upper part of the term */
    float   term_bottom(0.0);   /** Bottom part of the term */
    float   term(0.0);          /** Current term */
    float   exp(0.0);           /** Exponent of the term */
    float   sign(0.0);          /** Sign of the term (+ or -) */
    float   value(0.0);         /** Value of the argument of the function sin */
    int     index(0);           /** Index of the counter of the terms */
    
    if (2 != argc)
    {
        std::cerr << "Usage is\n";
        std::cerr << "\tmain <value>\n";
        exit(8);
    }

    value = fix_float(atof(&argv[1][0]));
    exp = 1.0;
    sign = 1.0;

    for (index = 0; /* Take care of it below */; ++index)
    {
        term_top = fix_float(pow(value, exp));
        term_bottom = fix_float(factorial(exp));
        term = fix_float(term_top / term_bottom);

        std::cout << "x**" << static_cast<int>(exp) << "\t\t"
                  << float_2_ascii(term_top) << "\n";
        std::cout << exp << "!\t\t" << float_2_ascii(term_bottom) << "\n";
        std::cout << "x**" << static_cast<int>(exp) << "/"
                  << static_cast<int>(exp) << "! " << float_2_ascii(term)
                  << "\n";

        new_total = fix_float(total + sign * term);

        if (total == new_total)
        {
            break;
        }

        total = new_total;
        sign = -sign;
        exp += 2.0;
        
        std::cout << "  total   " << float_2_ascii(total) << "\n";
        std::cout << "\n";
    }

    std::cout << index + 1 << "  term computed\n";
    std::cout << "sin(" << float_2_ascii(value) << ")=\n";
    std::cout << " " << float_2_ascii(total) << "\n";
    std::cout << "Actual sin(" << atof(&argv[1][0]) << ")="
              << sin(atof(&argv[1][0])) << "\n";

    return 0;
}   /* main() */

/**
 * @brief   Convertion from floating number to ascii string
 * @param[in]   number  Number to be converted to ascii.
 * @return  Pointer to the string containing the number.
 * @attention   This function uses static memory, hence the next calls will
 *              rewrite the current values.
 */
static char *
float_2_ascii (float number)
{
    static char result[15]{0};

    std::sprintf(result, "%8.3E", number);

    return (result);
}   /* float_2_ascii() */

/**
 * @brief   Convertion from high precision numbers to low precision numbers to
 *          simulate a very simplified floating point structure
 * @param[in]   number  Number to be managed.
 * @return  5 digit precision number.
 * @note    This function converts a number in ascii an viceversa. It's slow.
 */
static float
fix_float (float number)
{
    float   result(0.0);
    char    ascii[15]{0};

    std::sprintf(ascii, "%8.4e", number);
    std::sscanf(ascii, "%e", &result);

    return (result);
}   /* fix_float() */

/**
 * @brief   Calculation of the factorial of a number
 * @param[in]   number  Number for the factorial.
 * @return  The factorial of the number.
 * @note    It is a floating point routine, but using non-integer numbers is not
 *          a good idea.
 */
static float
factorial (float number)
{
    if (number <= 1.0)
    {
        return (number);
    }
    else
    {
        return (number * factorial(number - 1.0));
    }
}   /* factorial() */


/*** End of file ***/
