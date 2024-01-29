/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    17/09/2023
 * @brief   Simple program to manage a FIFO queue.
 */

#include <iostream>
#include <cstdlib>

#define STACK_SIZE  (100)

class bound_err
{
    public:
        const std::string what;

        bound_err(const std::string& i_what) : what(i_what)
        {
            /* Do nothing */
        }
};

class stack
{
    private:
        int count;
        int data[STACK_SIZE];
    public:
        stack() : count(0)
        {
            /* Do nothing */
        }

        void push(const int item);
        int pop();
};

static void push_a_lot(stack& test_stack);

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created class works.
 * @return  Always 0 (success).
 */
int
main ()
{
    static stack test_stack;
    
    try
    {
        push_a_lot(test_stack);
    }
    catch(const bound_err& err)
    {
        std::cerr << "Error: bounds exceeded\n";
        std::cerr << "Reason: " << err.what << std::endl;
        exit(8);
    }
    catch(...)
    {
        std::cerr << "Error: unexpected exception occurred\n";
        exit(8);
    }

    return 0;
}   /* main() */

/**
 * @brief   Adds an item to stack
 * @param[in]   item    The value that the user wants to add.
 * @return  Nothing.
 */
inline void
stack::push (const int item)
{
    if ((count < 0) || (count >= (int) (sizeof data / sizeof data[0])))
    {
        std::cerr << "## count = " << count << std::endl;
        throw bound_err("Push overflows stack");
    }

    data[count] = item;
    ++count;
}   /* stack::push() */

/**
 * @brief   Returns the first element in the stack
 * @return  The first element in the stack.
 */
inline int
stack::pop ()
{
    --count;

    if ((count < 0) || (count >= (int) (sizeof data / sizeof data[0])))
    {
        throw bound_err("Pop underflows stack");
    }

    return(data[count]);
}   /* stack::pop() */

/**
 * @brief   Adds too much elements to the stack.
 * @param[in]   test_stack  The class stack.
 * @return  Nothing
 */
static void
push_a_lot (stack& test_stack)
{
    int index(0);

    for (index = 0; index < 5000; ++index)
    {
        test_stack.push(index);
    }
}   /* push_a_lot() */


/*** End of file ***/
