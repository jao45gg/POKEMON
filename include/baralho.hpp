#ifndef BARALHO_HPP
#define BARALHO_HPP

#include "Cartas.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Baralho{
    protected:
    vector <Cartas> _cartas;
    string _nome;

    public:
    Baralho(vector <Cartas> cartasP, string nomeP);
    ~Baralho();
    string getNome();
    void setNome(string nomeP);
};
#endif