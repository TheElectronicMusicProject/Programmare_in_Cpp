/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    27/01/2024
 * @brief   Define a base class to search for strings, and define a derived
 *          class that searches for words, numbers, empty strings.
 */

#include <iostream>
#include <cstring>

class string_matcher
{
    private:
        std::string local_string;
    protected:
        string_matcher();
        string_matcher(const char * const p_input);
        int match(const char * const p_match);
    public:
        void put(const char * const p_input);
        std::string& get();
};

class find_item: public string_matcher
{
    public:
        find_item();
        find_item(const char * const p_input);
        bool search_string(const char * const p_input);
        bool search_number(int num);
        bool search_void();
};

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created class works.
 * @return  Always 0 (success).
 */
int
main ()
{
    find_item my_item("Hello world!");

    std::cout << "Test 1 -> " << my_item.search_string("lo w") << std::endl;
    std::cout << "Test 2 -> " << my_item.search_number(2) << std::endl;
    std::cout << "Test 3 -> " << my_item.search_void() << std::endl;


    my_item.put("123456");
    std::cout << "Test 1 -> " << my_item.search_string("lo w") << std::endl;
    std::cout << "Test 2 -> " << my_item.search_number(2) << std::endl;
    std::cout << "Test 3 -> " << my_item.search_void() << std::endl;

    my_item.put("");
    std::cout << "Test 1 -> " << my_item.search_string("lo w") << std::endl;
    std::cout << "Test 2 -> " << my_item.search_number(2) << std::endl;
    std::cout << "Test 3 -> " << my_item.search_void() << std::endl;

    return 0;
}   /* main() */

/**
 * @brief   Constructor for class `string_matcher`
 * @par     Description
 * The class variabile `local_string` is initialized to an empty string.
 * @return  Always nothing.
 */
inline
string_matcher::string_matcher ()
{
    local_string = "";
}   /* string_matcher::string_matcher() */

/**
 * @brief   Constructor for class `string_matcher`
 * @par     Description
 * The class variabile `local_string` is assigned to an input value.
 * @param[in]   p_input The input string.
 * @return  Always nothing.
 */
inline
string_matcher::string_matcher (const char * const p_input)
{
    local_string = p_input;
}   /* string_matcher::string_matcher() */

/**
 * @brief   Assignment of the variable `local_string`
 * @par     Description
 * The class variabile `local_string` is assigned to an input value.
 * @param[in]   p_input The input string.
 * @return  Nothing.
 */
inline void
string_matcher::put (const char * const p_input)
{
    local_string = p_input;
}   /* string_matcher::put() */

/**
 * @brief   Return the variabile `local_string`
 * @return  The variabile `local_string`
 */
inline std::string&
string_matcher::get ()
{
    return (local_string);
}   /* string_matcher::get() */

/**
 * @brief   Search for the match
 * @par     Description
 * The class variabile `local_string` is used as string to be compared with the
 * input.
 * @param[in]   p_match The input string.
 * @return  1 if the substring is found, 0 otherwise.
 */
inline int
string_matcher::match (const char * const p_match)
{
    unsigned int in_len(strlen(p_match));
    unsigned int idx(0);
    unsigned int idx2(0);
    int b_ret(0);

#if DEBUG
    std::cerr << "## in_len = " << in_len << " local_string.length = "
              << local_string.length() << std::endl;
#endif /* DEBUG */

    if (in_len > local_string.length())
    {
        b_ret = 0;
    }
    else
    {
        for (idx = 0; idx < local_string.length(); ++idx)
        {
#if DEBUG
            std::cerr << "## idx = " << idx << " local_string.at(idx) = "
                      << local_string.at(idx) << " p_match[idx2] = "
                      << p_match[idx2] << std::endl;
#endif /* DEBUG */
            if (local_string.at(idx) == p_match[idx2])
            {
                b_ret = 1;
                ++idx2;

                if (in_len == idx2)
                {
                    break;
                }
            }
            else
            {
                // To avoid losing the next character.
                //
                if (0 != idx2)
                {
                    idx -= idx2;
                    idx2 = 0;
                }

                b_ret = 0;
            }
        }
    }

    return (b_ret);
}   /* string_matcher::match() */

/**
 * @brief   Constructor for class `find_item`
 * @par     Description
 * The class variabile `local_string` is initialized to an empty string.
 * @return  Always nothing.
 */
inline
find_item::find_item ()
{
    string_matcher::put("");
}   /* find_item::find_item() */

/**
 * @brief   Constructor for class `string_matcher`
 * @par     Description
 * The class variabile `local_string` is assigned to an input value.
 * @param[in]   p_input The input string.
 * @return  Always nothing.
 */
inline
find_item::find_item (const char * const p_input)
{
    string_matcher::put(p_input);
}   /* find_item::find_item() */

/**
 * @brief   Search for the string match
 * @par     Description
 * The class variabile `local_string` is used as string to be compared with the
 * input string `p_input`.
 * @param[in]   p_input The input string.
 * @return  1 if the substring is found, 0 otherwise.
 */
inline bool
find_item::search_string (const char * const p_input)
{
    bool b_ret(false);

    b_ret = string_matcher::match(p_input);

    return(b_ret);
}   /* find_item::search_string() */

/**
 * @brief   Search for the number match
 * @par     Description
 * The class variabile `local_string` is used as string to be compared with the
 * input number `num`.
 * @param[in]   num     The input number.
 * @return  1 if the number is found, 0 otherwise.
 */
inline bool
find_item::search_number (int num)
{
    bool b_ret(false);
    std::string str_num(std::to_string(num));

    b_ret = string_matcher::match(str_num.c_str());

    return (b_ret);
}   /* find_item::search_number() */

/**
 * @brief   Search for an empty string
 * @par     Description
 * Checks if the class variabile `local_string` is empty.
 * @return  1 if the number is found, 0 otherwise.
 */
inline bool
find_item::search_void ()
{
    bool b_ret(true);
    std::string str = string_matcher::get();

    if (str.length() > 0)
    {
        b_ret = false;
    }

    return (b_ret);
}   /* find_item::search_void() */


/*** End of file ***/
