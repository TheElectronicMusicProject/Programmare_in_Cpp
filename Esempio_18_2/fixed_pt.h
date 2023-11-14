/**
 * @file    fixed_pt.h
 * @author  Filippo Graziani
 * @date    13/11/2023
 * @brief   Fixed point class.
 */

#ifndef FIXED_PT_H
#   define FIXED_PT_H

#   include <iostream>
#   include <assert.h>
#   include <stdlib.h>

namespace fixed_pt
{
    /**
     * 10**fixed_point.
     */
    const int fixed_exp = 100;

    /**
     * To convert from double to fixed point.
     */
    const double fixed_fudge_factor = 0.0001;

    class fixed_pt
    {
        private:
            /**
             * Fixed point numeric value.
             */
            long int value;

            /**
             * Construction of a fixed point fixed_pt by using a double number.
             */
            static long int
            double_to_fp (const double the_double)
            {
                return (static_cast<long int>(the_double *
                                              static_cast<double>(fixed_exp) +
                                              fixed_fudge_factor));
            }   /* double_to_fp() */

        public:
            /**
             * Default constructor.
             */
            fixed_pt (): value(0)
            {
                /* Do nothing. */
            }   /* fixed_pt() */

            /**
             * Copy constructor.
             */
            fixed_pt (const fixed_pt& other_fixed_pt) :
                                                value(other_fixed_pt.value)
            {
                /* Do nothing. */
            }   /* fixed_pt() */

            /**
             * Creates a fixed_pt by using a double (constructor).
             */
            fixed_pt (const double init_real) : value(double_to_fp(init_real))
            {
                /* Do nothing. */
            }   /* fixed_pt() */

            /**
             * Destructor won't do anything.
             */
            ~fixed_pt ()
            {
                /* Do nothing. */
            }   /* ~fixed_pt() */

            /**
             * Function to set the number.
             */
            void
            set (const double real)
            {
                value = double_to_fp(real);
            }   /* set() */

            /**
             * Function to get the number.
             */
            double
            get () const
            {
                return (static_cast<double>(value) / fixed_exp);
            }   /* get() */

            /**
             * Operator =.
             */
            fixed_pt
            operator = (const fixed_pt& oper2)
            {
                value = oper2.value;

                return (*this);
            }   /* operator = () */

            /**
             * Operator +=.
             */
            fixed_pt&
            operator += (const fixed_pt& oper2)
            {
                value += oper2.value;

                return (*this);
            }   /* operator += () */

            /**
             * Operator +=.
             */
            fixed_pt&
            operator += (double oper2)
            {
                value += double_to_fp(oper2);

                return (*this);
            }   /* operator += () */

            /**
             * Operator -=.
             */
            fixed_pt&
            operator -= (const fixed_pt& oper2)
            {
                value -= oper2.value;

                return (*this);
            }   /* operator -= () */

            /**
             * Operator -=.
             */
            fixed_pt&
            operator -= (double oper2)
            {
                value -= double_to_fp(oper2);

                return (*this);
            }   /* operator -= () */

            /**
             * Operator *=.
             */
            fixed_pt&
            operator *= (const fixed_pt& oper2)
            {
                value *= oper2.value;
                value /= fixed_exp;

                return (*this);
            }   /* operator *= () */

            /**
             * Operator *=.
             */
            fixed_pt&
            operator *= (double oper2)
            {
                value *= double_to_fp(oper2);
                value /= fixed_exp;

                return (*this);
            }   /* operator *= () */

            /**
             * Operator /=.
             */
            fixed_pt&
            operator /= (const fixed_pt& oper2)
            {
                assert(0 != oper2.value);
                value /= oper2.value;
                value *= fixed_exp;

                return (*this);
            }   /* operator /= () */

            /**
             * Operator /=.
             */
            fixed_pt&
            operator /= (double oper2)
            {
                assert(0.0 != double_to_fp(oper2));
                value /= double_to_fp(oper2);
                value *= fixed_exp;

                return (*this);
            }   /* operator /= () */

            /**
             * Operator f++.
             */
            fixed_pt
            operator ++ (int)
            {
                fixed_pt result(*this);
                value += fixed_exp;

                return (result);
            }   /* operator ++ () */

            /**
             * Operator ++f.
             */
            fixed_pt&
            operator ++ ()
            {
                value += fixed_exp;

                return (*this);
            }   /* operator ++ () */

            /**
             * Operator f--.
             */
            fixed_pt
            operator -- (int)
            {
                fixed_pt result(*this);
                value -= fixed_exp;

                return (result);
            }   /* operator -- () */

            /**
             * Operator --f.
             */
            fixed_pt&
            operator -- ()
            {
                value -= fixed_exp;

                return (*this);
            }   /* operator -- () */

        private:
            fixed_pt (const long int i_value) : value(i_value)
            {
                /* Do nothing. */
            }   /* fixed_pt() */

            friend fixed_pt operator + (const fixed_pt& oper1,
                                        const fixed_pt& oper2);
            friend fixed_pt operator + (const fixed_pt& oper1,
                                        const double oper2);
            friend fixed_pt operator + (const double oper1,
                                        const fixed_pt& oper2);

