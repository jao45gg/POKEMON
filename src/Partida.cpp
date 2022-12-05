#ifndef _PARTIDA_CPP
#define _PARTIDA_CPP

#include "../include/Partida.hpp"
#include "../include/Usuario.hpp"
#include "../include/Cartas.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

Partida::Partida(Usuario jogador, Usuario bot, string nomeBaralhoJogador, string nomeBaralhoBot)
{
    _jogador = &jogador;
    _jogador->setNome(jogador.getNome());
    _bot = &bot;
    _bot->setNome(bot.getNome());
    _cartaEmBatalhaBot.destroiCarta();
    //_cartaEmBatalhaBot = vazia;
    _cartaEmBatalhaJogador.destroiCarta();

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

    for (int i = 0, ie = 6; i < ie; i++)
    {
        int n1, n2;
        int numElementosJogador = (_baralhoJogador.getSize());
        int numElementosBot = (_baralhoBot.getSize());
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
        unsigned seed = time(0);
        srand(seed);
        n1 = (rand() % (numElementosJogador));
        n2 = (rand() % (numElementosBot));
        // cout << n1 << " " << n2 << endl;

        mao_jogador.push_back(_baralhoJogador.getCarta(n1));
        mao_bot.push_back(_baralhoBot.getCarta(n2));
        // cout << "adicionou uma carta pra mao do jogador e bot\n";
        _baralhoJogador.removeCarta(_baralhoJogador.getCarta(n1).getNome());
        _baralhoBot.removeCarta(_baralhoBot.getCarta(n2).getNome());
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
void Partida::comprarCarta(string nomeJogador)
{
    if (nomeJogador != "Bot")
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
            cout << endl << nomeJogador << " comeu uma carta de seu Baralho" << endl;
            cout << endl;
        }
        else
        {
            //cout << endl;
            cout << "Nao existem mais cartas no Baralho de " << nomeJogador << " para comprar" << endl << endl;
        }
    }
    else if (nomeJogador == "Bot")
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
            cout << endl << "Bot" << " comeu uma carta de seu Baralho" << endl;
            cout << endl;
            // mao_bot.push_back(_baralhoJogador.getCarta(rand() % (_baralhoBot.getSize() + 1)));
        }
        else
        {
            //cout << endl;
            cout << "Nao existem mais cartas no Baralho do Bot para comprar" << endl << endl;
        }
    }
}

void Partida::Ataque(string usuarioAtacante, string usuarioDefensor)
{
    if (usuarioAtacante == "Bot")
    {
        vector<pair<string, int>> ataque = _cartaEmBatalhaBot.getAtaques();
        string PokemonAtacante = getNomeCartaBatalha("Bot");
        string PokemonDefensor = getNomeCartaBatalha(usuarioDefensor);

        int defesa = _cartaEmBatalhaJogador.getDefesa();
        //cout << "Defesa: " << defesa << endl;
        int resultadoDoAtaque = ataque.at(0).second - defesa;
        // cout << ataque.at(0).first << " " << ataque.at(0).second << " " << nomePokemonBot << endl;
        //cout << endl;
        cout << PokemonAtacante << " do Bot usou " << ataque.at(0).first << " e causou ";
        if (resultadoDoAtaque >= 0)
        {
            cout << resultadoDoAtaque << " de dano no " << PokemonDefensor << " de " << usuarioDefensor;
            cout << endl;
            _cartaEmBatalhaJogador.sofrerDano(resultadoDoAtaque);
        }
        else if (resultadoDoAtaque < 0)
        {
            resultadoDoAtaque = resultadoDoAtaque * (-1);
            cout << resultadoDoAtaque << " de dano em si mesmo pois o golpe foi rebatido" << endl;
            //cout << endl;
            _cartaEmBatalhaBot.sofrerDano(resultadoDoAtaque);
        }
    }
    else
    {
        vector<pair<string, int>> ataque = _cartaEmBatalhaJogador.getAtaques();
        string PokemonAtacante = getNomeCartaBatalha(usuarioAtacante);
        string PokemonDefensor = getNomeCartaBatalha("Bot");

        int defesa = _cartaEmBatalhaBot.getDefesa();
        //cout << "Defesa do inimigo: " << defesa << endl;

        int resultadoDoAtaque = (ataque.at(0).second) - defesa;

        //cout << ataque.at(0).first << " " << ataque.at(0).second << " " << PokemonAtacante << endl;
        //cout << endl;
        cout << _cartaEmBatalhaJogador.getNome() << " de " << usuarioAtacante << " usou " << ataque.at(0).first << " e causou ";
        if (resultadoDoAtaque >= 0)
        {
            cout << resultadoDoAtaque << " de dano no " << PokemonDefensor << " do Bot";
            cout << endl << endl;
            _cartaEmBatalhaBot.sofrerDano(resultadoDoAtaque);
        }
        else if (resultadoDoAtaque < 0)
        {
            resultadoDoAtaque = resultadoDoAtaque * (-1);
            cout << resultadoDoAtaque << " de dano em si mesmo pois o golpe foi rebatido" << endl;
            _cartaEmBatalhaJogador.sofrerDano(resultadoDoAtaque);
        }
    }
};

