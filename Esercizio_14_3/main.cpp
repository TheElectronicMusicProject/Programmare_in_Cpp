/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    18/09/2023
 * @brief   Simple program to manage an unused stack.
 */

#include <iostream>
#include <string>
#include <cstring>

#define STACK_SIZE  (100)

class stack
{
    private:
        static int count;
        static int data[STACK_SIZE];
    public:
        friend class instance;
        stack();
};

class instance
{
    private:
        int current_instance;
        static int n_instance;
        static int block_instance;
    public:
        bool stack_block();
        bool stack_release();
        instance();
};

int stack::count(0);
int stack::data[STACK_SIZE]{0};
int instance::n_instance(0);
int instance::block_instance(-1);

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created class works.
 * @return  Always 0 (success).
 */
int
main ()
{
    instance new_instance1;
    instance new_instance2;
    instance new_instance3;
    stack my_stack;

    std::cout << "Stack bloccato da 1: " << new_instance1.stack_block() << '\n';
    std::cout << "Stack bloccato da 2: " << new_instance2.stack_block() << '\n';
    std::cout << "Stack bloccato da 3: " << new_instance3.stack_block() << '\n';

    std::cout << "Stack rilasciato da 2: " << new_instance2.stack_release() << '\n';
    std::cout << "Stack rilasciato da 1: " << new_instance1.stack_release() << '\n';

    std::cout << "Stack bloccato da 3: " << new_instance3.stack_block() << '\n';
    std::cout << "Stack rilasciato da 3: " << new_instance3.stack_release() << '\n';
    
    return 0;
}   /* main() */

/**
 * @brief   The block of the stack
 * @par     Description
 * This functions blocks the stack when an instance calls this function.
 * @return  true if it correctly blocks the stack, false otherwise.
 */
inline bool
instance::stack_block ()
{
    if (-1 == block_instance)
    {
        block_instance = current_instance;
        return true;
    }
    
    return false;
}   /* instance::stack_block() */

/**
 * @brief   The release of the stack
 * @par     Description
 * This functions releases the stack when the currently active instance calls
 * this function.
 * @return  true if it correctly releases the stack, false otherwise.
 */
inline bool
instance::stack_release ()
{
    if ((0 <= block_instance) && (current_instance == block_instance))
    {
        block_instance = -1;
        return true;
    }
    
    return false;
}   /* instance::stack_release() */

/**
 * @brief   Constructor for class `instance`
 * @par     Description
 * The total counter of active instances (related to the class) is assigned to
 * the `current_instance` variable that is related to the created object.
 * After this operation, `n_instance` is incremented.
 * @return  Always nothing.
 */
instance::instance ()
{
    current_instance = n_instance;
    ++n_instance;
}   /* instance::instance() */

/**
 * @brief   Constructor for class `stack`
 * @par     Description
 * This function does nothing.
 * @return  Always nothing.
 */
stack::stack()
{
    /* Do nothing */
}   /* astack::stack() */


/*** End of file ***/
