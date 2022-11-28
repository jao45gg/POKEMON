#ifndef _EFEITOS_CPP
#define _EFEITOS_CPP

#include "../include/Efeitos.hpp"
#include <iostream>

using namespace std;

void Efeitos::setNome (string nome){
    _nome = nome;
}
void Efeitos::setDuracao (int duracao){
    _duracao = duracao;
}
string Efeitos::getNome (){
    return _nome;
}
int Efeitos::getDuracao(){
    return _duracao;
}

//Efeitos::Efeitos(string nome, unsigned int duracao){

    //_nome = nome;
    //_duracao = duracao;

//}

//Efeitos::~Efeitos(){}

#endif