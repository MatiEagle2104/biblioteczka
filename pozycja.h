#ifndef POZYCJA_H_INCLUDED
#define POZYCJA_H_INCLUDED
#include <iostream>

class pozycja{
private:
    std::string typ;

public:
    static int liczba_pozycji;

    pozycja();
    explicit pozycja(std::string type);
    pozycja(pozycja & kopia);
    pozycja & operator=(const pozycja &)
    {
        return *this;
    }

    ~pozycja();

    static void zmien_l_poz();
    void wypisywanie()const;
    virtual void wypisz()=0;
    virtual void dodaj()=0;
    friend class manager;
};

#endif // POZYCJA_H_INCLUDED
