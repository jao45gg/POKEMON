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
     * @brief Construtor simples para Baralho,
     * realiza atribuicoes genericas para o preparo
     * do uso
     * 
     */
    Baralho();
    
    /**
     * @brief Construtor que faz as atribuicoes iniciais
     * das variaveis contidas na classe Baralho.
     * @param cartasExistentes Endereco do vetor de cartas que sera salvo
     * @param nomeP String que equivale ao nome em que o baralho
     * eh salvo
     * 
     */

    Baralho(string nomeP, vector<Cartas> &cartasExistentes);
    
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
     * @brief Funcao que retorna um vetor de
     * cartas do baralho
     * @return Vector contendo todas cartas
     * baralho
     * 
     */
    vector<Cartas> getCartasBaralho();
    
    /**
     * @brief Funcao que iguala os conteudos
     * de um baralho aos de outro baralho
     * @param operando Endereco do baralho em que
     * os seus conteudos serao igualados aos conteudos
     * do primeiro baralho (baralho = operando)
     * 
     */
    //void operator=(Baralho &operando);
    
    /**
     * @brief Funcao que altera o nome do baralho
     * @param nomeP String que equivale ao novo nome
     * 
     */

    void setNome(string nomeP);
    
    /**
     * @brief Funcao que retorna uma carta contida no baralho
     * @return Carta representada por num
     * @param num int que representa carta usada
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
    
    /**
     * @brief Funcao que retorna o valor inteiro da quantidade
     * de cartas
     * @param cartasP vector que contem cartas a ser inseridas no baralho
     * 
     */
    void setCartas(vector<Cartas> cartasP);
    
    /**
     * @brief Funcao que imprime na tela as cartas 
     * contidas no baralho
     */
    void mostraBaralho();
};
#endif
