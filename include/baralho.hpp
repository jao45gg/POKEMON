#ifndef BARALHO_HPP
#define BARALHO_HPP

#include "carta.hpp"
#include <vector>

using namespace std;

class Baralho{
    protected:
    vector <Carta> _cartas;
    string _nome;

    public:
    Baralho(vector <Carta> cartasP, string nomeP);
    ~Baralho();
    string getNome();
    void setNome(string nomeP);
}

#endif