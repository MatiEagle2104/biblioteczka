#include "manager.h"
#include "pozycja.h"
#include "ksiazka.h"
#include "film.h"
#include "muzyka.h"
#include "gra.h"
#include "statystyka.h"

#include <iostream>

using namespace std;

int main()
{
    pozycja * ptr;

    ksiazka a[250];
    muzyka b[100];
    film c[100];
    gra d[50];

    manager e;
    e.odczyt(a, b, c, d);
    e.aplikacja(ptr, a, b, c, d);

    return 0;
}
