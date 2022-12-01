#include "Partida.hpp"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <sstream>

int main()
{

  string nome_jogador;

  cout << "Digite o nome do jogador :)\n";
  cin >> nome_jogador;
  Usuario jogador(nome_jogador);

  Usuario bot("bot");

  string nomeBaralhoJogador, nomeBaralhoBot;
  cout << "Digite o nome do baralho do jogador :)\n";
  cin >> nomeBaralhoJogador;

  Partida p(&jogador, &bot, nomeBaralhoJogador, "bot");

  p.exibirMao(&jogador);
  p.comprarCarta(&jogador);
  p.exibirMao(&jogador);

  return 0;
}