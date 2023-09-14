/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    14/09/2023
 * @brief   Simple program get and print a custom mailing list.
 */

#include <iostream>
#include <string>
#include <cstring>

#define N_LIST  (80)

struct mailing
{
    char name[60];
    char address[60];
    char city[60];
    char state[2];
    long int zip;
} g_mailing_list[N_LIST];

static int fill_struct(struct mailing& element);
static void print_struct(struct mailing list[], int n_elem);
static void find_struct(struct mailing list[], int size, char * name);

/**
 * @brief   Main function
 * @par     Description
 * The program requires an input from the user (a mailing list), and exits if
 * it exceed the maximum number or if the user inserts an empty value.
 * Then all the list is printed.
 * @return  Always 0 (success).
 */
int
main ()
{
    int idx(0);

    std::cout << "Insert data in the following format: \n";
    std::cout << "Name: Mario Rossi\n";
    std::cout << "Address: Via Pellicani, 12\n";
    std::cout << "City: Rome\n";
    std::cout << "State: IT\n";
    std::cout << "ZIP: 60403\n";

    for (idx = 0; idx < N_LIST; ++idx)
    {
        std::cout << "Element #" << idx << std::endl;

        if (0 != fill_struct(g_mailing_list[idx]))
        {
            break;
        }
    }

    print_struct(g_mailing_list, idx);

    std::cout << "\t TEST\n";

    char test[] = "Filippo";

    find_struct(g_mailing_list, N_LIST, test);

    return 0;
}   /* main() */

/**
 * @brief   Filling of the structure
 * @par     Description
 * The program requires all the data of the mailing list: name, address, city,
 * state, zip.
 * The input struct is written with these fields.
 * @param[out]  element The struct that must be filled with data.
 * @return  1 for normal exit, 0 if an empty field has been detected.
 */
static int
fill_struct (struct mailing& element)
{
    std::string temp_string = "";

    std::cout << "Name: ";
    std::getline(std::cin, temp_string, '\n');

    if (0 == temp_string.length())
    {
        return 1;
    }

    std::strncpy(element.name, temp_string.c_str(), sizeof(element.name));

    std::cout << "Address: ";
    std::getline(std::cin, temp_string, '\n');

    if (0 == temp_string.length())
    {
        return 1;
    }

    std::strncpy(element.address, temp_string.c_str(), sizeof(element.address));

    std::cout << "City: ";
    std::getline(std::cin, temp_string, '\n');

    if (0 == temp_string.length())
    {
        return 1;
    }

    std::strncpy(element.city, temp_string.c_str(), sizeof(element.city));

    std::cout << "State: ";
    std::getline(std::cin, temp_string, '\n');
    element.state[0] = temp_string.at(0);
    element.state[1] = temp_string.at(1);

    // Non uso std::cin perché causa problemi per le letture successive.
    //
    std::cout << "ZIP: ";
    std::getline(std::cin, temp_string, '\n');
    element.zip = stoi(temp_string);

    return 0;
}   /* fill_struct() */

/**
 * @brief   Print of the structure
 * @par     Description
 * The program prints all the data of the mailing list: name, address, city,
 * state, zip.
 * @param[in]   list    The list that must be printed.
 * @param[in]   n_elem  The number of elements to be printed.
 * @return  Nothing.
 */
static void
print_struct (struct mailing list[], int n_elem)
{
    if (n_elem <= 0)
    {
        return;
    }

    for (int idx = 0; idx < n_elem; ++idx)
    {
        std::cout << "Element #" << idx << '\n';
        std::cout << "Name: " << list[idx].name << '\n';
        std::cout << "Address: " << list[idx].address << '\n';
        std::cout << "City: " << list[idx].city << '\n';
        std::cout << "State: " << list[idx].state[0] << list[idx].state[1] << '\n';
        std::cout << "ZIP: " << list[idx].zip << '\n' << '\n';
    }
}   /* print_struct() */

/**
 * @brief   Search the given name in the list
 * @par     Description
 * The program scans all the names of the mailing list.
 * Then it prints the mailing address of the found item.
 * @param[in]   list    The list that must be printed.
 * @param[in]   size    The number of members in the list.
 * @param[in]   name    The name to be searched.
 * @return  Nothing.
 */
static void
find_struct (struct mailing list[], int size, char * name)
{
    for (int idx = 0; idx < size; ++idx)
    {
        if (0 == std::strncmp(name, list[idx].name, sizeof(list[idx].name)))
        {
            std::cout << "Element #" << idx << '\n';
            std::cout << "Name: " << list[idx].name << '\n';
            std::cout << "Address: " << list[idx].address << '\n';
            std::cout << "City: " << list[idx].city << '\n';
            std::cout << "State: " << list[idx].state[0] << list[idx].state[1] << '\n';
            std::cout << "ZIP: " << list[idx].zip << '\n' << '\n';
        }
    }
}   /* find_struct() */

/*** End of file ***/
