#ifndef _CARTAS_HPP_
#define _CARTAS_HPP_

#include <string>
#include <utility>
#include <vector>

using namespace std;

class Cartas
{
private:
//Variaveis
  string _nome_pokemon;
  int _qtnd_atks;
  vector<pair<string, int>> _ataque;
  int _defesa;
  string _tipo;
  int _hp;
  bool energiaLigada;
  bool cartaEnergiaUsada;
//Metodos
public:
   /**
   * @brief Construtor para a classe Cartas, 
   * faz atribuicoes iniciais de variaveis.
   * @param nome Nome atribuido aa carta
   * @param qtnd_atks Atributo da quantidade de movimentos que a carta possui
   * @param defesa Atributo do modificador do dano recebido
   * @param tipo Atributo de modificador do dano realizado
   * @param hp Atributo de dano que pode ser recebido
   * @param ataque vector que contem os movimentos/habilidades que a carta pode realizar
   * 
   */
  Cartas(string nome, int qtnd_atks, vector<pair<string, int>> ataque, int defesa, string tipo,
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
   * @brief Funcao que retorna um ataque
   * @param nome_atk nome do movimento que sera encontrado 
   * @return Ataque da carta
   * 
   */
  pair<string, int> getAtaque(int seleciona_atks);
  
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
   * @return vector que contem todos os movimentos da carta
   * 
   */
  vector<pair<string, int>> getAtaques();
  
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
  void mostraCarta();
};

#endif
