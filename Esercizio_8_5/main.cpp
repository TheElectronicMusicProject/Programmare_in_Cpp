/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    30/08/2023
 * @brief   Simple program to detect a letter.
 */

#include <iostream>
#include <cassert>

/**
 * @brief   Main function
 * @par     Description
 * The program detects if the inserted letter is a vowel or a consonant.
 * @return  Always 0 (success).
 */
int
main ()
{
    char letter(0);

    while (true)
    {
        std::cout << "Insert a letter: ";
        std::cin >> letter;

        if ('%' == letter)
        {
            std::cout << "Thank you for using this tool\n";
            break;
        }

        if (((letter >= 0x41) && (letter <= 0x5A)) ||
            ((letter >= 0x61) && (letter <= 0x7A)))
        {
            if ((0x41 == letter) || (0x45 == letter) ||
                (0x49 == letter) || (0x4F == letter) ||
                (0x55 == letter) || (0x61 == letter) ||
                (0x65 == letter) || (0x69 == letter) ||
                (0x6F == letter) || (0x75 == letter))
            {
                std::cout << "The letter is a vowel\n";
            }
            else
            {
                std::cout << "The letter is a consonant\n";
            }
        }
        else
        {
            std::cout << "Not a letter!\n";
        }
    }

    return 0;
}   /* main() */

/*** End of file ***/
