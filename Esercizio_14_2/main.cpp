/**
 * @file    main.cpp
 * @author  Filippo Graziani
 * @date    18/09/2023
 * @brief   Simple program to add animals to the vet using classes.
 */

#include <iostream>
#include <string>
#include <cstring>

class cat
{
    private:
        static int n_cat;
    public:
        friend class animals;
        cat();
};

class dog
{
    private:
        static int n_dog;
    public:
        friend class animals;
        dog();
};

class horse
{
    private:
        static int n_horse;
    public:
        friend class animals;
        horse();
};

class animals
{
    private:
        static int n_animals;
    public:
#if 0
        void new_animal(std::string animal);
        void cared_animal(std::string animal);
#endif
        static int num_animal(std::string animal);
        animals();
        friend class cat;
        friend class dog;
        friend class horse;
};

int animals::n_animals = 0;
int cat::n_cat = 0;
int dog::n_dog = 0;
int horse::n_horse = 0;

/**
 * @brief   Main function
 * @par     Description
 * The program tests if the created class works.
 * @return  Always 0 (success).
 */
int
main ()
{
    animals vet_animals;

    std::cout << "N animals: " << vet_animals.num_animal("ALL") << '\n';

    cat vet_cat1;
    dog vet_dog1;
    horse vet_horse1;

    std::cout << "N cats: " << vet_animals.num_animal("Cat") << '\n';
    std::cout << "N animals: " << vet_animals.num_animal("ALL") << '\n';

    cat vet_cat2;

    std::cout << "N cats: " << vet_animals.num_animal("Cat") << '\n';
    std::cout << "N animals: " << vet_animals.num_animal("ALL") << '\n';
    
    return 0;
}   /* main() */

/**
 * @brief   The number of the given type of animal
 * @par     Description
 * The function requires a string: "Cat", "Dog", "Horse" or other string.
 * @param[in]   animal  The string with the searched animal.
 * @return  It returns the number of the specified animal, the total number
 *          otherwise.
 */
inline int
animals::num_animal (std::string animal)
{
    if (0 == std::strncmp(animal.c_str(), "Cat", 4))
    {
        return cat::n_cat;
    }
    else if (0 == std::strncmp(animal.c_str(), "Dog", 4))
    {
        return dog::n_dog;
    }
    else if (0 == std::strncmp(animal.c_str(), "Horse", 6))
    {
        return horse::n_horse;
    }
    else
    {
        return animals::n_animals;
    }
}   /* animals::num_animal() */

#if 0
inline void
animals::cared_animal (std::string animal)
{
    if (n_animals <= 0)
    {
        return;
    }

    if (0 == std::strncmp(animal.c_str(), "Cat", 4))
    {
        --cat::n_cat;
    }
    else if (0 == std::strncmp(animal.c_str(), "Dog", 4))
    {
        --dog::n_dog;
    }
    else if (0 == std::strncmp(animal.c_str(), "Horse", 6))
    {
        --horse::n_horse;
    }
    else
    {
        return;
    }

    n_animals = cat::n_cat + dog::n_dog + horse::n_horse;
}   /* animals::cared_animal() */

inline void
animals::new_animal (std::string animal)
{
    if (0 == std::strncmp(animal.c_str(), "Cat", 4))
    {
        ++cat::n_cat;
    }
    else if (0 == std::strncmp(animal.c_str(), "Dog", 4))
    {
        ++dog::n_dog;
    }
    else if (0 == std::strncmp(animal.c_str(), "Horse", 6))
    {
        ++horse::n_horse;
    }
    else
    {
        return;
    }

    n_animals = cat::n_cat + dog::n_dog + horse::n_horse;
}   /* animals::new_animal() */
#endif

/**
 * @brief   Constructor for class `cat`
 * @par     Description
 * This function does nothing.
 * @return  Always nothing.
 */
cat::cat ()
{
    ++cat::n_cat;
    ++animals::n_animals;
}   /* cat::cat() */

/**
 * @brief   Constructor for class `dog`
 * @par     Description
 * This function does nothing.
 * @return  Always nothing.
 */
dog::dog ()
{
    ++dog::n_dog;
    ++animals::n_animals;
}   /* dog::dog() */

/**
 * @brief   Constructor for class `horse`
 * @par     Description
 * This function does nothing.
 * @return  Always nothing.
 */
horse::horse ()
{
    ++horse::n_horse;
    ++animals::n_animals;
}   /* horse::horse() */

/**
 * @brief   Constructor for class `animals`
 * @par     Description
 * This function does nothing.
 * @return  Always nothing.
 */
animals::animals ()
{
    /* Do nothing */
}   /* animals::animals() */


/*** End of file ***/

