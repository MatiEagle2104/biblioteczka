#include "manager.h"
#include "pozycja.h"
#include "ksiazka.h"
#include "film.h"
#include "muzyka.h"
#include "gra.h"
#include "statystyka.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

manager::manager()
{
    wybor = '0';
    wyb2 = '0';
    bufor = 0;
    bufor_wczytywanie = "";
    szukane = "-----";
}

manager::manager(manager & kopia)
{
    wybor = kopia.wybor;
    wyb2 = kopia.wyb2;
    bufor = kopia.bufor;
    szukane = kopia.szukane;
}

manager::~manager(){}

void manager::menu()const
{
    cout << "-----BIBLIOTECZKA-----" << endl;
    cout << "----------------------" << endl;
    cout << "1. Wyszukaj pozycje " << endl;
    cout << "2. Dodaj pozycje " << endl;
    cout << "3. Usun pozycje " << endl;
    cout << "4. Statystyki" << endl;
    cout << "5. Wyjscie" << endl << endl;
    cout << "Twoj wybor: ";
}

void manager::menu_v2()const
{
    cout << "-----BIBLIOTECZKA-----" << endl;
    cout << "----------------------" << endl;
    cout << "1. Ksiazka " << endl;
    cout << "2. Film " << endl;
    cout << "3. Muzyka " << endl;
    cout << "4. Gra" << endl;
    cout << "5. Wyjscie" << endl << endl;
    cout << "Twoj wybor: ";
}

void manager::odczyt(ksiazka books[250], muzyka music[100], film films[100], gra games[50])
{
    ifstream plik;
    plik.open("lista.txt", ios::in);

    if (plik.good()==false)
    {
        cout << "BRAK PLIKU DO ODCZYTU" << endl;
        exit (0);
    }

    for(size_t i=0; plik.eof()!=1; i++)
        {
            plik >> bufor_wczytywanie;

            if(bufor_wczytywanie=="ksiazka")
                {
                    plik >> books[ksiazka::liczba_ksiazek].tytul >> books[ksiazka::liczba_ksiazek].autor >> books[ksiazka::liczba_ksiazek].gatunek >> books[ksiazka::liczba_ksiazek].rzad >> books[ksiazka::liczba_ksiazek].polka;

                    ksiazka::liczba_ksiazek++;
                    pozycja::liczba_pozycji++;
                }
            else if(bufor_wczytywanie=="film")
                {
                    plik >> films[film::liczba_filmow].tytul >> films[film::liczba_filmow].gatunek >> films[film::liczba_filmow].dlugosc >> films[film::liczba_filmow].rzad >> films[film::liczba_filmow].polka;

                    film::liczba_filmow++;
                    pozycja::liczba_pozycji++;
                }
            else if(bufor_wczytywanie=="gra")
                {
                    plik >> games[gra::liczba_gier].tytul >> games[gra::liczba_gier].platforma >> games[gra::liczba_gier].rzad >> games[gra::liczba_gier].polka;

                    gra::liczba_gier++;
                    pozycja::liczba_pozycji++;
                }
            else if(bufor_wczytywanie=="muzyka")
                {
                    plik >> music[muzyka::liczba_albumow].nazwa >> music[muzyka::liczba_albumow].autor >> music[muzyka::liczba_albumow].rzad >> music[muzyka::liczba_albumow].polka;

                    muzyka::liczba_albumow++;
                    pozycja::liczba_pozycji++;
                }
            else break;
            bufor_wczytywanie.clear();
        }
    plik.close();
}


