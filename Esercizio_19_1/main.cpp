/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    07/01/2024
 * @brief   Class that uses strings to show floating point numbers in the format
 *          (+/-)D.DDDDE(+/-)N, with the functions of read, write, sum,
 *          substract, multiply, divide two numbers with floating point.
 */

#include <iostream>

namespace floating_point_t
{
    class floating_point_t
    {
        public:
            floating_point_t ()
            {
                long unsigned int idx(0);

                for (idx = 0; idx < (sizeof float_arr) / (sizeof float_arr[0]);
                     ++idx)
                {
                    this->float_arr[idx] = 0;
                }

                this->float_sign = 0;
                this->exp_sign = 0;
                this->exp = 0;
            }

            floating_point_t (const floating_point_t& old_num)
            {
                long unsigned int idx(0);

                for (idx = 0; idx < (sizeof float_arr) / (sizeof float_arr[0]);
                     ++idx)
                {
                    this->float_arr[idx] = old_num.float_arr[idx];
                }

                this->float_sign = old_num.float_sign;
                this->exp_sign = old_num.exp_sign;
                this->exp = old_num.exp;
            }

            ~floating_point_t()
            {
                long unsigned int idx(0);

                for (idx = 0; idx < (sizeof float_arr) / (sizeof float_arr[0]);
                     ++idx)
                {
                    this->float_arr[idx] = 0;
                }

                this->float_sign = 0;
                this->exp_sign = 0;
                this->exp = 0;
            }

            floating_point_t
            operator + (const floating_point_t& num_2)
            {
                floating_point_t out_num;

                int integer_num1(0);
                int integer_num2(0);
                int integer_out(0);

                // `diff` > 0 then the first number is greater than the
                // second; `diff` < 0 then the second number is greater.
                //
                int diff(0);

                // CASE 1) Equal sign and positive/negative.
                //
                if ((this->exp_sign == num_2.exp_sign))
                {
                    diff = this->exp - num_2.exp;
                }
                // CASE 2) Equal sign and negative.
                //
                else if ((this->exp_sign == num_2.exp_sign) &&
                         (true == this->exp_sign))
                {
                    diff = num_2.exp - this->exp;
                }
                // CASE 3) First is positive, second in negative.
                //
                else if ((false == this->exp_sign) && (true == num_2.exp_sign))
                {
                    diff = this->exp + num_2.exp;
                }
                // CASE 4) First is negative, second in positive.
                //
                else if ((false == this->exp_sign) && (true == num_2.exp_sign))
                {
                    diff = -this->exp - num_2.exp;
                }

                integer_num1 = this->float_arr[4] * 100000 +
                               this->float_arr[3] * 10000 +
                               this->float_arr[2] * 1000 +
                               this->float_arr[1] * 100 + 
                               this->float_arr[0] * 10;

                integer_num1 *= (true == this->float_sign) ? -1 : 1;

                integer_num2 = num_2.float_arr[4] * 100000 +
                               num_2.float_arr[3] * 10000 +
                               num_2.float_arr[2] * 1000 +
                               num_2.float_arr[1] * 100 + 
                               num_2.float_arr[0] * 10;

                integer_num2 *= (true == this->float_sign) ? -1 : 1;

                if (0 == diff)
                {
                    integer_out = integer_num1 + integer_num2;
                    out_num.float_sign = this->float_sign;

                }

                return out_num;
            }

