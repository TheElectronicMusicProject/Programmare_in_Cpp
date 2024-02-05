/**
 * @file    file_style.cpp
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
#include <cstring>
#include <istream>

file_style_t::file_style_t ()
{
    file_status = 0;
    page_counter = 0;
}   /* file_style_t::file_style_t() */

file_style_t::~file_style_t ()
{
    if (1 == file_status)
    {
        file_status = 0;
        h_out_file.close();
    }
}   /* file_style_t::~file_style_t() */

int32_t
file_style_t::open_file (char * p_name)
{
    int32_t ret(0);

    h_out_file.open(p_name, std::ios::out | std::ios::binary);

    if (h_out_file.bad() || h_out_file.fail())
    {
        throw file_error_t("Error: cannot open the file");
        ret = 1;
    }
    else
    {
        file_status = 1;
    }

    return ret;
}   /* file_style_t::open_file() */

int32_t
file_style_t::define_header (char * p_heading)
{
    if (0 != page_counter)
    {
        page();
    }

    print_line(p_heading);
    page();

    return 0;
}   /* file_style_t::define_header() */

int32_t
file_style_t::print_line (char * p_line)
{
    uint32_t idx(0);

    for (idx = 0; idx < strlen(p_line); ++idx)
    {
        h_out_file.put(p_line[idx]);
    }

    h_out_file.put('\n');

    return 0;
}   /* file_style_t::print_line() */

int32_t
file_style_t::page ()
{
    ++page_counter;
    h_out_file.put('\f');

    return 0;
}   /* file_style_t::page() */

int32_t
file_style_t::close_file ()
{
    file_status = 0;

    h_out_file.close();

    return 0;
}   /* file_style_t::close_file() */


/*** End of file ***/
