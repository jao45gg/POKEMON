#ifndef _USUARIO_CPP
#define _USUARIO_CPP

#include "Usuario.hpp"
#include "Cartas.hpp"
#include "baralho.hpp"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <sstream>

Usuario::Usuario()
{
    this->nome = "Jogador";
    this->vitorias = 0;
    this->derrotas = 0;
    this->baralhos = {};
}

Usuario::~Usuario()
{
    this->nome = "";
    vitorias = 0;
    derrotas = 0;
    baralhos.clear();
}

Usuario::Usuario(string nome)
{
    // cout << "criou o objeto usuario" << endl;
    this->nome = nome;
    this->vitorias = 0;
    this->derrotas = 0;

    vector<Cartas> cartasExistentes;
    vector<pair<string, int>> ataque;
    vector<Baralho> BaralhosDisponiveis;

    Baralho Baralho1 = Baralho();
    Baralho1.setNome("Baralho de Fogo");

    vector<Cartas> CartasFogo;
    pair<string, int> foo;
    foo = make_pair("Presas de Fogo", 20);
    ataque.push_back(foo);
    Cartas Carta = Cartas("Charmander", 1, ataque, 93, "Fogo", 118);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Lanca Chamas", 80);
    ataque.push_back(foo);
    Carta = Cartas("Charmeleon", 1, ataque, 126, "Fogo", 151);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Labareda Real", 100);
    ataque.push_back(foo);
    Carta = Cartas("Charizard", 1, ataque, 173, "Fogo", 186);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Chama", 20);
    ataque.push_back(foo);
    Carta = Cartas("Vulpix", 1, ataque, 109, "Fogo", 116);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Cauda de Chamas", 90);
    ataque.push_back(foo);
    Carta = Cartas("Ninetales", 1, ataque, 190, "Fogo", 177);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Combustao", 30);
    ataque.push_back(foo);
    Carta = Cartas("Growlithe", 1, ataque, 93, "Fogo", 146);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Crina de Fogo", 130);
    ataque.push_back(foo);
    Carta = Cartas("Arcanine", 1, ataque, 166, "Fogo", 207);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Carvao Vivo", 15);
    ataque.push_back(foo);
    Carta = Cartas("Ponyta", 1, ataque, 127, "Fogo", 137);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Anel de Fogo", 50);
    ataque.push_back(foo);
    Carta = Cartas("Rapidash", 1, ataque, 162, "Fogo", 163);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Lanca Chamas", 80);
    ataque.push_back(foo);
    Carta = Cartas("Magmar", 1, ataque, 154, "Fogo", 163);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Inflamar", 120);
    ataque.push_back(foo);
    Carta = Cartas("Flareon", 1, ataque, 179, "Fogo", 163);
    CartasFogo.push_back(Carta);
    
    ataque.clear();
    foo = make_pair("Chama Furacao", 180);
    ataque.push_back(foo);
    Carta = Cartas("Moltres", 1, ataque, 181, "Fogo", 207);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Cortina de Fumaca", 130);
    ataque.push_back(foo);
    Carta = Cartas("Cyndaquil", 1, ataque, 93, "Fogo", 118);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Superchamuscada", 60);
    ataque.push_back(foo);
    Carta = Cartas("Quilava", 1, ataque, 126, "Fogo", 151);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Chama Perdida", 120);
    ataque.push_back(foo);
    Carta = Cartas("Typhlosion", 1, ataque, 173, "Fogo", 186);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Fenix Ardente", 180);
    ataque.push_back(foo);
    Carta = Cartas("Ho-Oh", 1, ataque, 244, "Fogo", 214);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Bicada", 10);
    ataque.push_back(foo);
    Carta = Cartas("Torchic", 1, ataque, 87, "Fogo", 128);
    CartasFogo.push_back(Carta);
    
    ataque.clear();
    foo = make_pair("Bico de Calor", 40);
    ataque.push_back(foo);
    Carta = Cartas("Combusken", 1, ataque, 115, "Fogo", 155);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Incendio Max", 130);
    ataque.push_back(foo);
    Carta = Cartas("Blaziken", 1, ataque, 141, "Fogo", 190);
    CartasFogo.push_back(Carta);

    ataque.clear();
    foo = make_pair("Incendio Incrivel", 270);
    ataque.push_back(foo);
    Carta = Cartas("Reshiram", 1, ataque, 211, "Fogo", 205);
    CartasFogo.push_back(Carta);
    
    ataque.clear();
    Baralho1.setCartas(CartasFogo);
    BaralhosDisponiveis.push_back(Baralho1);

    // string nome_pokemon;
    // int defesa;
    // string tipo;
    // int hp;

    if (nome == "Bot")
    {
        // cout << "aqui foi" << endl;
        vector<pair<string, int>> ataque;
        pair<string, int> foo;

        ataque.clear();
        foo = make_pair("Mordida", 30);
        ataque.push_back(foo);
        Cartas aux = Cartas("Deino", 1, ataque, 93, "Dark", 141);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Presa Sombria", 65);
        ataque.push_back(foo);
        aux = Cartas("Zweilous", 1, ataque, 135, "Dark", 176);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Presas do Breu", 130);
        ataque.push_back(foo);
        aux = Cartas("Hydreigon", 1, ataque, 188, "Dark", 211);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Chuva Borrifante", 10);
        ataque.push_back(foo);
        aux = Cartas("Dratini", 1, ataque, 91, "Dragao", 121);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Ataque da Cauda", 60);
        ataque.push_back(foo);
        aux = Cartas("Dragonair", 1, ataque, 135, "Dragao", 156);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Gigaimpacto", 180);
        ataque.push_back(foo);
        aux = Cartas("Dragonite", 1, ataque, 198, "Dragao", 209);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Soco Absoluto", 30);
        ataque.push_back(foo);
        aux = Cartas("Riolu", 1, ataque, 78, "Lutador", 120);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Chute Ciclone", 130);
        ataque.push_back(foo);
        aux = Cartas("Lucario", 1, ataque, 144, "Planta", 172);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Tiro Psiquico", 30);
        ataque.push_back(foo);
        aux = Cartas("Mew", 1, ataque, 115, "Psiquico", 157);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Transferencia Intensa", 160);
        ataque.push_back(foo);
        aux = Cartas("Mewtwo", 1, ataque, 188, "Psiquico", 211);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Pulso Sonolente", 10);
        ataque.push_back(foo);
        aux = Cartas("Gastly", 1, ataque, 67, "Fantasma", 102);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Pesadelo", 20);
        ataque.push_back(foo);
        aux = Cartas("Haunter", 1, ataque, 107, "Fantasma", 128);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Terror e Panico", 100);
        ataque.push_back(foo);
        aux = Cartas("Gengar", 1, ataque, 149, "Fantasma", 155);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Surra de Cauda", 25);
        ataque.push_back(foo);
        aux = Cartas("Eevee", 1, ataque, 114, "Normal", 146);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Miragem Lunar", 80);
        ataque.push_back(foo);
        aux = Cartas("Umbreon", 1, ataque, 240, "Dark", 216);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Relampago", 90);
        ataque.push_back(foo);
        aux = Cartas("Jolteon", 1, ataque, 182, "Eletrico", 163);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Vento da Fada", 110);
        ataque.push_back(foo);
        aux = Cartas("Sylveon", 1, ataque, 205, "Fada", 216);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Trovao", 80);
        ataque.push_back(foo);
        aux = Cartas("Pikachu", 1, ataque, 96, "Eletrico", 111);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Relampago", 120);
        ataque.push_back(foo);
        aux = Cartas("Raichu", 1, ataque, 151, "Eletrico", 155);
        cartasExistentes.push_back(aux);

        ataque.clear();
        foo = make_pair("Semente Sanguessuga", 10);
        ataque.push_back(foo);
        aux = Cartas("Sunkern", 1, ataque, 55, "Planta", 102);
        cartasExistentes.push_back(aux);    

        Baralho BaralhoBot = Baralho();
        BaralhoBot.setNome("Baralho do Bot");
        BaralhoBot.setCartas(cartasExistentes);
        (this->baralhos).push_back(BaralhoBot);
        // cout << "foi certinho pro bot, finalizando..." << endl;
        // break;
    }
    else if (nome != "Bot")
    {
        string nomeBaralho;
        int comando;
        int adicionadas = 0;
        do
        {
            cout << "Digite '1' para selecionar um dos baralhos existentes" << endl;
            cout << "Digite '2' para criar um novo baralho do zero" << endl
                 << endl;

            cin >> comando;
            cout << endl;

            if (comando == 1)
            {
                int comandoAux;

                cout << "Baralhos disponiveis:" << endl;

                for (int i = 0, ie = BaralhosDisponiveis.size(); i < ie; i++)
                {
                    cout << endl;
                    cout << "   < " << i << " > " << BaralhosDisponiveis.at(i).getNome() << endl;
                }

                do
                {
                    cout << endl;
                    cout << "Digite '1' se deseja visualizar as cartas de algum dos baralhos" << endl;
                    cout << "Digite '2' se deseja escolher algum dos baralhos" << endl << endl;
                    cin >> comandoAux;

                    unsigned int novoComando;

                    if (comandoAux == 1)
                    {
                        do
                        {
                            cout << endl;
                            cout << "Digite o numero do baralho que deseja visualizar as cartas:" << endl << endl;
                            cin >> novoComando;

                            if (novoComando >= BaralhosDisponiveis.size() || novoComando < 0)
                            {
                                cout << endl;
                                cout << "Nao existe um baralho com este numero" << endl;
                            }
                            else
                            {
                                cout << endl;
                                cout << " < " << novoComando << " > " << BaralhosDisponiveis.at(novoComando).getNome() << endl
                                     << endl;
                                //for (int i = 0, ie = BaralhosDisponiveis.at(novoComando).getSize(); i < ie; i++)
                                //{
                                    BaralhosDisponiveis.at(novoComando).mostraNomesCartas();
                                //}

                                cout << endl;
                                string buffer;
                                cout << "Digite qualquer tecla para voltar:" << endl
                                     << endl;
                                cin >> buffer;
                                comandoAux = 99;
                            }
                        } while (novoComando >= BaralhosDisponiveis.size() || novoComando < 0);
                    }
                    if (comandoAux == 2)
                    {
                        cout << endl;
                        cout << "Digite o numero do baralho que deseja selecionar:" << endl
                             << endl;
                        unsigned int numeroBaralho;
                        cin >> numeroBaralho;
                        if (numeroBaralho >= BaralhosDisponiveis.size() || numeroBaralho < 0)
                        {
                            cout << endl;
                            cout << "Nao existe um baralho com este numero" << endl;
                        }
                        else
                        {
                            cout << endl;
                            (this->baralhos).push_back(BaralhosDisponiveis.at(numeroBaralho));
                            cout << (this->baralhos).at(0).getNome() << " selecionado" << endl;
                            //comandoAux = 99;
                            return;
                        }
                    }
                } while (comandoAux != 1 && comandoAux != 2);
            }
            if (comando == 2)
            {
                //cout << endl;
                cout << "Digite o nome do baralho:" << endl
                     << endl;
                cin >> nomeBaralho;
                cartasExistentes.clear();

                Baralho novo = Baralho();
                novo.setNome(nomeBaralho);
                //int adicionadas = 0;
                while (adicionadas < 20)
                {
                    vector<pair<string, int>> ataque;
                    pair<string, int> foo;
                    ataque.clear();

                    cout << endl;
                    cout << "Digite o nome do pokemon da carta [   " << adicionadas << "   ] :" << endl;
                    string nomeCarta;
                    cin >> nomeCarta;
                    cout << "Digite o nome do ataque do pokemon da carta [   " << adicionadas << "   ] :" << endl;
                    string nomeAtaque;
                    cin >> nomeAtaque;
                    cout << "Digite o valor de dano do ataque do pokemon da carta [   " << adicionadas << "   ] :" << endl;
                    int danoAtaque;
                    cin >> danoAtaque;
                    foo = make_pair(nomeAtaque, danoAtaque);
                    ataque.push_back(foo);
                    cout << "Digite o valor da defesa do pokemon da carta [   " << adicionadas << "   ] :" << endl;
                    int valorDefesa;
                    cin >> valorDefesa;
                    cout << "Digite o tipo do pokemon da carta [   " << adicionadas << "   ] :" << endl;
                    string tipoPokemon;
                    cin >> tipoPokemon;
                    cout << "Digite o valor da vida do pokemon da carta [   " << adicionadas << "   ] :" << endl;
                    int valorVida;
                    cin >> valorVida;
                    Cartas cartaNova = Cartas(nomeCarta, 1, ataque, valorDefesa, tipoPokemon, valorVida);
                    cartasExistentes.push_back(cartaNova);
                    cout << endl << "Carta " << cartasExistentes.at(adicionadas).getNome() << " salva com sucesso" << endl;
                    adicionadas++;
                }
                novo.setCartas(cartasExistentes);
                (this->baralhos).push_back(novo);
            }
        } while (comando != 1 && comando != 2);
    }

};

int Usuario::getVitorias()
{
    return this->vitorias;
}

int Usuario::getDerrotas()
{
    return this->derrotas;
}
void Usuario::setVitorias(int vitorias)
{
    this->vitorias++;
}
void Usuario::setDerrotas(int derrotas)
{
    this->derrotas++;
}
std::string Usuario::getNome()
{
    return this->nome;
}
std::vector<Baralho> Usuario::getBaralhos()
{
    return this->baralhos;
}
void Usuario::setBaralhos(Baralho baralho)
{
    this->baralhos.push_back(baralho);
}
std::string Usuario::toString()
{
    std::string retorno = "Nome: " + this->nome + "\n";
    retorno += "Vitorias: " + std::to_string(this->vitorias) + "\n";
    retorno += "Derrotas: " + std::to_string(this->derrotas) + "\n";
    retorno += "Baralhos:";
    for (unsigned int i = 0; i < ((this->baralhos).size()); i++)
    {
        retorno += (((this->baralhos[i]).getNome()) + "\n");
    }
    return retorno;
}

std::string Usuario::getNomeBaralho(int num)
{
    return ((this->baralhos).at(num).getNome());
};

void Usuario::setNome(string nomeP)
{
    this->nome = nomeP;
}

#endif