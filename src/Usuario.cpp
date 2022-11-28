#ifndef _USUARIO_CPP
#define _USUARIO_CPP

#include "../include/Usuario.hpp"

Usuario::Usuario()
{
    this->nome = "Jogador";
    this->vitorias = 0;
    this->derrotas = 0;
    this->baralhos = {};
}

Usuario::~Usuario()
{

}
Usuario::Usuario(std::string nome, int vitorias, int derrotas, std::vector<Baralho> baralhos)
{
    this->nome = nome;
    this->vitorias = 0;
    this->derrotas = 0;
    this->baralhos = baralhos;
}

int Usuario::getVitorias()
{
    return this->vitorias;
}

int Usuario::getDerrotas()
{
    return this->derrotas;
}
void Usuario::setVitorias(int vitorias)
{
    this->vitorias++;
}
void Usuario::setDerrotas(int derrotas)
{
    this->derrotas++;
}
std::string Usuario::getNome()
{
    return this->nome;
}
std::vector<Baralho> Usuario::getBaralhos()
{
    return this->baralhos;
}
void Usuario::setBaralhos(Baralho baralho)
{
    this->baralhos.push_back(baralho);
}
std::string Usuario::toString()
{
    std::string retorno = "Nome: " + this->nome + "\n";
    retorno += "Vitorias: " + std::to_string(this->vitorias) + "\n";
    retorno += "Derrotas: " + std::to_string(this->derrotas) + "\n";
    retorno += "Baralhos:";
    for (int i = 0; i < this->baralhos.size(); i++)
    {
        retorno += this->baralhos[i].getNome() + "\n";
    }
    return retorno;
}

#endif