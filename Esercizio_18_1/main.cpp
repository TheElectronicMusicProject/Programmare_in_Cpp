/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    29/12/2023
 * @brief   Class used to manage fractions such as 1/3, with sum, substract,
 *          multiplication and division operators.
 */

#include <iostream>
#include <ctype.h>
#include <string>

#define MAX(num_a, num_b)   (((num_a) > (num_b)) ? (num_a) : (num_b))

namespace fract_t
{
    class fract_t
    {
        public:
            int num;
            int den;

            fract_t ()
            {
                fraction = "1/1";
                num = 1;
                den = 1;
            }

            fract_t (std::string frac)
            {
                if (true == check_if_frac(frac))
                {
                    fraction = frac;
                }
                else
                {
                    std::cerr << frac << " is not a fraction!\n";
                    exit(EXIT_FAILURE);
                }

                int ret = extract_frac(frac, num, den);

                switch (ret)
                {
                    case 1:
                        std::cerr << "Denominator cannot be 0\n";
                        exit(EXIT_FAILURE);
                    break;
                
                    case 0:
                        /* Fall through */
                    default:
                    break;
                }
            }

            fract_t (const fract_t& old_frac)
            {
                fraction = old_frac.fraction;
                num = old_frac.num;
                den = old_frac.den;
            }

            ~fract_t()
            {
                fraction = "";
            }

        private:
            std::string fraction;

            unsigned int factorization(unsigned int num,
                                       unsigned int * p_list[2],
                                       unsigned int& p_n_elem);
            bool is_prime_number(unsigned int num);
            void print_factorization(unsigned int * p_array[2],
                                     unsigned int size);
            unsigned int mcm(unsigned int num1, unsigned int num2);
            bool check_if_frac(std::string in_str);
            int extract_frac(std::string in_str, int& num, int& den);

        friend fract_t operator + (const fract_t& oper1, const fract_t& oper2);
        friend fract_t operator - (const fract_t& oper1, const fract_t& oper2);
        friend fract_t operator / (const fract_t& oper1, const fract_t& oper2);
        friend fract_t operator * (const fract_t& oper1, const fract_t& oper2);
        friend inline std::ostream& operator << (std::ostream& out_file,
                                                 const fract_t& number);
    };

    inline fract_t
    operator + (const fract_t& oper1,
                const fract_t& oper2)
    {
        std::string new_fract = "";
        fract_t obj;
        int new_den = obj.mcm(oper1.den, oper2.den);
        int new_num = (new_den / oper1.den * oper1.num) +
                      (new_den / oper2.den * oper2.num);

        if (0 == new_num)
        {
            new_den = 1;
        }
        
        new_fract = std::to_string(new_num) + "/" + std::to_string(new_den);

        return fract_t(new_fract);
    }   /* operator + () */

    inline fract_t
    operator - (const fract_t& oper1,
                const fract_t& oper2)
    {
        std::string new_fract = "";
        fract_t obj;
        int new_den = obj.mcm(oper1.den, oper2.den);
        int new_num = (new_den / oper1.den * oper1.num) -
                      (new_den / oper2.den * oper2.num);

        if (0 == new_num)
        {
            new_den = 1;
        }
        
        new_fract = std::to_string(new_num) + "/" + std::to_string(new_den);

        return fract_t(new_fract);
    }   /* operator - () */

    inline fract_t
    operator * (const fract_t& oper1,
                const fract_t& oper2)
    {
        std::string new_fract = "";
        int new_num(oper1.num * oper2.num);
        int new_den(oper1.den * oper2.den);

        if (0 == new_num)
        {
            new_den = 1;
        }
        
        new_fract = std::to_string(new_num) + "/" + std::to_string(new_den);

        return fract_t(new_fract);
    }   /* operator * () */

