/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    11/01/2024
 * @brief   Example of a list.
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

        void add_list(int item);
        bool find(int item);
        void enter(int item);
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
    my_list.enter(25);
    std::cout << "Search for 12: " << my_list.find(12) << std::endl;
    std::cout << "Search for 32: " << my_list.find(32) << std::endl;
    std::cout << "Search for 7: " << my_list.find(7) << std::endl;
    std::cout << "Search for 25: " << my_list.find(25) << std::endl;

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
 * @brief       Add an item to **an ordered list**.
 * @param[in]   item     The value of the element to be found.
 * @return      Nothing.
 */
void
linked_list::enter (int item)
{
    linked_list_element * p_before = NULL;
    linked_list_element * p_after = NULL;

    p_after = p_first;

    while ((NULL != p_after) && (item < p_after->data))
    {
        p_before = p_after;
        p_after = p_after->p_next;
    }

    linked_list_element * p_new = new linked_list_element;
    p_new->data = item;

    p_before->p_next = p_new;
    p_new->p_next = p_after;
}   /* linked_list::enter() */


/*** End of file ***/
