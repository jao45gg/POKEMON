#ifndef BARALHO_HPP
#define BARALHO_HPP

#include "Cartas.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Baralho
{
private:
    vector<Cartas> _cartas;
    string _nome;

public:
    Baralho(vector<Cartas> cartasP, string nomeP);
    ~Baralho();
    string getNome();
    void setNome(string nomeP);
    Cartas getCarta(int num);
    void removeCarta(string nome);
    int getSize();
};
#endif
