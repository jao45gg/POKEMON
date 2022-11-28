#ifndef _CARTAS_CPP
#define _CARTAS_CPP

#include "../include/Cartas.hpp"

Cartas::Cartas(string nome, int ataque, int defesa, string tipo, Habilidades *habilidades, int hp, Efeitos efeitos){
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
  _habilidades = habilidades;
  //
  _hp = new int;
  *_hp = hp;
  //
  _efeitos = new Efeitos();
  *_efeitos = efeitos;

  energiaLigada = false;
  cartaEnergiaUsada = false;
}
Cartas::Cartas(string nome, int ataque, int defesa, string tipo, int hp, Efeitos efeitos){
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
  _habilidades = nullptr;
  //
  _hp = new int;
  *_hp = hp;
  //
  _efeitos = new Efeitos();
  *_efeitos = efeitos;

  energiaLigada = false;
  cartaEnergiaUsada = false;
}
Cartas::Cartas(string nome, int ataque, int defesa, string tipo, Habilidades *habilidades, int hp){
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
  _habilidades = habilidades;
  //
  _hp = new int;
  *_hp = hp;
  //
  _efeitos = nullptr;

  energiaLigada = false;
  cartaEnergiaUsada = false;
}
Cartas::Cartas(string nome, int ataque, int defesa, string tipo, int hp){
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
  _habilidades = nullptr;
  //
  _hp = new int;
  *_hp = hp;
  //
  _efeitos = nullptr;

  energiaLigada = false;
  cartaEnergiaUsada = false;
}
Cartas::Cartas(string tipo){
  _nome_pokemon = nullptr; 
  //
  _ataque = nullptr;
  //
  _defesa = nullptr;
  //
  _tipo = new string;
  *_tipo = tipo;
  //
  _habilidades = nullptr;
  //
  _hp = nullptr;
  //
  _efeitos = nullptr;

  energiaLigada = false;
  cartaEnergiaUsada = false;
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
string Cartas::getTipo(){
  return *_tipo;
}
int Cartas::getHp(){
  return *_hp;
}
string Cartas::sobEfeitos(){
  return _efeitos->getNome();
}
Efeitos* Cartas::getEfeitos(){
  return _efeitos;
}
Habilidades* Cartas::getHabilidade(){
  return _habilidades;
}

void Cartas::ligarEnergia(Cartas *cartaEnergia, Cartas *pokemon) {
  if(cartaEnergia->getTipo() == "energia") {
    pokemon->energiaLigada = true;
    cartaEnergia->cartaEnergiaUsada = true;
  }

}

#endif