#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>
#include <ostream>
#include <fstream>
#include <istream>
#pragma once

using namespace std;

class Kwota{
protected:
    time_t czas_;
    double kwota_;
    string nazwa_;
public:
    Kwota();
    Kwota(string c, double k);
    Kwota(string c, double k, time_t t);
    double wezKwote() const;
    string wezNazwe() const;
    time_t wezCzas() const;
    string wezCzasJakoString() const;
    string doPliku();
    friend ofstream& operator<<(ofstream& stream, const Kwota& k);
    friend ostream& operator<<(ostream& stream, const Kwota& k);
    friend istream& operator>>(istream& stream, Kwota& k);
    Kwota& operator=(Kwota k);
    double operator+(double k);
    virtual double odsetki() const;
};