            floating_point_t
            operator * (const floating_point_t& num_2)
            {
                floating_point_t out_num;

                long int integer_num1(0);
                long int integer_num2(0);
                long int integer_out(0);
                int exp_num1(0);
                int exp_num2(0);
                int exp_out(0);

                integer_num1 = this->float_arr[0] * 100000 +
                               this->float_arr[1] * 10000 +
                               this->float_arr[2] * 1000 +
                               this->float_arr[3] * 100 + 
                               this->float_arr[4] * 10;

                integer_num1 *= (true == this->float_sign) ? -1 : 1;
                //std::cerr << "integer_num1 = " << integer_num1 << std::endl;

                integer_num2 = num_2.float_arr[0] * 100000 +
                               num_2.float_arr[1] * 10000 +
                               num_2.float_arr[2] * 1000 +
                               num_2.float_arr[3] * 100 + 
                               num_2.float_arr[4] * 10;

                integer_num2 *= (true == this->float_sign) ? -1 : 1;
                //std::cerr << "integer_num2 = " << integer_num2 << std::endl;

                integer_out = integer_num1 * integer_num2 / 100000;
                // Using the guard digit to round the number.
                //
                integer_out += 50;
                integer_out /= 100;

                //std::cerr << "integer_out = " << integer_out << std::endl;
                out_num.float_sign = (this->float_sign == num_2.float_sign) ?
                                     false : true;
                
                exp_num1 = (false == this->exp_sign) ? this->exp : -this->exp;
                //std::cerr << "exp_num1 = " << exp_num1 << std::endl;
                exp_num2 = (false == num_2.exp_sign) ? num_2.exp : -num_2.exp;
                //std::cerr << "exp_num2 = " << exp_num2 << std::endl;
                exp_out = exp_num1 + exp_num2;

                if (exp_out >= 0)
                {
                    out_num.exp = exp_out;
                    out_num.exp_sign = false;
                }
                else
                {
                    out_num.exp = -exp_out;
                    out_num.exp_sign = true;
                }

                out_num.float_arr[4] = integer_out % 10;
                //std::cerr << "out_num.float_arr[4] = " << (int) out_num.float_arr[4] << std::endl;
                integer_out /= 10;
                out_num.float_arr[3] = integer_out % 10;
                //std::cerr << "out_num.float_arr[3] = " << (int) out_num.float_arr[3] << std::endl;
                integer_out /= 10;
                out_num.float_arr[2] = integer_out % 10;
                //std::cerr << "out_num.float_arr[2] = " << (int) out_num.float_arr[2] << std::endl;
                integer_out /= 10;
                out_num.float_arr[1] = integer_out % 10;
                //std::cerr << "out_num.float_arr[1] = " << (int) out_num.float_arr[1] << std::endl;
                integer_out /= 10;
                out_num.float_arr[0] = integer_out % 10;
                //std::cerr << "out_num.float_arr[0] = " << (int) out_num.float_arr[0] << std::endl;

                // Adjust to have the first number different from zero.
                //
                unsigned long int idx(0);
                unsigned long int cnt(0);

                for (idx = 0; idx < (sizeof out_num.float_arr) /
                                    (sizeof out_num.float_arr[0]); ++idx)
                {
                    if (0 == out_num.float_arr[idx])
                    {
                        ++cnt;
                    }
                    else
                    {
                        break;
                    }
                }

                for (idx = 0;
                     (0 != cnt) && (idx < (sizeof out_num.float_arr) /
                                          (sizeof out_num.float_arr[0])); ++idx)
                {
                    if ((idx + cnt) > (sizeof(out_num.float_arr) /
                                       sizeof(out_num.float_arr[0])))
                    {
                        out_num.float_arr[idx] = 0;
                    }
                    else
                    {
                        out_num.float_arr[idx] = out_num.float_arr[idx + 1];
                    }
                }

                return out_num;
            }   /* operator * () */

