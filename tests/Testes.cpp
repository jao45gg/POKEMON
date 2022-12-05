#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"

//Arquivos testados:
#include "../include/Cartas.hpp"
#include "../include/baralho.hpp"
#include "../include/Usuario.hpp"
#include "../include/Partida.hpp"


//Biblioteca padrao:
#include <iostream>
#include <vector>
#include <string>

using namespace std;

TEST_CASE("Testando Cartas:"){
    SUBCASE("Construtor vazio:"){
        Cartas *carta = new Cartas();
        CHECK(carta->getNome() == "");
        CHECK(carta->getDefesa() == 0);
        CHECK(carta->getHp()==0);
    }
    SUBCASE("Construtor parametrizado:"){
        pair<string, int> ataque = {"ataque",4};
        vector < pair<string, int>> ataques;
        ataques.push_back(ataque);
        Cartas *carta = new Cartas("teste", 1, ataques, 3, "tipo", 4);
        CHECK(carta->getNome() == "teste");
        CHECK(carta->getDefesa() == 3);
        CHECK(carta->getHp()==4);
        CHECK(carta->getAtaque(0) == pair<string, int>{"ataque", 4});
        CHECK(carta->getTipo() == "tipo");
        carta->sofrerDano(3);
        CHECK(carta->getHp() == 1);
        carta->destroiCarta();
        CHECK(carta->getNome() == "");
        CHECK(carta->getDefesa() == 0);
        CHECK(carta->getHp()==0);
    }
}

TEST_CASE("Testando Baralho:"){
    SUBCASE("Construtor vazio:"){
        Baralho *baralho = new Baralho();

        baralho->setNome("teste");
        CHECK(baralho->getNome() == "teste");
        CHECK(baralho->getSize() == 0);
    }
}

TEST_CASE("Testando Usuario:"){
    SUBCASE("Construtor vazio:"){
        Usuario *usuario = new Usuario();

        CHECK(usuario->getNome() == "Jogador");

        usuario->setNome("teste");
        CHECK(usuario->getNome() == "teste");

        CHECK(usuario->getVitorias() == 0);
        usuario->setVitorias(1);
        CHECK(usuario->getVitorias() == 1);

        CHECK(usuario->getDerrotas() == 0);
        usuario->setDerrotas(0);
        CHECK(usuario->getDerrotas() == 1);
    }
    SUBCASE("Construtor parametrizado"){
        Usuario *usuario = new Usuario("Teste");

        CHECK(usuario->getNome() == "Teste");
        CHECK(usuario->getNomeBaralho(0) == "Baralho de Fogo");

    }
}