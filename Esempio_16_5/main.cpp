/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    08/11/2023
 * @brief   Copy a file in another.
 */

#include <iostream>
#include <cstdlib>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifdef __WIN32__
#   include <io.h>
#else /* __WIN32__ */
#   include <unistd.h>
#endif /* __WIN32__ */

const int g_buffer_size(16 * 1024);

/**
 * @brief   Main function
 * @par     Description
 * Usage: copy <from> <to> where <from> is the input file, while <to> is the
 * output file.
 * @return  Always 0 (success).
 */
int
main (int argc, char * argv[])
{
    char buffer[g_buffer_size]{0};
    int in_file = 0;
    int out_file = 0;
    int read_size = 0;

    if (4 != argc)
    {
        std::cerr << "Error: wrong number of arguments\n";
        std::cerr << "Usage is: copy <from> <to>\n";
        exit(EXIT_FAILURE);
    }

    in_file = open(argv[2], O_RDONLY);

    if (in_file < 0)
    {
        std::cerr << "Error: unable to open " << argv[2] << '\n';
        exit(EXIT_FAILURE);
    }

    out_file = open(argv[3], O_WRONLY | O_TRUNC | O_CREAT, 0666);

    if (out_file < 0)
    {
        std::cerr << "Error: unable to open " << argv[3] << '\n';
        exit(EXIT_FAILURE);
    }

    while (true)
    {
        read_size = read(in_file, buffer, sizeof(buffer));

        if (0 == read_size)
        {
            break;
        }

        if (read_size < 0)
        {
            std::cerr << "Error: read error\n";
            exit(EXIT_FAILURE);
        }

        write(out_file, buffer, (unsigned int) read_size);
    }

    close(in_file);
    close(out_file);
    
    return 0;
}   /* main() */


/*** End of file ***/
