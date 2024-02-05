/**
 * @file    file_style.cpp
 * @author  Filippo Graziani
 * @date    05/02/2024
 * @brief   Routine serch and open a file.
 * Write a module called `search_open` which receives an array of file names,
 * searches the file and opens it.
 */

#include "search_open.h"
#include <iostream>

void
file_open_t::add_list (std::string& file_name)
{
    linked_list_element * p_new = NULL;

    p_new = new linked_list_element;

    p_new->file_name = file_name;
    p_new->p_next = p_first;

    p_first = p_new;
}   /* file_open_t::add_list() */

void
file_open_t::print ()
{
    linked_list_element * p_current = p_first;

    while (NULL != p_current)
    {
        std::cout << "Element " << p_current->file_name << std::endl;
        p_current = p_current->p_next;
    }
}   /* file_open_t::print() */

bool
file_open_t::search_open (std::string& file_name)
{
    linked_list_element * p_current = NULL;

    p_current = p_first;

    while (NULL != p_current)
    {
        if (p_current->file_name == file_name)
        {
            break;
        }

        p_current = p_current->p_next;
    }

    return (NULL != p_current);
}   /* file_open_t::search_open() */


/*** End of file ***/
