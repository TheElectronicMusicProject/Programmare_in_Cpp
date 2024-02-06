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

void
lookup_t::enter (const std::string& name)
{
    linked_list_element * p_new(NULL);

    p_new = new linked_list_element;

    if (NULL == p_new)
    {
        throw lookup_error_t("Error: insufficient memory for allocation");
    }

    p_new->file_name = name;
    p_new->p_next = p_first;

    p_first = p_new;
}   /* lookup_t::enter() */

int
lookup_t::lookup (const std::string& name)
{
    int b_ret(0);
    linked_list_element * p_search(p_first);

    while (NULL != p_search)
    {
        if (name == p_search->file_name)
        {
            b_ret = 1;
            break;
        }

        p_search = p_search->p_next;
    }

    return b_ret;
}   /* lookup_t::lookup() */

void
lookup_t::remove (const std::string& name)
{
    linked_list_element * p_current(p_first);
    linked_list_element * p_previous(NULL);

    while (NULL != p_current)
    {
        if (name == p_current->file_name)
        {
            if (p_current == p_first)
            {
                p_first = p_first->p_next;
            }
            else
            {
                p_previous->p_next = p_current->p_next;
            }

            delete p_current;
            p_current = NULL;

            break;
        }

        p_previous = p_current;
        p_current = p_current->p_next;
    }
}   /* lookup_t::remove() */

void
lookup_t::print_all ()
{
    linked_list_element * p_element(p_first);

    while (NULL != p_element)
    {
        if (1 == p_element->file_name.empty())
        {
            throw lookup_error_t("Error: empty value detected");
        }

        std::cout << p_element->file_name << std::endl;
        p_element = p_element->p_next;
    }
}   /* lookup_t::print_all() */


/*** End of file ***/
