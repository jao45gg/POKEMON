#ifndef _USUARIO_HPP
#define _USUARIO_HPP
#include <string>
#include <vector>
#include <Baralho.hpp>

class Usuario
{
public:
//Metodos
    /**
     * @brief Construtor padrao que inicializa as 
     * variaveis da classe Usuario
     * 
     */
    Usuario();
    /**
     * @brief Construtor ad-hoc da classe Usuario,
     * inicializa as variaveis e da um nome ao Usuario
     * @param nome Nome de usuario
     * 
     */
    Usuario(std::string nome);
    /**
     * @brief Destrutor da classe, desaloca memoria dinamica
     * 
     */
    ~Usuario();
    /**
     * @brief Funcao que retorna o nome de usuario
     * @return String que equivale ao nome
     * 
     */
    std::string getNome();
    /**
     * @brief Funcao que retorna a quantidade de vitorias
     * do usuario
     * @return Int que equivale aas vitorias
     * 
     */
    int getVitorias();
    /**
     * @brief Funcao que retorna a quantidade de derrotas
     * @return Int que equivale aas derrotas
     * 
     */
    int getDerrotas();
    /**
     * @brief Funcao que retorna os baralhos salvos pelo usuario
     * @return Vetor de baralhos, que contem todos os baralhos do
     * usuario
     * 
     */
    std::vector<Baralho> getBaralhos();
    /**
     * @brief Funcao que aumenta em 1 a 
     * quantidade de vitorias do usuario
     * @param vitorias quantidade de vitorias
     * 
     */
    void setVitorias(int vitorias);
    /**
     * @brief Funcao que aumenta em 1 a 
     * quantidade de derrotas do usuario
     * @param derrotas quantidade de derrotas
     * 
     */
    void setDerrotas(int derrotas);
    /**
     * @brief Funcao que registra um novo baralho ao usuario
     * @param baralhos Baralho recem adicionado ao usuario
     * 
     */
    void setBaralhos(Baralho baralhos);
    /**
     * @brief Funcao que formata o status do usuario
     * @return String de status do usuario
     * 
     */
    std::string toString();
//Variaveis
private:
    std::string nome;
    int vitorias;
    int derrotas;
    std::vector<Baralho> baralhos;
};

#endif
