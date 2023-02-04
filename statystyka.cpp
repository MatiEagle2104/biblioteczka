#include "manager.h"
#include "pozycja.h"
#include "ksiazka.h"
#include "film.h"
#include "muzyka.h"
#include "gra.h"
#include "statystyka.h"

#include <iostream>
#include <math.h>

using namespace std;

statystyka::statystyka()
{
    zaj_ogl = pozycja::liczba_pozycji/5;
    zaj_ks = round(ksiazka::liczba_ksiazek*100/250);
    zaj_muza = muzyka::liczba_albumow;
    zaj_fil = film::liczba_filmow;
    zaj_gry = gra::liczba_gier*2;
}

statystyka::~statystyka(){}

void statystyka::show_stats()const
{
    cout << "W biblioteczce znajduje sie " << pozycja::liczba_pozycji << "/500 pozycji." << endl;
    cout << "Biblioteczka jest zajeta w " << zaj_ogl << "%. " << 500-pozycja::liczba_pozycji << " pozycji jest jeszcze wolne." << endl << endl;
    cout << "W bilbioteczce jest " << ksiazka::liczba_ksiazek << "/250 (" << zaj_ks << "% zajete) ksiazek." << endl;
    cout << "W bilbioteczce jest " << muzyka::liczba_albumow << "/100 (" << zaj_muza << "% zajete) albumow muzycznych." << endl;
    cout << "W bilbioteczce jest " << film::liczba_filmow << "/100 (" << zaj_fil << "% zajete) filmow." << endl;
    cout << "W bilbioteczce jest " << gra::liczba_gier << "/50 (" << zaj_gry << "% zajete) gier." << endl << endl;
    cout << round(ksiazka::liczba_ksiazek*100/pozycja::liczba_pozycji) << "% pozycji w biblioteczce to ksiazki." << endl;
    cout << round(muzyka::liczba_albumow*100/pozycja::liczba_pozycji) << "% pozycji w biblioteczce to albumy muzyczne." << endl;
    cout << round(film::liczba_filmow*100/pozycja::liczba_pozycji) << "% pozycji w biblioteczce to filmy." << endl;
    cout << round(gra::liczba_gier*100/pozycja::liczba_pozycji) << "% pozycji w biblioteczce to gry." << endl;

    cout << endl;
    system("PAUSE");
    system("cls");
}
