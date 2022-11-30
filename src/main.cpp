#include "Partida.hpp"

int main()
{
  string nome_jogador;

  cout << "Digite o nome do jogador :)\n";
  cin >> nome_jogador;
  Usuario jogador(nome_jogador);

  cout << "Digite o nome do bot :)\n";
  cin >> nome_jogador;
  Usuario bot(nome_jogador);

  string nomeBaralhoJogador,nomeBaralhoBot;
  cout << "Digite o nome do baralho do jogador :)\n";
  cin >> nomeBaralhoJogador;

  cout << "Digite o nome do baralho do bot :)\n";
  cin >> nomeBaralhoBot;

  Partida p(&jogador, &bot,nomeBaralhoJogador, nomeBaralhoBot);


  p.exibirMao(&jogador);
  p.comprarCarta(&jogador);
  p.exibirMao(&jogador);
  

  return 0;
}