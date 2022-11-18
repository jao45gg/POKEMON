#include "../include/Cartas.hpp"

Cartas::Cartas(string nome, int ataque, int defesa, string tipo, Habilidades habilidades, int hp, Efeitos efeitos){
  _nome_pokemon = new string; 
  *_nome_pokemon = nome; 
  //
  _ataque = new int;
  *_ataque = ataque;
  //
  _defesa = new int;
  *_defesa = defesa;
  //
  _tipo = new string;
  *_tipo = tipo;
  //
  _habilidades = new Habilidades();
  *_habilidades = habilidades;
  //
  _hp = new int;
  *_hp = hp;
  //
  _efeitos = new Efeitos();
  *_efeitos = efeitos;
}
Cartas::~Cartas(){
  delete _nome_pokemon;
  delete _ataque;
  delete _defesa;
  delete _tipo;
  delete _habilidades;
  delete _hp;
  delete _efeitos;
}
string Cartas::getNome(){
  return *_nome_pokemon;
}
int Cartas::getAtaque(){
  return *_ataque;
}
int Cartas::getDefesa(){
  return *_defesa;
}
int Cartas::getTipo(){
  return *_tipo;
}
int Cartas::getHp(){
  return *_hp;
}
string Cartas::sobEfeitos(){
  return _efeitos->_nome_efeitos;
}
Efeitos* Cartas::getEfeitos(){
  Efeitos* _efeitos = new Efeitos();
  *_efeitos = *(this->_efeitos);
  return _efeitos;
}
Habilidades* Cartas::getHabilidade(){
  Habilidades* _habilidades = new Habilidades();
  *_habilidades = *(this->_habilidades);
  return _habilidades;
}