/**
 * @file    file_style.h
 * @author  Filippo Graziani
 * @date    05/02/2024
 * @brief   Routine serch and open a file.
 * Write a module called `search_open` which receives an array of file names,
 * searches the file and opens it.
 */

#include <string>
#include <cstdint>

class file_open_t
{
    private:
        class linked_list_element
        {
            public:
                std::string file_name;
            private:
                linked_list_element * p_next;
            
            friend class file_open_t;
        };
    
    public:
        linked_list_element * p_first;

        file_open_t ()
        {
            p_first = NULL;
        }

        ~file_open_t ()
        {
            linked_list_element * p_temp = NULL;

            while (NULL != p_first->p_next)
            {
                p_temp = p_first->p_next;
                delete p_first;
                p_first = p_temp;
            }
        }

        void add_list(std::string& file_name);
        void print();
        bool search_open(std::string& file_name);
};


/*** End of file ***/
