#include "../include/Partida.hpp"
#include "../include/Usuario.hpp"
#include "../include/Cartas.hpp"
#include "../include/baralho.hpp"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

int main()
{
  cout << " _____     _                        _____ _____ _____ " << endl;
  cout << "|  _  |___| |_ ___ _____ ___ ___   |_   _|     |   __|" << endl;
  cout << "|   __| . | '_| -_|     | . |   |    | | |   --|  |  |" << endl;
  cout << "|__|  |___|_,_|___|_|_|_|___|_|_|    |_| |_____|_____|" << endl;
  cout << "                        PDS II                        " << endl;
  cout << endl;

  int comando;
  int comandoAux;

  do
  {
    cout << "Menu" << endl
         << endl;
    cout << "Digite '1' para Iniciar um Jogo" << endl;
    cout << "Digite '2' para Ver os Creditos" << endl;
    cout << "Digite '3' para Fechar o Jogo" << endl;
    cout << endl;

    do
    {
      cin >> comando;
      cout << endl;
    } while (comando != 1 && comando != 2 && comando != 3);

    if (comando == 1)
    {
      string nomePersonagem;
      cout << "Digite o nome do seu personagem:" << endl
           << endl;
      cin >> nomePersonagem;
      cout << endl;

      Usuario jogador = Usuario(nomePersonagem);
      Usuario Bot = Usuario("Bot");

      string nomeBaralhoJogador;
      nomeBaralhoJogador = jogador.getNomeBaralho(0);
      // // cout << "pegou o nome do baralho " << nomeBaralhoJogador << endl;

      Partida Jogo = Partida(jogador, Bot, nomeBaralhoJogador, "Baralho do Bot");

      cout << endl;
      cout << "Sorteio Cara ou Coroa" << endl;

      int moeda;
      int jogadorInicia = 0;
      int vezDoJogador = 0;

      do
      {
        cout << "Digite '1' para escolher Cara ou '2' para escolher Coroa : " << endl
             << endl;
        cin >> moeda;
        cout << endl;
        if (moeda == 1 || moeda == 2)
        {
          unsigned seed = time(0);
          srand(seed);
          int sorteio = rand() % 2;
          sorteio++;
          if (sorteio == 1)
          {
            cout << "Cara!" << endl;
          }
          else if (sorteio == 2)
          {
            cout << "Coroa!" << endl;
          }

          if (sorteio == moeda)
          {
            jogadorInicia = 1;
            break;
          }
          else if (sorteio != moeda)
          {
            jogadorInicia = 0;
            break;
          }
        }
        else
        {
          cout << "Valor invalido, tente novamente" << endl
               << endl;
        }
      } while (moeda != 1 && moeda != 2);

      if (jogadorInicia)
      {
        cout << endl;
        cout << nomePersonagem << " comeca jogando!" << endl
             << endl;
      }
      else
      {
        cout << endl;
        cout << "Bot comeca jogando!" << endl
             << endl;
      }
      // return 0;

      vezDoJogador = jogadorInicia;
      int primeiraRodadaJogador = 1;
      int primeiraRodadaBot = 1;
      int contagemRodadas = 1;
      int contagemPlayer = 0, contagemBot = 0;

      while (((Jogo.numPremio(nomePersonagem)) > 0) && ((Jogo.numPremio("Bot")) > 0))
      {
        // char buffer;
        cout << "RODADA " << contagemRodadas << endl;
        cout << endl;
        // cin >> buffer;

        if (vezDoJogador == 1)
        {
          cout << "Vez de " << nomePersonagem << endl;
          int numCarta;

          if (Jogo.estaSemCarta(nomePersonagem))
          {
            if (primeiraRodadaJogador == 0)
            {
              cout << endl;
              // if(Jogo.cartaMorta(nomePersonagem)){
              // Jogo.matarCarta(nomePersonagem);
              Jogo.comprarCarta(nomePersonagem);
              cout << "Sua carta em batalha morreu, digite o numero de uma outra carta de substituicao" << endl;
              //}
            }
            if (primeiraRodadaJogador == 1)
            {
              cout << endl;
              cout << "Digite o numero da carta que deseja enviar para batalha : " << endl;
            }
            cout << endl;
            vector<Cartas> MaoJogador = Jogo.getMaoJogador(nomePersonagem);
            for (int i = 0, ie = MaoJogador.size(); i < ie; i++)
            {
              cout << "   [" << i << "] " << MaoJogador.at(i).getNome();
              cout << endl;
            }

            cout << endl;

            do
            {
              // cout << endl
              //      << "Digite o numero da carta que deseja enviar para batalha : " << endl << endl;
              cin >> numCarta;
              cout << endl;
              if (numCarta < 0 || numCarta >= (int)(MaoJogador.size()))
              {
                cout << endl
                     << "Numero de carta invalido, tente novamente" << endl
                     << endl;
              }
              else
              {
                Jogo.setCartaEmBatalha(numCarta, nomePersonagem);

                // cout << endl << "Carta movida para batalha" << endl;
              }
            } while (numCarta < 0 || numCarta >= (int)(MaoJogador.size()));
          }
          else if (Jogo.estaSemCarta("Bot"))
          {
            // break;
          }
          else if (!(Jogo.estaSemCarta("Bot")) && !(Jogo.estaSemCarta(nomePersonagem)))
          {
            if (primeiraRodadaBot == 1 || primeiraRodadaJogador == 1)
            {
              cout << "Primeira rodada, nao ha movimentos" << endl << endl;
            }
            else if (primeiraRodadaJogador == 0 && primeiraRodadaBot == 0)
            {
              Jogo.comprarCarta(nomePersonagem);

              // cout << endl
              //      << nomePersonagem << " comeu uma carta de seu Baralho" << endl;
              //      cout << endl;

              if (Jogo.estaSemCarta(nomePersonagem))
              {
                cout << "o ponteiro da carta em batalha ficou nulo o" << endl;
              }

              Jogo.Ataque(nomePersonagem, "Bot");
              if (Jogo.cartaMorta("Bot"))
              {
                Jogo.matarCarta("Bot");
                // cout << endl;
                cout << nomePersonagem << " derrotou o Pokemon em batalha do Bot" << endl;
                Jogo.ganharPremio(nomePersonagem);
              }
            }
          }
          vezDoJogador = 0;
          primeiraRodadaJogador = 0;
          contagemPlayer = 1;
        }
        else if (vezDoJogador == 0)
        {
          cout << "Vez do Bot" << endl;
          cout << endl;
          // cout << endl;
          //  if(Jogo.cartaMorta("Bot")){
          //      Jogo.matarCarta("Bot");
          //    }
          if (Jogo.estaSemCarta("Bot"))
          {
            cout << endl;
            vector<Cartas> MaoBot = Jogo.getMaoJogador("Bot");
            unsigned seed = time(0);
            srand(seed);
            Jogo.comprarCarta("Bot");
            int cartaEscolhidaBot = rand() % MaoBot.size();
            Jogo.setCartaEmBatalha(cartaEscolhidaBot, "Bot");
            if (!primeiraRodadaBot)
            {
              Jogo.Ataque("Bot", nomePersonagem);
              if (Jogo.cartaMorta(nomePersonagem))
              {
                Jogo.matarCarta(nomePersonagem);
                // cout << endl;
                cout << "Bot derrotou o Pokemon em batalha de " << nomePersonagem << endl;
                Jogo.ganharPremio("Bot");
              }
            }
            // cout << "Bot enviou " << MaoBot.at(cartaEscolhidaBot).getNome() << " para o campo de batalha" << endl << endl;
          }
          else if (!(Jogo.estaSemCarta("Bot")) && !(Jogo.estaSemCarta(nomePersonagem)))
          {
            if (primeiraRodadaBot == 1 || primeiraRodadaJogador == 1)
            {
              cout << "Primeira rodada, Bot nao realizou movimentos" << endl;
            }
            else if (primeiraRodadaJogador == 0 && primeiraRodadaBot == 0)
            {

              Jogo.comprarCarta("Bot");

              // cout << endl
              //      << "Bot comeu uma carta de seu Baralho" << endl;
            }

            Jogo.Ataque("Bot", nomePersonagem);
            if (Jogo.cartaMorta(nomePersonagem))
            {
              Jogo.matarCarta(nomePersonagem);
              // cout << endl;
              cout << "Bot derrotou o Pokemon em batalha de " << nomePersonagem << endl;
              Jogo.ganharPremio("Bot");
            }
          }
          vezDoJogador = 1;
          primeiraRodadaBot = 0;
          contagemBot = 1;
        }
        if (primeiraRodadaBot == 0 && primeiraRodadaJogador == 0 && contagemPlayer == 1 && contagemBot == 1)
        {
          contagemRodadas++;
          contagemBot = 0;
          contagemPlayer = 0;
        }
        // if(contagemRodadas == 10){
        //         break;
        //       }
      }
      // cout << "Parece que alguem ganhou heinn" << endl;
      // bool JogadorGanhou = 0, BotGanhou = 0;
      if (((Jogo.numPremio(nomePersonagem)) == 0) && ((Jogo.numPremio("Bot")) > 0))
      {
        cout << endl;
        cout << nomePersonagem << " VENCEU !!!!" << endl
             << endl;
      }
      if (((Jogo.numPremio("Bot")) == 0) && ((Jogo.numPremio(nomePersonagem)) > 0))
      {
        cout << endl;
        cout << "Bot"
             << " VENCEU !!!!" << endl
             << endl;
      }

      do
      {
        cout << endl;
        cout << "Digite '1' se deseja voltar ao menu inicial" << endl;
        cout << "Digite '2' se deseja fechar o jogo" << endl;
        cout << endl;

        cin >> comandoAux;
        cout << endl;

        if (comandoAux == 1)
        {
          cout << "Voltando ao Menu..." << endl;
          comando = 99;
          //break;
        }
        else if (comandoAux == 2)
        {
          cout << "Fechando o jogo...";
          return 0;
        }
        else if ((comandoAux != 1) && (comandoAux != 2))
        {
          cout << "Comando invalido, tente novamente..." << endl;
        }
      } while (comandoAux != 1 && comandoAux != 2);
    }
    else if (comando == 2)
    {

      cout << "Trabalho feito pelos alunos:" << endl;
      cout << endl;
      cout << "  [] Luiz Otavio Uchoa Pereira" << endl;
      cout << "  [] Thais Madeira da Silva" << endl;
      cout << "  [] Joao Pedro Souza Braga" << endl;
      cout << "  [] Christian Soares Santos" << endl;
      cout << "  [] Gabriel Hesse Vitusso" << endl;

      do
      {
        cout << endl;
        cout << "Digite '1' se deseja voltar ao menu inicial" << endl;
        cout << "Digite '2' se deseja fechar o jogo" << endl;
        cout << endl;

        cin >> comandoAux;
        cout << endl;

        if (comandoAux == 1)
        {
          cout << "Voltando para o Menu...";
          cout << endl;
          //break;
        }
        else if (comandoAux == 2)
        {
          cout << "Fechando o jogo...";
          break;
        }
        else if ((comandoAux != 1) && (comandoAux != 2))
        {
          cout << "Comando invalido, tente novamente..." << endl;
        }
      } while (comandoAux != 1 && comandoAux != 2);
    }
    else if (comando == 3)
    {
      cout << "Fechando o jogo...";
      return 0;
    }
    else if ((comando != 1) && (comando != 2) && (comando != 3))
    {
      cout << "Comando invalido, tente novamente" << endl;
    }

  } while (comando != 3 || comandoAux != 2);
  return 0;
}