            floating_point_t
            operator / (const floating_point_t& num_2)
            {
                floating_point_t out_num;

                long int integer_num1(0);
                long int integer_num2(0);
                long int integer_out(0);
                int exp_num1(0);
                int exp_num2(0);
                int exp_out(0);

                integer_num1 = this->float_arr[0] * 100000 +
                               this->float_arr[1] * 10000 +
                               this->float_arr[2] * 1000 +
                               this->float_arr[3] * 100 + 
                               this->float_arr[4] * 10;

                integer_num1 *= (true == this->float_sign) ? -1 : 1;
                std::cerr << "integer_num1 = " << integer_num1 << std::endl;

                integer_num2 = num_2.float_arr[0] * 100000 +
                               num_2.float_arr[1] * 10000 +
                               num_2.float_arr[2] * 1000 +
                               num_2.float_arr[3] * 100 + 
                               num_2.float_arr[4] * 10;

                integer_num2 *= (true == this->float_sign) ? -1 : 1;
                std::cerr << "integer_num2 = " << integer_num2 << std::endl;

                if (0 == integer_num2)
                {
                    std::cerr << "Cannot divide by zero!" << std::endl;
                    exit(EXIT_FAILURE);
                }

                double temp = (double) integer_num1 / (double) integer_num2;
                std::cerr << "temp1 = " << temp << std::endl;
                temp *= 1000000.0;
                std::cerr << "temp2 = " << temp << std::endl;
                integer_out = (double) integer_num1 /
                              (double) integer_num2 * 1000000.0;
                // Using the guard digit to round the number.
                //
                integer_out += 5;
                integer_out /= 10;
                std::cerr << "integer_out = " << integer_out << std::endl;

                out_num.float_sign = (this->float_sign == num_2.float_sign) ?
                                     false : true;
                
                exp_num1 = (false == this->exp_sign) ? this->exp : -this->exp;
                exp_num2 = (false == num_2.exp_sign) ? num_2.exp : -num_2.exp;
                exp_out = exp_num1 - exp_num2;

                if (exp_out >= 0)
                {
                    out_num.exp = exp_out;
                    out_num.exp_sign = false;
                }
                else
                {
                    out_num.exp = -exp_out;
                    out_num.exp_sign = true;
                }

                out_num.float_arr[4] = integer_out % 10;
                std::cerr << "out_num.float_arr[4] = " << (int) out_num.float_arr[4] << std::endl;
                integer_out /= 10;
                out_num.float_arr[3] = integer_out % 10;
                std::cerr << "out_num.float_arr[3] = " << (int) out_num.float_arr[3] << std::endl;
                integer_out /= 10;
                out_num.float_arr[2] = integer_out % 10;
                std::cerr << "out_num.float_arr[2] = " << (int) out_num.float_arr[2] << std::endl;
                integer_out /= 10;
                out_num.float_arr[1] = integer_out % 10;
                std::cerr << "out_num.float_arr[1] = " << (int) out_num.float_arr[1] << std::endl;
                integer_out /= 10;
                out_num.float_arr[0] = integer_out % 10;
                std::cerr << "out_num.float_arr[0] = " << (int) out_num.float_arr[0] << std::endl;

                // Adjust to have the first number different from zero.
                //
                unsigned long int idx(0);
                unsigned long int cnt(0);

                for (idx = 0; idx < (sizeof out_num.float_arr) /
                                    (sizeof out_num.float_arr[0]); ++idx)
                {
                    if (0 == out_num.float_arr[idx])
                    {
                        ++cnt;
                        std::cerr << "++cnt at" << idx << std::endl;
                    }
                    else
                    {
                        break;
                    }
                }

                for (idx = 0;
                     (0 != cnt) && (idx < (sizeof out_num.float_arr) /
                                          (sizeof out_num.float_arr[0])); ++idx)
                {
                    if ((idx + cnt) > (sizeof(out_num.float_arr) /
                                       sizeof(out_num.float_arr[0])))
                    {
                        out_num.float_arr[idx] = 0;
                    }
                    else
                    {
                        out_num.float_arr[idx] = out_num.float_arr[idx + 1];
                    }
                }

                return out_num;
            }   /* operator / () */

        private:
            bool float_sign;    /* 0 is +, 1 is -*/
            char float_arr[5];
            bool exp_sign;      /* 0 is +, 1 is -*/
            char exp;

