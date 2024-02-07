/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    07/02/2024
 * @brief   Test of a template class.
 */

#include <iostream>
#include <cstring>
#include <assert.h>

const int g_stack_size(100);

template<typename kind>
class stack
{
    private:
        int count;
        kind data[g_stack_size];
    public:
        stack ()
        {
            count = 0;
        }   /* stack() */

        kind
        pop ()
        {
            --count;

            assert(count >= 0);
            assert(count < static_cast<int>(sizeof data / sizeof data[0]));

            return (data[count]);
        }   /* pop() */

        void push(const kind item);
        void push(const char * const item);
    
    friend char * strdup(const char * p_str);
};

template<typename kind>
inline void
stack<kind>::push (const kind item)
{
    assert(count >= 0);
    assert(count < static_cast<int>(sizeof data / sizeof data[0]));

    data[count] = item;
    ++count;
}   /* stack<kind>::push () */

// Specialization for `push()` function.
//
template <>
inline void
stack<char * >::push (const char * const item)
{
    assert(count >= 0);
    assert(count < static_cast<int>(sizeof data / sizeof data[0]));

    data[count] = strdup(item);
    ++count;
}   /* stack<char * >::push () */

/**
 * @brief   It has the same behaviour of `strdup()`
 */
char *
strdup (const char * p_str)
{
    size_t slen = std::strlen(p_str);
    char * p_result = (char *) std::malloc(slen + 1);
    
    if (NULL == p_result)
    {
        return NULL;
    }

    memcpy(p_result, p_str, slen + 1);

    return p_result;
}   /* strdup() */

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created class works.
 * @return  Always 0 (success).
 */
int
main ()
{
    stack<int> a_stack;

    for (int idx = 1; idx < 11; ++idx)
    {
        a_stack.push(idx);
    }

    for (int idx = 1; idx < 6; ++idx)
    {
        std::cout << a_stack.pop() << '\n';
    }

    a_stack.push(100);

    for (int idx = 1; idx < 7; ++idx)
    {
        std::cout << a_stack.pop() << '\n';
    }

    return 0;
}   /* main() */


/*** End of file ***/