    inline fract_t
    operator / (const fract_t& oper1,
                const fract_t& oper2)
    {
        std::string new_fract = "";
        int new_num(oper1.num * oper2.den);
        int new_den(oper1.den * oper2.num);

        if (0 == new_num)
        {
            new_den = 1;
        }
        
        new_fract = std::to_string(new_num) + "/" + std::to_string(new_den);

        return fract_t(new_fract);
    }   /* operator / () */

    inline std::ostream&
    operator << (std::ostream& out_file,
                 const fract_t& number)
    {
        std::string str_frac = "";
        fract_t obj;

        str_frac = std::to_string(number.num) + "/" +
                   std::to_string(number.den);

        out_file << str_frac;

        return (out_file);
    }   /* operator << () */
}

/**
 * @brief   Main function
 * @par     Description
 * Test for the class fract_t, printing its values.
 * @return  Always 0 (success).
 */
int
main ()
{
    std::string input_str = "";

    std::cout << "Insert first number -> ";
    std::getline(std::cin, input_str);
    fract_t::fract_t num1(input_str);

    std::cout << "Insert second number -> ";
    std::getline(std::cin, input_str);
    fract_t::fract_t num2(input_str);

    fract_t::fract_t num3(num1 + num2);
    fract_t::fract_t num4(num1 - num2);
    fract_t::fract_t num5(num1 * num2);
    fract_t::fract_t num6(num1 / num2);

    std::cout << num1 << " + " << num2 << " = " << num3 << std::endl;
    std::cout << num1 << " - " << num2 << " = " << num4 << std::endl;
    std::cout << num1 << " * " << num2 << " = " << num5 << std::endl;
    std::cout << num1 << " / " << num2 << " = " << num6 << std::endl;

    return (0);
}   /* main() */

/**
 * @brief   Calculation of the mcm of two numbers
 * @par     Description
 * The function finds the factorization of the given number, by using the
 * function factorization(), and calculates the mcm value.
 * @param[in]   num1    The first integer number.
 * @param[in]   num2    The second integer number.
 * @return  The mcm of the given numbers.
 */
inline unsigned int
fract_t::fract_t::mcm (unsigned int num1,
                       unsigned int num2)
{
    unsigned int * p_arr1[2] = {NULL, NULL};
    unsigned int * p_arr2[2] = {NULL, NULL};
    unsigned int n_elem1(0);
    unsigned int n_elem2(0);
    unsigned int result(1);

    factorization(num1, p_arr1, n_elem1);
    factorization(num2, p_arr2, n_elem2);
#if 0
    print_factorization(p_arr1, n_elem1);
    print_factorization(p_arr2, n_elem2);
#endif
    unsigned int idx1(0);
    unsigned int idx2(0);
    unsigned int temp1(0);
    unsigned int temp2(0);
    unsigned int temp_val(0);
    bool is_in_while(true);

    while (true == is_in_while)
    {
        unsigned int max_val(0);
        
        // Overflow of first.
        //
        if (idx1 < n_elem1)
        {
            temp1 = p_arr1[0][idx1];
        }
        else
        {
            temp1 = UINT32_MAX;
        }

        // Overflow of second.
        //
        if (idx2 < n_elem2)
        {
            temp2 = p_arr2[0][idx2];
        }
        else
        {
            temp2 = UINT32_MAX;
        }

        if (temp1 < temp2)
        {
#if 0
            std::cout << "## 1- if(" << temp1 << "<" << temp2 << ")"  << std::endl;
#endif
            temp_val = temp1;
            max_val = p_arr1[1][idx1];
            
            if (idx1 < n_elem1)
            {
                ++idx1;
            }
        }
        else if (temp1 == temp2)
        {
#if 0
            std::cout << "## 2- if(" << temp1 << "==" << temp2 << ")"  << std::endl;
#endif
            temp_val = temp1;
            max_val = MAX(p_arr1[1][idx1], p_arr2[1][idx2]);
            
            if (idx1 < n_elem1)
            {
                ++idx1;
            }

            if (idx2 < n_elem2)
            {
                ++idx2;
            }
        }
        else
        {
#if 0
            std::cout << "## 3- if(" << temp1 << ">" << temp2 << ")"  << std::endl;
#endif
            temp_val = temp2;
            max_val = p_arr2[1][idx2];
            
            if (idx2 < n_elem2)
            {
                ++idx2;
            }
        }

        // Multiplication.
        //
        unsigned int idx3(0);

        for (idx3 = 0; idx3 < max_val; ++idx3)
        {
            result *= temp_val;
        }

        // Exit condition.
        //
        if ((idx1 == n_elem1) && (idx2 == n_elem2))
        {
            is_in_while = false;
        }
    }

    free(p_arr1[0]);
    p_arr1[0] = NULL;

    free(p_arr1[1]);
    p_arr1[1] = NULL;

    free(p_arr2[0]);
    p_arr2[0] = NULL;

    free(p_arr2[1]);
    p_arr2[1] = NULL;

    return result;
}   /* fract_t::fract_t::mcm() */

