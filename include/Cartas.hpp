#ifndef _CARTAS_HPP_
#define _CARTAS_HPP_

#include <string>
#include <utility>
#include <vector>

using namespace std;

class Cartas
{
private:

  string *_nome_pokemon;
  int *_qtnd_atks;
  vector<pair<string, int>> _ataque;
  int *_defesa;
  string *_tipo;
  int *_hp;
  bool energiaLigada;
  bool cartaEnergiaUsada;

public:

  Cartas(string nome, int qtnd_atks, vector<pair<string, int>> ataque, int defesa, string tipo,
         int hp);
  Cartas(string tipo);
  ~Cartas();
  string getNome();
  pair<string, int> getAtaque(string nome_atk);
  int getDefesa();
  string getTipo();
  int getHp();
  vector<pair<string, int>> getAtaques();
  void ligarEnergia(Cartas *cartaEnergia, Cartas *pokemon);
  void sofrerDano(int dano);
  bool getEnergia();
};

#endif
