#ifndef MUZYKA_H_INCLUDED
#define MUZYKA_H_INCLUDED

class muzyka:public pozycja{
private:
    std::string autor;
    int rzad;
    int polka;

public:
    std::string nazwa;
    static int liczba_albumow;

    muzyka();
    muzyka(std::string type, std::string title, std::string author, int row, int shelf);
    muzyka(muzyka & kopia);
    muzyka & operator=(const muzyka &)
    {
        return *this;
    }

    ~muzyka();

    void wypisz();
    void dodaj();
    void usun(muzyka & m2);
    friend class manager;
};

#endif // MUZYKA_H_INCLUDED
