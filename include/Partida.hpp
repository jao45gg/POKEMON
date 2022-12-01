#ifndef _PARTIDA_HPP
#define _PARTIDA_HPP

#include "Usuario.hpp"
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

public:

    Partida(Usuario jogador, Usuario bot, string nomeBaralhoJogador, string nomeBaralhoBot);
    ~Partida();
    void comprarCarta(Usuario *atacante);
    void Ataque(string *cartaAtacando, string *cartaAtacada, Usuario *atacante);       // ataque generico
    void ataqueTipo(Cartas *_atacando, Cartas *_defendendo, float multiplicador_dano); // ataque especifico de cada tipo de pokemon
    void _ligarEnergia(Cartas *_cartaEnergia, Cartas *_pokemon, Usuario *atacante);
<<<<<<< Updated upstream
=======
    void pokemonMorto(Baralho *baralho, Cartas *morto);
    void exibirMao(Usuario mao);
>>>>>>> Stashed changes
};

#endif