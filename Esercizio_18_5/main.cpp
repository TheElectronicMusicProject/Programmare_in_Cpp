/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    04/01/2024
 * @brief   Class to manage dates
 *          There are the functions to sum, substract, read and print the date.
 *          The format of the date is DD/MM (no year) and the year is supposed
 *          to be non leap.
 */

#include <iostream>
#include <iomanip>

namespace date_t
{
    class date_t
    {
        public:
            int day;
            int month;

            date_t ()
            {
                day = 0;
                month = 0;
            }

            date_t (int in_day,
                    int in_month)
            {
                day = in_day;
                month = in_month;
            }

            date_t (const date_t& old_arr)
            {
                day = old_arr.day;
                month = old_arr.month;
            }

            ~date_t()
            {
                day = 0;
                month = 0;
            }

        private:
            int daysinmonth(int month);

        friend date_t operator + (const date_t& oper1,
                                  const date_t& oper2);
        friend date_t operator - (const date_t& oper1,
                                  const date_t& oper2);
        friend std::ostream& operator << (std::ostream& out_file,
                                          const date_t& in_time);
        friend std::istream& operator >> (std::istream& in_file,
                                          date_t& out_time);
            
    };

    inline date_t
    operator + (const date_t& oper1,
                const date_t& oper2)
    {
        date_t out_time;

        out_time.month = (oper1.month + oper2.month) % 13;
        out_time.day = oper1.day + oper2.day;

        if (out_time.day > out_time.daysinmonth(out_time.month))
        {
            ++out_time.month;
            out_time.month %= 13;

            out_time.day = out_time.day - out_time.daysinmonth(out_time.month);
        }

        return (out_time);
    }   /* operator + () */

    inline date_t
    operator - (const date_t& oper1,
                const date_t& oper2)
    {
        date_t out_date;

        if (oper1.month == oper2.month)
        {
            if (oper1.day > oper2.day)
            {
                out_date.day = oper1.day - oper2.day;
            }
            else
            {
                out_date.day = oper2.day - oper1.day;
            }

            out_date.month = 0;
        }
        else if (oper1.month < oper2.month)
        {
            out_date.day = out_date.daysinmonth(oper1.month) - oper1.day;
            out_date.day += oper2.day;
            out_date.month = oper2.month - oper1.month;
        }
        else
        {
            out_date.day = out_date.daysinmonth(oper2.month) - oper2.day;
            out_date.day += oper1.day;
            out_date.month = oper1.month - oper2.month;
        }
        
        return (out_date);
    }   /* operator - () */

    inline std::ostream&
    operator << (std::ostream& out_file,
                 const date_t& in_date)
    {
        out_file << std::setw(2) << std::setfill('0') << in_date.day << "/"
                 << std::setw(2) << std::setfill('0') << in_date.month;

        return (out_file);
    }   /* operator << () */

    inline std::istream&
    operator >> (std::istream& in_file,
                 date_t& out_time)
    {
        char chr(0);
        date_t temp;

        // To protect I/O.
        //
        std::istream::sentry the_sentry(in_file, true);

        if (the_sentry)
        {
            if (in_file.bad())
            {
                return (in_file);
            }

            // Day.
            //
            in_file >> out_time.day;

            if (in_file.bad())
            {
                return (in_file);
            }

            // First char after the number.
            //
            in_file >> chr;

            if (in_file.bad())
            {
                return (in_file);
            }

            if ('/' != chr)
            {
                in_file.setstate(std::ios::failbit);

                return (in_file);
            }

            // Month.
            //
            in_file >> out_time.month;

            if (in_file.bad())
            {
                return (in_file);
            }

            int n_day = temp.daysinmonth(out_time.month);

            if ((-1 == n_day) || (out_time.day < 0) || (out_time.day > n_day))
            {
                std::cerr << "Invalid format: day = " << out_time.day
                          << ", month = " << out_time.month;

                out_time.month = 0;
                out_time.day = 0;
            }
        }
        else
        {
            in_file.setstate(std::ios::failbit);
        }

        return (in_file);
    }   /* operator >> () */
}

/**
 * @brief   Main function
 * @par     Description
 * Test for the class date_t, printing its values.
 * @return  Always 0 (success).
 */
int
main ()
{
    date_t::date_t first_date(12, 5);
    date_t::date_t second_date;

    std::cin >> second_date;

    std::cout << "First date: " << first_date << std::endl;
    std::cout << "Second date: " << second_date << std::endl;
    std::cout << "Difference: " << first_date - second_date << std::endl;
    std::cout << "Difference: " << second_date - first_date << std::endl;
    std::cout << "Sum: " << second_date + first_date << std::endl;

    return (0);
}   /* main() */

/**
 * @brief   Number of days in a specific month
 * @par     Description
 * The funcion calculates how many days are in a specific month without the
 * year, hence considering a non leap year.
 * @param[in]   month   The month (e.g. 2 - February)
 * @return  -1 in case of wrong input value, the number of days of the specified
 *          month otherwise.
 */
inline int
date_t::date_t::daysinmonth (int month)
{
    int n_days(0);

    if ((month <= 0) || (month >= 13))
    {
        return -1;
    }

	if ((11 == month) || (4 == month) || (6 == month) || (9 == month))
    {
		n_days = 30;
    }
	else if (2 == month)
	{
		n_days = 28;
    }
	else
    {
		n_days = 31;
    }

    return n_days;
}   /* daysinmonth() */


/*** End of file ***/
