#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>
#include <ostream>
#include <fstream>
#include <istream>
#include "KwotaPoch.h"

using namespace std;

KwotaPoch::KwotaPoch(double s,Kwota k)
{
    kwota_=k.wezKwote();
    czas_=k.wezCzas();
    nazwa_=k.wezNazwe();
    pochodna_=s;
}


KwotaPoch::KwotaPoch()
{
    kwota_=0;
    nazwa_="";
    time(&czas_);
    pochodna_=0;
}

KwotaPoch::KwotaPoch(double s, string c, double k)
{
    kwota_=k;
    nazwa_=c;
    time(&czas_);
    pochodna_=s;
}

KwotaPoch::KwotaPoch(double s, string c, double k,  time_t t)
{
    kwota_=k; nazwa_=c; czas_=t;
    pochodna_=s;
}

double KwotaPoch::wezPochodna() const
{
    return pochodna_;
}

KwotaPoch& KwotaPoch::operator=(KwotaPoch k)
{
    kwota_=k.wezKwote();
    nazwa_=k.wezNazwe();
    czas_=k.wezCzas();
    pochodna_=k.wezPochodna();
}

string KwotaPoch::doPliku()
{
    stringstream ss;
    ss<<Kwota::doPliku()<<" "<<pochodna_;
    return ss.str();
}

//Powyzszcza funkcja pelni identyczna role jak ponizszy OFSTREAM

ofstream& operator<<(ofstream& s, const KwotaPoch& k)
{
    const Kwota& b(k);
    s<<b<<" "<<k.wezPochodna();
    return s;
}

ostream& operator<<(ostream& s, const KwotaPoch& k)
{
    const Kwota& b(k);
    s<<b<<" przy oporcentowaniu: "<<k.wezPochodna()*100<<"% zmiana w skali roku wynosi: "<<k.odsetki();
    return s;
}

istream& operator>>(istream& a, KwotaPoch& k)
{
    time_t t; string s; double d; double p;
    a>>t>>s>>d>>p;
    KwotaPoch po(p, s, d, t);
    k=po;
}

double KwotaPoch::odsetki() const
{
    double k;
    k=kwota_*pochodna_;
    return k;
}