/**
 * @brief   Prints of factorization
 * @par     Description
 * The function prints the factorization result.
 * @param[in]   p_array         Two arrays of pointers: first row is related to
 *                              the number of the factorization, second row is
 *                              the number of its power.
 * @param[in]   size            The number of elements in p_array.
 * @return  Nothing.
 */
inline void
fract_t::fract_t::print_factorization (unsigned int * p_array[2],
                                       unsigned int size)
{
    if ((NULL != p_array[0]) && (NULL != p_array[1]) && (size > 0))
    {
        unsigned int idx(0);

        for (idx = 0; idx < size; ++idx)
        {
            std::cout << "At index " << idx << " = "
                      << *(p_array[0] + idx) << " with repetition "
                      << *(p_array[1] + idx) << '\n';
        } 
    }
}   /* fract_t::fract_t::print_factorization() */

/**
 * @brief   Factorization of a given number
 * @par     Description
 * The function requires a number, and two pointers to integers. The results of
 * the factorization will be written on the p_list.
 * @param[in]       num         The integer number.
 * @param[in,out]   p_list      Two arrays of pointers: first row is related to
 *                              the number of the factorization, second row is
 *                              the number of its power.
 * @param[out]      p_n_elem    The number of elements in p_list.
 * @attention   The user must free the memory.
 * @return  1 if an error occourred, 0 otherwise.
 */
inline unsigned int
fract_t::fract_t::factorization (unsigned int num,
                                 unsigned int * p_list[2],
                                 unsigned int& p_n_elem)
{
    unsigned int ret(0);
    p_n_elem = 0;

    if (num > 0)
    {
        unsigned int n_elem = 10;

        p_list[0] = (unsigned int *) calloc(n_elem, sizeof(unsigned int));

        if (NULL != p_list[0])
        {
            p_list[1] = (unsigned int *) calloc(n_elem, sizeof(unsigned int));

            if (NULL != p_list[1])
            {
                unsigned int idx(0);
                unsigned int scan(2);
                unsigned int prev_scan(scan);
                bool is_first_iter = true;

                p_n_elem = 1;

                if (true == is_prime_number(num))
                {
                    p_list[0][0] = num;
                    p_list[1][0] = 1;
                    scan = num + 1;
                }

                while ((num != 1) && (scan <= num))
                {
                    if (true == is_prime_number(scan))
                    {
                        if (0 == (num % scan))
                        {
                            num /= scan;

                            if (true == is_first_iter)
                            {
                                prev_scan = scan;
                                is_first_iter = false;
                            }

                            if (scan != prev_scan)
                            {
                                prev_scan = scan;
                                ++idx;
                            }

                            p_list[0][idx] = scan;
                            ++p_list[1][idx];
                        }
                        else
                        {
                            ++scan;
                        }
                    }
                    else
                    {
                        ++scan;
                    }

                    // Adjust the number of elements.
                    //
                    if (scan == n_elem)
                    {
                        n_elem += 10;
                        p_list[0] = (unsigned int *) realloc(
                                                p_list[0],
                                                n_elem * sizeof(unsigned int));

                        if (NULL != p_list[0])
                        {
                            p_list[1] = (unsigned int *) realloc(
                                                p_list[1],
                                                n_elem * sizeof(unsigned int));

                            if (NULL == p_list[0])
                            {
                                exit(EXIT_FAILURE);
                            }
                        }
                        else
                        {
                            exit(EXIT_FAILURE);
                        }
                    }
                }

                p_n_elem += idx;
            }
            else
            {
                p_n_elem = 0;
                ret = 1;
            }
        }
        else
        {
            p_n_elem = 0;
            ret = 1;
        }
    }
    else
    {
        p_n_elem = 0;
        ret = 1;
    }

    return ret;
}   /* fract_t::fract_t::factorization() */

