/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    20/01/2024
 * @brief   How virtual functions work.
 */

#include <iostream>

class base
{
    public:
        void
        a ()
        {
            std::cout << "base::a called\n";
        }

        virtual void
        b ()
        {
            std::cout << "base::b called\n";
        }

        virtual void
        c ()
        {
            std::cout << "base::c called\n";
        }
};

class derived: public base
{
    public:
        void
        a ()
        {
            std::cout << "derived::a called\n";
        }

        void
        b ()
        {
            std::cout << "derived::b called\n";
        }
};

void
do_base (base& a_base)
{
    std::cout << "Call functions in the base class\n";

    a_base.a();
    a_base.b();
    a_base.c();
}

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created class works.
 * @return  Always 0 (success).
 */
int
main ()
{
    derived a_derived;

    std::cout << "Calling functions in the derived class\n";

    a_derived.a();
    a_derived.b();
    a_derived.c();

    do_base(a_derived);

    return 0;
}   /* main() */


/*** End of file ***/
