#ifndef _CARTAS_HPP_
#define _CARTAS_HPP_

#include <string>
#include <utility>
#include <vector>

using namespace std;

class Cartas{
private:
//Variaveis
  string _nome_pokemon;
  int _qtnd_atks;
  vector<pair<string, int>> _ataque;
  int _defesa;
  string _tipo;
  int _hp;

public:

  Cartas();
  Cartas(string nome, int qtnd_atks, vector<pair<string, int>> ataque, int defesa, string tipo, int hp);
  //Cartas(string tipo);
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
   * @brief Funcao que retorna um vector de pair com todos os ataques
   * @return vector que contem todos os ataques da carta
   * 
   */
  vector<pair<string, int>> getAtaques();
  void sofrerDano(int dano);
  void mostraCarta();
  void destroiCarta();
};

#endif
