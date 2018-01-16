#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include <ostream>
#include "KwotaPoch.h"
#pragma once
using namespace std;

template<typename Typ>class tablicaKwot{
    vector <Typ> k_;
public:
    tablicaKwot(string File);
    tablicaKwot& operator++();
    tablicaKwot& operator--();
    void zapisywanie(string File);
    void szukanie(string s);
    double suma();
    Typ wezKlase(int i) const;
    template<typename U>
    friend ostream& operator<<(ostream& stream, const tablicaKwot<U>& t);
};

#include "tablicaKwot.txt"
