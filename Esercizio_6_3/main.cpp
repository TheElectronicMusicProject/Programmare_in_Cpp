/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    26/08/2023
 * @brief   Simple program to calculate the number of cents needed.
 */

#include <iostream>

/**
 * @brief   Main function
 * @par     Description
 * The program prints number of cents needed to reach the given amount of cents.
 * @return  Always 0 (success).
 */
int
main ()
{
    int money(0);
    int money_fifty(0);
    int money_twenty(0);
    int money_ten(0);
    int money_five(0);
    int money_two(0);
    int money_one(0);

    while (true)
    {
        std::cout << "Write your amount in cents: ";
        std::cin >> money;

        if (money < 0)
        {
            break;
        }

        money_fifty = money / 50;
        money -= money_fifty * 50;

        money_twenty = money / 20;
        money -= money_twenty * 20;

        money_ten = money / 10;
        money -= money_ten * 10;

        money_five = money / 5;
        money -= money_five * 5;

        money_two = money / 2;
        money -= money_two * 2;

        money_one = money;

        std::cout << "You need " << money_fifty << " of 50 cents, "
                  << money_twenty << " of 20 cents, "
                  << money_ten << " of 10 cents, "
                  << money_five << " of 5 cents, "
                  << money_two << " of 2 cents, "
                  << money_one << " of 1 cents\n";
    }

    return 0;
}   /* main() */

/*** End of file ***/
