/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    27/01/2024
 * @brief   Combine the exercises 13-2 and 13-3 to create a class that manages a
 *          cheque book, capable of printing the last 10 elements.
 */

#include <iostream>
#include <cassert>

#define QUEUE_SIZE  (100)

class queue
{
    protected:
        int n_items;
        int queue_array[QUEUE_SIZE];
    public:
        void put(int item);
        int get();
        queue();
};

class check: public queue
{
    private:
        int total_amount;
    public:
        void add_item(int amount);
        int total();
        void print_last_10();
        check();
};

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created class works.
 * @return  Always 0 (success).
 */
int
main ()
{
    check my_cheque_book;

    for (int idx = 1; idx < 11; ++idx)
    {
        my_cheque_book.add_item(idx);
    }
    
    my_cheque_book.print_last_10();

    return 0;
}   /* main() */

/**
 * @brief   Adds an item to queue
 * @par     Description
 * The function inserts the given item `item` in the queue and increments the
 * counter of elements.
 * @param[in]   item    The value that the user wants to add.
 * @return  Nothing.
 */
inline void
queue::put (int item)
{
    queue_array[n_items] = item;
    ++n_items;
    assert(n_items < QUEUE_SIZE);
}   /* queue::put() */

/**
 * @brief   Returns the first element in the queue
 * @par     Description
 * This function first inserted item in the queue.
 * @return  The first element in the queue.
 */
inline int
queue::get ()
{
    int temp_val = queue_array[0];

    --n_items;

    assert(n_items >= 0);

    for (int idx = 0; idx < n_items; ++idx)
    {
        queue_array[idx] = queue_array[idx + 1];
    }

    return temp_val;
}   /* queue::get() */

/**
 * @brief   Constructor for class `queue`
 * @par     Description
 * The class variabile `n_items` is initialized to zero.
 * @return  Always nothing.
 */
queue::queue ()
{
    n_items = 0;
}   /* queue::queue() */

/**
 * @brief   Adds a value to `total_amount`
 * @par     Description
 * The function increments the class variable `total_amount` with the given
 * value `amount`.
 * @param[in]   amount  The amount that the user wants to add to the total.
 * @return  Nothing.
 */
inline void
check::add_item (int amount)
{
    assert(amount >= 0);
    total_amount += amount;
    assert(amount <= INT32_MAX);
    queue::put(amount);
}   /* check::add_item() */

/**
 * @brief   Returns the total amount
 * @par     Description
 * This function returns the value inside `total_amount`.
 * @return  The total value.
 */
inline int
check::total ()
{
    return (total_amount); 
}   /* check::total() */

/**
 * @brief   Constructor for class `check`
 * @par     Description
 * The class variabile `total_amount` is initialized to zero.
 * @return  Always nothing.
 */
check::check ()
{
    total_amount = 0;
}   /* check::check() */

/**
 * @brief   Prints the last 10 elements of the cheque book.
 * @par     Description
 * Print of the last 10 elements of the queue, starting from the most recent one
 * and checking if the number of elements is greater than zero.
 * @return  Nothing.
 */
inline void
check::print_last_10 ()
{
    int idx(0);

    if (0 == n_items)
    {
        std::cout << "Cheque book is empty\n";
    }
    else
    {
        for (idx = 0; idx < 10; ++idx)
        {
            std::cout << queue_array[n_items - 1 - idx] << std::endl;
        }
    }
}   /* check::print_last_10() */


/*** End of file ***/
