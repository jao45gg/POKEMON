#ifndef _PARTIDA_HPP
#define _PARTIDA_HPP

#include "Usuario.hpp"
#include <cstdlib> // bib que tem o rand() para gerar números aleatórios

using namespace std;

class Partida
{
private:
   Usuario *_jogador;
   Usuario *_bot;
   Baralho *_baralhoJogador;
   Baralho *_baralhoBot;
   vector <Cartas> mao_jogador;
   vector <Cartas> mao_bot;
   string _nomeBaralhoJogador, _nomeBaralhoBot;
   Cartas pokemonJogador;
   Cartas podemonBot;
public:
    Partida(Usuario *jogador, Usuario *bot, string nomeBaralhoJogador, string nomeBaralhoBot);
    ~Partida();
    void comprarCarta(Usuario *atacante);
    void usarHabilidade(string *cartaFazendo, Usuario *atacante);
    void Ataque(string *cartaAtacando, Usuario *atacante);
    void _ligarEnergia(Cartas *_cartaEnergia, Cartas *_pokemon, Usuario *atacante);
};

#endif