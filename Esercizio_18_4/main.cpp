/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    03/01/2024
 * @brief   Class to simulate the managing of time.
 *          There are the functions to sum, substract, read and print the hour.
 *          Negative hour are not allowed, and will be truncated to 0.
 *          High hour are truncated to 0 too (e.g. 25:60:17 is truncated to
 *          00:00:17).
 */

#include <iostream>
#include <iomanip>

namespace hour_t
{
    class hour_t
    {
        public:

            int sec;

            hour_t ()
            {
                sec = 0;
            }

            hour_t (int in_hour, int in_min, int in_sec)
            {
                if ((in_hour <= 23) && (in_hour >= 0))
                {
                    sec = in_hour * 60 * 60;
                }
                else
                {
                    sec = 0;
                }

                if ((in_min <= 59) && (in_min >= 0))
                {
                    sec += in_min * 60;
                }
                else
                {
                    sec += 0;
                }
                
                if ((in_sec <= 59) && (in_sec >= 0))
                {
                    sec += in_sec;
                }
                else
                {
                    sec += 0;
                }
            }

            hour_t (const hour_t& old_arr)
            {
                sec = old_arr.sec;
            }

            ~hour_t()
            {
                sec = 0;
            }

        private:

        friend hour_t operator + (const hour_t& oper1,
                                  const hour_t& oper2);
        friend hour_t operator - (const hour_t& oper1,
                                  const hour_t& oper2);
        friend std::ostream& operator << (std::ostream& out_file,
                                          const hour_t& in_time);
        friend std::istream& operator >> (std::istream& in_file,
                                          hour_t& out_time);
            
    };

    inline hour_t
    operator + (const hour_t& oper1,
                const hour_t& oper2)
    {
        hour_t out_time;

        out_time.sec = oper1.sec + oper2.sec;

        return (out_time);
    }

    inline hour_t
    operator - (const hour_t& oper1,
                const hour_t& oper2)
    {
        hour_t out_time;

        if (oper1.sec <= oper2.sec)
        {
            out_time.sec = 0;
        }
        else
        {
            out_time.sec = oper1.sec - oper2.sec;
        }
        
        return (out_time);
    }

    inline std::ostream&
    operator << (std::ostream& out_file,
                 const hour_t& in_time)
    {
        int hour = (in_time.sec / 3600);
        int min = (in_time.sec / 60) - (hour * 60);
        int sec = in_time.sec - (min * 60) - (hour * 3600);

        out_file << std::setw(2) << std::setfill('0') << hour << ":"
                 << std::setw(2) << std::setfill('0') << min << ":"
                 << std::setw(2) << std::setfill('0') << sec;

        return (out_file);
    }

    inline std::istream&
    operator >> (std::istream& in_file,
                 hour_t& out_time)
    {
        int hour(0);
        int min(0);
        int sec(0);
        char chr(0);

        // To protect I/O.
        //
        std::istream::sentry the_sentry(in_file, true);

        if (the_sentry)
        {
            if (in_file.bad())
            {
                return (in_file);
            }

            // Hours.
            //
            in_file >> hour;

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

            if (':' != chr)
            {
                in_file.setstate(std::ios::failbit);

                return (in_file);
            }

            // Minutes.
            //
            in_file >> min;

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

            if (':' != chr)
            {
                in_file.setstate(std::ios::failbit);

                return (in_file);
            }

            // Seconds.
            //
            in_file >> sec;

            if (in_file.bad())
            {
                return (in_file);
            }

            out_time.sec = sec + 60 * min + 3600 * hour;
        }
        else
        {
            in_file.setstate(std::ios::failbit);
        }

        return (in_file);
    }
}

/**
 * @brief   Main function
 * @par     Description
 * Test for the class hour_t, printing its values.
 * @return  Always 0 (success).
 */
int
main ()
{
    hour_t::hour_t test_time1(12, 59, 58);
    hour_t::hour_t test_time2;
    
    std::cout << "Insert a number: ";
    std::cin >> test_time2;

    hour_t::hour_t test_time3 = test_time1 + test_time2;
    hour_t::hour_t test_time4 = test_time1 - test_time2;

    std::cout << test_time3 << std::endl;
    std::cout << test_time4 << std::endl;

    return (0);
}   /* main() */


/*** End of file ***/
