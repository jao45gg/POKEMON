#ifndef _CARTAS_CPP
#define _CARTAS_CPP

#include "../include/Cartas.hpp"

Cartas::Cartas(string nome, int qtnd_atks, vector<pair<string, int>> ataque, int defesa, string tipo, int hp)
{
  _nome_pokemon = new string;
  *_nome_pokemon = nome;
  //
  _qtnd_atks = new int;
  *_qtnd_atks = qtnd_atks;
  //

  for (int i = 0; i < qtnd_atks; i++)
  {

    if (ataque[i].second >= 0 && ataque[i].second <= 400)
    {
      _ataque.push_back(ataque[i]);
    }
    else if (ataque[i].second < 0)
    {
      pair<string, int> aux = ataque[i];
      aux.second = 0;
      _ataque.push_back(aux);
    }
    else if (ataque[i].second > 400)
    {
      pair<string, int> aux = ataque[i];
      aux.second = 400;
      _ataque.push_back(aux);
    }
  }
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
  _ataque.clear();
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
  delete _defesa;
  delete _tipo;
  delete _hp;
  delete _qtnd_atks;
}
string Cartas::getNome()
{
  return *_nome_pokemon;
}
vector<pair<string, int>> Cartas::getAtaques()
{
  return _ataque;
}
pair<string, int> Cartas::getAtaque(int seleciona_atks)
{
  if (seleciona_atks >= 0 && seleciona_atks < *_qtnd_atks)
  {
    return _ataque[seleciona_atks];
  }
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
