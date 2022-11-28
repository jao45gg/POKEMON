#ifndef _BARALHO_CPP
#define _BARALHO_CPP

#include "Baralho.hpp"

using namespace std;

Baralho::Baralho(vector<Cartas> cartasP, string nomeP)
{
    this->_cartas = cartasP;
    this->_nome = nomeP;
};

Baralho::~Baralho()
{
    (this->_cartas).clear();
    this->_nome = "";
};

string Baralho::getNome()
{
    return this->_nome;
};

void Baralho::setNome(string nomeP)
{
    this->_nome = nomeP;
};

Cartas Baralho::getCarta(int num)
{
    for (int i = 0, ie = _cartas.size(); i < ie; i++)
    {
        if (i == num)
            return _cartas[i];
    }
};

void Baralho::removeCarta(string nome) {
    bool control = true;
    int ie = 0;
    for(auto i = _cartas.begin(); control; i++) {
        if(_cartas.at(ie).getNome() == nome) {
            _cartas.erase(i);
            break;
        }
        ie++;     
    }
}

int Baralho::getSize() {
    return _cartas.size();
}

#endif