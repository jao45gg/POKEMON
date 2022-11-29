#ifndef _USUARIO_CPP
#define _USUARIO_CPP

#include "../include/Usuario.hpp"
#include <fstream>

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
Usuario::Usuario(std::string nome)
{
    this->nome = nome;
    this->vitorias = 0;
    this->derrotas = 0;
    vector<Cartas> cartasExistentes;

    std::ifstream myfile;
    myfile.open("pokemons.txt");
    std::string nome_pokemon;
    int ataque;
    int defesa;
    string tipo;
    int hp;
    if (myfile.is_open())
    {
        while (myfile)
        {
            std::getline(myfile, nome_pokemon);
            myfile >> ataque;
            myfile >> defesa;
            std::getline(myfile, tipo);
            myfile >> hp;
            cartasExistentes.push_back(Cartas(nome_pokemon, ataque, defesa, tipo, hp));
        }
    }
    else
        std::cout << "Falha ao abrir o arquivo \n";

    string nomeBaralho;
    cout << "Qual será o nome do baralho?\n";
    cin >> nomeBaralho;
    vector<Cartas> cartasP;
    Baralho b = Baralho(cartasP, nomeBaralho, cartasExistentes); // funcionará com o prox atualizacao de baralho
    baralhos.push_back(b);
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