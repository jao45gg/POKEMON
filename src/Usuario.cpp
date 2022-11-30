#ifndef _USUARIO_CPP
#define _USUARIO_CPP

#include "../include/Usuario.hpp"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <sstream>

Usuario::Usuario()
{
    this->nome = "Jogador";
    this->vitorias = 0;
    this->derrotas = 0;
    this->baralhos = {};
}

Usuario::~Usuario()
{
    this->nome = "";
    vitorias = 0;
    derrotas = 0;
    baralhos.clear();
}

Usuario::Usuario(std::string nome)
{
    this->nome = nome;
    this->vitorias = 0;
    this->derrotas = 0;

    ifstream myfile;
    myfile.open("pokemons.txt");
    
    vector<Cartas> cartasExistentes;
    string nome_pokemon;
    int qtnd_atks;
    vector<pair<string, int> > ataque;
    int defesa;
    string tipo;
    int hp;

    if (myfile.is_open())
    {
        int i = 0;
        while (myfile)
        {
            getline(myfile, nome_pokemon), '\n';

            string tmp,nome_atk;
            int dano;

            getline(myfile, tmp);
            sscanf(tmp.c_str(), "%d", &qtnd_atks);
            
            for (int i = 0, ie = qtnd_atks; i < ie; i++)
            {
                string line, tmp;
                getline(myfile, line);
                istringstream iss(line);
                getline(iss, nome_atk, ':');

                getline(iss, tmp, '\n');
                istringstream(tmp) >> dano;

                pair<string, int> foo;
                foo = make_pair(nome_atk, dano);
                ataque.push_back(foo);
            }
            
            getline(myfile, tmp);
            sscanf(tmp.c_str(), "%d", &defesa);

            getline(myfile, tipo);

            getline(myfile, tmp);
            sscanf(tmp.c_str(), "%d", &hp);

            cartasExistentes.push_back(Cartas (nome_pokemon, qtnd_atks, ataque, defesa, tipo, hp));
         
        }
    }
    else
        std::cout << "Falha ao abrir o arquivo \n";

    string nomeBaralho;
    cout << "Qual será o nome do baralho?\n";
    cin >> nomeBaralho;
    baralhos.push_back(Baralho (nomeBaralho, cartasExistentes));
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