/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    07/11/2023
 * @brief   Write on file.
 */

#include <iostream>
#include <cassert>
#include <fstream>
#include <cstring>

/**
 * @brief   Write log message on file
 * @par     Description
 * It writes a message in a log file.
 * It opens the file for output, appending data and writing starting from the
 * end.
 * @param[in]   msg Input string that will be saved on file.
 * @return  Nothing.
 */
static void
log_message (const std::string& msg)
{
    std::ofstream out_file("data.log",
                           std::ios::out | std::ios::app | std::ios::ate);
    
    if (out_file.bad())
    {
        return;
    }

    out_file << msg << std::endl;
}

/**
 * @brief   Main function
 * @par     Description
 * Program to test log_message().
 * @return  Always 0 (success).
 */
int
main ()
{
    log_message("Hello world!\n");
    
    return 0;
}   /* main() */


/*** End of file ***/
