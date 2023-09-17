/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    17/09/2023
 * @brief   Simple program to manage a FIFO queue.
 */

#include <iostream>
#include <cassert>

#define QUEUE_SIZE  (100)

class queue
{
    private:
        int n_items;
        int queue_array[QUEUE_SIZE];
    public:
        void put(int item);
        int get();
        queue();
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
    queue queue_fifo;

    for (int idx = 1; idx < 11; ++idx)
    {
        queue_fifo.put(idx);
    }

    for (int idx = 1; idx < 6; ++idx)
    {
        std::cout << queue_fifo.get() << '\n';
    }

    queue_fifo.put(100);

    for (int idx = 1; idx < 7; ++idx)
    {
        std::cout << queue_fifo.get() << '\n';
    }

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


/*** End of file ***/
