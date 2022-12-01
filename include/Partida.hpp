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
    Baralho _baralhoJogador; //copia para fazer os pokemons mortos
    Baralho _baralhoBot;
    vector<Cartas> mao_jogador;
    vector<Cartas> mao_bot;
    string _nomeBaralhoJogador, _nomeBaralhoBot;

public:

    /**
     * @brief Construtor de partidas, inicializa classe
     * e atribui os nomes de jogadores e Usuarios
     * @param jogador Ponteiro de Usuario dado ao jogador
     * @param bot Ponteiro de Usuario dado ao computador
     * @param nomeBaralhoJogador Nome do baralho
     * @param nomeBaralhoBot Nome do baralho do Bot
     * 
     */
    Partida(Usuario *jogador, Usuario *bot, string nomeBaralhoJogador, string nomeBaralhoBot);
    
     /**
     * @brief Destrutor para a classe Partida,
     * desaloca a memoria dinamica
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
    void Ataque(string *cartaAtacando, string *cartaAtacada, Usuario *atacante); // ataque generico
    
     /**
     * @brief Determina o dano de uma habilidade
     * @param _atacando Ponteiro que indica a carta que ataca
     * @param _defendendo ponteiro que indica a carta que defende
     * @param multiplicador_dano atributo que altera o dano aplicado
     * @param infos Vector de informacao de tipos
     * 
     */
    void ataqueTipo(Cartas *_atacando, Cartas *_defendendo, float multiplicador_dano); // ataque especifico de cada tipo de pokemon
    
    
    void _ligarEnergia(Cartas *_cartaEnergia, Cartas *_pokemon, Usuario *atacante);
};

#endif