/**
 * @brief   Tells if a number is prime
 * @par     Description
 * The function verifies if the given number is prime.
 * @param[in]   num    The integer number.
 * @return  true if is prime, false otherwise.
 */
inline bool
fract_t::fract_t::is_prime_number (unsigned int num)
{
    unsigned int scan(0);
    bool is_prime(true);

    for (scan = (num - 1); scan > 1; --scan)
    {
        if (0 == (num % scan))
        {
            is_prime = false;
            break;
        }
    }

    return is_prime;
}   /* fract_t::fract_t::is_prime_number() */

/**
 * @brief   Check if the string containts a fraction
 * @par     Description
 * The function verifies if the given string is composed by a fraction between
 * two integer numbers (e.g. 13/4, 2/9).
 * @param[in]   in_str      The string containing a fraction.
 * @return  true if it is a valid fraction, false otherwise.
 */
inline bool
fract_t::fract_t::check_if_frac (std::string in_str)
{
    bool ret(true);
    long unsigned int idx(0);
    int cnt(0);

    if ('-' == in_str.at(0))
    {
        ++idx;
    }

    for (; (idx < in_str.length()) && (true == ret); ++idx)
    {
        switch (cnt)
        {
            case 0:
                if (0 == isdigit(in_str.at(idx)))
                {
                    ret = false;
                }
                else
                {
                    ++cnt;
                }
            break;

            case 1:
                if (0 == isdigit(in_str.at(idx)))
                {
                    if ('/' == in_str.at(idx))
                    {
                        ++cnt;
                    }
                    else
                    {
                        ret = false;
                    }
                }
            break;

            case 2:
                if ('-' == in_str.at(idx))
                {
                    ++idx;
                }

                if (0 == isdigit(in_str.at(idx)))
                {
                    ret = false;
                }
            break;

            default:
            break;
        }
    }

    if (2 != cnt)
    {
        ret = false;
    }

    return ret;
}   /* fract_t::fract_t::check_if_frac() */

/**
 * @brief   Extraction of numerator and denominator from a string.
 * @par     Description
 * The function extract the numerator and denominator from the input string.
 * @param[in]   in_str  String with the fraction in the form of A/B.
 * @param[out]  num     The numerator A.
 * @param[out]  den     The denominator B.
 * @return  0 if the fraction is valid, 1 if denominator is zero.
 */
inline int
fract_t::fract_t::extract_frac (std::string in_str,
                                int& num,
                                int& den)
{
    std::string delim = "/";
    std::string token = in_str.substr(0, in_str.find(delim));
    int ret(0);

    num = stoi(token);

    token = in_str.substr(token.length() + 1, in_str.length());

    den = stoi(token);

    if (0 == num)
    {
        den = 1;
    }

    if (0 == den)
    {
        ret = 1;
    }

    return ret;
}   /* fract_t::fract_t::extract_frac() */


/*** End of file ***/
