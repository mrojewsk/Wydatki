#include <iostream>
#include "Kwota.h"
#include <ctime>
#include <sstream>
#include <vector>
#include <ostream>
#include <fstream>
#include <istream>
#pragma once

using namespace std;

class KwotaPoch: public Kwota{
    double pochodna_;
public:
    KwotaPoch();
    KwotaPoch(double s, Kwota k);
    KwotaPoch(double s, string c, double k);
    KwotaPoch(double s, string c, double k, time_t t);
    KwotaPoch& operator=(KwotaPoch k);
    double wezPochodna() const;
    string doPliku();
    friend ofstream& operator<<(ofstream& stream, const KwotaPoch& k);
    friend ostream& operator<<(ostream& stream, const KwotaPoch& k);
    friend istream& operator>>(istream& stream, KwotaPoch& k);
    double odsetki() const;
};
