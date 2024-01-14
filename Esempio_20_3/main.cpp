/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    14/01/2024
 * @brief   Lexical analysis of a file and print of a list of word in ASCII
 *          order.
 */

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cstdlib>

void scan(const char * const p_name);

class tree
{
    private:
        class node
        {
            private:
                node * p_right;
                node * p_left;

            public:
                std::string word;

            friend class tree;
        };
    
        node * p_root;
        
        // & is a reference. Here we use a reference to a pointer.
        // It is like a pointer to a pointer, because we want to modify the
        // content of the pointer variable.
        //
        void enter_one(node * &pp_new_node, const std::string& word);
        void print_one(node * p_top);

    public:
        tree ()
        {
            p_root = NULL;
        }   /* tree () */

        void
        enter (std::string& word)
        {
            enter_one(p_root, word);
        }   /* enter() */

        void
        print ()
        {
            print_one(p_root);
        }   /* print() */
};

static tree g_words;

/**
 * @brief   Main function
 * @par     Description
 * use: main <file>
 * @return  Always 0 (success).
 */
int
main (int argc, char * argv[])
{
    if (2 != argc)
    {
        std::cerr << "Error: Wrong number of parameters\n";
        std::cerr << "\ton the command line \n";
        std::cerr << "Usage is:\n";
        std::cerr << "\twords 'file'\n";
        exit(8);
    }

    scan(argv[1]);
    g_words.print();

    return (0);
}   /* main() */

void
scan (const char * const p_name)
{
    std::string new_word;
    int chr = 0;
    std::ifstream h_in_file;

    h_in_file.open(p_name, std::ios::in);

    if (h_in_file.bad())
    {
        std::cerr << "Error: unable to open " << p_name << std::endl;
        exit(8); 
    }

    do
    {
        new_word = {0};

        do
        {
            chr = h_in_file.get();
        } while ((EOF != chr) && (0 == std::isalpha(chr)));

        if (EOF  != chr)
        {
            while (0 != std::isalpha(chr))
            {
                new_word += chr;
                chr = h_in_file.get();
            }

            g_words.enter(new_word);
        }
    } while (EOF != chr);
}   /* scan() */

/**
 * @brief   Inserts a word in the tree.
 * @param[in,out]   pp_new_node Current node.
 * @param[in]       word        Word to be inserted.
 * @return  Nothing.
 */
void
tree::enter_one (node * &pp_new_node, const std::string& word)
{
    // Chek if it founds the end.
    //
    if (NULL == pp_new_node)
    {
        pp_new_node = new node;

        pp_new_node->p_left = NULL;
        pp_new_node->p_right = NULL;
        pp_new_node->word = word;
    }

    if (word == pp_new_node->word)
    {
        return;
    }

    if (pp_new_node->word < word)
    {
        enter_one(pp_new_node->p_right, word);
    }
    else
    {
        enter_one(pp_new_node->p_left, word);
    }
}   /* tree::enter_one() */

/**
 * @brief   Prints the words of a tree
 * @param[in]   p_top   Root of the tree to be printed.
 * @return  Nothing.
 */
void
tree::print_one (node * p_top)
{
    if (NULL == p_top)
    {
        return;
    }

    print_one(p_top->p_left);
    std::cout << p_top->word << "\n";
    print_one(p_top->p_right);
}   /* tree::print_one() */


/*** End of file ***/
