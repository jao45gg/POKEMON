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
        mao_jogador.push_back(_baralhoJogador->getCarta(rand()%(_baralhoJogador->getSize()+1)));
        mao_bot.push_back(_baralhoJogador->getCarta(rand()%(_baralhoBot->getSize()+1)));
        
    }
}

Partida::~Partida() {
    delete _jogador;
    delete _bot;
    delete _baralhoJogador;
    delete _baralhoBot;
    mao_jogador.clear();
    mao_bot.clear();
    _nomeBaralhoJogador = "";
    _nomeBaralhoBot = "";
}
//teste
void Partida::comprarCarta(Usuario *atacante) {
    if(atacante->getNome() == _jogador->getNome()) {
        mao_jogador.push_back(_baralhoJogador->getCarta(rand()%(_baralhoJogador->getSize()+1)));
    }
    else if(atacante->getNome() == _bot->getNome()) {
        mao_bot.push_back(_baralhoJogador->getCarta(rand()%(_baralhoBot->getSize()+1)));
    }
}

void Partida::usarHabilidade(string *cartaFazendo, Usuario *atacante) {

}

void Partida::Ataque(string *cartaAtacando, Usuario *atacante) {
    
}

void Partida::_ligarEnergia(Cartas *_cartaEnergia, Cartas *_pokemon, Usuario *atacante) {
    if(atacante->getNome() == _jogador->getNome()) {
        bool controle = true;
        for (int i = 0; controle; i++)
        {
            if(*_pokemon == _baralhoJogador->getCarta(i))
                _pokemon->ligarEnergia(_cartaEnergia,_pokemon);
        }
        
    }
    else if(atacante->getNome() == _bot->getNome()) {
        bool controle = true;
        for (int i = 0; controle; i++)
        {
            /* code */
        }
        
    }
}

#endif