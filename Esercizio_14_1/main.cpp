/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    18/09/2023
 * @brief   Simple program to check if a file is used by a class or another.
 */

#include <iostream>

class file_mod
{
    private:
        static int b_is_used;
    public:
        static int check_used();
        void use_file();
        void release_file();
        file_mod();
};

int file_mod::b_is_used = 0;

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created class works.
 * @return  Always 0 (success).
 */
int
main ()
{
    file_mod my_file;

    std::cout << "File used? " << file_mod::check_used() << '\n';


    my_file.use_file();

    std::cout << "File used? " << file_mod::check_used() << '\n';


    my_file.release_file();

    file_mod my_new_file;

    std::cout << "File used? " << file_mod::check_used() << '\n';


    my_new_file.use_file();

    std::cout << "File used? " << file_mod::check_used() << '\n';


    my_file.use_file();

    std::cout << "File used? " << file_mod::check_used() << '\n';


    my_new_file.release_file();

    std::cout << "File used? " << file_mod::check_used() << '\n';


    my_file.release_file();

    std::cout << "File used? " << file_mod::check_used() << '\n';
    
    return 0;
}   /* main() */

/**
 * @brief   Manages a right answer
 * @par     Description
 * The element at the top of the list is discarded, and the number of available
 * elements is decreased.
 * @return  Nothing.
 */
inline int
file_mod::check_used ()
{
    return ((0 != b_is_used) ? 1 : 0);
}   /* file_mod::check_used() */

/**
 * @brief   Uses the file
 * @par     Description
 * Uses the used file (by incrementing the static class variable).
 * @attention   Calling this function more than one time per class can show a
 *              used file although it hasn't been used from the other
 *              classes.
 * @return  Nothing.
 */
inline void
file_mod::use_file ()
{
    ++b_is_used;
}   /* file_mod::use_file() */

/**
 * @brief   Releases the file
 * @par     Description
 * Releases the used file (by decrementing the static class variable).
 * @attention   Calling this function more than one time per class can show a
 *              released file although it hasn't been release from the other
 *              classes.
 * @return  Nothing.
 */
inline void
file_mod::release_file ()
{
    if (b_is_used > 0)
    {
        --b_is_used;
    }
}   /* file_mod::release_file() */

/**
 * @brief   Constructor for class `file_mod`
 * @par     Description
 * This function does nothing.
 * @return  Always nothing.
 */
file_mod::file_mod ()
{
    
}   /* file_mod::file_mod() */


/*** End of file ***/
