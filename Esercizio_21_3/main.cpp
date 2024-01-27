/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    27/01/2024
 * @brief   Define a base class that describes every siple figure, i.e. square,
 *          circle, triangle.
 *          Define a derive class for each figure.
 */

#include <iostream>
#include <math.h>
#include <cassert>

class shape
{
    private:
        double dim;
    protected:
        void
        set_dim (double val)
        {
            dim = val;
        }   /* set_dim() */

        double
        get_dim ()
        {
            return (dim);
        }   /* get_dim() */
    public:
        shape ()
        {
            dim = 0;
        }   /* shape() */

        shape (double val)
        {
            dim = val;
        }   /* shape() */

        virtual double area() = 0;
};

class square: public shape
{
    public:
        square (double side)
        {
            shape::set_dim(side);
        }   /* square() */

        double
        area ()
        {
            return (shape::get_dim() * shape::get_dim());
        }   /* area() */
};

class triangle: public shape
{
    public:
        triangle (double side)
        {
            shape::set_dim(side);
        }   /* triangle() */

        double
        area ()
        {
            return (shape::get_dim() *
                    sqrt((shape::get_dim() * shape::get_dim()) -
                         (shape::get_dim() / 2.0 * shape::get_dim() / 2.0))
                    / 2.0);
        }   /* area() */
};

class circle: public shape
{
    public:
        circle (double radius)
        {
            shape::set_dim(radius);
        }   /* circle() */

        double
        area ()
        {
            return (3.14159 * shape::get_dim() * shape::get_dim());
        }   /* area() */
};

static double find_area(shape& in_shape);

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created class works.
 * @return  Always 0 (success).
 */
int
main ()
{
    class circle first_shape(2.0);
    class square second_shape(1.25);
    class triangle third_shape(12.59);

    std::cout << "Circle area -> " << find_area(first_shape) << std::endl;
    std::cout << "Square area -> " << find_area(second_shape) << std::endl;
    std::cout << "Triangle area -> " << find_area(third_shape) << std::endl;

    return 0;
}   /* main() */

/**
 * @brief   Area caluclation
 * @par     Description
 * The area of the given shape will be returned.
 * @param[in]   in_shape    The base class for a shape.
 * @return  The area.
 */
static double
find_area (shape& in_shape)
{
    return (in_shape.area());
}   /* find_area() */


/*** End of file ***/
