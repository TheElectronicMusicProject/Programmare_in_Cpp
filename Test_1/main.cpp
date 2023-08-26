#include <iostream>
#include <string>
#include <cstring>

int
main ()
{
#if 0
    int base(0);
    int altezza(0);

    std::cout << "Inserire base e altezza: ";
    std::cin >> base >> altezza;
    std::cout << "Area = " << base * altezza <<
                 ", Perimetro = " << 2 * (base + altezza) <<
                 '\n';
#else
    std::string nome;
    signed char character = 0;
    signed char& char_2 = character;

    std::cout << "Inserire nome: ";
    std::getline(std::cin, nome);
    std::cout << "Nome inserito = " << nome <<
                 ", lunghezza = " << nome.length() <<
                 ", prima lettera = " << nome.at(0) <<
                 ", rimanenti lettere = " << nome.substr(1) <<
                 '\n';

    character = 37;
    std::cout << "Numero = " << static_cast<int>(char_2) <<
                 ", carattere = " << char_2 <<
                 '\n';
#endif
    return (0);
}