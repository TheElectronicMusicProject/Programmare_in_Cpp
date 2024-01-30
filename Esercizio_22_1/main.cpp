/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    30/01/2024
 * @brief   Add to class queue of Esercizio_13_3 the code to enable an
 *          exception wwhen there are too many elements in the queue.
 */

#include <iostream>
#include <string>

#define QUEUE_SIZE  (100)

class bounds_err
{
    public:
        const std::string err_type;

        bounds_err(const std::string& msg) : err_type(msg)
        {
            /* Do nothing */
        }
};

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

    try
    {
        for (int idx = 1; idx < 1000; ++idx)
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
    }
    catch (const bounds_err& err)
    {
        std::cerr << "Bounds exception: " << err.err_type << std::endl;
        exit(8);
    }
    catch (...)
    {
        std::cerr << "Unknown error" << std::endl;
        exit(8);
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

    if (n_items >= QUEUE_SIZE)
    {
        throw bounds_err("You put " + std::to_string(n_items) + " elements " +
                         " in a queue of size " + std::to_string(QUEUE_SIZE));
    }
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

    if (n_items < 0)
    {
        throw bounds_err("You get " + std::to_string(n_items) +
                         " in a queue of size " + std::to_string(QUEUE_SIZE));
    }

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



/*** End of file ***/
