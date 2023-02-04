#include "pozycja.h"
#include <iostream>

using namespace std;

int pozycja::liczba_pozycji = 0;

void pozycja::zmien_l_poz()
{
    liczba_pozycji++;
}

pozycja::pozycja()
{
    typ = "Pozycja w biblioteczce";
}

pozycja::pozycja(std::string type):typ(type){}

pozycja::pozycja(pozycja & kopia)
{
    typ = "KOPIA " + kopia.typ;
}

pozycja::~pozycja()
{
    liczba_pozycji--;
}

void pozycja::wypisywanie()const
{
    cout << "-----" << typ << "-----" << endl;
}
