#ifndef KSIAZKA_H_INCLUDED
#define KSIAZKA_H_INCLUDED

#include <iostream>
#include "pozycja.h"

class ksiazka:public pozycja{
private:
    std::string autor;
    std::string gatunek;
    int rzad;
    int polka;

public:
    std::string tytul;
    static int liczba_ksiazek;

    ksiazka();
    ksiazka(std::string type, std::string title, std::string author, std::string gatunek, int row, int shelf);
    ksiazka(ksiazka & kopia);
    ksiazka & operator=(const ksiazka &)
    {
        return *this;
    }

    ~ksiazka();

    void wypisz();
    void dodaj();
    void usun (ksiazka & k2);
    friend class manager;
};

#endif // KSIAZKA_H_INCLUDED
