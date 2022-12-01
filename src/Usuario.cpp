#ifndef _USUARIO_CPP
#define _USUARIO_CPP

#include "Usuario.hpp"
#include "Cartas.hpp"
#include "baralho.hpp"
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

Usuario::Usuario(string nome)
{
    //cout << "criou o objeto usuario" << endl;
    this->nome = nome;
    this->vitorias = 0;
    this->derrotas = 0;
    
    vector<Cartas> cartasExistentes;
    //string nome_pokemon;
    vector<pair<string, int> > ataque;
    //int defesa;
    //string tipo;
    //int hp;

    //bool condicao = true;
    //int i = 0;
    //int teste = 10;
    //int cartasAddJog = 0;

    if(nome == "bot"){
        //cout << "aqui foi" << endl;
        vector<pair<string, int>> ataque;
        pair<string, int> foo;
        foo = make_pair("Mordida", 10);
        ataque.push_back(foo);
        Cartas aux = Cartas("Bulbasaur", 1, ataque, 15, "Planta", 70);
        cartasExistentes.push_back(aux);
        Cartas aux1 = Cartas("Ivysaur", 1, ataque, 15, "Planta", 70);
        cartasExistentes.push_back(aux1);
        Cartas aux2 = Cartas("Venusaur", 1, ataque, 15, "Planta", 70);
        cartasExistentes.push_back(aux2);
        Cartas aux3 = Cartas("Charmander", 1, ataque, 15, "Fogo", 70);
        cartasExistentes.push_back(aux3);
        Cartas aux4 = Cartas("Charmeleon", 1, ataque, 15, "Fogo", 70);
        cartasExistentes.push_back(aux4);
        Cartas aux5 = Cartas("Charizard", 1, ataque, 15, "Fogo", 70);
        cartasExistentes.push_back(aux5);
        Cartas aux6 = Cartas("Squirtle", 1, ataque, 15, "Agua", 70);
        cartasExistentes.push_back(aux6);
        Cartas aux7 = Cartas("Wartortle", 1, ataque, 15, "Agua", 70);
        cartasExistentes.push_back(aux7);
        Cartas aux8 = Cartas("Blastoise", 1, ataque, 15, "Agua", 70);
        cartasExistentes.push_back(aux8);
        Cartas aux9 = Cartas("Caterpie", 1, ataque, 15, "Inseto", 70);
        cartasExistentes.push_back(aux9);
        Cartas aux10 = Cartas("Metapod", 1, ataque, 15, "Inseto", 70);
        cartasExistentes.push_back(aux10);
        Cartas aux11 = Cartas("Butterfree", 1, ataque, 15, "Inseto", 70);
        cartasExistentes.push_back(aux11);
        Cartas aux12 = Cartas("Pikachu", 1, ataque, 15, "Eletrico", 70);
        cartasExistentes.push_back(aux12);
        Cartas aux13 = Cartas("Raichu", 1, ataque, 15, "Eletrico", 70);
        cartasExistentes.push_back(aux13);
        Cartas aux14 = Cartas("Psyduck", 1, ataque, 15, "Agua", 70);
        cartasExistentes.push_back(aux14);
        Cartas aux15 = Cartas("Golduck", 1, ataque, 15, "Agua", 70);
        cartasExistentes.push_back(aux15);
        Baralho ajuda = Baralho();
        ajuda.setNome("Baralho do Bot");
        ajuda.setCartas(cartasExistentes);
        (this->baralhos).push_back(ajuda);
        //cout << "foi certinho pro bot, finalizando..." << endl;
        //break; 
    }
    else if((this->nome) != "bot"){
        string nomeBaralho;
        int adicionadas = 0;
        cout << "Digite o nome do baralho: \n";
        cin >> nomeBaralho;
        Baralho novo = Baralho();
        novo.setNome(nomeBaralho);
        while(adicionadas < 15){
            ataque.clear();

            //int i = (cartasExistentes.size());
            // cout << "Digite o nome do pokemon [" << i << "] :\n";
            // cin >> nome_pokemon;
            // cout << "Digite o nome do ataque do pokemon [" << i << "] :\n";
            // string nomeAtaque;
            // cin >> nomeAtaque;
            // int danoAtaque;
            // cout << "Digite o dano do ataque do pokemon [" << i << "] :\n";
            // cin >> danoAtaque;
            // pair<string, int> foo;
            // foo = make_pair(nomeAtaque, danoAtaque);
            // ataque.push_back(foo);
            // cout << "Digite a defesa do pokemon [" << i << "] :\n";
            // cin >> defesa;
            // cout << "Digite o tipo do pokemon [" << i << "] :\n";
            // cin >> tipo;
            // cout << "Digite o hp do pokemon [" << i << "] :\n";
            // cin >> hp;
            // Cartas aux = Cartas(nome_pokemon, 1, ataque, defesa, tipo, hp);

            pair<string, int> foo;
            foo = make_pair("Mordida", 10);
            ataque.push_back(foo);
            
            Cartas aux = Cartas("Pikachu", 1, ataque, 50, "Eletrico", 100);
            adicionadas++;
            cartasExistentes.push_back(aux);
        }
        novo.setCartas(cartasExistentes);
        this->baralhos.push_back(novo);
        //this->baralhos.at(0).mostraBaralho();
    }
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
    for (int i = 0; i < ((this->baralhos).size()); i++)
    {
        retorno += (((this->baralhos[i]).getNome()) + "\n");
    }
    return retorno;
}

std::string Usuario::getNomeBaralho(int num){
    return ((this->baralhos).at(num).getNome());
};

void Usuario::setNome(string nomeP){
    this->nome = nomeP;
}

#endif