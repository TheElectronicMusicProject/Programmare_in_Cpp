/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    13/02/2024
 * @brief   Write a program to create an index of a book. The input file is a
 *          set of page numbers and information concerning the index with the
 *          following form:
 *          <page-number>   <index entry>
 *          To every entry of the index, there will be more records. The output
 *          should be an ordered list of entries like:
 *          alpha  10, 20, 30
 *          beta  5, 6, 18
 *          .....
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <map>
#include <algorithm>

class index_list
{
    private:
        std::map<std::string, std::vector<int32_t>> index;

    public:
        void
        add_index (const std::string& name, int32_t page)
        {
            std::map<std::string, std::vector<int32_t>>::iterator the_word =
                                                            index.find(name);

            if (the_word == index.end())
            {
                // Init the key with a number of elements equal to zero.
                //
                index.insert(std::pair<std::string,
                                       std::vector<int32_t>>(name, 0));
                the_word = index.find(name);
            }

            the_word->second.resize(the_word->second.size() + 1);
            the_word->second[the_word->second.size() - 1] = page;
        }   /* add_index() */

        void
        print_words ()
        {
            // Copy of the vector to a new vector which will be sorted.
            //
            std::vector<std::string> sorted_index;
            std::map<std::string, std::vector<int32_t>>::iterator cur_iterator;

            for (cur_iterator = index.begin(); cur_iterator != index.end();
                 ++cur_iterator)
            {
                sorted_index.push_back(cur_iterator->first);
            }

            std::sort(sorted_index.begin(), sorted_index.end());
            
            // Index to print the elements.
            //
            std::vector<std::string>::const_iterator cur_print;
            
            for (cur_print = sorted_index.begin();
                 cur_print != sorted_index.end();
                 ++cur_print)
            {
                std::vector<std::int32_t> sorted_vect;

                // Index of the vector elements.
                //
                std::vector<int32_t>::const_iterator cur_page;

                for (cur_page = index[*cur_print].begin();
                     cur_page != index[*cur_print].end();
                     ++cur_page)
                {
                    sorted_vect.push_back(*cur_page);
                }
                
                std::cout << *cur_print << "  ";

                // Sort the page numbers.
                //
                std::sort(sorted_vect.begin(), sorted_vect.end());

                for (cur_page = sorted_vect.begin();
                     cur_page != sorted_vect.end();
                     ++cur_page)
                {
                    std::cout << *cur_page;

                    if ((cur_page + 1) != sorted_vect.end())
                    {
                        std::cout << ", ";
                    }
                }

                std::cout << "\n";
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

    class index_list my_index;
    std::string temp_string;
#if 0
    my_index.add_index("ciao", 1);
    my_index.add_index("hello", 10);
    my_index.add_index("ciao", 12);
    my_index.add_index("cane", 59);
    my_index.add_index("ciao", 22);
    my_index.add_index("abba", 1);
#endif

    while (std::getline(h_file, temp_string))
    {
        char temp_name[20]{0};
        int32_t temp_page(0);
        //std::cout << "Line is " << temp_string << std::endl;

        std::sscanf(temp_string.c_str(), "%d\t%s", &temp_page, temp_name);
        my_index.add_index(temp_name, temp_page);
    }

    my_index.print_words();

    h_file.close();

    return 0;
}   /* main() */


/*** End of file ***/
