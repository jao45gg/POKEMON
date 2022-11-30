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

    for (int i = 0, ie = 7; i < ie; i++)
    {
        int n1, n2;
        n1 = rand() % (_baralhoJogador.getSize() + 1);
        n2 = rand() % (_baralhoJogador.getSize() + 1);

        mao_jogador.push_back(_baralhoJogador.getCarta(n1));
        mao_bot.push_back(_baralhoBot.getCarta(n2));
        _baralhoJogador.removeCarta(_baralhoJogador.getCarta(n1).getNome());
        _baralhoBot.removeCarta(_baralhoBot.getCarta(n2).getNome());

        n1 = rand() % (_baralhoJogador.getSize() + 1);
        n2 = rand() % (_baralhoJogador.getSize() + 1);

        premiosJogador.push_back(_baralhoJogador.getCarta(n1));
        premiosBot.push_back(_baralhoBot.getCarta(n2));
        _baralhoJogador.removeCarta(_baralhoJogador.getCarta(n1).getNome());
        _baralhoBot.removeCarta(_baralhoBot.getCarta(n1).getNome());
    }
}

Partida::~Partida()
{
    mao_jogador.clear();
    mao_bot.clear();
    _nomeBaralhoJogador = "";
    _nomeBaralhoBot = "";
    premiosJogador.clear();
    premiosBot.clear();
    _baralhoJogador.~Baralho();
    _baralhoBot.~Baralho();
}

void Partida::pokemonMorto(Baralho *baralho, Cartas *morto)
{
    baralho->removeCarta(morto->getNome());
    if (premiosBot.size() == 0 && premiosJogador.size() > 0)
    {
        cout << _bot->getNome() << " é o vencedor ihuuuuu!\n";
        _bot->setVitorias();
        _jogador->setDerrotas();
        this->~Partida();
    }
    else if (premiosJogador.size() == 0 && premiosBot.size() > 0)
    {
        cout << _jogador->getNome() << " é o vencedor ihuuuuu!\n";
        _jogador->setVitorias();
        _bot->setDerrotas();
        this->~Partida();
    }
    else if (_baralhoBot.getSize() == 0 && mao_bot.size() == 0 && _baralhoJogador.getSize() > 0 && _baralhoJogador.getSize() > 0)
    {
        cout << _jogador->getNome() << " é o vencedor ihuuuuu!\n";
        _jogador->setVitorias();
        _bot->setDerrotas();
        this->~Partida();
    }
    else if (_baralhoJogador.getSize() == 0 && mao_jogador.size() == 0 && _baralhoBot.getSize() > 0 && _baralhoBot.getSize() > 0)
    {
        cout << _bot->getNome() << " é o vencedor ihuuuuu!\n";
        _bot->setVitorias();
        _jogador->setDerrotas();
        this->~Partida();
    }
}

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

bool Partida::ataqueTipo(Cartas *_atacando, Cartas *_defendendo, float multiplicador_dano, pair<string, int> infos)
{
    if (multiplicador_dano * infos.second > _defendendo->getDefesa() && _atacando->getEnergia())
    {
        _defendendo->sofrerDano(multiplicador_dano * infos.second - _defendendo->getDefesa());

        cout << _atacando->getNome() << " regaçou " << _defendendo->getNome() << " e tirou "
             << multiplicador_dano * infos.second - _defendendo->getDefesa()
             << " de vida !" << endl;

        if (_defendendo->getHp() <= 0)
        {
            cout << _defendendo->getNome() << " foi de beise!" << endl;
            return true;
        }
        else
            return false;
    }
    else if (multiplicador_dano * infos.second < _defendendo->getDefesa())
    {
        _atacando->sofrerDano(-(multiplicador_dano * infos.second - _defendendo->getDefesa()));

        cout << _atacando->getNome() << " cabaçou e " << _defendendo->getNome() << " defendeu causando "
             << -(multiplicador_dano * infos.second - _defendendo->getDefesa()) << " de dano!" << endl;

        if (_atacando->getHp() <= 0)
        {
            cout << _atacando->getNome() << " foi de beise!" << endl;
            return true;
        }
        else
            return false;
    }
    else if (!_atacando->getEnergia())
    {
        cout << "Carta sem energia para atacar espertão!" << endl;
        return false;
    }
    else
    {
        cout << _atacando->getNome() << " e " << _defendendo->getNome() << " sairam ilesos da batalha !";
        return false;
    }
}

