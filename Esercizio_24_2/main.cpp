/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    08/02/2024
 * @brief   Create a class template `min` to realize an array with the limits
 *          check.
 */

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cstring>

class error_vect_t
{
    public:
        const std::string what;

        error_vect_t (const std::string& error) : what(error)
        {
            /* Do nothing */
        }   /* error_vect_t() */
};

template<typename kind>
class vect_t
{
    private:
        kind * p_vector;
        const uint32_t fixed_incr_size;
        uint32_t num_elements;
        uint32_t total_vector_size;

    public:
        vect_t () : fixed_incr_size(10)
        {
            num_elements = 0;
            total_vector_size = fixed_incr_size;
            p_vector = (kind *) std::malloc(fixed_incr_size * sizeof(kind));

            if (NULL == p_vector)
            {
                throw error_vect_t("Error: malloc failed"); 
            }
        }   /* vect_t() */

        vect_t (uint32_t n_elem) : fixed_incr_size(10)
        {
            num_elements = 0;
            total_vector_size = n_elem;
            p_vector = (kind *) std::malloc(n_elem * sizeof(kind));

            if (NULL == p_vector)
            {
                throw error_vect_t("Error: malloc failed");
            }
        }   /* vect_t() */

        ~vect_t ()
        {
            std::free(p_vector);
            p_vector = NULL;
        }   /* ~vect_t() */

        void
        add_elem (kind elem)
        {
            if (total_vector_size < num_elements)
            {
                throw error_vect_t("Error: bad number of elements");
            }

            if (total_vector_size == num_elements)
            {
                uint32_t new_length = fixed_incr_size + total_vector_size;
                p_vector = (kind *) std::realloc(p_vector,
                                                 new_length * sizeof(kind));
                
                if (NULL == p_vector)
                {
                    throw error_vect_t("Error: realloc failed");
                }

                total_vector_size = new_length;
            }

            *(p_vector + num_elements) = elem;

            ++num_elements;
        }   /* add_elem() */

        kind print_elem(uint32_t index);
        void del_elem(uint32_t index);
};

template<typename kind>
inline kind
vect_t<kind>::print_elem (uint32_t index)
{
    if (index >= num_elements)
    {
        throw error_vect_t("Error: bad index");
    }

    return (*(p_vector + index));
}   /* vect_t<kind>::print_elem() */

template<>
inline void
vect_t<char *>::add_elem (char * p_elem)
{
    uint32_t elem_len = std::strlen(p_elem) + 1;

    if (total_vector_size < num_elements)
    {
        throw error_vect_t("Error: bad number of elements");
    }

    if (total_vector_size == num_elements)
    {
        uint32_t new_length = fixed_incr_size + total_vector_size;
        p_vector = (char **) std::realloc(p_vector,
                                          new_length * sizeof(char *));
        
        if (NULL == p_vector)
        {
            throw error_vect_t("Error: realloc failed");
        }

        total_vector_size = new_length;
    }

    *(p_vector + num_elements) = (char *) std::malloc(elem_len * sizeof(char));
    
    if (NULL == (p_vector + num_elements))
    {
        throw error_vect_t("Error: string allocation failed");
    }

    memcpy(*(p_vector + num_elements), p_elem, elem_len);

    ++num_elements;
}   /* vect_t<char *>::add_elem() */

template<typename kind>
inline void
vect_t<kind>::del_elem (uint32_t index)
{
    if (index >= num_elements)
    {
        throw error_vect_t("Error: bad index " + std::to_string(index));
    }

    /*std::free(*(p_vector + index));
    *(p_vector + index) = NULL;*/

    for (uint32_t val = index; val < (num_elements - 1); ++val)
    {
        *(p_vector + val) = *(p_vector + val + 1);
    }

    --num_elements;
}   /* vect_t<kind>::del_elem() */

template<>
inline void
vect_t<char * >::del_elem (uint32_t index)
{
    if (index >= num_elements)
    {
        throw error_vect_t("Error: bad index " + std::to_string(index));
    }

    std::free(*(p_vector + index));
    *(p_vector + index) = NULL;

    for (uint32_t val = index; val < (num_elements - 1); ++val)
    {
        *(p_vector + val) = *(p_vector + val + 1);
    }

    --num_elements;
}   /* vect_t<kind>::del_elem() */

template<>
inline char *
vect_t<char *>::print_elem (uint32_t index)
{
    if (index >= num_elements)
    {
        throw error_vect_t("Error: bad index " + std::to_string(index));
    }

    return (*(p_vector + index));
}   /* vect_t<char *>::print_elem() */

template<>
inline
vect_t<char *>::~vect_t ()
{
    for (uint32_t idx; idx < num_elements; ++idx)
    {
        std::free(*(p_vector + idx));
        *(p_vector + idx) = NULL;
    }

    std::free(p_vector);
    p_vector = NULL;
}   /* vect_t<char *>::~vect_t() */

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created template works.
 * @return  Always 0 (success).
 */
int
main ()
{
    try
    {
        vect_t<int> int_array;

        for (uint32_t idx = 0; idx < 100; ++idx)
        {
            int_array.add_elem(idx * 2);
        }

        int_array.del_elem(98);
        int_array.del_elem(3);

        for (uint32_t idx = 0; idx < 98; ++idx)
        {
            std::cout << "Value at " << idx << " is "
                      << int_array.print_elem(idx) << std::endl;
        }

        vect_t<char *> char_pt_array;

        for (uint32_t idx = 0; idx < 100; ++idx)
        {
            std::string in_str = "Hello " + std::to_string(idx);
            char_pt_array.add_elem((char *) in_str.c_str());
        }

        char_pt_array.del_elem(98);
        char_pt_array.del_elem(3);

        for (uint32_t idx = 0; idx < 98; ++idx)
        {
            std::cout << "Value at " << idx << " is "
                      << char_pt_array.print_elem(idx) << std::endl;
        }
    }
    catch (const error_vect_t& err)
    {
        std::cerr << err.what << "\n";
        exit(8);
    }
    catch (...)
    {
        std::cerr << "Unknown error\n";
        exit(8);
    }

    return 0;
}   /* main() */


/*** End of file ***/
