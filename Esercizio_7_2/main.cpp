/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    31/08/2023
 * @brief   Simple program to calculate the difference in days between 2 dates.
 */

#include <iostream>
#include <string>
#include <cstring>

static bool leap_year(int year);
static int num_days_in_month(int month, int year);

/**
 * @brief   Main function
 * @par     Description
 * The program asks for 2 dates and calculate the number of days of difference.
 * @return  Always 0 (success).
 */
int
main ()
{
    std::string first_date = "";
    std::string second_date = "";
    int first_day = 0;
    int first_month = 0;
    int first_year = 0;
    int second_day = 0;
    int second_month = 0;
    int second_year = 0;
    int n_days_diff = 0;

    std::cout << "Insert the initial date (e.g. 6/1/1990): ";
    std::getline(std::cin, first_date);
    std::sscanf(first_date.c_str(), "%d/%d/%d",
                &first_day, &first_month, &first_year);
    std::cout << "Insert the final date (e.g. 8/3/1992): ";
    std::getline(std::cin, second_date);
    std::sscanf(second_date.c_str(), "%d/%d/%d",
                &second_day, &second_month, &second_year);
    
    if ((first_month == second_month) && (first_year == second_year))
    {
        n_days_diff = second_day - first_day;
    }
    else if (first_year == second_year)
    {
        n_days_diff = num_days_in_month(first_month, first_year) - first_day;
        n_days_diff += second_day;

        for (int month = first_month + 1; month < second_month; ++month)
        {
            n_days_diff += num_days_in_month(month, first_year);
        }
    }
    else
    {
        n_days_diff = num_days_in_month(first_month, first_year) - first_day;
        n_days_diff += second_day;

        for (int month = first_month + 1; month <= 12; ++month)
        {
            n_days_diff += num_days_in_month(month, first_year);
        }

        for (int month = 1; month < second_month; ++month)
        {
            n_days_diff += num_days_in_month(month, second_year);
        }

        for (int year = first_year + 1; year < second_year; ++year)
        {
            n_days_diff += true == leap_year(year) ? 366 : 365;
        }
    }

    std::cout << "Days of difference = " << n_days_diff << '\n';

    return 0;
}   /* main() */

/**
 * @brief   Leap year calculator
 * @par     Description
 * The funcion detects if the inserted year is leap.
 * @param[in]   year    The year (e.g. 1923)
 * @return  true if leap year; false otherwise.
 */
static bool
leap_year (int year)
{
    bool b_is_leap = false;

    if (year < 0)
    {
        b_is_leap = false;
    }
    else
    {
        if ((0 == year % 400) ||
            ((0 == year % 4) && !(0 == year % 100)))
        {
                b_is_leap = true;
        }
        else
        {
            b_is_leap = false;
        }
    }

    return b_is_leap;
}   /* leap_year() */

/**
 * @brief   Number of days in a specific month
 * @par     Description
 * The funcion calculates how many days are in a specific month
 * of a specific year (the year is used to calculate a leap year).
 * @param[in]   month   The month (e.g. 2 - February)
 * @param[in]   year    The year (e.g. 1923)
 * @return  Number of days of the specified month.
 */
static int
num_days_in_month (int month, int year)
{
    int num = 0;

    switch (month)
    {
        case 4:
            /* Fall through */
        case 6:
            /* Fall through */
        case 9:
            /* Fall through */
        case 11:
            num = 30;
        break;

        case 1:
            /* Fall through */
        case 3:
            /* Fall through */
        case 5:
            /* Fall through */
        case 7:
            /* Fall through */
        case 8:
            /* Fall through */
        case 10:
            /* Fall through */
        case 12:
            num = 31;
        break;

        case 2:
            num = true == leap_year(year) ? 29 : 28;
        break;

        default:
        break;
    }

    return num;
}   /* num_days_in_month() */

/*** End of file ***/
