#ifndef _BARALHO_CPP
#define _BARALHO_CPP

#define NC 2

#include "baralho.hpp"
#include "Cartas.hpp"
#include <vector>
#include <iostream>

using namespace std;

Baralho::Baralho()
{
    this->_nome = "";
    (this->_cartas).clear();
}

Baralho::Baralho(string nomeP, vector<Cartas> &cartasExistentes)
{
    this->_nome = nomeP;
    // REPETIR O CICLO ENQUANTO O BARALHO NÃO ATINGIR SEU TAMANHO CORRETO
    while (((this->_cartas).size()) <= NC) // coloquei 2 so para agilizar nos testes
    {
        // PEDE O NOME DA CARTA QUE SE QUER ADICIONAR AO BARALHO
        string nomeCarta;
        cout << "Digite o nome da carta que deseja adicionar ao baralho !\n";
        cin >> nomeCarta;
        int numCartasRep = 0;
        bool existeCarta = false;
        bool adicionouCarta = false;
        bool estourouLimite = false;

        // VERIFICA SE EXISTE UMA CARTA DE MESMO NOME NO BARALHO DE CARTAS ADICIONAVEIS
        for (int j = 0, je = (cartasExistentes.size()); j < je; j++)
        {
            string procuraNome = ((cartasExistentes.at(j)).getNome());
            if (nomeCarta == procuraNome)
            {
                // CASO EXISTA UMA CARTA DE MESMO NOME NO BARALHO DE CARTAS ADICIONAVEIS
                // VERIFICA-SE SE JA NAO EXISTEM 4 REPETICOES DESSA CARTA NO BARALHO QUE ESTA SENDO CRIADO
                for (int k = 0, ke = ((this->_cartas).size()); k < ke; k++)
                {
                    // PERCORRE O BARALHO QUE ESTA SENDO CRIADO COMPARANDO O NOME DAS CARTAS COM O ESCRITO
                    string nomeDessaCarta = _cartas.at(k).getNome();
                    if (nomeCarta == nomeDessaCarta)
                    {
                        numCartasRep++;
                    }
                }
                // CASO TENHAM MENOS DE 4 APARICOES PERMITE O PUSHBACK
                if (numCartasRep < 4)
                {
                    (this->_cartas).push_back(cartasExistentes.at(j));
                    existeCarta = true;
                    adicionouCarta = true;
                    break;
                }
                // DO CONTRARIO NAO PERMITE
                else if (numCartasRep >= 4)
                {
                    cout << "Essa carta atingiu o limite maximo de repeticoes por baralho" << endl;
                    estourouLimite = true;
                    break;
                }
            }
            // CONDICAO PRA PARAR DE PERCORRER O BARALHO ADICIONAVEL POIS JA DEU PUSHBACK NA CARTA CERTA
            if (adicionouCarta || estourouLimite)
            {
                break;
            }
        }
        if (!existeCarta)
        {
            cout << "Nao existe carta que pode ser adicionada com esse nome" << endl;
        }
    }
};

Baralho::~Baralho()
{
    (this->_cartas).clear();
    this->_nome = "";
};

string Baralho::getNome()
{
    return this->_nome;
};

vector<Cartas> Baralho::getCartasBaralho()
{
    return (this->_cartas);
}

void Baralho::operator=(Baralho &operando)
{
    this->_nome = (operando.getNome());
    this->_cartas = (operando.getCartasBaralho());
}

void Baralho::setNome(string nomeP)
{
    this->_nome = nomeP;
};

Cartas Baralho::getCarta(int num)
{
    for (int i = 0, ie = _cartas.size(); i < ie; i++)
    {
        if (i == num)
            return _cartas[i];
    }
};

void Baralho::removeCarta(string nome)
{
    bool control = true;
    int ie = 0;
    for (auto i = _cartas.begin(); control; i++)
    {
        if (_cartas.at(ie).getNome() == nome)
        {
            _cartas.erase(i);
            control = false;
            break;
        }
        ie++;
    }
    if(control)
        cout << "Carta não encontrada para remover!\n";
}

int Baralho::getSize()
{
    return _cartas.size();
}

#endif