#include "../third_party/doctest.h"
#include "../include/Usuario.hpp"
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Esse arquivo tem o objetivo de testar
 * os metodos da classe Usuario
 * 
 */
TEST_CASE("Inicializacao de um Usuario nulo"){
    Usuario *ptr = new Usuario();
    SUBCASE("Teste das funcoes get e set vitorias"){
        CHECK(ptr->getVitorias() == 0);
        ptr->setVitorias(ptr->getVitorias());
        CHECK(ptr->getVitorias() == 1);
    }
    SUBCASE("Teste das funcoes get e set derrotas"){
        CHECK(ptr->getDerrotas() == 0);
        ptr->setDerrotas(ptr->getDerrotas());
        CHECK(ptr->getDerrotas() == 1);
    }
    SUBCASE("Teste da funcao getNome()"){
        CHECK(ptr->getNome() == "Jogador");
    }
    SUBCASE("Teste das funcoes get e setBaralhos"){
        Baralho *aux = new Baralho();
        aux->setNome("TESTE");

        ptr->setBaralhos(*aux);
        vector<Baralho> retorno = ptr->getBaralhos();

        Baralho *aux2 = new Baralho();
        aux2 = &retorno[0];

        CHECK(aux->getNome() == aux2->getNome());
        delete aux, aux2, ptr;
    }
    SUBCASE("Teste da funcao ToString()"){
        Usuario *novo = new Usuario;
        novo->setVitorias(novo->getVitorias());
        novo->setVitorias(novo->getVitorias());
        novo->setDerrotas(novo->getDerrotas());
        
        Baralho *teste = new Baralho();
        teste->setNome("TESTE");
        novo->setBaralhos(*teste);

        CHECK(novo->toString() == "Nome: Jogador\nVitorias: 2\nDerrotas: 1\nBaralhos:TESTE\n");
    }
}