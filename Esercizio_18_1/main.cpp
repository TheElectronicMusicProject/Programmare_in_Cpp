/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    29/12/2023
 * @brief   Test for the class fixed_pt.
 */

#include <iostream>

#define MAX(num_a, num_b)   (((num_a) > (num_b)) ? (num_a) : (num_b))

static unsigned int factorization(unsigned int num,
                                  unsigned int * p_list[2],
                                  unsigned int &p_n_elem);
static bool is_prime_number(unsigned int num);
static void print_factorization(unsigned int * p_array[2], unsigned int size);
static unsigned int mcm(unsigned int num1, unsigned int num2);

/**
 * @brief   Main function
 * @par     Description
 * Test for the class fixed_pt, printing its values.
 * @return  Always 0 (success).
 */
int
main ()
{
    unsigned int val(0);
#if 0
    unsigned int * p_array[2] = {NULL, NULL};
    unsigned int n_elem = 0;
    unsigned int val = 0;

    val = factorization( 15892, p_array, &n_elem);

    if (0 == val)
    {
        print_factorization(p_array, n_elem);
    }
#endif

    val = mcm(8895, 9768);

    std::cout << "MCM(18, 64) = " << val << std::endl;
    
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
static unsigned int
mcm (unsigned int num1, unsigned int num2)
{
    unsigned int * p_arr1[2] = {NULL, NULL};
    unsigned int * p_arr2[2] = {NULL, NULL};
    unsigned int n_elem1(0);
    unsigned int n_elem2(0);
    unsigned int result(1);

    factorization(num1, p_arr1, n_elem1);
    factorization(num2, p_arr2, n_elem2);

    print_factorization(p_arr1, n_elem1);
    print_factorization(p_arr2, n_elem2);

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
}   /* mcm() */

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
static void
print_factorization (unsigned int * p_array[2], unsigned int size)
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
}   /* print_factorization() */

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
static unsigned int
factorization (unsigned int num,
               unsigned int * p_list[2],
               unsigned int &p_n_elem)
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
                        p_list[0] = (unsigned int *) realloc(p_list[0], n_elem * sizeof(unsigned int));

                        if (NULL != p_list[0])
                        {
                            p_list[1] = (unsigned int *) realloc(p_list[1], n_elem * sizeof(unsigned int));

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
}   /* factorization() */

/**
 * @brief   Tells if a number is prime
 * @par     Description
 * The function verifies if the given number is prime.
 * @param[in]   num    The integer number.
 * @return  true if is prime, false otherwise.
 */
static bool
is_prime_number (unsigned int num)
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
}   /* is_prime_number() */


/*** End of file ***/
