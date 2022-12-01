#ifndef _USUARIO_CPP
#define _USUARIO_CPP

#include "../include/Usuario.hpp"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

Usuario::Usuario()
{
    this->nome = "Jogador";
    this->vitorias = 0;
    this->derrotas = 0;
    this->baralhos.clear();
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

    vector<Cartas> cartasExistentes;
    string nome_pokemon;
    int qtnd_atks;
    vector<pair<string, int>> ataque;
    int defesa;
    string tipo;
    int hp;

    bool condicao = true;
    int i = 0;
    int teste = 10;
    while (condicao)
    {
        if (this->nome == "bot")
            cout << "Insira ao menos 10 cartas para o bot!\n\n";
        else
            cout << "Insira ao menos 10 cartas para o jogador!\n\n";

        cout << "Insira o nome do pokemon\n";
        cin >> nome_pokemon;

        string tmp, nome_atk;
        int dano;

        cout << "Insira a quantidade de ataques do pokemon\n\n";
        cin >> qtnd_atks;

        for (int i = 0, ie = qtnd_atks; i < ie; i++)
        {
            cout << "Insira o nome do ataque\n\n";
            cin >> nome_atk;

            cout << "Insira o dano do ataque\n\n";
            cin >> dano;

            pair<string, int> foo;
            foo = make_pair(nome_atk, dano);
            ataque.push_back(foo);
        }

        cout << "Insira a defesa\n\n";
        cin >> defesa;

        cout << "Insira o tipo\n\n";
        cin >> tipo;

        cout << "Insira o hp\n\n";
        cin >> hp;

        cartasExistentes.push_back(Cartas(nome_pokemon, qtnd_atks, ataque, defesa, tipo, hp));
        if (i == teste - 1)
        {
            char c;
            cout << "Deseja inserir mais cartas ? (s/n) \n";
            cin >> c;
            if (c == 'n')
                condicao = false;
            else if (c == 's')
            {
                int n;
                cout << "quantas ?\n";
                cin >> n;
                teste += n;
            }
        }
        i++;
    }

    string nomeBaralho;
    cout << "Qual será o nome do baralho?\n";
    cin >> nomeBaralho;
    baralhos.push_back(Baralho(nomeBaralho, cartasExistentes));
}

int Usuario::getVitorias()
{
    return this->vitorias;
}

int Usuario::getDerrotas()
{
    return this->derrotas;
}
void Usuario::setVitorias()
{
    this->vitorias++;
}
void Usuario::setDerrotas()
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