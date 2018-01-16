#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include "tablicaKwot.h"
#include <ctime>
#include <vector>
#include <ostream>
#include "KwotaPoch.h"

using namespace std;


int main()
{
    tablicaKwot<KwotaPoch> Zyski("Zyski.txt");
    tablicaKwot<KwotaPoch> Wydatki("Wydatki.txt");
    tablicaKwot<int> Inty("Inty.txt");

    cout<<"Oto program do analizy wydatkow"<<endl;
    while(9)
    {
        cout<<"Wybierz jedna z opcji:"<<endl
        <<"1-Dodaj nowa kwote"<<endl
        <<"2-Usun kwote"<<endl
        <<"3-Analiza zyskow i strat"<<endl
        <<"4-Dzialanie na tablicy intow"<<endl
        <<"5-Testowanie klasy pochodnej"<<endl
        <<"6-Wyjdz z programu"<<endl;

        int zmienna;
        cin>>zmienna;
        cout<<endl;
        switch (zmienna)
        {
            case 1:
            {
                cout<<"Chcesz dodac zysk czy wydatek?"<<endl
                <<"1-Zysk"<<endl
                <<"2-Wydatek"<<endl;
                int dodawanie;
                cin>>dodawanie;
                switch(dodawanie){
                    case 1:
                    {
                        ++Zyski;
                        break;
                    }
                    case 2:
                    {
                        ++Wydatki;
                        break;
                    }
                    break;
                };
            break;
            }; //KONIEC CASE 1

        case 2: //USUWANIE
        {
            cout<<"Chcesz usunac zysk czy wydatek"<<endl
            <<"1-Zysk"<<endl
            <<"2-wydatek"<<endl;
            int usuw;
            cin>>usuw;
            cout<<endl;
            switch (usuw)
            {
                case 1:
                {
                    --Zyski;
                    break;
                };
                case 2:
                {
                    --Wydatki;
                    break;
                };
                break;
            };
            break;
        }; //KONIEC CASE 2

        case 3:
        {
            cout<<"Dostepne sa opcje:"<<endl
            <<"1-Wyswietl dane"<<endl
            <<"2-Bilans zyskow i strat"<<endl
            <<"3-Wyszukaj wszystkie zyski i wydatki z konkretnego dnia"<<endl;
            int analiza;
            cin>>analiza;
            cout<<endl;
            switch (analiza)
            {
                case 1:
                {
                    cout<<"Wydatki sa nastepujace:"<<endl<<Wydatki<<endl;
                    cout<<"Zyski sa nastepujace:"<<endl<<Zyski<<endl;
                    cout<<endl;
                    break;
                };
                case 2:
                {
                    cout<<"Suma zyskow wynosi: "<<Zyski.suma()<<endl;
                    cout<<"Suma wydatkow wynosi: "<<Wydatki.suma()<<endl;
                    cout<<"Bilans zyskow i strat wynosi: "<<Zyski.suma()-Wydatki.suma()<<endl<<endl;
                    break;
                };
                case 3:
                {
                    cout<<"Wprowadz szukana date w formacie dd.mm.yyyy: ";
                    string data;
                    cin>>data;
                    cout<<"Nastepujace zyski spelniaja oczekiwanie:"<<endl;
                    Zyski.szukanie(data);
                    cout<<"Nastepujace wydatki spelniaja oczekiwanie:"<<endl;
                    Wydatki.szukanie(data);
                    cout<<endl;
                    break;
                };
                break;
            };
        break;
        };  //KONIEC CASE 3
        case 4:
        {
            cout<<"Dostepne sa opcje:"<<endl
            <<"1-Wyswietl dane"<<endl
            <<"2-Dodaj dane"<<endl
            <<"3-Usun dane"<<endl;
            int dana;
            cin>>dana;
            switch(dana)
            {
                case 1:
                {
                    cout<<"Dane sa nastepujace:"<<endl;
                    cout<<Inty<<endl;
                    break;
                };
                case 2:
                {
                    ++Inty;
                    break;
                };
                case 3:
                {
                    --Inty;
                    break;
                };
                break;
            };
            break;
        };                 //KONIEC CASE 4
        case 5:
        {
            cout<<"Wprowadz nazwe, kwote i oprocentowanie: ";
            string s; double k; double d;
            cin>>s>>k>>d;
            Kwota* bazowa[1];
            bazowa[0] = new KwotaPoch(d, s, k);
            cout<<"Odsetki obliczone za pomoca metody wirtualnej to: "<<bazowa[0]->odsetki()<<"zl;"<<endl<<endl;
            delete bazowa;
            break;
        };
        case 6:
        {
            Zyski.zapisywanie("Zyski.txt");
            Wydatki.zapisywanie("Wydatki.txt");
            Inty.zapisywanie("Inty.txt");
            return 0;
        };
        break;
        };                            //Koniec petli switch
    };                              //Koniec petli while
}                                     //Koniec funkcji main