void Partida::exibirMao(Usuario *mao)
{
    if ((mao->getNome()) == "bot")
    {
        for (int i = 0, ie = mao_bot.size(); i < ie; i++)
        {
            if (ie == 0)
            {
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
            if (ie == 0)
            {
                cout << "Mao vazia" << endl;
                break;
            }
            cout << "CARTA  [  " << i << "  ] DA MAO DO JOGADOR.\n";
            mao_jogador.at(i).mostraCarta();
        }
    }
}

void Partida::ganharPremio(string nomeJogador)
{
    if (nomeJogador == "Bot")
    {
        if (premiosBot.size() > 0)
        {
            cout << endl;
            cout << "Bot recebeu uma de suas Cartas Premio!" << endl;
            mao_bot.push_back(premiosBot.at(0));
            premiosBot.erase(premiosBot.begin());
            cout << "Agora restam apenas [  " << premiosBot.size() << "  ]" << endl << endl;
        }
        else
        {
            cout << endl;
            cout << "Bot nao possui mais Cartas Premio disponiveis";
            cout << endl
                 << endl;
        }
    }
    else
    {
        if (premiosJogador.size() > 0)
        {
            cout << endl;
            cout << nomeJogador << " recebeu uma de suas Cartas Premio!" << endl;
            mao_jogador.push_back(premiosJogador.at(0));
            premiosJogador.erase(premiosJogador.begin());
            cout << "Agora restam apenas [  " << premiosJogador.size() << "  ]" << endl << endl; 
        }
        else
        {
            cout << endl;
            cout << nomeJogador << " nao possui mais Cartas Premio disponiveis" << endl
                 << endl;
        }
    }
}

int Partida::numPremio(string nomeJogador)
{
    if (nomeJogador == "Bot")
    {
        return ((this->premiosBot).size());
    }
    else
    {
        return ((this->premiosJogador).size());
    }
};

bool Partida::estaSemCarta(string nomeJogador)
{
    if (nomeJogador == "Bot")
    {
        if (_cartaEmBatalhaBot.getNome() == "")
        {
            //cout << nomeJogador << " esta sem carta batalhando" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (_cartaEmBatalhaJogador.getNome() == "")
        {
            //cout << nomeJogador << " esta sem carta batalhando" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
}

void Partida::setCartaEmBatalha(int numCarta, string nomePlayer)
{
    if (nomePlayer == "Bot")
    {
        if (mao_bot.size() > 0)
        {
            // cout << "teste!!!" << endl;
            (_cartaEmBatalhaBot) = (mao_bot.at(numCarta));
            cout << "Pokemon " << _cartaEmBatalhaBot.getNome() << " movido para o Campo de Batalha" << endl << endl;
        }
        else
        {
            cout << endl << "Nao existem mais cartas na mao do Bot" << endl << endl;
            //cout << _cartaEmBatalhaJogador.getNome() << " carta do bot " << endl;
        }
        //_baralhoJogador.removeCarta(_baralhoJogador.getCarta(numCarta).getNome());
    }
    else
    {
        if (mao_jogador.size() > 0)
        {
            // cout << "teste!!!" << endl;
            (_cartaEmBatalhaJogador) = (mao_jogador.at(numCarta));
            cout << "Pokemon " << _cartaEmBatalhaJogador.getNome() << " movido para o Campo de Batalha" << endl << endl;
        }
        else
        {
            cout << endl << "Nao existem mais cartas na mao do " << nomePlayer << endl << endl;
        }
        //_baralhoBot.removeCarta(_baralhoBot.getCarta(numCarta).getNome());
    }
}

bool Partida::cartaMorta(string nomeJogador)
{
    if (nomeJogador == "Bot")
    {
            if (_cartaEmBatalhaBot.getHp() <= 0)
            {
                cout << "O Pokemon " << _cartaEmBatalhaBot.getNome() << " do Bot que estava em batalha morreu" << endl << endl;
                return true;
            }
            else
            {
                return false;
            }
    }
    else
    {
            if (_cartaEmBatalhaJogador.getHp() <= 0)
            {
                cout << "O Pokemon " << _cartaEmBatalhaJogador.getNome() << " de " << nomeJogador << " que estava em batalha morreu" << endl << endl;
                return true;
            }
            else
            {
                return false;
            }
    }
};

void Partida::matarCarta(string nomeJogador)
{
    if (nomeJogador == "Bot")
    {
        vector<Cartas>::iterator it;
        it = mao_bot.begin();
        int i = 0;
        unsigned int ie = mao_bot.size();

        //cout << "tESTE VER SE MATA 1" << endl << "numero de elementos na mao do BOT " << ie;
            cout << endl;

        for (unsigned int it = 0; it < ie; it++)
        {
            if ((_cartaEmBatalhaBot.getNome()) == mao_bot.at(it).getNome())
            {
                //cout << "tESTE VER SE MATA 2" << endl << endl;
                _cartaEmBatalhaBot.destroiCarta();
                //cout << mao_bot.at(i).getNome() << " foi apagada da mao do Bot" << endl << endl;
                if(mao_bot.size() > 0){
                    //cout << "tESTE VER SE MATA 3" << endl << endl;
                    mao_bot.erase(mao_bot.begin()+it);
                    //cout << "tESTE VER SE MATA 4" << endl << endl;
                    ie = mao_bot.size();
                }
                else{
                    cout << endl;
                    cout << "Impossivel apagar essa carta da mao do bot" << endl << endl;
                }

            }
            i++;
        }
    }
    else
    {
        vector<Cartas>::iterator it;
        it = mao_jogador.begin();
        int i = 0;
        unsigned int ie = mao_jogador.size();
        
            //cout << "tESTE VER SE MATA 1" << endl << "numero de elementos na mao do " << nomeJogador << " " << ie;
            cout << endl;

        for (unsigned int it = 0; it < ie; it++)
        {
            if ((_cartaEmBatalhaJogador.getNome()) == mao_jogador.at(it).getNome())
            {
                //cout << "tESTE VER SE MATA 2" << endl << endl;
                _cartaEmBatalhaJogador.destroiCarta();
                //cout << mao_jogador.at(i).getNome() << " foi apagada da mao de " << nomeJogador << endl << endl;
                if(mao_jogador.size() > 0){
                    //cout << "tESTE VER SE MATA 3" << endl << endl;
                    mao_jogador.erase(mao_jogador.begin()+it);
                    //cout << "tESTE VER SE MATA 4" << endl << endl;
                    ie = mao_jogador.size();
                }
                else{
                    cout << endl;
                    cout << "Foi impossivel apagar essa carta da mao do " << nomeJogador << endl << endl;
                }
            }
            i++;
        }
    }
}

vector<Cartas> Partida::getMaoJogador(string nomeJogador)
{
    if (nomeJogador == "Bot")
    {
        return (this->mao_bot);
    }
    else
    {
        return (this->mao_jogador);
    }
}

string Partida::getNomeCartaBatalha(string nomeJogador)
{
    if (nomeJogador == "Bot")
    {
        return (_cartaEmBatalhaBot.getNome());
    }
    else
    {
        return (_cartaEmBatalhaJogador.getNome());
    }
}

// Cartas Partida::*getCartaBatalha(string nomeJogador){
//     if(nomeJogador == "Bot"){
//         return
//     }
// }

#endif