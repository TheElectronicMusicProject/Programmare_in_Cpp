/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    31/08/2023
 * @brief   Simple program the taxes applied to a value.
 */

#include <iostream>

/**
 * @brief   Main function
 * @par     Description
 * The program asks for a numeric value and calculates the final value with
 * 8% fee.
 * @return  Always 0 (success).
 */
int
main ()
{
    double money(0.0);
    int temp_money(0);

    while (true)
    {
        std::cout << "Insert the value ";
        std::cin >> money;

        if (money < 0.0)
        {
            break;
        }
        
        money += money * 0.08;

        temp_money = (int) (100.0 * money);
        money = ((float) temp_money) / 100.0;

        std::cout << "With tax = " << money << '\n';
    }

    return 0;
}   /* main() */

/*** End of file ***/