void manager::zapis(ksiazka books[250], muzyka music[100], film films[100], gra games[50])
{
    ofstream zapis;
    zapis.open("biblioteczka.txt", ios::out);
        for (int i=0; i<ksiazka::liczba_ksiazek; i++)
        {
            if(books[i].polka!=0)
            {
                zapis << "ksiazka " << books[i].tytul << " " << books[i].autor << " " << books[i].gatunek << " " << books[i].rzad << " " << books[i].polka << "\n";
            }
        }
        for (int i=0; i<film::liczba_filmow; i++)
        {
            if(books[i].rzad!=0)
            {
                zapis << "film " << films[i].tytul << " " << films[i].gatunek << " " << films[i].dlugosc << " " << films[i].rzad << " " << films[i].polka << "\n";
            }
        }
        for (int i=0; i<muzyka::liczba_albumow; i++)
        {
            if(music[i].polka!=0)
            {
                zapis << "muzyka " << music[i].nazwa << " " << music[i].autor << " " << music[i].rzad << " " << music[i].polka << "\n";
            }
        }
        for (int i=0; i<gra::liczba_gier; i++)
        {
            if(games[i].polka!=0)
            {
                zapis << "gra " << games[i].tytul << " " << games[i].platforma << " " << games[i].rzad << " " << games[i].polka << "\n";
            }
        }
        zapis.close();
}

