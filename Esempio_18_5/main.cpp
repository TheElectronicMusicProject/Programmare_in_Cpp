/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    13/11/2023
 * @brief   There is an error while using the copy of a class and the =
 *          operator.
 */

#include <iostream>

class trouble
{
    public:
        int data;
        trouble();
        trouble(const trouble& old);
#ifdef NOT_WORKING
        trouble operator = (const trouble old_trouble);
#else
        trouble& operator = (const trouble& old_trouble);
#endif
};

trouble::trouble ()
{
    data = 0;
}   /* trouble::trouble() */

trouble::trouble (const trouble& old)
{
    std::cout << "Copy constructor called\n";

    *this = old;
}   /* trouble::trouble(const trouble& old) */

#ifdef NOT_WORKING
trouble trouble::operator = (const trouble old_trouble)
#else
trouble& trouble::operator = (const trouble& old_trouble)
#endif
{
    std::cout << "Operator = called\n";
    data = old_trouble.data;

    return (*this);
}   /* trouble trouble::operator = (const trouble& old_trouble) */

/**
 * @brief   Main function
 * @par     Description
 * Test to find the error, if NOT_WORKING is defined.
 * @return  Always 0 (success).
 */
int
main ()
{
    trouble trouble1;
    trouble trouble2(trouble1);
    
    return 0;
}   /* main() */


/*** End of file ***/
