#ifndef _PARTIDA_CPP
#define _PARTIDA_CPP

#include "Partida.hpp"

Partida::Partida(Usuario *jogador, Usuario *bot, string nomeBaralhoJogador, string nomeBaralhoBot)
{

    _jogador = jogador;
    _bot = bot;

    bool test = true;
    for (int i = 0; test; i++)
    {
        bool controle = false, controle1 = false;
        if (_jogador->getBaralhos().at(i).getNome() == nomeBaralhoJogador)
        {
            _baralhoJogador = &_jogador->getBaralhos().at(i);
            controle = true;
        }
        if (_bot->getBaralhos().at(i).getNome() == nomeBaralhoBot)
        {
            _baralhoBot = &_bot->getBaralhos().at(i);
            controle1 = true;
        }
        if (controle && controle1)
            test = false;
    }

    for (int i = 0, ie = 7; i < ie; i++)
    {
        mao_jogador.push_back(_baralhoJogador->getCarta(rand() % (_baralhoJogador->getSize() + 1)));
        mao_bot.push_back(_baralhoJogador->getCarta(rand() % (_baralhoBot->getSize() + 1)));
    }
}

Partida::~Partida()
{
    delete _jogador;
    delete _bot;
    delete _baralhoJogador;
    delete _baralhoBot;
    mao_jogador.clear();
    mao_bot.clear();
    _nomeBaralhoJogador = "";
    _nomeBaralhoBot = "";
}
// teste
void Partida::comprarCarta(Usuario *atacante)
{
    if (atacante->getNome() == _jogador->getNome())
    {
        mao_jogador.push_back(_baralhoJogador->getCarta(rand() % (_baralhoJogador->getSize() + 1)));
    }
    else if (atacante->getNome() == _bot->getNome())
    {
        mao_bot.push_back(_baralhoJogador->getCarta(rand() % (_baralhoBot->getSize() + 1)));
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
            if (*cartaAtacando == _baralhoJogador->getCarta(i).getNome())
            {
                controle = false;
                atacando = &_baralhoJogador->getCarta(i);
            }
        }
        controle = true;
        for (int i = 0; controle; i++)
        {
            if (*cartaAtacada == _baralhoBot->getCarta(i).getNome())
            {
                controle = false;
                defendendo = &_baralhoBot->getCarta(i);
            }
        }
    }
    else if (atacante->getNome() == _bot->getNome())
    {
        controle = true;
        for (int i = 0; controle; i++)
        {
            if (*cartaAtacando == _baralhoBot->getCarta(i).getNome())
            {
                controle = false;
                atacando = &_baralhoBot->getCarta(i);
            }
        }
        controle = true;
        for (int i = 0; controle; i++)
        {
            if (*cartaAtacada == _baralhoJogador->getCarta(i).getNome())
            {
                controle = false;
                defendendo = &_baralhoJogador->getCarta(i);
            }
        }
    }
    if (atacando->getAtaque() > defendendo->getDefesa() && atacando->getEnergia())
    {
        defendendo->sofrerDano(atacando->getAtaque() - defendendo->getDefesa());

        cout << atacando->getNome() << " regaçou " << defendendo->getNome() << " e tirou "
             << atacando->getAtaque() - defendendo->getDefesa()
             << " de vida !" << endl;
    }
    else if (atacando->getAtaque() < defendendo->getDefesa())
    {
        atacando->sofrerDano(-(atacando->getAtaque() - defendendo->getDefesa()));

        cout << atacando->getNome() << " cabaçou e " << defendendo->getNome() << " defendeu causando "
             << -(atacando->getAtaque() - defendendo->getDefesa()) << " de dano!" << endl;
    }
    else if (!atacando->getEnergia())
        cout << "Carta sem energia para atacar espertão!" << endl;
    else
        cout << atacando->getNome() << " e " << defendendo->getNome() << " sairam ilesos da batalha !";
}

void Partida::_ligarEnergia(Cartas *_cartaEnergia, Cartas *_pokemon, Usuario *atacante)
{
    if (atacante->getNome() == _jogador->getNome())
    {
        bool controle = true;
        for (int i = 0; controle; i++)
        {
            if (_pokemon->getNome() == _baralhoJogador->getCarta(i).getNome())
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
            if (_pokemon->getNome() == _baralhoBot->getCarta(i).getNome())
            {
                controle = false;
                _pokemon->ligarEnergia(_cartaEnergia, _pokemon);
            }
        }
    }
}

#endif