void manager::aplikacja(pozycja *ptr, ksiazka books[250], muzyka music[100], film films[100], gra games[50])
{
    while(true)
    {
        menu();
        cin >> wybor;
        system ("cls");

    switch(wybor){
    case '1':
        {
            menu_v2();
            cin >> wyb2;

            if(wyb2=='1')
            {
                system("cls");
                cin.clear();
                cin.sync();

                cout << "Wyszukaj ksiazke: ";
                getline(cin, szukane);
                system("cls");

                for(size_t i=0; i<ksiazka::liczba_ksiazek; i++)
                {
                    if(books[i].tytul==szukane)
                    {
                        ptr = &books[i];
                        ptr -> wypisz();
                        bufor++;
                    }
                }
                if(bufor==0)
                {
                    cout << "Brak ksiazki *" << szukane << "* w biblioteczce" << endl << endl;
                }
                szukane.clear();
                bufor = 0;

                system("PAUSE");
                system("cls");
            }

            else if(wyb2=='2')
            {
                system("cls");
                cin.clear();
                cin.sync();

                cout << "Wyszukaj film: ";
                getline(cin, szukane);
                system("cls");

                for(size_t i=0; i<film::liczba_filmow; i++)
                {
                    if(films[i].tytul==szukane)
                    {
                        ptr = &films[i];
                        ptr -> wypisz();
                        bufor++;
                    }
                }
                if(bufor==0)
                {
                    cout << "Brak filmu *" << szukane << "* w biblioteczce" << endl << endl;
                }
                szukane.clear();
                bufor = 0;

                system("PAUSE");
                system("cls");
            }

            else if(wyb2=='3')
            {
                system("cls");
                cin.clear();
                cin.sync();

                cout << "Wyszukaj album muzyczny: ";
                getline(cin, szukane);
                system("cls");

                for(size_t i=0; i<muzyka::liczba_albumow; i++)
                {
                    if(music[i].nazwa==szukane)
                    {
                        ptr = &music[i];
                        ptr -> wypisz();
                        bufor++;
                    }
                }
                if(bufor==0)
                {
                    cout << "Brak albumu *" << szukane << "* w biblioteczce" << endl << endl;
                }
                szukane.clear();
                bufor = 0;

                system("PAUSE");
                system("cls");
            }

            else if(wyb2=='4')
            {
                system("cls");
                cin.clear();
                cin.sync();

                cout << "Wyszukaj gre: ";
                getline(cin, szukane);
                system("cls");

                for(size_t i=0; i<gra::liczba_gier; i++)
                {
                    if(games[i].tytul==szukane)
                    {
                        ptr = &games[i];
                        ptr -> wypisz();
                        bufor++;
                    }
                }
                if(bufor==0)
                {
                    cout << "Brak gry *" << szukane << "* w biblioteczce" << endl << endl;
                }
                szukane.clear();
                bufor = 0;

                system("PAUSE");
                system("cls");
            }
            else {system("cls");}
            break;
        }

    case '2':
        {
            menu_v2();
            cin >> wyb2;

            if(wyb2=='1')
            {
                system("cls");
                ptr = &books[ksiazka::liczba_ksiazek];
                ptr -> dodaj();
            }

            else if(wyb2=='2')
            {
                system("cls");
                ptr = &films[film::liczba_filmow];
                ptr -> dodaj();
            }

            else if(wyb2=='3')
            {
                system("cls");
                ptr = &music[muzyka::liczba_albumow];
                ptr -> dodaj();
            }

            else if(wyb2=='4')
            {
                system("cls");
                ptr = &games[gra::liczba_gier];
                ptr -> dodaj();
            }

            else {system("cls");}

            break;
        }
    case '3':
        {
            menu_v2();
            cin >> wyb2;

            if(wyb2=='1')
            {
                system("cls");
                cin.clear();
                cin.sync();

                cout << "Podaj tytul ksiazki, ktora chcesz usunac: ";
                getline(cin, szukane);
                system("cls");

                for(size_t i=0; i<ksiazka::liczba_ksiazek; i++)
                {
                    if(books[i].tytul==szukane)
                    {
                        books[i].usun(books[ksiazka::liczba_ksiazek-1]);
                        bufor++;
                    }
                }
                if(bufor==0)
                {
                    cout << "Brak ksiazki *" << szukane << "* w biblioteczce" << endl << endl;
                    system("PAUSE");
                    system("cls");
                }
                szukane.clear();
                bufor = 0;
            }

            else if(wyb2=='2')
            {
                system("cls");
                cin.clear();
                cin.sync();

                cout << "Podaj tytul filmu, ktora chcesz usunac: ";
                getline(cin, szukane);
                system("cls");

                for(size_t i=0; i<film::liczba_filmow; i++)
                {
                    if(films[i].tytul==szukane)
                    {
                        films[i].usun(films[film::liczba_filmow-1]);
                        bufor++;
                    }
                }
                if(bufor==0)
                {
                    cout << "Brak filmu *" << szukane << "* w biblioteczce" << endl << endl;
                    system("PAUSE");
                    system("cls");
                }
                szukane.clear();
                bufor = 0;
            }

            else if(wyb2=='3')
            {
                system("cls");
                cin.clear();
                cin.sync();

                cout << "Podaj tytul albumu, ktorego chcesz usunac: ";
                getline(cin, szukane);
                system("cls");

                for(size_t i=0; i<muzyka::liczba_albumow; i++)
                {
                    if(music[i].nazwa==szukane)
                    {
                        music[i].usun(music[muzyka::liczba_albumow-1]);
                        bufor++;
                    }
                }
                if(bufor==0)
                {
                    cout << "Brak albumu *" << szukane << "* w biblioteczce" << endl << endl;
                    system("PAUSE");
                    system("cls");
                }
                szukane.clear();
                bufor = 0;

            }
            else if(wyb2=='4')
            {
                system("cls");
                cin.clear();
                cin.sync();

                cout << "Podaj nazwe gry, ktora chcesz usunac: ";
                getline(cin, szukane);
                system("cls");

                for(size_t i=0; i<gra::liczba_gier; i++)
                {
                    if(games[i].tytul==szukane)
                    {
                        games[i].usun(games[gra::liczba_gier-1]);
                        bufor++;
                    }
                }
                if(bufor==0)
                {
                    cout << "Brak gry *" << szukane << "* w biblioteczce" << endl << endl;
                    system("PAUSE");
                    system("cls");
                }
                szukane.clear();
                bufor = 0;
            }

            else {system("cls");}
            break;
        }

    case '4':
        {
            if(pozycja::liczba_pozycji != 0)
            {
                statystyka s;
                s.show_stats();
                break;
            }
            else
            {
                cout << "BRAK STATYSTYK DO WYSWIETLENIA" << endl << endl;
                system("PAUSE");
                system("cls");
                break;
            }
        }

    case '5':
        {
            cout << "WYJSCIE" << endl << endl;
            system ("PAUSE");
            zapis(books, music, films, games);
            exit (0);
        }
    }
}
}
