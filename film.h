#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

#include <iostream>
#include "pozycja.h"

class film:public pozycja{
private:
    std::string gatunek;
    int dlugosc;
    int rzad;
    int polka;

public:
    std::string tytul;
    static int liczba_filmow;

    film();
    film(std::string type, std::string title, std::string gatunek, int length, int row, int shelf);
    film(film & kopia);
    film & operator=(const film &)
    {
        return *this;
    }

    ~film();

    void wypisz();
    void dodaj();
    void usun(film & f2);
    friend class manager;
};

#endif // FILM_H_INCLUDED
