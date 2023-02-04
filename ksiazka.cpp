#include "pozycja.h"
#include "ksiazka.h"
#include <iostream>

using namespace std;

int ksiazka::liczba_ksiazek = 0;

ksiazka::ksiazka():pozycja("KSIAZKA")
{
    tytul = "tytul ksiazki";
    autor = "autor ksiazki";
    gatunek = "gatunek";
    rzad = 0;
    polka = 0;
}

ksiazka::ksiazka(std::string type, std::string title, std::string author, std::string gatunek, int row, int shelf):pozycja(type)
{
    tytul = type;
    autor = author;
    this->gatunek = gatunek;
    rzad = row;
    polka = shelf;

    liczba_ksiazek++;
}

ksiazka::ksiazka(ksiazka & kopia):pozycja("KSIAZKA")
{
    tytul = "KOPIA " + kopia.tytul;
    autor = kopia.autor;
    gatunek = kopia.gatunek;
    rzad = kopia.rzad;
    polka = kopia.polka;

    liczba_ksiazek++;
}

ksiazka::~ksiazka()
{
    liczba_ksiazek--;
    liczba_pozycji--;
}

void ksiazka::wypisz()
{
    wypisywanie();
    cout << "Tytul: " << tytul << endl;
    cout << "Autor: " << autor << endl;
    cout << "Gatunek: " << gatunek << endl;
    cout << "Ksiazka " << tytul << " znajduje sie w rzedzie nr " << rzad << ", na " << polka << " polce" << endl << endl;
}

void ksiazka::dodaj()
{
    cout << "-----DODAWANIE KSIAZKI-----" << endl << "---------------------------" << endl;
    cin.clear();                        cin.sync();
    cout << "Tytul: ";                  getline(cin, tytul);
    cin.clear();                        cin.sync();
    cout << "Autor: ";                  getline(cin, autor);
    cin.clear();                        cin.sync();
    cout << "Gatunek: ";                getline(cin, gatunek);
    cout << "Rzad: ";                   cin >> rzad;
    cout << "Polka: ";                  cin >> polka;

    liczba_pozycji++;
    liczba_ksiazek++;

    system("cls");
    cout << "Dodano!" << endl << endl;
    system("PAUSE");
    system("cls");
}

void ksiazka::usun(ksiazka & k2)
{
    tytul = k2.tytul;               k2.tytul.clear();
    autor = k2.autor;               k2.autor.clear();
    gatunek = k2.gatunek;           k2.gatunek.clear();
    rzad = k2.rzad;                 k2.rzad=0;
    polka = k2.polka;               k2.polka=0;

    liczba_ksiazek--;
    liczba_pozycji--;

    cout << "Usunieto!" << endl << endl;
    system("PAUSE");
    system("cls");
}
