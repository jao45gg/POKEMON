#include "../include/Partida.hpp"
#include "../include/Usuario.hpp"
#include "../include/Cartas.hpp"
#include "../include/baralho.hpp"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <sstream>

int main()
{

  string nome_jogador;

  cout << "Digite o nome do jogador :)\n";
  cin >> nome_jogador;
  Usuario jogador = Usuario(nome_jogador);
  Usuario bot = Usuario("bot");

  string nomeBaralhoJogador;
  nomeBaralhoJogador = jogador.getNomeBaralho(0);
  //cout << "pegou o nome do baralho " << nomeBaralhoJogador << endl;
  
  Partida Jogo = Partida(jogador, bot, nomeBaralhoJogador, "Baralho do Bot");
  //cout << "criou partida direito \n";

  Jogo.exibirMao(jogador);
  // p.comprarCarta(&jogador);
  // p.exibirMao(&jogador);

  return 0;
}