#ifndef _PARTIDA_CPP
#define _PARTIDA_CPP

#include "../include/Partida.hpp"
#include "Usuario.hpp"
#include <iostream>

using namespace std;

Partida::Partida(Usuario jogador, Usuario bot, string nomeBaralhoJogador, string nomeBaralhoBot)
{

    _jogador = &jogador;
    _jogador->setNome(jogador.getNome());
    _bot = &bot;
    _bot->setNome(bot.getNome());

    // cout << "aqui foi" << endl;

    bool test = true;
    for (int i = 0; test; i++)
    {
        bool controle = false, controle1 = false;
        if (_jogador->getBaralhos().at(i).getNome() == nomeBaralhoJogador)
        {
            _baralhoJogador = _jogador->getBaralhos().at(i);
            controle = true;
        }
        if (_bot->getBaralhos().at(i).getNome() == nomeBaralhoBot)
        {
            _baralhoBot = _bot->getBaralhos().at(i);
            controle1 = true;
        }
        if (controle && controle1)
            test = false;
    }

    // cout << "os respectivos baralhos foram copiados" << endl;

    for (int i = 0, ie = 7; i < ie; i++)
    {
        int n1, n2;
        int numElementosJogador = (_baralhoJogador.getSize());
        if (numElementosJogador == 0)
        {
            numElementosJogador = 1;
        }
        int numElementosBot = (_baralhoBot.getSize());
        if (numElementosBot == 0)
        {
            numElementosBot = 1;
        }
        n1 = (rand() % (numElementosJogador));
        n2 = (rand() % (numElementosBot));
        // cout << n1 << " " << n2 << endl;

        mao_jogador.push_back(_baralhoJogador.getCarta(n1));
        mao_bot.push_back(_baralhoBot.getCarta(n2));
        // cout << "adicionou uma carta pra mao do jogador e bot\n";
        _baralhoJogador.removeCarta(_baralhoJogador.getCarta(n1).getNome());
        _baralhoBot.removeCarta(_baralhoBot.getCarta(n2).getNome());

        // mao_jogador.at(i).mostraCarta();

        numElementosJogador = (_baralhoJogador.getSize());
        if (numElementosJogador == 0)
        {
            numElementosJogador = 1;
        }
        numElementosBot = (_baralhoBot.getSize());
        if (numElementosBot == 0)
        {
            numElementosBot = 1;
        }

        n1 = rand() % (numElementosJogador);
        n2 = rand() % (numElementosBot);
        // cout << n1 << " " << n2 << endl;

        premiosJogador.push_back(_baralhoJogador.getCarta(n1));
        premiosBot.push_back(_baralhoBot.getCarta(n2));
        // cout << "adicionou uma carta premio do jogador e bot\n";
        _baralhoJogador.removeCarta(_baralhoJogador.getCarta(n1).getNome());
        _baralhoBot.removeCarta(_baralhoBot.getCarta(n1).getNome());
    }
}

Partida::~Partida()
{
    delete _jogador;
    delete _bot;
    mao_jogador.clear();
    mao_bot.clear();
    _nomeBaralhoJogador = "";
    _nomeBaralhoBot = "";
}
// teste
void Partida::comprarCarta(Usuario *atacante)
{
    if (atacante->getNome() != "bot")
    {
        int n1;
        int numElementosJogador = (_baralhoJogador.getSize());
        if (numElementosJogador == 0)
        {
            numElementosJogador = 1;
        }
        n1 = (rand() % (numElementosJogador));
        // cout << n1 << " " << n2 << endl;
        if ((_baralhoJogador.getSize()) > 0)
        {
            mao_jogador.push_back(_baralhoJogador.getCarta(n1));
            // cout << "comeu carta\n";
            // mao_jogador.at(mao_jogador.size()-1).mostraCarta();
            _baralhoJogador.removeCarta(_baralhoJogador.getCarta(n1).getNome());
            // mao_jogador.push_back(_baralhoJogador.getCarta(rand() % (_baralhoJogador.getSize() + 1)));
        }
        else
        {
            cout << "Nao existem mais cartas para comprar." << endl;
        }
    }
    else if (atacante->getNome() == "bot")
    {
        int n2;
        int numElementosBot = (_baralhoBot.getSize());
        if (numElementosBot == 0)
        {
            numElementosBot = 1;
        }
        n2 = (rand() % (numElementosBot));
        if ((_baralhoBot.getSize()) > 0)
        {
            mao_bot.push_back(_baralhoBot.getCarta(n2));
            _baralhoBot.removeCarta(_baralhoBot.getCarta(n2).getNome());
            // mao_bot.push_back(_baralhoJogador.getCarta(rand() % (_baralhoBot.getSize() + 1)));
        }
        else
        {
            cout << "Nao existem mais cartas para comprar." << endl;
        }
    }
}

