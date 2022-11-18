#ifndef _HABILIDADES_HPP_
#define _HABILIDADES_HPP_

#include "Efeitos.hpp"

#include <iostream>


using namespace std;

class Habilidades{
private:
    int _tempoRecarga;
    Efeitos _efeito;
protected:
    string _nome;
public:
    Habilidades(int tempoRecarga, string nome, Efeitos efeito);
    ~Habilidades();
    Efeitos* getEfeito();
    int gettempoRecarga();
};

#endif
