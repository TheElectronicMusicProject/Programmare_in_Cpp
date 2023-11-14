/**
 * @file    fixed_pt.cpp
 * @author  Filippo Graziani
 * @date    13/11/2023
 * @brief   Fixed point class.
 */

#include <iostream>
#include "fixed_pt.h"
#include "ctype.h"

namespace fixed_pt
{
    /**
     * @brief       Operator >>.
     * Reads a number fixed_pt.
     * @param[in]   in_file     File which will be read.
     * @param[in]   number      Position in which the number will be put.
     * @return      Reference to the input file.
     */
    std::istream& operator >> (std::istream& in_file,
                               fixed_pt& number)
    {
        long int before_dp(0);
        char after_dp1(0);
        char after_dp2(0);
        char chr(0);

        number = 0.0;

        assert(100 == fixed_exp);

        // To protect I/O.
        //
        std::istream::sentry the_sentry(in_file, true);

        if (the_sentry)
        {
            if (in_file.bad())
            {
                return (in_file);
            }

            // Number after the space.
            //
            in_file >> before_dp;

            if (in_file.bad())
            {
                return (in_file);
            }

            // First char after the number.
            //
            in_file >> chr;

            if (in_file.bad())
            {
                return (in_file);
            }

            if ('.' != chr)
            {
                in_file.setstate(std::ios::failbit);

                return (in_file);
            }

            // Two numbers after the point.
            //
            in_file >> after_dp1 >> after_dp2;

            if (in_file.bad())
            {
                return (in_file);
            }

            if ((!isdigit(after_dp1)) || (!isdigit(after_dp2)))
            {
                in_file.setstate(std::ios::failbit);

                return (in_file);
            }

            number.value = before_dp * fixed_exp + (after_dp1 - '0') * 10 +
                           (after_dp2 - '0');
        }
        else
        {
            in_file.setstate(std::ios::failbit);
        }

        return (in_file);
    }   /* operator >> () */
}


/*** End of file ***/
