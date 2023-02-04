#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include "pozycja.h"
#include "film.h"
#include "muzyka.h"
#include "gra.h"
#include "ksiazka.h"
#include "statystyka.h"

#include <iostream>
#include <fstream>

class manager{
private:
    char wybor;
    char wyb2;
    std::string szukane;
    std::string bufor_wczytywanie;
    int bufor;

public:
    manager();
    ~manager();
    manager(manager & kopia);
    manager & operator=(const manager &)
    {
        return *this;
    }

    void menu()const;
    void menu_v2()const;
    void odczyt(ksiazka[250], muzyka[100], film[100], gra[50]);
    void zapis(ksiazka books[250], muzyka music[100], film films[100], gra games[50]);
    void aplikacja(pozycja *ptr, ksiazka[250], muzyka[100], film[100], gra[50]);
};

#endif // MANAGER_H_INCLUDED
