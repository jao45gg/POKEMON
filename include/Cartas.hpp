#ifndef _CARTAS_HPP_
#define _CARTAS_HPP_

#include <string>

using namespace std;

class Cartas
{
private:
  string *_nome_pokemon;
  int *_ataque;
  int *_defesa;
  string *_tipo;
  int *_hp;
  bool energiaLigada;
  bool cartaEnergiaUsada;

public:
  Cartas(string nome, int ataque, int defesa, string tipo,
         int hp);
  Cartas(string tipo);
  ~Cartas();
  string getNome();
  int getAtaque();
  int getDefesa();
  string getTipo();
  int getHp();
  void ligarEnergia(Cartas *cartaEnergia, Cartas *pokemon);
  void sofrerDano(int dano);
  bool getEnergia();
};

#endif
