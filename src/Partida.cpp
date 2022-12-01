#ifndef _PARTIDA_CPP
#define _PARTIDA_CPP

#include "Partida.hpp"
#include <iostream>

using namespace std;

Partida::Partida(Usuario jogador, Usuario bot, string nomeBaralhoJogador, string nomeBaralhoBot)
{

    _jogador = &jogador;
    //_jogador->setNome(jogador.getNome());
    _bot = &bot;
    //_bot->setNome(bot.getNome());

    //cout << "aqui foi" << endl;

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
    
    //cout << "os respectivos baralhos foram copiados" << endl;

    for (int i = 0, ie = 7; i < ie; i++)
    {
<<<<<<< Updated upstream
        mao_jogador.push_back(_baralhoJogador.getCarta(rand() % (_baralhoJogador.getSize() + 1)));
        mao_bot.push_back(_baralhoJogador.getCarta(rand() % (_baralhoBot.getSize() + 1)));
=======
        int n1, n2;
        int numElementosJogador = (_baralhoJogador.getSize());
        if(numElementosJogador == 0){
            numElementosJogador = 1;
        }
        int numElementosBot = (_baralhoBot.getSize());
        if(numElementosBot == 0){
            numElementosBot = 1;
        }
        n1 = (rand() % (numElementosJogador));
        n2 = (rand() % (numElementosBot));
        //cout << n1 << " " << n2 << endl;

        mao_jogador.push_back(_baralhoJogador.getCarta(n1));
        mao_bot.push_back(_baralhoBot.getCarta(n2));
        _baralhoJogador.removeCarta(_baralhoJogador.getCarta(n1).getNome());
        _baralhoBot.removeCarta(_baralhoBot.getCarta(n2).getNome());

        //mao_jogador.at(i).mostraCarta();

        numElementosJogador = (_baralhoJogador.getSize());
        if(numElementosJogador == 0){
            numElementosJogador = 1;
        }
        numElementosBot = (_baralhoBot.getSize());
        if(numElementosBot == 0){
            numElementosBot = 1;
        }

        n1 = rand() % (numElementosJogador);
        n2 = rand() % (numElementosBot);
        //cout << n1 << " " << n2 << endl;

        premiosJogador.push_back(_baralhoJogador.getCarta(n1));
        premiosBot.push_back(_baralhoBot.getCarta(n2));
        _baralhoJogador.removeCarta(_baralhoJogador.getCarta(n1).getNome());
        _baralhoBot.removeCarta(_baralhoBot.getCarta(n1).getNome());
>>>>>>> Stashed changes
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
    if (atacante->getNome() == _jogador->getNome())
    {
        mao_jogador.push_back(_baralhoJogador.getCarta(rand() % (_baralhoJogador.getSize() + 1)));
    }
    else if (atacante->getNome() == _bot->getNome())
    {
        mao_bot.push_back(_baralhoJogador.getCarta(rand() % (_baralhoBot.getSize() + 1)));
    }
}

void Partida::ataqueTipo(Cartas *_atacando, Cartas *_defendendo, float multiplicador_dano)
{
    if (multiplicador_dano * _atacando->getAtaque() > _defendendo->getDefesa() && _atacando->getEnergia())
    {
        _defendendo->sofrerDano(multiplicador_dano * _atacando->getAtaque() - _defendendo->getDefesa());

        cout << _atacando->getNome() << " regaçou " << _defendendo->getNome() << " e tirou "
             << multiplicador_dano * _atacando->getAtaque() - _defendendo->getDefesa()
             << " de vida !" << endl;
        if (_defendendo->getHp() <= 0)
            cout << _defendendo->getNome() << " foi de beise!" << endl;
        // fazer aqui a parte do pokemon morto
    }
    else if (multiplicador_dano * _atacando->getAtaque() < _defendendo->getDefesa())
    {
        _atacando->sofrerDano(-(multiplicador_dano * _atacando->getAtaque() - _defendendo->getDefesa()));

        cout << _atacando->getNome() << " cabaçou e " << _defendendo->getNome() << " defendeu causando "
             << -(multiplicador_dano * _atacando->getAtaque() - _defendendo->getDefesa()) << " de dano!" << endl;
        if (_atacando->getHp() <= 0)
            cout << _atacando->getNome() << " foi de beise!" << endl;
        // fazer aqui a parte do pokemon morto
    }
    else if (!_atacando->getEnergia())
        cout << "Carta sem energia para atacar espertão!" << endl;
    else
        cout << _atacando->getNome() << " e " << _defendendo->getNome() << " sairam ilesos da batalha !";
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
            if (*cartaAtacando == _baralhoJogador.getCarta(i).getNome())
            {
                controle = false;
                atacando = &_baralhoJogador.getCarta(i);
            }
        }
        controle = true;
        for (int i = 0; controle; i++)
        {
            if (*cartaAtacada == _baralhoBot.getCarta(i).getNome())
            {
                controle = false;
                defendendo = &_baralhoBot.getCarta(i);
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
                atacando = &_baralhoBot.getCarta(i);
            }
        }
        controle = true;
        for (int i = 0; controle; i++)
        {
            if (*cartaAtacada == _baralhoJogador.getCarta(i).getNome())
            {
                controle = false;
                defendendo = &_baralhoJogador.getCarta(i);
            }
        }
    }

    if (atacando->getTipo() == "água" && defendendo->getTipo() == "fogo")
        this->ataqueTipo(atacando, defendendo, 2);
    else if (atacando->getTipo() == "fogo" && defendendo->getTipo() == "planta")
        this->ataqueTipo(atacando, defendendo, 2);
    else if (atacando->getTipo() == "planta" && defendendo->getTipo() == "terra")
        this->ataqueTipo(atacando, defendendo, 2);
    else if (atacando->getTipo() == "terra" && defendendo->getTipo() == "elétrico")
        this->ataqueTipo(atacando, defendendo, 2);
    else if (atacando->getTipo() == "elétrico" && defendendo->getTipo() == "água")
        this->ataqueTipo(atacando, defendendo, 2);
    else if (atacando->getTipo() == "fogo" && defendendo->getTipo() == "água")
        this->ataqueTipo(atacando, defendendo, 0.5);
    else if (atacando->getTipo() == "planta" && defendendo->getTipo() == "fogo")
        this->ataqueTipo(atacando, defendendo, 0.5);
    else if (atacando->getTipo() == "terra" && defendendo->getTipo() == "planta")
        this->ataqueTipo(atacando, defendendo, 0.5);
    else if (atacando->getTipo() == "elétrico" && defendendo->getTipo() == "terra")
        this->ataqueTipo(atacando, defendendo, 0.5);
    else if (atacando->getTipo() == "água" && defendendo->getTipo() == "elétrico")
        this->ataqueTipo(atacando, defendendo, 0.5);
}

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

<<<<<<< Updated upstream
=======
void Partida::exibirMao(Usuario mao) {
    cout << "entrou aqui pai\n"; 
    if(mao.getNome() == _jogador->getNome()){
        cout << "ele compara certo" << endl;
        for(int i = 0, ie = mao_jogador.size(); i < ie; i++){
            mao_jogador.at(i).mostraCarta();
        }
    }
    if(mao.getNome() == _bot->getNome()){
        cout << "ele compara certo" << endl;
        for(int i = 0, ie = mao_bot.size(); i < ie; i++){
            mao_bot.at(i).mostraCarta();
        }
    }
    cout << "mostrou a mao" << endl;
        
    // }
    // else if (mao->getNome() == _bot->getNome())
    // {
    //     for (int i = 0, ie = mao_bot.size(); i < ie; i++)
    //     {
    //         (mao_bot.at(i)).mostraCarta();
    //     }
    // }
}

>>>>>>> Stashed changes
#endif