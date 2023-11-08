/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    08/11/2023
 * @brief   Example of reading a text.
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

/**
 * @brief   Main function
 * @par     Description
 * A test for getting a string from stdin.
 * @return  Always 0 (success).
 */
int
main ()
{
    char name[100]{0};
    std::FILE * p_in_file(NULL);

    std::printf("Name ? ");
    std::fgets(name, sizeof(name), stdin);

    name[std::strlen(name) - 1] = '\0';

    p_in_file = std::fopen(name, "r");

    if (NULL == p_in_file)
    {
        std::fprintf(stderr, "Could not open file %s\n", name);
        exit(EXIT_FAILURE);
    }

    std::printf("File found\n");
    std::fclose(p_in_file);
    
    return 0;
}   /* main() */


/*** End of file ***/