            friend fixed_pt operator - (const fixed_pt& oper1,
                                        const fixed_pt& oper2);
            friend fixed_pt operator - (const fixed_pt& oper1,
                                        const double oper2);
            friend fixed_pt operator - (const double oper1,
                                        const fixed_pt& oper2);

            friend fixed_pt operator * (const fixed_pt& oper1,
                                        const fixed_pt& oper2);
            friend fixed_pt operator * (const fixed_pt& oper1,
                                        const double oper2);
            friend fixed_pt operator * (const double oper1,
                                        const fixed_pt& oper2);

            friend fixed_pt operator / (const fixed_pt& oper1,
                                        const fixed_pt& oper2);
            friend fixed_pt operator / (const fixed_pt& oper1,
                                        const double oper2);
            friend fixed_pt operator / (const double oper1,
                                        const fixed_pt& oper2);

            friend bool operator == (const fixed_pt& oper1,
                                     const fixed_pt& oper2);
            friend bool operator != (const fixed_pt& oper1,
                                     const fixed_pt& oper2);
            friend fixed_pt operator - (const fixed_pt& oper1);
            friend fixed_pt operator + (const fixed_pt& oper1);
            friend std::ostream& operator << (std::ostream& out_file,
                                              const fixed_pt& number);
            friend std::istream& operator >> (std::istream& out_file,
                                              fixed_pt& number);
    };

    inline fixed_pt
    operator + (const fixed_pt& oper1,
                const fixed_pt& oper2)
    {
        return fixed_pt(oper1.value + oper2.value);
    }   /* operator + () */

    inline fixed_pt
    operator + (const fixed_pt& oper1,
                const double oper2)
    {
        return fixed_pt(oper1.value + fixed_pt::double_to_fp(oper2));
    }   /* operator + () */

    inline fixed_pt
    operator + (const double oper1,
                const fixed_pt& oper2)
    {
        return fixed_pt(fixed_pt::double_to_fp(oper1) + oper2.value);
    }   /* operator + () */

    inline fixed_pt
    operator - (const fixed_pt& oper1,
                const fixed_pt& oper2)
    {
        return fixed_pt(oper1.value - oper2.value);
    }   /* operator - () */

    inline fixed_pt
    operator - (const fixed_pt& oper1,
                const double oper2)
    {
        return fixed_pt(oper1.value - fixed_pt::double_to_fp(oper2));
    }   /* operator - () */

    inline fixed_pt
    operator - (const double oper1,
                const fixed_pt& oper2)
    {
        return fixed_pt(fixed_pt::double_to_fp(oper1) - oper2.value);
    }   /* operator - () */

    inline fixed_pt
    operator * (const fixed_pt& oper1,
                const fixed_pt& oper2)
    {
        return fixed_pt(oper1.value * oper2.value / fixed_exp);
    }   /* operator * () */

    inline fixed_pt
    operator * (const fixed_pt& oper1,
                const double oper2)
    {
        return fixed_pt(oper1.value * fixed_pt::double_to_fp(oper2) /
                        fixed_exp);
    }   /* operator * () */

    inline fixed_pt
    operator * (const double oper1,
                const fixed_pt& oper2)
    {
        return fixed_pt(fixed_pt::double_to_fp(oper1) * oper2.value /
                        fixed_exp);
    }   /* operator * () */

    inline fixed_pt
    operator / (const fixed_pt& oper1,
                const fixed_pt& oper2)
    {
        assert(0 != oper2.value);
        return fixed_pt((oper1.value * fixed_exp) / oper2.value);
    }   /* operator / () */

    inline fixed_pt
    operator / (const fixed_pt& oper1,
                const double oper2)
    {
        assert(0 != oper2);
        return fixed_pt((oper1.value * fixed_exp) /
                        fixed_pt::double_to_fp(oper2));
    }   /* operator / () */

    inline fixed_pt
    operator / (const double oper1,
                const fixed_pt& oper2)
    {
        assert(0 != oper2.value);
        return fixed_pt((fixed_pt::double_to_fp(oper1) * fixed_exp) /
                        oper2.value);
    }   /* operator / () */

    inline bool
    operator == (const fixed_pt& oper1,
                 const fixed_pt& oper2)
    {
        return (oper1.value == oper2.value);
    }   /* operator == () */

    inline bool
    operator != (const fixed_pt& oper1,
                 const fixed_pt& oper2)
    {
        return !(oper1.value == oper2.value);
    }   /* operator != () */

    inline fixed_pt
    operator - (const fixed_pt& oper1)
    {
        return fixed_pt(-oper1.value);
    }   /* operator - () */

    inline fixed_pt
    operator + (const fixed_pt& oper1)
    {
        return fixed_pt(oper1);
    }   /* operator + () */

    inline std::ostream&
    operator << (std::ostream& out_file,
                 const fixed_pt& number)
    {
        long int before_dp = number.value / fixed_exp;
        long int after_dp1 = abs(number.value % fixed_exp);
        long int after_dp2 = after_dp1 % 10;
        after_dp1 /= 10;

        out_file << before_dp << '.' << after_dp1 << after_dp2;

        return (out_file);
    }   /* operator << () */

    extern std::istream& operator >> (std::istream& out_file,
                                      fixed_pt& number);
}


#endif /* FIXED_PT_H */


/*** End of file ***/
