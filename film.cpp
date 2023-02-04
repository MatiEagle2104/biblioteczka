#include "pozycja.h"
#include "film.h"
#include <iostream>

using namespace std;

int film::liczba_filmow = 0;

film::film():pozycja("FILM")
{
    tytul = "tytul filmu";
    gatunek = "gatunek filmu";
    dlugosc = 100;
    rzad = 0;
    polka = 0;
}

film::film(std::string type, std::string title, std::string gatunek, int length, int row, int shelf):pozycja(type)
{
    tytul = type;
    this->gatunek = gatunek;
    dlugosc = length;
    rzad = row;
    polka = shelf;

    liczba_filmow++;
}

film::film(film & kopia):pozycja("FILM")
{
    tytul = "KOPIA " + kopia.tytul;
    gatunek = kopia.gatunek;
    dlugosc = kopia.dlugosc;
    rzad = kopia.rzad;
    polka = kopia.polka;

    liczba_filmow++;
}

film::~film()
{
    liczba_filmow--;
    liczba_pozycji--;
}

void film::wypisz()
{
    wypisywanie();
    cout << "Tytul: " << tytul << endl;
    cout << "Gatunek: " << gatunek << endl;
    cout << "Czas trwania: " << dlugosc << " min" << endl;
    cout << "Film " << tytul << " znajduje sie w rzedzie nr " << rzad << ", na " << polka << " polce" << endl << endl;
}

void film::dodaj()
{
    cout << "-----DODAWANIE FILMU-----" << endl << "-------------------------" << endl;
    cin.clear();                   cin.sync();
    cout << "Tytul: ";             getline(cin, tytul);
    cin.clear();                   cin.sync();
    cout << "Gatunek: ";           getline(cin, gatunek);
    cout << "Czas trwania: ";      cin >> dlugosc;
    cout << "Rzad: ";              cin >> rzad;
    cout << "Polka: ";             cin >> polka;

    liczba_pozycji++;
    liczba_filmow++;

    system("cls");
    cout << "Dodano!" << endl << endl;
    system("PAUSE");
    system("cls");
}

void film::usun(film & f2)
{
    tytul = f2.tytul;               f2.tytul.clear();
    gatunek = f2.gatunek;           f2.gatunek.clear();
    dlugosc = f2.dlugosc;           f2.dlugosc=0;
    rzad = f2.rzad;                 f2.rzad=0;
    polka = f2.polka;               f2.polka=0;

    liczba_filmow--;
    liczba_pozycji--;

    cout << "Usunieto!" << endl << endl;
    system("PAUSE");
    system("cls");
}
