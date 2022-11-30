#ifndef BARALHO_HPP
#define BARALHO_HPP

#include "Cartas.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Baralho
{
private:
//Variaveis
    vector<Cartas> _cartas;
    string _nome;
//Metodos
public:
    /**
     * @brief Construtor que faz as atribuicoes iniciais
     * das variaveis contidas na classe Baralho.
     * @param cartasP Vetor de cartas que sera salvo
     * @param nomeP String que equivale ao nome em que o baralho
     * eh salvo
     * 
     */
    Baralho(vector<Cartas> cartasP, string nomeP);
    /**
     * @brief Destrutor da classe, desaloca a memoria dinamica.
     * 
     */
    ~Baralho();
    /**
     * @brief Funcao que retorna o nome do baralho
     * @return Nome do Baralho
     * 
     */
    string getNome();
    /**
     * @brief Funcao que altera o nome do baralho
     * @param nomeP String que equivale ao novo nome
     * 
     */
    void setNome(string nomeP);
    /**
     * @brief Funcao que retorna um numero equivalente a uma carta
     * @return "Id" ou numero de representacao de uma carta
     * 
     */
    Cartas getCarta(int num);
    /**
     * @brief Funcao que remove a carta escolhida do baralho
     * @param nome Nome da carta que sera removida
     * 
     */
    void removeCarta(string nome);
    /**
     * @brief Funcao que retorna o valor inteiro da quantidade
     * de cartas
     * @return Int de quantidade de cartas no baralho
     * 
     */
    int getSize();
};
#endif
