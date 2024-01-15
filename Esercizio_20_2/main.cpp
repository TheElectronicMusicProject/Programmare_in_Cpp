/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    15/01/2024
 * @brief   Function to delete an element from a linked list.
 */

#include <iostream>

class linked_list
{
    private:
        class linked_list_element
        {
            public:
                int data;
            private:
                linked_list_element * p_next;
            
            friend class linked_list;
        };
    
    public:
        linked_list_element * p_first;

        linked_list ()
        {
            p_first = NULL;
        }

        ~linked_list ()
        {
            linked_list_element * p_temp = NULL;

            while (NULL != p_first->p_next)
            {
                p_temp = p_first->p_next;
                delete p_first;
                p_first = p_temp;
            }
        }

        void add_list(int item);
        void remove(int item);
        bool find(int item);
        void print(void);
};

/**
 * @brief   Main function
 * @par     Description
 * Test for the list example.
 * @return  Always 0 (success).
 */
int
main ()
{
    class linked_list my_list;

    my_list.add_list(12);
    my_list.add_list(32);
    my_list.add_list(25);
    std::cout << "Search for 12: " << my_list.find(12) << std::endl;
    std::cout << "Search for 32: " << my_list.find(32) << std::endl;
    std::cout << "Search for 7: " << my_list.find(7) << std::endl;
    std::cout << "Search for 25: " << my_list.find(25) << std::endl;

    std::cout << std::endl;
    my_list.print();

    my_list.remove(12);

    std::cout << std::endl;
    my_list.print();

    return (0);
}   /* main() */

/**
 * @brief       Add an element at the top of the list.
 * @param[in]   item     The value of the element.
 * @return      Nothing.
 */
void
linked_list::add_list (int item)
{
    linked_list_element * p_new = NULL;

    p_new = new linked_list_element;

    (*p_new).data = item;
    (*p_new).p_next = p_first;

    p_first = p_new;
}   /* linked_list::add_list() */

/**
 * @brief       Delete an element at the top of the list.
 * @param[in]   item     The value of the element to be removed.
 * @return      Nothing.
 */
void
linked_list::remove (int item)
{
    linked_list_element * p_current = p_first;
    linked_list_element * p_previous = NULL;

    while (NULL != p_current)
    {
        if (item == p_current->data)
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
}   /* linked_list::remove() */

/**
 * @brief       Search for an element in the list.
 * @param[in]   item     The value of the element to be found.
 * @return      `true` if the item is found, `false` otherwise.
 */
bool
linked_list::find (int item)
{
    linked_list_element * p_current = NULL;

    p_current = p_first;

    while (NULL != p_current)
    {
        if (p_current->data == item)
        {
            break;
        }

        p_current = p_current->p_next;
    }

    return (NULL != p_current);
}   /* linked_list::find() */

/**
 * @brief       Print all the elements of the list in order.
 * @return      Nothing.
 */
void
linked_list::print ()
{
    linked_list_element * p_current = p_first;

    while (NULL != p_current)
    {
        std::cout << "Element " << p_current->data << std::endl;
        p_current = p_current->p_next;
    }
}   /* linked_list::print() */


/*** End of file ***/
