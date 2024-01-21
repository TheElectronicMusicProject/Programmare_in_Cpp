/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    21/01/2024
 * @brief   Correct a bug.
 */

#include <iostream>
#include <cstdlib>

#define CORRECTION

class list
{
    private:
        int item;

    public:
        virtual void
        clear () = 0;

        void
        next_item ()
        {
            ++item;
        }

        list ()
        {
            item = 0;
        }

        virtual
        ~list ()
        {
#ifndef CORRECTION
            clear();
#endif
        }
};

class list_of_integers: public list
{
    public:
        int array[100];

#ifdef CORRECTION
        ~list_of_integers ()
        {
            clear ();
        }
#endif

        void
        clear ()
        {
            int idx(0);

            for (idx = 0; idx < 100; ++idx)
            {
                array[idx] = 0;
            }
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
    list_of_integers * p_list = new list_of_integers;

    // Problems.
    //
    delete p_list;
    p_list = NULL;

    return 0;
}   /* main() */


/*** End of file ***/
