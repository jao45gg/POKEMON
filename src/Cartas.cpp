#ifndef _CARTAS_CPP
#define _CARTAS_CPP

#include "../include/Cartas.hpp"

Cartas::Cartas(string nome, int qtnd_atks, int ataque, int defesa, string tipo, int hp)
{
  _nome_pokemon = new string;
  *_nome_pokemon = nome;
  //
  _qtnd_atks = new int;
  *_qtnd_atks = qtnd_atks;
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
  //
  _hp = new int;
  *_hp = hp;
  //
  energiaLigada = false;
  cartaEnergiaUsada = false;
}
Cartas::Cartas(string tipo)
{
  _nome_pokemon = nullptr;
  //
  _qtnd_atks = nullptr;
  //
  _ataque = nullptr;
  //
  _defesa = nullptr;
  //
  _tipo = new string;
  *_tipo = tipo;
  //
  _hp = nullptr;
  //

  energiaLigada = false;
  cartaEnergiaUsada = false;
}
Cartas::~Cartas()
{
  delete _nome_pokemon;
  delete _ataque;
  delete _defesa;
  delete _tipo;
  delete _hp;
}
string Cartas::getNome()
{
  return *_nome_pokemon;
}
int Cartas::getAtaque()
{
  return *_ataque;
}
int Cartas::getDefesa()
{
  return *_defesa;
}
string Cartas::getTipo()
{
  return *_tipo;
}
int Cartas::getHp()
{
  return *_hp;
}

void Cartas::ligarEnergia(Cartas *cartaEnergia, Cartas *pokemon)
{
  if (cartaEnergia->getTipo() == "energia")
  {
    pokemon->energiaLigada = true;
    cartaEnergia->cartaEnergiaUsada = true;
  }
}

void Cartas::sofrerDano(int dano)
{
  *_hp -= dano;
}

bool Cartas::getEnergia()
{
  if (energiaLigada)
    return true;
  return false;
}

#endif