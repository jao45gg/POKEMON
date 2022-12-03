#ifndef _CARTAS_CPP
#define _CARTAS_CPP

#include "../include/Cartas.hpp"
#include <iostream>

using namespace std;

Cartas::Cartas(){
  this->_hp = 0;
  this->_defesa = 0;
  this->_nome_pokemon = "";
  this->_qtnd_atks = 0;
  vector<pair<string, int>> vazio;
  vazio.clear();
  this->_ataque = vazio;
};

Cartas::Cartas(string nome, int qtnd_atks, vector<pair<string, int>> ataque, int defesa, string tipo, int hp)
{
  _nome_pokemon = nome;
  _qtnd_atks = qtnd_atks;
  _ataque.clear();

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
  _defesa = defesa;
  //
  _tipo = tipo;
  //
  //
  _hp = hp;
  //
};
// Cartas::Cartas(string tipo)
// {
//   _nome_pokemon = "";
//   //
//   _qtnd_atks = 0;
//   //
//   _ataque.clear();
//   //
//   _defesa = 0;
//   //
//   _tipo = tipo;
//   //
//   _hp = 0;
//   //
// }
Cartas::~Cartas()
{
  _nome_pokemon = "";
  _defesa = 0;
  _tipo = "";
  _hp = 0;
  _qtnd_atks = 0;
}
string Cartas::getNome()
{
  return _nome_pokemon;
}
vector<pair<string, int>> Cartas::getAtaques()
{
  return _ataque;
}

pair<string, int> Cartas::getAtaque(int seleciona_atks)
{
  if (seleciona_atks >= 0 && seleciona_atks < _qtnd_atks)
  {
    return (_ataque.at(seleciona_atks));
  }
}

int Cartas::getDefesa()
{
  return _defesa;
}
string Cartas::getTipo()
{
  return _tipo;
}
int Cartas::getHp()
{
  return _hp;
}


void Cartas::sofrerDano(int dano)
{
  (this->_hp) = _hp - dano;
  cout << "--> " << "  Vida depois do ataque: " << _hp << endl << endl;
}

void Cartas::mostraCarta(){
  cout << "Pokemon " << (this->_nome_pokemon) << endl;
  cout << "Ataque " << (this->_ataque).at(0).first << " tem dano " << (this->_ataque).at(0).second << endl;
  cout << "Defesa " << (this->_defesa) << endl;;
  cout << "Tipo " << (this->_tipo) << endl;
  cout << "Vida " << (this->_hp) << endl;
}

void Cartas::destroiCarta(){
  this->_hp = 0;
  this->_defesa = 0;
  this->_nome_pokemon = "";
  this->_qtnd_atks = 0;
  vector<pair<string, int>> vazio;
  vazio.clear();
  this->_ataque = vazio;
}

#endif
