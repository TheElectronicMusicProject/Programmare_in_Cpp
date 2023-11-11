/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    11/11/2023
 * @brief   The uses a custom memcpy().
 */

#include <iostream>
#include <cstring>
#include <chrono>

void * memcpy_custom(void * p_destination, const void * p_source, size_t num);

struct
{
    char name[40];
    int age;
} person, person_copy;

/**
 * @brief   Main function
 * @par     Description
 * The program tests the custom memcpy_custom().
 * @return  Always 0 (success).
 */
int
main ()
{
    char myname[] = "Pierre de Fermat";
    person.age = 46;

    const auto time_start = std::chrono::steady_clock::now();

    // Copy of the string in the first structure.
    //
    memcpy_custom(person.name, myname, strlen(myname) + 1);

    // Copy of the structure.
    //
    memcpy_custom(person_copy.name, person.name, sizeof(person_copy.name));
    memcpy_custom(&person_copy.age, &person.age, sizeof(person_copy.age));

    const auto time_end = std::chrono::steady_clock::now();

    std::cout << "person_copy: " << person_copy.name << ", " << person_copy.age
              << std::endl;

    const std::chrono::duration<double> elapsed_seconds{time_end - time_start};
    std::cout << "Time required: " << elapsed_seconds.count() << " seconds\n";
    
    return 0;
}   /* main() */

/**
 * @brief       Copies the values of num bytes from the location pointed to by
 *              source directly to the memory block pointed to by destination.
 * @param[out]  p_destination Pointer to the destination array where the
 *                            content is to be copied, type-casted to a pointer
 *                            of type void*.
 * @param[in]  p_source       Pointer to the source of data to be copied,
 *                            type-casted to a pointer of type const void*.
 * @param[in]  num            Number of bytes to copy.
 * @return     p_destination is returned.
 */
void *
memcpy_custom (void * p_destination,
               const void * p_source,
               size_t num)
{
    if ((NULL == p_destination) || (NULL == p_source))
    {
        return NULL;
    }

    unsigned int idx(0);
    char * p_dest = (char *) p_destination;
    const char * p_sour = (char *) p_source;

    for (idx = 0; idx < num; ++idx)
    {
        *(p_dest + idx) = *(p_sour + idx);
    }

    return p_destination;
}   /* memcpy() */


/*** End of file ***/
