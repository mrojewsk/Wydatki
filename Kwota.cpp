#include <iostream>
#include "Kwota.h"
#include <ctime>
#include <sstream>
#include <vector>
#include <ostream>
#include <fstream>
#include <istream>

 Kwota::Kwota()
{
    kwota_=0;
    nazwa_="";
    time(&czas_);
}

Kwota::Kwota(string c, double k)
{
    kwota_=k; nazwa_=c; time(&czas_);
}

Kwota::Kwota(string c, double k, time_t t)
{
    kwota_=k; nazwa_=c; czas_=t;
}

double Kwota::wezKwote() const
{
    return kwota_;
}

string Kwota::wezNazwe() const
{
    return nazwa_;
}

long int Kwota::wezCzas() const
{
    return czas_;
}

string Kwota::wezCzasJakoString() const
{
    tm* time=localtime(&czas_);
    stringstream i;
    i<<time->tm_mday<<"."<<1+time->tm_mon<<"."<<1900+time->tm_year;
    return i.str();
}

string Kwota::doPliku()
{
    stringstream ss;
    ss<<czas_<<" "<<nazwa_<<" "<<kwota_;
    return ss.str();
}

ofstream& operator<<(ofstream& stream, const Kwota& k)
{
    stream<<k.wezCzas()<<" "<<k.wezNazwe()<<" "<<k.wezKwote();
    return stream;
}

ostream& operator<<(ostream& stream, const Kwota& k)
{
    stream<<k.wezCzasJakoString()<<"r. "<<k.wezNazwe()<<" "<<k.wezKwote()<<" zl,";
    return stream;
}

istream& operator>>(istream& stream, Kwota& k)
{
    double x; string y; time_t z;
    stream>>z>>y>>x;
    Kwota c(y,x,z);
    k=c;
}

Kwota& Kwota::operator=(Kwota k)
{
    kwota_=k.wezKwote();
    nazwa_=k.wezNazwe();
    czas_=k.wezCzas();
}

double Kwota::operator+(double k)
{
    double c;
    c=k+wezKwote();
    return c;
}

double Kwota::odsetki() const
{
    return 0;
}
