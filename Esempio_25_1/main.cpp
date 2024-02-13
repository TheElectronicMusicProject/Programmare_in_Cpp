/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    10/02/2024
 * @brief   Simple class to manage students and grade.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

/**
 * Maximum number of students per class.
 */
const unsigned int g_max_students(5);

class class_stuff_t
{
    public:
        // A set of grades.
        //
        typedef std::vector<int> grades;

        // List of students participating at the current class.
        //
        std::map<std::string, grades> roster;

        // Students waiting for the class.
        //
        std::list<std::string> waiting_list;

        // Predefined constructor.
        // Predefined destructor.
        // Predefined copy constructor.
        // Assignment operator.

        void add_student(const std::string& name);
        void drop_student(const std::string& name);
        void record_grade(const std::string& name, const int grade,
                          const unsigned int assignment_number);
        void print_grades();
    
    private:
        // Insert a student in the class.
        //
        void
        new_student (const std::string& name)
        {
            // Initialize an empty set of grades.
            //
            grades no_grades;
            roster.insert(std::pair<std::string, grades>(name, no_grades));
        }   /* new_student() */
};

/**
 * @brief   Adds a student to the class. If the class is complete, inserts it in
 *          the waiting list.
 * @param[in]   name    Name of the student to be added.
 * @return  Nothing.
 */
void
class_stuff_t::add_student (const std::string& name)
{
    // Do not add it if it's already in the class.
    //
    if (roster.end() != roster.find(name))
    {
        return;
    }

    // If the class has available seats, it adds the student.
    //
    if (roster.size() < g_max_students)
    {
        new_student(name);
    }
    // If no seats are available, adds it to the waiting list.
    //
    else
    {
        waiting_list.push_back(name);
    }
}   /* class_stuff_t::add_student() */

/**
 * @brief   Removes a student from a class. If there is a waiting list, the
 *          first student of the list will be inserted in the class.
 * @param[in]   name    Name of the student to be deleted.
 * @return  Nothing.
 */
void
class_stuff_t::drop_student (const std::string& name)
{
    // Student that must be removed.
    //
    std::map<std::string, grades>::iterator the_student = roster.find(name);

    // The student is not in the class.
    //
    if (roster.end() == the_student)
    {
        return;
    }

    roster.erase(name);

    // Adds a student from the waiting list if there is one.
    //
    if (waiting_list.size() > 0)
    {
        std::string wait_name = waiting_list.front();
        waiting_list.pop_front();

        new_student(wait_name);
    }
}   /* class_stuff_t::drop_student() */

/**
 * @brief   Stores a grade of a student.
 * @param[in]   name                Name of the student.
 * @param[in]   grade               Grade of the test.
 * @param[in]   assignment_number   Number of the test.
 * @return  Nothing.
 */
void
class_stuff_t::record_grade (const std::string& name,
                             const int grade,
                             const unsigned int assignment_number)
{
    std::map<std::string, grades>::iterator the_student = roster.find(name);

    if (roster.end() == the_student)
    {
        std::cerr << "Error: no such student " << name << "\n";
    }

    // Changes the size of the list of grades if there isn't sufficient space.
    //
    if (the_student->second.size() <= assignment_number)
    {
        the_student->second.resize(assignment_number + 1);
    }

    the_student->second[assignment_number] = grade;
}   /* class_stuff_t::record_grade() */

/**
 * @brief   Prints the students and their grades.
 * @return  Nothing.
 */
void
class_stuff_t::print_grades ()
{
    // Names of the ordered students.
    //
    std::vector<std::string> sorted_names;

    // Name of the students to be put in the ordered list.
    //
    std::map<std::string, grades>::iterator cur_student;

    for (cur_student = roster.begin(); cur_student != roster.end();
         ++cur_student)
    {
        sorted_names.push_back(cur_student->first);
    }

    std::sort(sorted_names.begin(), sorted_names.end());

    // The current student.
    //
    std::vector<std::string>::const_iterator cur_print;

    for (cur_print = sorted_names.begin(); cur_print != sorted_names.end();
         ++cur_print)
    {
        std::cout << *cur_print << "\t";

        // Grade to be printed.
        //
        grades::const_iterator cur_grade;

        for (cur_grade = roster[*cur_print].begin();
             cur_grade != roster[*cur_print].end(); ++cur_grade)
        {
            std::cout << *cur_grade << " ";
        }

        std::cout << "\n";
    }
}   /* class_stuff_t::print_grades() */

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created class works.
 * @return  Always 0 (success).
 */
int
main ()
{
    class_stuff_t test_class;

    test_class.add_student("Able, Sam");
    test_class.add_student("Baker, Mary");
    test_class.add_student("Johnson, Robin");
    test_class.add_student("Smith, Joe");
    test_class.add_student("Mouse, Micky");
    test_class.add_student("Gadot, Waiting");
    test_class.add_student("Congreve, William");

    std::cout << "Before drop " << std::endl;
    test_class.print_grades();
    std::cout << "\n";

    test_class.drop_student("Johnson, Robin");

    std::cout << "After drop " << std::endl;
    test_class.print_grades();
    std::cout << "\n";

    int idx(0);

    for (idx = 0; idx < 5; ++idx)
    {
        test_class.record_grade("Able, Sam", idx * 10 + 50, idx);
        test_class.record_grade("Baker, Mary", idx * 10 + 50, idx);
        test_class.record_grade("Smith, Joe", idx * 10 + 50, idx);
        test_class.record_grade("Mouse, Micky", idx * 10 + 50, idx);
        test_class.record_grade("Gadot, Waiting", idx * 10 + 50, idx);
    }

    std::cout << "Final" << std::endl;
    test_class.print_grades();
    std::cout << "\n";

    return 0;
}   /* main() */


/*** End of file ***/
