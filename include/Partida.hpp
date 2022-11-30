#ifndef _PARTIDA_HPP
#define _PARTIDA_HPP

#include "Usuario.hpp"
#include <cstdlib> // bib que tem o rand() para gerar números aleatórios

using namespace std;

class Partida
{
private:
//Variaveis
    Usuario *_jogador;
    Usuario *_bot;
    Baralho *_baralhoJogador;
    Baralho *_baralhoBot;
    vector<Cartas> mao_jogador;
    vector<Cartas> mao_bot;
    string _nomeBaralhoJogador, _nomeBaralhoBot;

public:
//Metodos
    /**
     * @brief Construtor da classe Partida, 
     * inicializa e atribui as variaveis
     * @param jogador ponteiro do usuario que ira jogar
     * @param bot ponteiro do usuario(bot) que ira jogar
     * @param nomeBaralhoJogador string do nome do baralho jogado
     * @param nomeBaralhoBot string do nome do baralho adversario
     */
    Partida(Usuario *jogador, Usuario *bot, string nomeBaralhoJogador, string nomeBaralhoBot);
    /**
     * @brief Destrutor para a classe Partida, desaloca a memoria dinamica
     * 
     */
    ~Partida();
    /**
     * @brief Faz com que o atacante compre uma carta durante a partida
     * @param atacante ponteiro que indica o jogador que fez a acao
     * 
     */
    void comprarCarta(Usuario *atacante);
    /**
     * @brief Faz com que o atacante realize um ataque
     * @param cartaAtacando ponteiro da carta que ataca
     * @param cartaAtacada ponteiro da carta que sofre o dano
     * @param atacante ponteiro do usuario que faz a acao
     * 
     */
    void Ataque(string *cartaAtacando, string *cartaAtacada, Usuario *atacante);
    /**
     * @brief Atribui uma carta de energia a uma carta de pokemon
     * @param _cartaEnergia ponteiro da carta de energia
     * @param _pokemon ponteiro da carta de pokemon
     * @param atacante ponteiro do usuario que faz a acao
     * 
     */
    void _ligarEnergia(Cartas *_cartaEnergia, Cartas *_pokemon, Usuario *atacante);
};

#endif