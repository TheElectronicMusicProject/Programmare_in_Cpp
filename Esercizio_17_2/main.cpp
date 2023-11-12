/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    12/11/2023
 * @brief   The program reads a file containing a vector of numbers and sums
 *          its contents.
 */

#include <iostream>
#include <fstream>
#include <chrono>

static int matrix_product(const int * p_matrix1, int row1, int col1,
                          const int * p_matrix2, int row2, int col2,
                          int * p_matrix_out, int rowout, int colout);
static void print_matrix(const int * p_matrix, unsigned int row,
                         unsigned int col);

/**
 * @brief   Main function
 * @par     Description
 * The program opens a file for scanning its elements, copies them in an array,
 * calls a function to sum them (calculating the elapsed time) and write some
 * data in an output file.
 * @return  Always 0 (success).
 */
int
main ()
{

    std::ifstream h_file_mat1("matrix1.dat");

    if (h_file_mat1.fail())
    {
        std::cout << "Error: cannot open matrix1.dat\n";
        exit(EXIT_FAILURE);
    }

    std::ifstream h_file_mat2("matrix2.dat");

    if (h_file_mat2.fail())
    {
        std::cout << "Error: cannot open matrix2.dat\n";
        exit(EXIT_FAILURE);
    }

    int temp(0);
    int row_mat1(0);
    int col_mat1(0);

    h_file_mat1 >> row_mat1;
    h_file_mat1 >> col_mat1;

    int mat1[2][3] = {{1, 0, 2}, {0, 3, -1}};
    int mat2[3][2] = {{4, 1}, {-2, 2}, {0, 3}};
    int mat_prod[2][2] = {0};
    int ret(0);

    print_matrix(mat1[0], 2, 3);
    print_matrix(mat2[0], 3, 2);

    // I could write auto instead of std::chrono::system_clock::time_point.
    //
    const std::chrono::steady_clock::time_point time_start =
                                            std::chrono::steady_clock::now();

    ret = matrix_product(&mat1[0][0], 2, 3, &mat2[0][0], 3, 2,
                         &mat_prod[0][0], 2, 2);

    const std::chrono::steady_clock::time_point time_end =
                                            std::chrono::steady_clock::now();

    // Print the required execution time.
    //
    const std::chrono::duration<double> elapsed_seconds{time_end - time_start};
    std::cout << "Time required: " << elapsed_seconds.count() << " seconds\n";

    if (0 == ret)
    {
        print_matrix(mat_prod[0], 2, 2);
    }

    std::ofstream h_file_out("result.dat");

    if (h_file_out.fail())
    {
        std::cout << "Error: cannot open result.dat\n";
        exit(EXIT_FAILURE);
    }
    
    return 0;
}   /* main() */

/**
 * @brief       Optimized function to sum the elements of an array.
 * @param[in]   p_array Pointer to the first element of the array.
 * @param[in]   size    Size of the array (its number of elements).
 * @return      The sum of all the elements.
 */
static int
matrix_product (const int * p_matrix1, int row1, int col1,
                const int * p_matrix2, int row2, int col2,
                int * p_matrix_out, int rowout, int colout)
{
    int ret = 0;

    if ((rowout != row1) || (colout != col2))
    {
        ret = -1;
    }
    else if (col1 != row2)
    {
        ret = -2;
    }
    else if ((0 == row1) || (0 == col1) || (0 == row2) || (0 == col2) ||
             (0 == rowout) || (0 == colout))
    {
        ret = -3;
    }
    else if ((NULL == p_matrix1) || (NULL == p_matrix2) ||
             (NULL == p_matrix_out))
    {
        ret = -4;
    }
    else
    {
        int idx1(0);
        int idx2(0);
        int idx3(0);
        
        for (idx1 = 0; idx1 < row1; ++idx1)
        {
            for (idx2 = 0; idx2 < col2; ++idx2)
            {
                *(p_matrix_out + col2 * idx1 + idx2) = 0;

                for (idx3 = 0; idx3 < col1; ++idx3)
                {
                    *(p_matrix_out + col2 * idx1 + idx2) +=
                                            *(p_matrix1 + col1 * idx1 + idx3) *
                                            *(p_matrix2 + col2 * idx3 + idx2);
                }
            }
        }

        ret = 0;
    }

    return ret;
}   /* matrix_product() */

static void
print_matrix (const int * p_matrix,
              unsigned int row,
              unsigned int col)
{
    if (NULL == p_matrix)
    {
        std::cerr << "Error: NULL pointer\n";
    }
    else if (0 == row)
    {
        std::cerr << "Error: can't process 0 rows\n";
    }
    else if (0 == col)
    {
        std::cerr << "Error: can't process 0 columns\n";
    }
    else
    {
        std::cout << "The matrix has " << row << " rows and "
                  << col << " columns\n";

        unsigned int idx1(0);
        unsigned int idx2(0);

        for (idx1 = 0; idx1 < row; ++idx1)
        {
            for (idx2 = 0; idx2 < col; ++idx2)
            {
                std::cout << *(p_matrix + col * idx1 + idx2) << '\t';
            }

            std::cout << std::endl;
        }
    }
}   /* print_matrix() */


/*** End of file ***/
