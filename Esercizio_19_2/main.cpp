/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    06/01/2024
 * @brief   Class to manage fixed point numbers. A fixed point number has a
 *          constant number of decimals.
 *          The user can select the global scaling factor, that will be
 *          converter to a power of 2.
 */

#include <iostream>
#include <stdint.h>
#include <iomanip>
#include <cmath>

namespace fixed_point_t
{
    class fixed_point_t
    {
        public:
            fixed_point_t ()
            {
                fixed_pt_num = 0;
            }

            fixed_point_t (const fixed_point_t& old_arr)
            {
                fixed_pt_num = old_arr.fixed_pt_num;
                fractional_bits = old_arr.fractional_bits;
            }

            ~fixed_point_t()
            {
                fixed_pt_num = 0;
            }

            void
            set_num (double num)
            {
                fixed_pt_num = double_to_fixed(num);
            }

            void
            set_scaling (int32_t fract_bits)
            {
                fractional_bits = fract_bits;
            }

            fixed_point_t
            operator + (const fixed_point_t& oper2)
            {
                fixed_point_t out_num;

                out_num.fixed_pt_num = this->fixed_pt_num + oper2.fixed_pt_num;

                return out_num;
            }   /* operator + () */

            fixed_point_t
            operator - (const fixed_point_t& oper2)
            {
                fixed_point_t out_num;

                out_num.fixed_pt_num = this->fixed_pt_num - oper2.fixed_pt_num;

                return out_num;
            }   /* operator - () */

            fixed_point_t
            operator * (const fixed_point_t& oper2)
            {
                fixed_point_t out_num;

                out_num.fixed_pt_num = (int64_t) this->fixed_pt_num *
                                       (int64_t) oper2.fixed_pt_num /
                                       (int64_t) (1 << fractional_bits);

                return out_num;
            }   /* operator * () */

            fixed_point_t
            operator / (const fixed_point_t& oper2)
            {
                fixed_point_t out_num;

                if (0 == oper2.fixed_pt_num)
                {
                    std::cerr << "CANNOT DIVIDE BY ZERO!" << std::endl;
                    exit(EXIT_FAILURE);
                }

                out_num.fixed_pt_num = (int64_t) this->fixed_pt_num *
                                       (int64_t) (1 << fractional_bits) /
                                       (int64_t) oper2.fixed_pt_num;

                return out_num;
            }   /* operator / () */

        private:
            static int32_t fractional_bits;
            int32_t fixed_pt_num;

            int32_t
            double_to_fixed (double in_num)
            {
                return ((int32_t) round(in_num *
                                        (double) (1 << fractional_bits)));
            }

            double
            fixed_to_double (int32_t in_num) const
            {
                return (((double) in_num) / ((double) (1 << fractional_bits)));
            }

        friend std::ostream&
        operator << (std::ostream& out_file,
                     const fixed_point_t& in_num)
        {
            out_file << in_num.fixed_to_double(in_num.fixed_pt_num);

            return (out_file);
        }   /* operator << () */

        friend std::istream&
        operator >> (std::istream& in_file,
                     fixed_point_t& out_num)
        {
            double in_num(0);

            // To protect I/O.
            //
            std::istream::sentry the_sentry(in_file, true);

            if (the_sentry)
            {
                if (in_file.bad())
                {
                    return (in_file);
                }

                // Read the number.
                //
                in_file >> in_num;

                if (in_file.bad())
                {
                    return (in_file);
                }

                out_num.fixed_pt_num = out_num.double_to_fixed(in_num);
            }
            else
            {
                in_file.setstate(std::ios::failbit);
            }

            return (in_file);
        }   /* operator >> () */
    };

    int32_t fixed_point_t::fixed_point_t::fractional_bits(0);
}

/**
 * @brief   Main function
 * @par     Description
 * Test for the class fixed_point_t, printing its values.
 * @return  Always 0 (success).
 */
int
main ()
{
    const int32_t scaling = 16;

    fixed_point_t::fixed_point_t num1;
    num1.set_scaling(scaling);

    std::cout << "Read first number ";
    std::cin >> num1;
    //num1.set_num(-2.03);

    fixed_point_t::fixed_point_t num2;

    std::cout << "Read second number ";
    std::cin >> num2;
    //num2.set_num(12e-3);

    std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
    std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
    std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
    std::cout << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;

    return (0);
}   /* main() */


/*** End of file ***/
