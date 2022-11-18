#ifndef BARALHO_CPP
#define BARALHO_CPP

#include "baralho.hpp"
#include "carta.hpp"
#include <vector>
#include <iostream>

using namespace std;

Baralho::Baralho(vector <Carta> cartasP, string nomeP){
    this->_cartas = cartasP;
    this->_nome = nomeP;
};

Baralho::~Baralho(){
    (this->_cartas).clear();
    this->_nome = "";
};

string Baralho::getNome(){
    return this->_nome;
};

void Baralho::setNome(string nomeP){
    this->_nome = nomeP;
};

#endif