#include "pozycja.h"
#include "gra.h"
#include <iostream>

using namespace std;

int gra::liczba_gier = 0;

gra::gra():pozycja("GRA")
{
    tytul = "tytul gry";
    platforma = "konsola";
    rzad = 0;
    polka = 0;
}

gra::gra(std::string type, std::string title, std::string platform, int row, int shelf):pozycja(type)
{
    tytul = type;
    platforma = platform;
    rzad = row;
    polka = shelf;

    liczba_gier++;
}

gra::gra(gra & kopia):pozycja("GRA")
{
    tytul = "KOPIA " + kopia.tytul;
    platforma = kopia.platforma;
    rzad = kopia.rzad;
    polka = kopia.polka;

    liczba_gier++;
}

gra::~gra()
{
    liczba_gier--;
    liczba_pozycji--;
}

void gra::wypisz()
{
    wypisywanie();
    cout << "Tytul: " << tytul << endl;
    cout << "Platforma: " << platforma << endl;
    cout << "Gra " << tytul << " na " << platforma << " znajduje sie w rzedzie nr " << rzad << ", na " << polka << " polce" << endl << endl;
}

void gra::dodaj()
{
    cout << "-----DODAWANIE GRY-----" << endl << "-----------------------" << endl;
    cin.clear();                cin.sync();
    cout << "Nazwa: ";          getline(cin, tytul);
    cin.clear();                cin.sync();
    cout << "Platforma: ";      getline(cin, platforma);
    cout << "Rzad: ";           cin >> rzad;
    cout << "Polka: ";          cin >> polka;

    liczba_pozycji++;
    liczba_gier++;

    system("cls");
    cout << "Dodano!" << endl << endl;
    system("PAUSE");
    system("cls");
}

void gra::usun(gra & g2)
{
    tytul = g2.tytul;                g2.tytul.clear();
    platforma = g2.platforma;        g2.platforma.clear();
    rzad = g2.rzad;                  g2.rzad=0;
    polka = g2.polka;                g2.polka=0;

    liczba_gier--;
    liczba_pozycji--;

    cout << "Usunieto!" << endl << endl;
    system("PAUSE");
    system("cls");
}
