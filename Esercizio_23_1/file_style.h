/**
 * @file    file_style.h
 * @author  Filippo Graziani
 * @date    05/02/2024
 * @brief   Routine to format a file.
 * Create a class to manage the style of the pages, with the following
 * functions:
 * - `open_file(char * name)` to open the file;
 * - `define_header(char * heading)` to define the text header;
 * - `print_line(char * line)` to send a new line;
 * - `page()` to initialize a new page;
 * - `close_file()` to close the file.
 */

#include <fstream>
#include <string>
#include <cstdint>

class file_error_t
{
    public:
        std::string what;
    
        file_error_t (const std::string& err_str) : what(err_str)
        {
            /* Do nothing */
        }

};

class file_style_t
{
    private:
        std::ofstream h_out_file;
        uint8_t file_status;
        uint32_t page_counter;
    public:
        file_style_t();
        ~file_style_t();
        int32_t open_file(char * p_name);
        int32_t define_header(char * p_heading);
        int32_t print_line(char * p_line);
        int32_t page();
        int32_t close_file();
};


/*** End of file ***/
