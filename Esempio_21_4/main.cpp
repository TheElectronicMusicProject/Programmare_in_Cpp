/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    21/01/2024
 * @brief   Order of calling base and derived classes.
 */

#include <iostream>

class base_class
{
    public:
        base_class ()
        {
            std::cout << "base_class constructor called\n";
        }

        // SPECIAL CASE: it calls before the derived class destructor and after
        // the base class destructor.
        //
        virtual
        ~base_class ()
        {
            std::cout << "base_class destructor called\n";
        }
};

class derived_class: public base_class
{
    public:
        derived_class ()
        {
            std::cout << "derived_class constructor called\n";
        }

        ~derived_class ()
        {
            std::cout << "derived_class destructor called\n";
        }
};

/**
 * @brief   Main function
 * @par     Description
 * The program tests the order in which base and derived classes are called.
 * @return  Always 0 (success).
 */
int
main ()
{
    std::cout << "TEST 1\n";
    derived_class * p_sample1 = new derived_class;

    std::cout << "NOW WE DESTROY IT\n";

    delete p_sample1;
    p_sample1 = NULL;

    std::cout << "TEST 2\n";
    base_class * p_sample2 = new derived_class;

    std::cout << "NOW WE DESTROY IT\n";

    delete p_sample2;
    p_sample2 = NULL;

    return 0;
}   /* main() */


/*** End of file ***/