        friend std::ostream&
        operator << (std::ostream& out_file,
                     const floating_point_t& in_num)
        {
            char sign1(0);
            char sign2(0);
            
            if (0 == in_num.float_sign)
            {
                sign1 = '+';
            }
            else
            {
                sign1 = '-';
            }

            if (0 == in_num.exp_sign)
            {
                sign2 = '+';
            }
            else
            {
                sign2 = '-';
            }

            out_file << sign1 << static_cast<int>(in_num.float_arr[0]) << "."
                     << static_cast<int>(in_num.float_arr[1])
                     << static_cast<int>(in_num.float_arr[2])
                     << static_cast<int>(in_num.float_arr[3])
                     << static_cast<int>(in_num.float_arr[4])
                     << "E" << sign2 << static_cast<int>(in_num.exp);

            return (out_file);
        }   /* operator << () */

        friend std::istream&
        operator >> (std::istream& in_file,
                     floating_point_t& out_num)
        {
            int cnt(0);
            char in_chr[11]{0};
            int dot_pos(-1);
            int first_nonzero(-1);
            char in_sym(0);

            out_num.exp_sign = false;

            // To protect I/O.
            //
            std::istream::sentry the_sentry(in_file, true);

            if (the_sentry)
            {
                if (in_file.bad())
                {
                    return (in_file);
                }

                while (std::cin.get(in_sym))
                {
                    if (('\n' == in_sym) || ('\r' == in_sym) )
                    {
                        break;
                    }

                    if (isdigit(in_sym))
                    {
                        in_chr[cnt] = in_sym - '0';

                        if ((0 != in_chr[cnt]) && (-1 == first_nonzero))
                        {
                            first_nonzero = cnt;
                        }

                        ++cnt;
                    }
                    else
                    {
                        if ((('+' ==  in_sym) || ('-' ==  in_sym)) &&
                            (0 == cnt))
                        {
                            if ('-' ==  in_sym)
                            {
                                out_num.exp_sign = true;
                            }
                            else
                            {
                                out_num.exp_sign = false;
                            }
                        }
                        else
                        {
                            if (('.' ==  in_sym) && (0 != cnt) &&
                                (-1 == dot_pos))
                            {
                                in_chr[cnt] = in_sym;
                                dot_pos = cnt;
                                ++cnt;
                            }
                            else
                            {
                                in_file.setstate(std::ios::failbit);
                                break;
                            }
                        }
                    }
                }

                // If the input is 0.001 then `diff = 3`, if the input is 12.03
                // then `diff = -2`.
                //
                int diff(first_nonzero - dot_pos);
                long unsigned int idx(0);
                long unsigned int float_idx(0);

                // The case `diff = 0` cannot exists.
                //
                if (diff > 0)
                {
                    out_num.exp = diff;
                    out_num.exp_sign = true;

                    // Before the "." which is saved, the number is after
                    // diff + 1 elements, after the "." is after diff.
                    //
                    ++diff;

                    for (idx = 0;
                         idx < (sizeof(in_chr) / sizeof(in_chr[0]));
                         ++idx)
                    {
                        if ((int) idx == dot_pos)
                        {
                            --diff;
                            continue;
                        }

                        if ((idx + diff) > (sizeof(in_chr) / sizeof(in_chr[0])))
                        {
                            in_chr[idx] = 0;
                        }
                        else
                        {
                            in_chr[idx] = in_chr[idx + diff];
                        }
                    }
                }
                else
                {
                    ++diff;
                    out_num.exp = -diff;
                    out_num.exp_sign = false;
                }

                for (idx = 0; idx < (sizeof out_num.float_arr) /
                                    (sizeof out_num.float_arr[0]); ++idx)
                {
                    if ('.' == in_chr[idx])
                    {
                        continue;
                    }

                    out_num.float_arr[float_idx] = in_chr[idx];
                    ++float_idx;
                }
            }
            else
            {
                in_file.setstate(std::ios::failbit);
            }

            return (in_file);
        }   /* operator >> () */
    };
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
    floating_point_t::floating_point_t num1;
    floating_point_t::floating_point_t num2;

    std::cout << "Insert the first number: ";
    std::cin >> num1;

    std::cout << "Insert the second number: ";
    std::cin >> num2;

    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    //std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
    //std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
    std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
    std::cout << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;

    return (0);
}   /* main() */


/*** End of file ***/
