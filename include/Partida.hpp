#ifndef _PARTIDA_HPP
#define _PARTIDA_HPP

#include "../include/Usuario.hpp"
#include "Usuario.hpp"
#include "Cartas.hpp"
#include "baralho.hpp"
#include <cstdlib> // bib que tem o rand() para gerar números aleatórios

using namespace std;

// FALTA FAZER A QUESTAO DO POKEMON MORRER E ENTAO SER MOVIDO PARA OS MORTOS PARA ISSO TEM QUE TER UMA COPIA E NAO UM PONTEIRO

class Partida
{
private:
    Usuario *_jogador;
    Usuario *_bot;
    Baralho _baralhoJogador; // copia para fazer os pokemons mortos
    Baralho _baralhoBot;
    vector<Cartas> mao_jogador;
    vector<Cartas> mao_bot;
    string _nomeBaralhoJogador, _nomeBaralhoBot;
    vector<Cartas> premiosJogador;
    vector<Cartas> premiosBot;
    Cartas _cartaEmBatalhaJogador;
    Cartas _cartaEmBatalhaBot;

public:

    Partida(Usuario jogador, Usuario bot, string nomeBaralhoJogador, string nomeBaralhoBot);
    ~Partida();
    void comprarCarta(string nomeJogador);
    void Ataque(string usuarioAtacante, string usuarioDefensor);       // ataque generico
    //void ataqueTipo(Cartas *_atacando, Cartas *_defendendo, float multiplicador_dano); //, pair<string,int> infos); // ataque especifico de cada tipo de pokemon
    void _ligarEnergia(Cartas *_cartaEnergia, Cartas *_pokemon, Usuario *atacante);
    void pokemonMorto(Baralho *baralho, Cartas *morto);
    void exibirMao(Usuario *mao);
    void ganharPremio(string nomeJogador);
    int numPremio(string nomeJogador);
    bool estaSemCarta(string nomeJogador);
    void setCartaEmBatalha(int numCarta, string nomePlayer);
    bool cartaMorta(string nomeJogador);
    void matarCarta(string nomeJogador);
    vector<Cartas> getMaoJogador(string nomeJogador);
    string getNomeCartaBatalha(string nomeJogador);
    // Cartas *getCartaBatalha(string nomeJogador);
};
#endif