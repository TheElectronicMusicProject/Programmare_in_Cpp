/**
 * @file    file_style.cpp
 * @author  Filippo Graziani
 * @date    06/02/2024
 * @brief   Create a lookup table.
 * Write a class for a lookup table that contains the funcions:
 * - `void enter(const std::string& name)` inserts a name in the table;
 * - `int lookup(const std::string& name)` returns 1 if the name is in the table
 * and 0 otherwise;
 * - `void remove(const std::string& name)` removes the name from the table.
 */

#include "lookup.h"
#include <iostream>

int
main ()
{
    lookup_t table;

    try
    {
        table.enter("Hello");
        table.enter("World");
        table.enter("My");
        table.enter("Name");
        table.enter("Is");
        table.enter("Pedro");
        
        std::cout << "The word 'Is' is " << table.lookup("Is") << std::endl;
        
        table.remove("Pedro");
        table.enter("Filippo");

        table.print_all();
    }
    catch (const lookup_error_t& err)
    {
        std::cerr << err.what << '\n';
    }
    catch (...)
    {
        std::cerr << "Unknown error\n";
    }

    return (0);
}   /* main() */


/*** End of file ***/
