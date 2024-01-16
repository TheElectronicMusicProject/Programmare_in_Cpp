/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    16/01/2024
 * @brief   Function to delete an element from a binary search tree.
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
                int word;

            friend class tree;
        };
    
        node * p_root;
        
        // & is a reference. Here we use a reference to a pointer.
        // It is like a pointer to a pointer, because we want to modify the
        // content of the pointer variable.
        //
        void enter_one(node * &pp_new_node, const int word);
        void print_one(node * p_top);
        void delete_one(node * &pp_new_node, const int word);

    public:
        tree ()
        {
            p_root = NULL;
        }   /* tree () */

        void
        enter (int word)
        {
            enter_one(p_root, word);
        }   /* enter() */

        void
        remove (int word)
        {
            delete_one(p_root, word);
        }

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
        std::cerr << "\tmain 'file'\n";
        exit(8);
    }

    scan(argv[1]);
    g_words.print();

    g_words.remove(5);
    g_words.print();

    return (0);
}   /* main() */

void
scan (const char * const p_name)
{
    int new_word(0);
    std::ifstream h_in_file;

    h_in_file.open(p_name, std::ios::in);

    if (h_in_file.bad())
    {
        std::cerr << "Error: unable to open " << p_name << std::endl;
        exit(8); 
    }

    while (h_in_file >> new_word)
    {
        g_words.enter(new_word);
    }
}   /* scan() */

/**
 * @brief   Inserts a word in the tree.
 * @param[in,out]   pp_new_node Current node.
 * @param[in]       word        Word to be inserted.
 * @return  Nothing.
 */
void
tree::enter_one (node * &pp_new_node, const int word)
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
 * @brief   Delets a word in the tree, by using a recursive method.
 * @param[in,out]   pp_new_node Current node.
 * @param[in]       word        Word to be inserted.
 * @return  Nothing.
 */
void
tree::delete_one (node * &pp_new_node, const int word)
{
    node * p_current = pp_new_node;
    node * p_prev = NULL;
    std::cerr << "## Before while loop 1 " << std::endl;
    // Scanning searching for the item to be deleted.
    //
    while ((NULL != p_current) && (word != p_current->word))
    {
        p_prev = p_current;

        if (word < p_current->word)
        {
            std::cerr << "## " << word << " < " << p_current->word << std::endl;
            p_current = p_current->p_left;
        }
        else
        {
            std::cerr << "## " << word << " > " << p_current->word << std::endl;
            p_current = p_current->p_right;
        }
    }

    std::cerr << "## After while loop 1 " << std::endl;

    if (NULL == p_current)
    {
        return;
    }

    std::cerr << "## Word found " << p_current->word << std::endl;
    std::cerr << "## Before if " << std::endl;

    // Case of node with one or no children.
    //
    if ((NULL == p_current->p_left) || (NULL == p_current->p_right))
    {
        node * p_new(NULL);

        std::cerr << "## First cond " << std::endl;

        if (NULL == p_current->p_left)
        {
            p_new = p_current->p_right;
        }
        else
        {
            p_new = p_current->p_left;
        }

        // If the node to be deleted is the root, `p_prev` is still NULL.
        //
        if (NULL == p_prev)
        {
            std::cerr << "## Before delete 1 " << std::endl;
            delete p_current;
            p_current = NULL;
            return;
        }

        if (p_current == p_prev->p_left)
        {
            p_prev->p_left = p_new;
        }
        else
        {
            p_prev->p_right = p_new;
        }

        delete p_current;
    }
    // Case with two children.
    //
    else
    {
        std::cerr << "## Second cond " << std::endl;
        // Starting from the right children.
        //
        node * p_temp(p_current->p_right);
        node * p_parent(NULL);

        // Scanner to find the minimum value.
        //
        while (NULL != p_temp->p_left)
        {
            p_parent = p_temp;
            p_temp = p_temp->p_left;
        }

        // The parent is not the same node.
        //
        if (NULL != p_parent)
        {
            p_parent->p_left = p_temp->p_right;
        }
        else
        {
            p_current->p_right = p_temp->p_right;
        }

        p_current->word = p_temp->word;

        std::cerr << "## Before delete 2 " << std::endl;
        delete p_temp;
        p_temp = NULL;
    }
}   /* tree::delete_one() */

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
