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

    Baralho();
    Baralho(string nomeP, vector<Cartas> &cartasExistentes);
    ~Baralho();
    string getNome();
    vector<Cartas> getCartasBaralho();
    //void operator=(Baralho &operando);
    void setNome(string nomeP);
    Cartas getCarta(int num);
    void removeCarta(string nome);
    int getSize();
    void setCartas(vector<Cartas> cartasP);
    void mostraBaralho();
};
#endif