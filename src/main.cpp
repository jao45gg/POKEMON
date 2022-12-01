<<<<<<< Updated upstream
=======
#include "Partida.hpp"
#include "Usuario.hpp"
#include <fstream>
#include <stdio.h>
>>>>>>> Stashed changes
#include <iostream>

#include "Partida.hpp"

int main()
{

<<<<<<< Updated upstream
=======
  string nome_jogador;

  cout << "Digite o nome do jogador :)\n";
  cin >> nome_jogador;
  Usuario jogador = Usuario(nome_jogador);
  Usuario bot = Usuario("bot");

  string nomeBaralhoJogador;
  nomeBaralhoJogador = jogador.getNomeBaralho(0);
  //cout << "pegou o nome do baralho " << nomeBaralhoJogador << endl;

  Usuario *jogadorpont;
  jogadorpont = &jogador;
  Usuario *botpont;
  botpont = &bot;
  
  Partida Jogo = Partida(jogador, bot, nomeBaralhoJogador, "Baralho do Bot");
  //cout << "criou partida direito \n";

  Jogo.exibirMao(jogador);
  // p.comprarCarta(&jogador);
  // p.exibirMao(&jogador);

>>>>>>> Stashed changes
  return 0;
}