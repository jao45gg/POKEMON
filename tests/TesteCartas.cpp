#include "../third_party/doctest.h"
#include "../include/Cartas.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Esse arquivo de testes tem a funcao de determinar o estado
 * dos metodos de Cartas.hpp e Cartas.cpp a partir de testes unitarios.
 * As variaveis sao
 * 
 */
TEST_CASE("Inicializador de objetos exemplo"){
    
    pair<string, int> ataque1, ataque2;
    ataque1.first = "NOME1";
    ataque2.first = "NOME2";
    ataque1.second = 1;
    ataque2.second = 2;

    vector<pair<string, int>> ataques;
    ataques.push_back(ataque1);
    ataques.push_back(ataque2);

    Cartas cartaTeste1("TESTE", 2, ataques, 3,
                         "FOGO", 10);

    Cartas cartaTeste2("energia");

    SUBCASE("Teste da funcao o.getNome()"){
        CHECK(cartaTeste1.getNome() == "TESTE");
        CHECK(cartaTeste2.getNome() == "");
    }
    SUBCASE("Teste da funcao o.getAtaques()"){
        vector<pair<string, int>>* ataquesTeste1,* ataquesTeste2;
        ataquesTeste1 = &cartaTeste1.getAtaques();
        ataquesTeste2 = &cartaTeste2.getAtaques();

        CHECK(ataquesTeste1 != nullptr);
        CHECK(ataquesTeste2 == nullptr);
    }
    SUBCASE("Teste da funcao o.getAtaque()"){
        pair<string, int> ataqueTeste1, ataqueTeste2;
        ataqueTeste1 = cartaTeste1.getAtaque("NOME1");
        ataqueTeste2 = cartaTeste1.getAtaque("NOME2");

        CHECK(ataqueTeste1.first == "NOME1");
        CHECK(ataqueTeste1.second == 1);
        CHECK(ataqueTeste2.first == "NOME2");
        CHECK(ataqueTeste2.second == 2);
    }
    SUBCASE("Teste da funcao o.getDefesa()"){
        CHECK(cartaTeste1.getDefesa() == 3);
    }
    SUBCASE("Teste da funcao o.getTipo()"){
        CHECK(cartaTeste1.getTipo() == "FOGO");
        CHECK(cartaTeste2.getTipo() == "energia"); 
    }
    SUBCASE("Teste da funcao o.getHp()"){
        CHECK(cartaTeste1.getHp() == 10);
    }
    SUBCASE("Teste da funcao o.ligarEnergia() e o.getEnergia()"){
        cartaTeste1.ligarEnergia(&cartaTeste2, &cartaTeste1);
        CHECK(cartaTeste1.getEnergia());
    }
    SUBCASE("Teste da funcao o.sofreDano()"){
        cartaTeste1.sofrerDano(3);
        CHECK(cartaTeste1.getHp() == 7);
    }

}