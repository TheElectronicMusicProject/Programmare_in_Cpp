/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    20/01/2024
 * @brief   Implementation of a simple stack class, adding a derived class.
 */

#include <iostream>
#include <cstdlib>
#include <cassert>

#define DINAMIC_ALLOC   1

#if 0 == DINAMIC_ALLOC
/**
 * Max stack dimension.
 */
const int g_stack_size(100);
#else
/**
 * Bad but works.
 */
#   define data     p_data
#endif

/**
 * Stack class.
 * Member functions:
 * - `stack()` initializes the stack
 * - `push()` adds an element to the stack
 * - `pop()` removes an element from the stack
 */
class stack
{
#if 0 == DINAMIC_ALLOC
    protected:
        long unsigned int count;
        int data[g_stack_size];

    public:
        stack();
        // ~stack() -- default destructor
#else
    private:
        int * p_data;

    protected:
        long unsigned int count;

    public:
        stack (const unsigned int size)
        {
            p_data = new int[size];
            count = 0;
        }

        virtual
        ~stack ()
        {
            delete[] p_data;
            p_data = NULL;
        }
#endif
        // default copy
        void push(const int item);
        int pop();
        void print();
};

#if 0 == DINAMIC_ALLOC
/**
 * @brief   Constructor for class `stack`
 * @par     Description
 * The class variabile `count` is initialized to zero.
 * @return  Always nothing.
 */
inline
stack::stack ()
{
    count = 0;
}   /* stack::stack() */
#endif

/**
 * @brief   Adds an element to the stack.
 * @warning Automatic size overflow check.
 * @param[in]   item    Element to be inserted in the stack.
 * @return  Nothing.
 */
inline void
stack::push (const int item)
{
#if 0 == DINAMIC_ALLOC
    assert((count >= 0) && (count < (sizeof data / sizeof data[0])));
    data[count] = item;
#else
    p_data[count] = item;
#endif
    ++count;
}   /* stack::push() */

/**
 * @brief   Removes an element from the stack.
 * @warning It doesn't check the overflow.
 * @return  The element at the top of the stack
 */
inline int
stack::pop ()
{
    --count;
#if 0 == DINAMIC_ALLOC
    assert((count >= 0) && (count < (sizeof data / sizeof data[0])));
    
    return (data[count]);
#else
    return (p_data[count]);
#endif
}   /* stack::pop() */

/**
 * @brief   Removes an element from the stack.
 * @warning It doesn't check the overflow.
 * @return  The element at the top of the stack
 */
inline void
stack::print ()
{
    long unsigned int index(0);

    for (index = 0; index < count; ++index)
    {
        assert(index >= 0);
#if 0 == DINAMIC_ALLOC
        assert(index < (sizeof data / sizeof data[0]));
#endif
        std::cout << "Element at " << index << " is " << data[index]
                  << std::endl;
    }
}   /* stack::print() */

/**
 * Stack with more elements.
 * Member functions:
 * - `push_three()` adds three elements to the stack
 * - `sum()` sums the value of the elemnts
 */
class m_stack: public stack
{
#if 1 == DINAMIC_ALLOC
    private:
        const unsigned int stack_size;
#endif
    public:
#if 1 == DINAMIC_ALLOC
        m_stack (const unsigned int size) : stack(size),
                                            stack_size(size)
        {
            /* Do nothing */
        }
#else
        // m_stack(); -- default constructor
#endif
        // ~m_stack() -- default destructor
        // default copy
        void push_three(const int item1, const int item2, const int item3);
        int sum();
};

/**
 * @brief   Adds three elements to the stack.
 * @param[in]   item1   The first element to be inserted in the stack.
 * @param[in]   item2   The second element to be inserted in the stack.
 * @param[in]   item3   The third element to be inserted in the stack.
 * @return  Nothing.
 */
inline void
m_stack::push_three (const int item1,
                     const int item2,
                     const int item3)
{
    stack::push(item1);
    stack::push(item2);
    stack::push(item3);
}   /* m_stack::push_three() */

/**
 * @brief   Sums the elements in the stack.
 * @return  The sum of all the elements.
 */
inline int
m_stack::sum ()
{
    long unsigned int index(0);
    int total(0);

    for (index = 0; index < count; ++index)
    {
        assert(index >= 0);
#if 0 == DINAMIC_ALLOC
        assert(index < (sizeof data / sizeof data[0]));

        total += data[index];
#endif
    }

    return total;
}   /* m_stack::sum() */

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created class works.
 * @return  Always 0 (success).
 */
int
main ()
{
#if 0 == DINAMIC_ALLOC
    class m_stack my_three_elem_stack;
#else
    class m_stack my_three_elem_stack(100);
#endif
    my_three_elem_stack.push_three(3, 8, 4);
    my_three_elem_stack.push_three(54, 58, 23);
    my_three_elem_stack.print();
    std::cout << "Sum is " << my_three_elem_stack.sum() << std::endl;

    my_three_elem_stack.pop();
    my_three_elem_stack.print();
    std::cout << "Sum is " << my_three_elem_stack.sum() << std::endl;

    return 0;
}   /* main() */


/*** End of file ***/
