/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    12/11/2023
 * @brief   The program reads two files containing 2 matrices and writes the
 *          result of the product of the two elements in a newly created file.
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
 * The program opens two files, matrix1.dat and matrix2.dat, to read the input
 * matrices.
 * The file must have the following format:
 * 
 * n_rows n_cols
 * elem(0) elem(1) elem(2) ... elem(n_rows - 1 * n_cols - 1)
 * 
 * Then the product of the matrices is calculated and the resulting matrix is
 * printed in the file result.dat with the same format of the input files.
 * The elapsed time is printed.
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

    // Process matrix #1.
    //
    int row_mat1(0);
    int col_mat1(0);

    h_file_mat1 >> row_mat1;
    h_file_mat1 >> col_mat1;

    int mat1[row_mat1][col_mat1];

    for (int idx_r = 0; idx_r < row_mat1; ++idx_r)
    {
        for (int idx_c = 0; idx_c < col_mat1; ++idx_c)
        {
            h_file_mat1 >> mat1[idx_r][idx_c];
        }
    }

    print_matrix(mat1[0], row_mat1, col_mat1);

    // Process matrix #2.
    //
    int row_mat2(0);
    int col_mat2(0);

    h_file_mat2 >> row_mat2;
    h_file_mat2 >> col_mat2;

    int mat2[row_mat2][col_mat2];

    for (int idx_r = 0; idx_r < row_mat2; ++idx_r)
    {
        for (int idx_c = 0; idx_c < col_mat2; ++idx_c)
        {
            h_file_mat2 >> mat2[idx_r][idx_c];
        }
    }

    print_matrix(mat2[0], row_mat2, col_mat2);

    // Output matrix.
    //
    int mat_prod[row_mat1][col_mat2] = {0};

    // I could write auto instead of std::chrono::system_clock::time_point.
    //
    const std::chrono::steady_clock::time_point time_start =
                                            std::chrono::steady_clock::now();

    int ret = matrix_product(&mat1[0][0], row_mat1, col_mat1,
                             &mat2[0][0], row_mat2, col_mat2,
                             &mat_prod[0][0], row_mat1, col_mat2);

    const std::chrono::steady_clock::time_point time_end =
                                            std::chrono::steady_clock::now();

    // Print the required execution time.
    //
    const std::chrono::duration<double> elapsed_seconds{time_end - time_start};
    std::cout << "Time required: " << elapsed_seconds.count() << " seconds\n";

    if (0 == ret)
    {
        print_matrix(mat_prod[0], row_mat1, col_mat2);
    }
    else
    {
        std::cerr << "Error! Value returned: " << ret << std::endl;
    }

    std::ofstream h_file_out("result.dat", std::ios::out);

    if (h_file_out.fail())
    {
        std::cout << "Error: cannot open result.dat\n";
        exit(EXIT_FAILURE);
    }

    // Parse output matrix.
    //
    h_file_out << row_mat1 << ' ';
    h_file_out << col_mat2 << ' ' << std::endl;

    for (int idx_r = 0; idx_r < row_mat1; ++idx_r)
    {
        for (int idx_c = 0; idx_c < col_mat2; ++idx_c)
        {
            h_file_out << mat_prod[idx_r][idx_c] << ' ';
        }
    }

    h_file_mat1.close();
    h_file_mat2.close();
    h_file_out.close();
    
    return 0;
}   /* main() */

/**
 * @brief       Calculates the product between two matrices.
 * @param[in]   p_matrix1       Pointer to the first matrix.
 * @param[in]   row1            Number of rows of the first matrix.
 * @param[in]   col1            Number of columns of the first matrix.
 * @param[in]   p_matrix2       Pointer to the second matrix.
 * @param[in]   row2            Number of rows of the second matrix.
 * @param[in]   col2            Number of columns of the second matrix.
 * @param[out]  p_matrix_out    Pointer to the ouput matrix.
 * @param[in]   rowout          Number of rows of the ouput matrix.
 * @param[in]   colout          Number of columns of the ouput matrix.
 * @return      The function returns: 0 in case of success, -1 if the number of
 *              elements of the ouput matrix are incoherent, -2 if the number
 *              of elements of the input matrices are incoherent, -3 if the
 *              number of elements of one of the matrices are 0, -4 if one of
 *              the matrices is a NULL pointer.
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
        
        // Scanning of rows of first matrix.
        //
        for (idx1 = 0; idx1 < row1; ++idx1)
        {
            // Scannig of columns of second matrix.
            //
            for (idx2 = 0; idx2 < col2; ++idx2)
            {
                *(p_matrix_out + col2 * idx1 + idx2) = 0;

                // Fixing the row of the first matrix and the column of the
                // second one, moves the columns of the first and the rows of
                // the second, permitting the product.
                //
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

/**
 * @brief       Prints the elements of the input matrix.
 * @param[in]   p_matrix    Pointer to the matrix.
 * @param[in]   row         Number of rows of the matrix.
 * @param[in]   col         Number of columns of the matrix.
 * @return      Nothing.
 */
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
