#include "square.h"
#include "integer.h"

template integer square<integer>(const integer input);

template<class integer>
integer
square (const integer input)
{
    return (input.value * input.value);
}