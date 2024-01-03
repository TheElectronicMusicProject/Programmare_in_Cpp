/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    03/01/2024
 * @brief   Class to realize a sparse array of integers. the struct is similar
 *          to a simple array `int simple_array[100]` but indexes can vary from
 *          0 to 1000000. However there can be a maximum of 100 elements
 *          different from zero. The other elements are zero.
 */

#include <iostream>

namespace sparse_t
{
    const int n_col(100);
    const int n_row(2);

    class sparse_t
    {
        public:
            sparse_t ()
            {
                int idx(0);
                size_of_array = 0;

                for (idx = 0; idx < n_col; ++idx)
                {
                    sparse_array[0][idx] = 0;
                    sparse_array[1][idx] = 0;
                }
            }

            sparse_t (const sparse_t& old_arr)
            {
                int idx(0);
                size_of_array = old_arr.size_of_array;

                for (idx = 0; idx < n_col; ++idx)
                {
                    sparse_array[0][idx] = old_arr.sparse_array[0][idx];
                    sparse_array[1][idx] = old_arr.sparse_array[1][idx];
                }
            }

            ~sparse_t()
            {
                int idx(0);
                size_of_array = 0;

                for (idx = 0; idx < n_col; ++idx)
                {
                    sparse_array[0][idx] = 0;
                    sparse_array[1][idx] = 0;
                }
            }

            int
            get_size ()
            {
                return size_of_array;
            }

            bool
            put_elem (int val, int index)
            {
                bool b_ret(true);

                if ((index < 0) || (index > 1000000))
                {
                    std::cerr << "Putting index out of bounds\n";
                    b_ret = false;
                }
                else if (size_of_array < 100)
                {
                    int idx(0);
                    bool b_idx_is_found(false);

                    for (idx = 0; idx < size_of_array; ++idx)
                    {
                        if (index == sparse_array[1][idx])
                        {
                            sparse_array[0][idx] = val;
                            b_idx_is_found = true;
                            break;
                        }
                    }

                    if (false == b_idx_is_found)
                    {
                        ++size_of_array;
                        sparse_array[0][size_of_array - 1] = val;
                        sparse_array[1][size_of_array - 1] = index;
                    }
                }
                else
                {
                    std::cerr << "Maximum number of active elements reached\n";
                    b_ret = false;
                }

                return b_ret;
            }

            bool
            get_elem (int& val, int index) const
            {
                bool b_ret(true);
                val = 0;

                if ((index < 0) || (index > 1000000))
                {
                    std::cerr << "Getting index out of bounds\n";
                    b_ret = false;
                }
                else
                {
                    int idx(0);

                    for (idx = 0; idx < size_of_array; ++idx)
                    {
                        if (index == sparse_array[1][idx])
                        {
                            val = sparse_array[0][idx];
                            break;
                        }
                    }
                }

                return b_ret;
            }

            bool
            del_elem (int index)
            {
                bool b_ret(true);

                if ((index < 0) || (index > 1000000))
                {
                    std::cerr << "Getting index out of bounds\n";
                    b_ret = false;
                }
                else
                {
                    int idx(0);

                    for (idx = 0; idx < size_of_array; ++idx)
                    {
                        if (index == sparse_array[1][idx])
                        {
                            int shift(idx);
                            --size_of_array;

                            for (; shift < size_of_array; ++shift)
                            {
                                sparse_array[0][shift] =
                                                    sparse_array[0][shift + 1];
                                sparse_array[1][shift] =
                                                    sparse_array[1][shift + 1];
                            }

                            break;
                        }
                    }
                }

                return b_ret;
            }

        private:
            int sparse_array[n_row][n_col];
            int size_of_array;
    };
}

/**
 * @brief   Main function
 * @par     Description
 * Test for the class sparse_t, printing its values.
 * @return  Always 0 (success).
 */
int
main ()
{
    sparse_t::sparse_t test_array;
    int num_value(0);
    int num_index(0);

    std::cout << "1 - Array size: " << test_array.get_size() << std::endl;

    num_index = 1000000;
    test_array.put_elem(-2, num_index);

    test_array.get_elem(num_value, num_index);
    std::cout << "2 - value: " << num_value << " at index " << num_index
              << std::endl;

    std::cout << "3 - Array size: " << test_array.get_size() << std::endl;

    test_array.del_elem(num_index);

    std::cout << "4 - Array size: " << test_array.get_size() << std::endl;

    int idx(0);

    for (idx = 0; idx < 1000; ++idx)
    {
        test_array.put_elem(idx + 100, idx);
        test_array.get_elem(num_value, idx);
        std::cout << "Value: " << num_value << " at index " << idx << std::endl;
    }

    std::cout << "5 - Array size: " << test_array.get_size() << std::endl;

    for (idx = 0; idx < 1000; ++idx)
    {
        test_array.del_elem(idx);
        test_array.get_elem(num_value, idx);
        std::cout << "Value: " << num_value << " at index " << idx << std::endl;
    }

    std::cout << "6 - Array size: " << test_array.get_size() << std::endl;

    return (0);
}   /* main() */


/*** End of file ***/
