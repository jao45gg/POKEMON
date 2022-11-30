#include "Partida.hpp"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <sstream>

int main()
{

  ifstream myfile;
  myfile.open("pokemons.txt");

  // vector<Cartas> cartasExistentes;

  if (myfile.is_open())
  {
    string nome_pokemon;
    int qtnd_atks;
    vector<pair<string, int>> ataque;
    int defesa;
    string tipo;
    int hp;
    
    while (myfile)
    {
      cout << "teste" << endl;
      getline(myfile, nome_pokemon);

      string tmp, nome_atk;
      int dano;

      getline(myfile, tmp);
      sscanf(tmp.c_str(), "%d", &qtnd_atks);

      for (int i = 0, ie = qtnd_atks; i < ie; i++)
      {
        string line, tmp;
        getline(myfile, line);
        istringstream iss(line);
        getline(iss, nome_atk, ':');

        getline(iss, tmp, '\n');
        istringstream(tmp) >> dano;

        pair<string, int> foo;
        foo = make_pair(nome_atk, dano);
        ataque.push_back(foo);
      }

      getline(myfile, tmp);
      sscanf(tmp.c_str(), "%d", &defesa);

      getline(myfile, tipo);

      getline(myfile, tmp);
      sscanf(tmp.c_str(), "%d", &hp);

      // cartasExistentes.push_back(Cartas(nome_pokemon, qtnd_atks, ataque, defesa, tipo, hp));

      cout << nome_pokemon << endl;
      cout << qtnd_atks << endl;
      // cout << ataque[1].first << ": "<< ataque[1].second << endl;
      cout << tipo << endl;
      cout << hp << endl;
    }
  }
  else
    std::cout << "Falha ao abrir o arquivo \n";

  // string nome_jogador;

  // cout << "Digite o nome do jogador :)\n";
  // cin >> nome_jogador;
  // Usuario jogador(nome_jogador);

  // cout << "Digite o nome do bot :)\n";
  // cin >> nome_jogador;
  // Usuario bot(nome_jogador);

  // string nomeBaralhoJogador, nomeBaralhoBot;
  // cout << "Digite o nome do baralho do jogador :)\n";
  // cin >> nomeBaralhoJogador;

  // cout << "Digite o nome do baralho do bot :)\n";
  // cin >> nomeBaralhoBot;

  // Partida p(&jogador, &bot, nomeBaralhoJogador, nomeBaralhoBot);

  // p.exibirMao(&jogador);
  // p.comprarCarta(&jogador);
  // p.exibirMao(&jogador);

  return 0;
}