void Partida::Ataque(string *cartaAtacando, string *cartaAtacada, Usuario *atacante, string *nome_atk)
{
    Cartas *atacando;
    Cartas *defendendo;
    bool controle = true;
    bool control_atk = false;
    int controle_usuario = 0;

    if (atacante->getNome() == _jogador->getNome())
    {
        for (int i = 0; controle; i++)
        {
            if (*cartaAtacando == _baralhoJogador.getCarta(i).getNome())
            {
                controle = false;
                *atacando = _baralhoJogador.getCarta(i);
                controle_usuario = 1;
            }
        }
        controle = true;
        for (int i = 0; controle; i++)
        {
            if (*cartaAtacada == _baralhoBot.getCarta(i).getNome())
            {
                controle = false;
                *defendendo = _baralhoBot.getCarta(i);
            }
        }
        controle = true;
        for (int i = 0; controle; i++)
        {
            if (atacando->getAtaque(*nome_atk).first == *nome_atk)
            {
                controle = false;
                control_atk = true;
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
                *atacando = _baralhoBot.getCarta(i);
                controle_usuario = 2;
            }
        }
        controle = true;
        for (int i = 0; controle; i++)
        {
            if (*cartaAtacada == _baralhoJogador.getCarta(i).getNome())
            {
                controle = false;
                *defendendo = _baralhoJogador.getCarta(i);
            }
        }
        controle = true;
        for (int i = 0; controle; i++)
        {
            if (atacando->getAtaque(*nome_atk).first == *nome_atk)
            {
                controle = false;
                control_atk = true;
            }
        }
    }

    bool controle_mortos = false;
    if (control_atk)
    {
        if (atacando->getTipo() == "água" && defendendo->getTipo() == "fogo")
            controle_mortos = this->ataqueTipo(atacando, defendendo, 2, atacando->getAtaque(*nome_atk));
        else if (atacando->getTipo() == "fogo" && defendendo->getTipo() == "planta")
            controle_mortos = this->ataqueTipo(atacando, defendendo, 2, atacando->getAtaque(*nome_atk));
        else if (atacando->getTipo() == "planta" && defendendo->getTipo() == "terra")
            controle_mortos = this->ataqueTipo(atacando, defendendo, 2, atacando->getAtaque(*nome_atk));
        else if (atacando->getTipo() == "terra" && defendendo->getTipo() == "elétrico")
            controle_mortos = this->ataqueTipo(atacando, defendendo, 2, atacando->getAtaque(*nome_atk));
        else if (atacando->getTipo() == "elétrico" && defendendo->getTipo() == "água")
            controle_mortos = this->ataqueTipo(atacando, defendendo, 2, atacando->getAtaque(*nome_atk));
        else if (atacando->getTipo() == "fogo" && defendendo->getTipo() == "água")
            controle_mortos = this->ataqueTipo(atacando, defendendo, 0.5, atacando->getAtaque(*nome_atk));
        else if (atacando->getTipo() == "planta" && defendendo->getTipo() == "fogo")
            controle_mortos = this->ataqueTipo(atacando, defendendo, 0.5, atacando->getAtaque(*nome_atk));
        else if (atacando->getTipo() == "terra" && defendendo->getTipo() == "planta")
            controle_mortos = this->ataqueTipo(atacando, defendendo, 0.5, atacando->getAtaque(*nome_atk));
        else if (atacando->getTipo() == "elétrico" && defendendo->getTipo() == "terra")
            controle_mortos = this->ataqueTipo(atacando, defendendo, 0.5, atacando->getAtaque(*nome_atk));
        else if (atacando->getTipo() == "água" && defendendo->getTipo() == "elétrico")
            controle_mortos = this->ataqueTipo(atacando, defendendo, 0.5, atacando->getAtaque(*nome_atk));
    }
    else
        cout << "Nome de ataque inválidoc!\n";
    if(controle_mortos) {
        if(controle_usuario == 1 && atacando->getHp() <=0)
            this->pokemonMorto(&_baralhoJogador, atacando);
        else if(controle_usuario == 1 && defendendo->getHp() <=0)
            this->pokemonMorto(&_baralhoBot, defendendo);
        else if(controle_usuario == 2 && atacando->getHp() <=0)
            this->pokemonMorto(&_baralhoBot, atacando);
        else if(controle_usuario == 2 && defendendo->getHp() <=0)
            this->pokemonMorto(&_baralhoJogador, defendendo);

    }
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

void Partida::exibirMao(Usuario *mao) {
    if (mao->getNome() == _jogador->getNome())
    {
        for (int i = 0, ie = _baralhoJogador.getSize(); i < ie; i++)
        {
            cout << _baralhoJogador.getCarta(i).getNome() << endl;
        }
        
    }
    else if (mao->getNome() == _bot->getNome())
    {
        for (int i = 0, ie = _baralhoBot.getSize(); i < ie; i++)
        {
            cout << _baralhoBot.getCarta(i).getNome() << endl;
        }
    }
}

#endif