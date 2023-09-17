/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    17/09/2023
 * @brief   Simple program to check if the user is able to translate from
 *          italian to english.
 */

#include <iostream>
#include <cassert>
#include <string>
#include <cstring>

#define N_ELEMENTS  (5)

struct single_card
{
    std::string question;
    std::string answer;
};

class flash_card
{
    private:
        int n_cards;
        single_card search_list[N_ELEMENTS];
    public:
        void right();
        void wrong();
        flash_card(single_card list[]);
        bool next_question();
};

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created class works.
 * @return  Always 0 (success).
 */
int
main ()
{
    single_card learn_words[N_ELEMENTS] =
    {
        {
            .question = "Acqua",
            .answer = "Water"
        },
        {
            .question = "Gatto",
            .answer = "Cat"
        },
        {
            .question = "Dito",
            .answer = "Finger"
        },
        {
            .question = "Verde",
            .answer = "Green"
        },
        {
            .question = "Frigorifero",
            .answer = "Fridge"
        }
    };

    flash_card test_card(learn_words);

    for (int n_test = 0; n_test < 10; ++n_test)
    {
        if (true == test_card.next_question())
        {
            test_card.right();
            std::cout << "OK\n";
        }
        else
        {
            test_card.wrong();
        }
    }
    
    return 0;
}   /* main() */

/**
 * @brief   Manages a right answer
 * @par     Description
 * The element at the top of the list is discarded, and the number of available
 * elements is decreased.
 * @return  Nothing.
 */
inline void
flash_card::right ()
{
    if (0 == n_cards)
    {
        return;
    }

    --n_cards;

    for (int idx = 0; idx < n_cards; ++idx)
    {
        search_list[idx].question = search_list[idx + 1].question;
        search_list[idx].answer = search_list[idx + 1].answer;
    }
}   /* flash_card::right() */

/**
 * @brief   Manages a wrong answer
 * @par     Description
 * The element at the top of the list is put at the end of the list.
 * @return  Nothing.
 */
inline void
flash_card::wrong ()
{
    if (0 == n_cards)
    {
        return;
    }

    single_card temp = {
        .question = search_list[0].question,
        .answer = search_list[0].answer
    };
    
    for (int idx = 0; idx < (n_cards - 1); ++idx)
    {
        search_list[idx].question = search_list[idx + 1].question;
        search_list[idx].answer = search_list[idx + 1].answer;
    }

    search_list[n_cards - 1].question = temp.question;
    search_list[n_cards - 1].answer = temp.answer;
}   /* flash_card::wrong() */

/**
 * @brief   Prints the question in the terminal
 * @par     Description
 * This function asks a question to the user.
 * If the user translates it correctly, then true is returned.
 * @return  true if correctly translated, false otherwise.
 */
inline bool
flash_card::next_question ()
{
    if (0 == n_cards)
    {
        return false;
    }

    std::string temp = "";
    std::cout << search_list[0].question <<'\n';

    std::getline(std::cin, temp);

    if (0 == std::strcmp(temp.c_str(), search_list[0].answer.c_str()))
    {
        return true;
    }
    
    return false;
}   /* flash_card::next_question() */

/**
 * @brief   Constructor for class `flash_card`
 * @par     Description
 * The input list is copied in the class member list.
 * @return  Always nothing.
 */
flash_card::flash_card (single_card list[])
{
    n_cards = N_ELEMENTS;

    for (int idx = 0; idx < N_ELEMENTS; ++idx)
    {
        search_list[idx].question = list[idx].question;
        search_list[idx].answer = list[idx].answer;
    }
}   /* flash_card::flash_card() */


/*** End of file ***/
