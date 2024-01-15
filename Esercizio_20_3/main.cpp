/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    15/01/2024
 * @brief   Function to delete an element from a double linked list.
 */

#include <iostream>

class double_list
{
    private:
        class double_list_element
        {
            public:
                int data;
            private:
                double_list_element * p_next;
                double_list_element * p_previous;
            
            friend class double_list;
        };
    
    public:
        double_list_element * p_head;
        double_list_element * p_tail;

        double_list ()
        {
            p_head = NULL;
            p_tail = NULL;
        }

        ~double_list ()
        {
            double_list_element * p_temp = NULL;

            while (p_tail != p_head->p_next)
            {
                p_temp = p_head->p_next;
                delete p_head;
                p_head = p_temp;
            }
        }

        void enter(int item);
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
    class double_list my_list;

    my_list.enter(12);
    my_list.enter(32);
    my_list.enter(25);
    std::cout << "Search for 12: " << my_list.find(12) << std::endl;
    std::cout << "Search for 32: " << my_list.find(32) << std::endl;
    std::cout << "Search for 7: " << my_list.find(7) << std::endl;
    std::cout << "Search for 25: " << my_list.find(25) << std::endl;

    std::cout << std::endl;
    my_list.print();

    my_list.remove(25);

    std::cout << std::endl;
    my_list.print();

    return (0);
}   /* main() */

/**
 * @brief       Delete an element at the top of the list.
 * @param[in]   item     The value of the element to be removed.
 * @return      Nothing.
 */
void
double_list::remove (int item)
{
    double_list_element * p_current = p_head;
    double_list_element * p_before = NULL;

    while (NULL != p_current)
    {
        if (item == p_current->data)
        {
            if (p_current == p_head)
            {
                p_head = p_head->p_next;
                p_current->p_next->p_previous = NULL;
            }
            else if (p_current == p_tail)
            {
                p_tail = p_current->p_previous;
                p_current->p_previous->p_next = NULL;
            }
            else
            {
                p_before->p_next = p_current->p_next;
                p_current->p_next->p_previous = p_before;
            }

            delete p_current;
            p_current = NULL;

            break;
        }

        p_before = p_current;
        p_current = p_current->p_next;
    }
}   /* double_list::remove() */

/**
 * @brief       Search for an element in the list.
 * @param[in]   item     The value of the element to be found.
 * @return      `true` if the item is found, `false` otherwise.
 */
bool
double_list::find (int item)
{
    double_list_element * p_current = NULL;

    p_current = p_head;

    while (NULL != p_current)
    {
        if (p_current->data == item)
        {
            break;
        }

        p_current = p_current->p_next;
    }

    return (NULL != p_current);
}   /* double_list::find() */

/**
 * @brief       Print all the elements of the list in order.
 * @return      Nothing.
 */
void
double_list::print ()
{
    double_list_element * p_current = p_head;

    while (NULL != p_current)
    {
        std::cout << "Element " << p_current->data << std::endl;
        p_current = p_current->p_next;
    }
}   /* double_list::print() */

/**
 * @brief       Add an item to **an ordered list**.
 * @param[in]   item     The value of the element to be found.
 * @return      Nothing.
 */
void
double_list::enter (int item)
{
    double_list_element * p_new = new double_list_element;
    p_new->data = item;
    p_new->p_next = NULL;

    if (NULL == p_head)
    {
        p_new->p_previous = NULL;
        p_head = p_new;
        p_tail = p_new;
    }
    else
    {
        p_new->p_previous = p_tail;
        // p_tail is referring to the previous last element, which must be
        // informed that there is a new next element.
        //
        p_tail->p_next = p_new;
        // Now p_tail can refer to the new element.
        //
        p_tail = p_new;
    }

}   /* double_list::enter() */


/*** End of file ***/
