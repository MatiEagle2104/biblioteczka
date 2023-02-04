#ifndef GRA_H_INCLUDED
#define GRA_H_INCLUDED

#include <iostream>
#include "pozycja.h"

class gra:public pozycja{
private:
    std::string platforma;
    int rzad;
    int polka;

public:
    std::string tytul;
    static int liczba_gier;

    gra();
    gra(std::string type, std::string title, std::string platform, int row, int shelf);
    gra(gra & kopia);
    gra & operator=(const gra &)
    {
        return *this;
    }

    ~gra();

    void wypisz();
    void dodaj();
    void usun(gra & g2);
    friend class manager;
};


#endif // GRA_H_INCLUDED
