/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    31/08/2023
 * @brief   Simple program to see if a number is prime.
 */

#include <iostream>

/**
 * @brief   Main function
 * @par     Description
 * The program calculates if the inserted number is prime.
 * @return  Always 0 (success).
 */
int
main ()
{
    int num(0);
    int temp_num(0);
    bool b_is_prime(false);

    while (true)
    {
        std::cout << "Insert a number ";
        std::cin >> num;

        if (num <= 0)
        {
            break;
        }

        if ((1 == num) || (2 == num))
        {
            std::cout << num << " is prime\n";
        }
        else
        {
            temp_num = num - 1;
            b_is_prime = false;

            while (0 != (num % temp_num))
            {
                --temp_num;

                if (temp_num <= 1)
                {
                    b_is_prime = true;
                }
            }

            std::cout << num << "is" << (true == b_is_prime ? " prime\n" : " not prime\n");
        }
    }

    return 0;
}   /* main() */

/*** End of file ***/
