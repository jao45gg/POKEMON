Skip to content
jao45gg
/
POKEMON
Public
Code
Issues
7
Pull requests
Actions
Projects
Wiki
More
POKEMON/include/Efeitos.hpp
@gabriezim
gabriezim Update Efeitos.hpp
 History
 2 contributors
@thaismadeira10@gabriezim
30 lines (19 sloc)  392 Bytes
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
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
POKEMON/Efeitos.hpp at Gabriel · jao45gg/POKEMON
