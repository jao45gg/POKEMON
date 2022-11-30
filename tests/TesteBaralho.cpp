#include "../third_party/doctest.h"
#include "../include/baralho.hpp"
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Esse arquivo tem funcao de determinar o funcionamento da classe
 * Baralho
 * 
 */
TEST_CASE("Inicializador de objetos exemplo"){
    Baralho *baralhoNulo = new Baralho();
    SUBCASE("Teste das funcoes o.setNome() e o.getNome()"){
        CHECK(baralhoNulo->getNome() == "");
        baralhoNulo->setNome("TESTE");
        CHECK(baralhoNulo->getNome() == "TESTE");
    }
    SUBCASE("Teste das funcoes getCartasBaralho() e getSize()"){
        vector<Cartas> aux = {};
        Cartas c1("energia");
        aux.push_back(c1);
        aux = baralhoNulo->getCartasBaralho();
        CHECK(aux.size() == baralhoNulo->getSize());
    }
}