#ifndef _EFEITOS_HPP_
#define _EFEITOS_HPP_

#include <iostream>

using namespace std;

class Efeitos {


    //VARIAVEIS
    protected:

    string _nome;
    int _duracao;

    //METODOS
    public:

    void setNome(string nome);
    string getNome();
    void setDuracao(int duracao);
    int getDuracao();


    //Efeitos(string nome, unsigned int duracao);
    //~Efeitos();

};
#endif
