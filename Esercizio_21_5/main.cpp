/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    29/01/2024
 * @brief   Define a base class `number` to store a single integer value and
 *          to contain the member function `print_it`. Define three derived
 *          classes to print the value in the hexidecimal, octal and decimal
 *          form.
 */

#include <iostream>
#include <string>
#include <stdint.h>

class number
{
    protected:
        int32_t num;
    public:
        number ()
        {
            num = 0;
        }   /* number() */

        number (int32_t in_num)
        {
            num = in_num;
        }   /* number() */

        void
        set (int32_t in_num)
        {
            num = in_num;
        }   /* set() */

        int32_t
        get ()
        {
            return num;
        }   /* get() */

        virtual void print_it() = 0;
};

class decimal: public number
{
    public:
        decimal (int32_t in_num)
        {
            number::set(in_num);
        }   /* decimal() */

        void
        print_it ()
        {
            std::cout << "Stored number is " << std::dec << num << std::endl;
        }   /* print_it() */
};

class octal: public number
{
    public:
        octal (int32_t in_num)
        {
            number::set(in_num);
        }   /* octal() */

        void
        print_it ()
        {
            std::cout << "Stored number is 0" << std::oct << num << std::endl;
        }   /* print_it() */
};

class hexadecimal: public number
{
    public:
        hexadecimal (int32_t in_num)
        {
            number::set(in_num);
        }   /* hexadecimal() */

        void
        print_it ()
        {
            std::cout << "Stored number is 0x" << std::hex << num << std::endl;
        }   /* print_it() */
};

static void print_value(number& in_number);

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created class works.
 * @return  Always 0 (success).
 */
int
main ()
{
    class decimal num1(296);
    class octal num2(785);
    class hexadecimal num3(45);

    print_value(num1);
    print_value(num2);
    print_value(num3);

    return 0;
}   /* main() */

/**
 * @brief   Print of the stored value
 * @par     Description
 * The value stored in the class is printed on the terminal's screen.
 * @param[in]   in_number   The base class for a number.
 * @return  Nothing.
 */
static void
print_value (number& in_number)
{
    return (in_number.print_it());
}   /* print_value() */


/*** End of file ***/