void Partida::Ataque(string *cartaAtacando, string *cartaAtacada, Usuario *atacante)
{
    Cartas *atacando;
    Cartas *defendendo;
    bool controle = true;

    if (atacante->getNome() == _jogador->getNome())
    {
        for (int i = 0; controle; i++)
        {
            if (*cartaAtacando == (_baralhoJogador.getCarta(i).getNome()))
            {
                controle = false;
                *atacando = (_baralhoJogador.getCarta(i));
            }
        }
        controle = true;
        for (int i = 0; controle; i++)
        {
            if (*cartaAtacada == _baralhoBot.getCarta(i).getNome())
            {
                controle = false;
                *defendendo = (_baralhoBot.getCarta(i));
            }
        }
    }
    else if (atacante->getNome() == _bot->getNome())
    {
        controle = true;
        for (int i = 0; controle; i++)
        {
            if (*cartaAtacando == _baralhoBot.getCarta(i).getNome())
            {
                controle = false;
                *atacando = (_baralhoBot.getCarta(i));
            }
        }
        controle = true;
        for (int i = 0; controle; i++)
        {
            if (*cartaAtacada == _baralhoJogador.getCarta(i).getNome())
            {
                controle = false;
                *defendendo = (_baralhoJogador.getCarta(i));
            }
        }
    }
    if ((atacando->getAtaque(1)).second > defendendo->getDefesa() && atacando->getEnergia())
    {
        defendendo->sofrerDano(atacando->getAtaque(1).second - defendendo->getDefesa());

        cout << atacando->getNome() << " regaçou " << defendendo->getNome() << " e tirou "
             << ((atacando->getAtaque(1).second) - (defendendo->getDefesa()))
             << " de vida !" << endl;
    }
    else if (atacando->getAtaque(1).second < defendendo->getDefesa())
    {
        atacando->sofrerDano(-(atacando->getAtaque(1).second - defendendo->getDefesa()));

        cout << atacando->getNome() << " cabaçou e " << defendendo->getNome() << " defendeu causando "
             << (-(atacando->getAtaque(1).second - defendendo->getDefesa())) << " de dano!" << endl;
    }
    else if (!atacando->getEnergia())
        cout << "Carta sem energia para atacar espertão!" << endl;
    else
        cout << atacando->getNome() << " e " << defendendo->getNome() << " sairam ilesos da batalha !";
};

void Partida::_ligarEnergia(Cartas *_cartaEnergia, Cartas *_pokemon, Usuario *atacante)
{
    if (atacante->getNome() == _jogador->getNome())
    {
        bool controle = true;
        for (int i = 0; controle; i++)
        {
            if (_pokemon->getNome() == _baralhoJogador.getCarta(i).getNome())
            {
                controle = false;
                _pokemon->ligarEnergia(_cartaEnergia, _pokemon);
            }
        }
    }
    else if (atacante->getNome() == _bot->getNome())
    {
        bool controle = true;
        for (int i = 0; controle; i++)
        {
            if (_pokemon->getNome() == _baralhoBot.getCarta(i).getNome())
            {
                controle = false;
                _pokemon->ligarEnergia(_cartaEnergia, _pokemon);
            }
        }
    }
}

void Partida::exibirMao(Usuario *mao)
{
    // cout << "entrou aqui pai\n";
    //  string ajuda = _jogador->getNome();
    //  cout << ajuda << endl;
    //  for (int i = 0, ie = mao_jogador.size(); i < ie; i++)
    //  {
    //      mao_jogador.at(i).mostraCarta();
    //  }
    if ((mao->getNome()) == "bot")
    {
        for (int i = 0, ie = mao_bot.size(); i < ie; i++)
        {
            if(ie == 0){
                cout << "Mao vazia" << endl;
                break;
            }
            cout << "CARTA  [  " << i << "  ] DA MAO DO BOT.\n";
            mao_bot.at(i).mostraCarta();
        }
    }
    else if ((mao->getNome()) != "bot")
    {
        // cout << "entendeu o if\n";
        for (int i = 0, ie = mao_jogador.size(); i < ie; i++)
        {
            if(ie == 0){
                cout << "Mao vazia" << endl;
                break;
            }
            cout << "CARTA  [  " << i << "  ] DA MAO DO JOGADOR.\n";
            mao_jogador.at(i).mostraCarta();
        }
    }
}

#endif