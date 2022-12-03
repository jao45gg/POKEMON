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

    /**
     * @brief Construtor de partidas, inicializa classe
     * e atribui os nomes de jogadores e Usuarios
     * @param jogador Ponteiro de Usuario dado ao jogador
     * @param bot Ponteiro de Usuario dado ao computador
     * @param nomeBaralhoJogador Nome do baralho
     * @param nomeBaralhoBot Nome do baralho do Bot
     * 
     */
    Partida(Usuario jogador, Usuario bot, string nomeBaralhoJogador, string nomeBaralhoBot);
    
     /**
     * @brief Destrutor para a classe Partida,
     * desaloca a memoria dinamica
     * 
     */
    ~Partida();
    void comprarCarta(string nomeJogador);
    void Ataque(string usuarioAtacante, string usuarioDefensor);       // ataque generico
    //void ataqueTipo(Cartas *_atacando, Cartas *_defendendo, float multiplicador_dano); //, pair<string,int> infos); // ataque especifico de cada tipo de pokemon
    
     /**
     * @brief Atribui uma carta de energia a uma carta de pokemon
     * @param _cartaEnergia ponteiro da carta de energia
     * @param _pokemon ponteiro da carta de pokemon
     * @param atacante ponteiro do usuario que faz a acao
     * 
     */    
    void _ligarEnergia(Cartas *_cartaEnergia, Cartas *_pokemon, Usuario *atacante);
    
    /**
     * @brief Funcao que determina as condicoes de parada da partida
     * @param baralho ponteiro do baralho usado na comparacao
     * @param morto ponteiro da carta que acabara de morrer
     * 
     */    
    void pokemonMorto(Baralho *baralho, Cartas *morto);
    
     /**
     * @brief Funcao que devolve as cartas presentes na mao do jogador
     * @param ponteiro do Usuario que escolheu ver a mao
     * 
     */   
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
