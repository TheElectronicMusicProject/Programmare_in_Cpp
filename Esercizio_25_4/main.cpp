/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    12/02/2024
 * @brief   Write a program to count how many times a word is present in a
 *          document.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <map>

class list_words
{
    private:
        std::map<std::string, int32_t> words;

    public:
        uint32_t
        count_words (const std::string& name)
        {
            if (words.find(name) != words.end())
            {
                words[name] += 1;
            }
            else
            {
                words.insert(std::pair<std::string, int32_t>(name, 1));
            }

            return (words[name]);
        }   /* count_words() */

        void
        print_words ()
        {
            std::map<std::string, int32_t>::iterator idx;

            for (idx = words.begin(); idx != words.end(); ++ idx)
            {
                std::cout << idx->first << "\tappears " << idx->second
                          << " times\n";
            }
        }   /* print_words() */
};

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created class/template works.
 * @param[in]   argc    The number of strings pointed by `argv`.
 * @param[in]   argv    Vector of input string commands.
 * @return  Always 0 (success).
 */
int
main (int argc, char * argv[])
{
    if (2 != argc)
    {
        std::cerr << "Usage is: main <filename>\n";
        exit(8);
    }

    std::ifstream h_file(argv[1]);

    if (h_file.bad() || h_file.fail())
    {
        std::cerr << "Error: cannot open " << argv[1] << "\n";
        exit(8);
    }

    class list_words my_list;
    std::string temp_string;

    while (h_file >> temp_string)
    {
        uint32_t idx(0);

        for (idx = 0; idx < temp_string.length(); ++idx)
        {
            if (0 == isalpha(temp_string.at(idx)))
            {
                temp_string.at(idx) = 0;
            }
        }
        my_list.count_words(temp_string);
    }

    my_list.print_words();

    h_file.close();

    return 0;
}   /* main() */


/*** End of file ***/
