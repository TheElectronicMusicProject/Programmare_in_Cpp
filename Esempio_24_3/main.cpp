#include "square.h"
#include "integer.h"
#include <iostream>

int
main ()
{
    integer test(5);

    integer test2 = square(test);

    std::cout << "Input is " << test.value << " and output is " << test2.value
              << std::endl;
}