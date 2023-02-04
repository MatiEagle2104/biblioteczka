#ifndef STATYSTYKA_H_INCLUDED
#define STATYSTYKA_H_INCLUDED

#include "manager.h"
#include <iostream>

class statystyka{
private:
    int zaj_ogl;
    int zaj_ks;
    int zaj_muza;
    int zaj_gry;
    int zaj_fil;

public:
    statystyka();
    ~statystyka();
    statystyka & operator=(const statystyka &)
    {
        return *this;
    }

    void show_stats()const;
    friend class manager;
};

#endif // STATYSTYKA_H_INCLUDED
