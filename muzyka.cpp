#include "pozycja.h"
#include "muzyka.h"
#include <iostream>

using namespace std;

int muzyka::liczba_albumow = 0;

muzyka::muzyka():pozycja("MUZYKA")
{
    nazwa = "tytul albumu";
    autor = "muzyk";
    rzad = 0;
    polka = 0;
}

muzyka::muzyka(std::string type, std::string title, std::string author, int row, int shelf):pozycja(type)
{
    nazwa = type;
    autor = author;
    rzad = row;
    polka = shelf;

    liczba_albumow++;
}

muzyka::muzyka(muzyka & kopia):pozycja("MUZYKA")
{
    nazwa = "KOPIA " + kopia.nazwa;
    autor = kopia.autor;
    rzad = kopia.rzad;
    polka = kopia.polka;

    liczba_albumow++;
}

muzyka::~muzyka()
{
    liczba_albumow--;
    liczba_pozycji--;
}

void muzyka::wypisz()
{
    wypisywanie();
    cout << "Tytul albumu: " << nazwa << endl;
    cout << "Autor(zy): " << autor << endl;
    cout << "Album z muzyka " << nazwa << " znajduje sie w rzedzie nr " << rzad << ", na " << polka << " polce" << endl << endl;
}

void muzyka::dodaj()
{
    cout << "-----DODAWANIE ALBUMU-----" << endl << "--------------------------" << endl;
    cin.clear();                        cin.sync();
    cout << "Tytul albumu: ";          getline(cin, nazwa);
    cin.clear();                        cin.sync();
    cout << "Autor(zy): ";              getline(cin, autor);
    cout << "Rzad: ";                   cin >> rzad;
    cout << "Polka: ";                  cin >> polka;

    liczba_pozycji++;
    liczba_albumow++;

    system("cls");
    cout << "Dodano!" << endl << endl;
    system("PAUSE");
    system("cls");
}

void muzyka::usun(muzyka & m2)
{
    nazwa = m2.nazwa;           m2.nazwa.clear();
    autor = m2.autor;           m2.autor.clear();
    rzad = m2.rzad;             m2.rzad=0;
    polka = m2.polka;           m2.polka=0;

    liczba_albumow--;
    liczba_pozycji--;

    cout << "Usunieto!" << endl << endl;
    system("PAUSE");
    system("cls");
}
