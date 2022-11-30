#ifndef _CARTAS_HPP_
#define _CARTAS_HPP_

#include <string>

using namespace std;

class Cartas
{
private:
//Variaveis
  string *_nome_pokemon;
  int *_ataque;
  int *_defesa;
  string *_tipo;
  int *_hp;
  bool energiaLigada;
  bool cartaEnergiaUsada;

public:
  /**
   * @brief Construtor para a classe Cartas, 
   * faz atribuicoes iniciais de variaveis.
   * @param nome Nome atribuido aa carta
   * @param ataque Atributo do dano que a carta realiza
   * @param defesa Atributo do modificador do dano recebido
   * @param tipo Atributo de modificador do dano realizado
   * @param hp Atributo de dano que pode ser recebido
   * 
   */
  Cartas(string nome, int ataque, int defesa, string tipo,
         int hp);
  /**
   * @brief Construtor ad-hoc para a classe, 
   * somente determina a atribuicao de tipo.
   * @param tipo Atributo do modificador do dano recebido
   * 
   */
  Cartas(string tipo);
  /**
   * @brief Destrutor para a classe Cartas.
   * Libera memoria alocada dinamicamente.
   * 
   */
  ~Cartas();
  /**
   * @brief Funcao que retorna nome
   * @return Nome da carta
   */
  string getNome();
  /**
   * @brief Funcao que retorna ataque
   * @return Ataque da carta
   * 
   */
  int getAtaque();
  /**
   * @brief Funcao que retorna defesa
   * @return Defesa da carta
   */
  int getDefesa();
  /**
   * @brief Funcao que retorna tipo
   * @return Tipo da carta
   * 
   */
  string getTipo();
  /**
   * @brief Funcao que retorna Hp da carta
   * @return Hp da carta
   * 
   */
  int getHp();
  /**
   * @brief Funcao que associa uma carta de energia
   * a uma carta de pokemon
   * @param cartaEnergia ponteiro Cartas que leva aa carta de energia
   * @param pokemon ponteiro Cartas que leva aa carta do pokemon
   * 
   */
  void ligarEnergia(Cartas *cartaEnergia, Cartas *pokemon);
  /**
   * @brief Funcao que altera o Hp da Carta em questao
   * @param dano Dano recebido
   * 
   */
  void sofrerDano(int dano);
  /**
   * @brief Funcao que retorna a energia da carta
   * @return bool que determina o status da energia
   * 
   */
  bool getEnergia();
};

#endif
