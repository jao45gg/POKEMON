#include "../include/Habilidades.hpp"
#include <iostream>

using namespace std;

Habilidades::Habilidades(int tempoRecarga, string nome, Efeitos efeito){
    _tempoRecarga = tempoRecarga;
    _nome = nome;
    _efeito.setNome(efeito.getNome());
    _efeito.setDuracao(efeito.getDuracao());
}
Efeitos* Habilidades::getEfeito(){
    Efeitos* efeito;
    return efeito;
}
int Habilidades:: gettempoRecarga(){
    return _tempoRecarga;
}
