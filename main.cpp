
/*Dana jest prostokątna tablica o m wierszach i n kolumnach, gdzie 1 ≤ m, n ≤ 5000. Komórki tej tablicy mają wartość 0 lub 1. Możliwa jest zmiana wartości dowolnej komórki tablicy z wyjątkiem komórek leżących w pierwszym rzędzie, przy czym pociąga ona za sobą zmianę wartości na przeciwne w czterech komórkach sąsiadujących (górnej, dolnej, lewej i prawej). Np. w tablicy:

1 0 1

1 1 1

0 1 0
zmiana w pozycji (1, 1) przekształci tablicę do następującego stanu:

1 1 1

0 0 0

0 0 0
Jeżeli komórka wskazana do zmiany znajduje się na granicy tablicy, zamienia się tylko sąsiadów znajdujących się w tablicy.

Zadanie polega na stwierdzeniu, czy możliwe jest wyzerowanie tablicy, a jeżeli tak, jaka najmniejsza liczba kroków jest do tego potrzebna. Jako pojedynczy krok rozumiana jest zamiana wskazanej komórki tablicy razem z jej sąsiedztwem.

Wejście

        W pierwszej linii wejścia znajdują się wartości m i n - rozmiary tablicy.
W następnych m wierszach znajduje się n 0 lub 1 rozdzielonych spacjami - zawartość tablicy.

Wyjście

        Jeżeli wyzerowanie tablicy jest możliwe, na wyjściu należy wyświetlić minimalną liczbę kroków, które są do tego potrzebne. W przeciwnym razie należy wyświetlić napis "niemozliwe".

Przykład 1

Wejście

3 3
0 1 0
1 1 1
0 1 0
Wyjście

1*/




#include <iostream>


using namespace std;

int licznik=0;
void switch_t(bool **tab,int b , int a)
{
    for(int i=1;i<b;i++)
    {
        for(int j=0;j<a;j++)
        {
            if(tab[i-1][j]==1 && licznik!=-1)
            {
                licznik++;

                tab[i][j]=!tab[i][j];

                if(j-1>=0)
                {
                    tab[i][j-1]=!tab[i][j-1];
                }

                if(j+1<a)
                {
                    tab[i][j+1]=!tab[i][j+1];
                }

                if(i-1>=0)
                {
                    tab[i-1][j]=!tab[i-1][j];
                }

                if(i+1<b)
                {
                    tab[i+1][j]=!tab[i+1][j];
                }


            }
        }
    }
}

int main(int argc, char *argv[])
{

    int b,a;
    cin>>b;
    cin>>a;

    bool **tab2 = new bool *[b];
    for ( int i = 0; i < b; ++i )
    {
        tab2[i] = new bool [a];
    }

    for(int i=0;i<b;i++)
    {
        for(int j=0;j<a;j++)
        {
            cin>>tab2[i][j];
        }
    }

    switch_t(tab2,b,a);

    for(int i=0;i<b;i++)
    {
        for(int j=0;j<a;j++)
        {
            if(tab2[i][j]==1)
            {
                licznik= -1;
                break;
            }
        }
    }

    if (licznik==-1)
    {
        cout<<"niemozliwe";
    }
    else
    {
        cout<<licznik;
    }

    for ( int i=0; i < b; ++i )
    {
        delete [] tab2[i];

    }
    delete [] tab2;

    return 0;
}