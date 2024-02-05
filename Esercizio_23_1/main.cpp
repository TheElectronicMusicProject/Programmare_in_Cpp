/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    05/02/2024
 * @brief   Routine to format a file.
 * Create a class to manage the style of the pages, with the following
 * functions:
 * - `open_file(char * name)` to open the file;
 * - `define_header(char * heading)` to define the text header;
 * - `print_line(char * line)` to send a new line;
 * - `page()` to initialize a new page;
 * - `close_file()` to close the file.
 */

#include "file_style.h"
#include <iostream>
#include <cstring>

int
main (int argc, char * argv[])
{
    file_style_t my_file;
    char message[30] = {0};

    if (3 != argc)
    {
        std::cerr << "Error: wrong number of arguments\n";
        std::cerr << "Usage is\n";
        std::cerr << "\tmain <data-file> <title>\n";
        exit(8);
    }

    try
    {
        my_file.open_file(argv[1]);
    }
    catch (const file_error_t& err)
    {
        std::cerr << err.what << '\n';
        exit(8);
    }
    catch (...)
    {
        std::cerr << "Unknown error\n";
        exit(8);
    }
    
    my_file.define_header(argv[2]);
    strncpy(message, "Hello world!", sizeof(message) - 1);
    my_file.print_line(message);
    strncpy(message, "this is page 1", sizeof(message) - 1);
    my_file.print_line(message);
    my_file.page();
    strncpy(message, "this is the second page", sizeof(message) - 1);
    my_file.print_line(message);
    my_file.define_header(argv[2]);
    my_file.close_file();

    return (0);
}   /* main() */


/*** End of file ***/
