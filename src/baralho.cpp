#ifndef _BARALHO_CPP
#define _BARALHO_CPP

#include "Baralho.hpp"
#include "Cartas.hpp"
#include <vector>
#include <iostream>

using namespace std;

Baralho::Baralho(vector<Cartas> &cartasP, string nomeP, vector<Cartas> &cartasExistentes)
{
    this->_nome = nomeP;
    while(((this->_cartas).size()) <= 60){
        string nomeCarta;
        cin >> nomeCarta;
        bool existeCarta = false;
        for(int j = 0, je = (cartasExistentes.size()); j < je; j++){
            string *procuraNome = ((cartasExistentes.at(j)).getNome());
            if(nomeCarta == *procuraNome){
                (this->_cartas).push_back(cartasExistentes.at(j));
                existeCarta = true;
                break;
            }
        }
        if(!existeCarta){
            cout << "Nao existe carta com esse nome" << endl;
        }
    }
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