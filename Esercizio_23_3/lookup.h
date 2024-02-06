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

#include <string>

class lookup_t
{
    private:
        class linked_list_element
        {
            public:
                std::string file_name;
            private:
                linked_list_element * p_next;
            
            friend class lookup_t;
        };
    
    public:
        linked_list_element * p_first;

        lookup_t ()
        {
            p_first = NULL;
        }   /* lookup_t() */

        ~lookup_t ()
        {
            linked_list_element * p_temp(NULL);

            while (NULL != p_first->p_next)
            {
                p_temp = p_first->p_next;
                delete p_first;
                p_first = p_temp;
            }
        }   /* ~lookup_t() */

        void enter(const std::string& name);
        int lookup(const std::string& name);
        void remove(const std::string& name);
        void print_all();
};

class lookup_error_t
{
    public:
        const std::string what;

        lookup_error_t(const std::string& msg) : what(msg)
        {
            /* Do nothing */
        }   /* lookup_error_t() */
};


/*** End of file ***/
