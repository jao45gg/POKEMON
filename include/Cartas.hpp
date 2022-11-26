#ifndef _CARTAS_HPP_
#define _CARTAS_HPP_
#include "Efeitos.hpp"
#include "Habilidades.hpp"

class Cartas
{
  private:
  string *_nome_pokemon;
  int *_ataque;
  int *_defesa;
  string *_tipo;
  Habilidades *_habilidades;
  int *_hp;
  Efeitos *_efeitos;

  public:
  Cartas(string nome, int ataque, int defesa, string tipo, 
  Habilidades habilidades, int hp, Efeitos efeitos);
  ~Cartas();
  string getNome();
  int getAtaque();
  int getDefesa();
  int getTipo();
  int getHp();
  string sobEfeitos();
  Efeitos* getEfeitos();
  Habilidades* getHabilidade();
    
};


#endif
