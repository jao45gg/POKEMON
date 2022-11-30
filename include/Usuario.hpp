#ifndef _USUARIO_HPP
#define _USUARIO_HPP
#include <string>
#include <vector>
#include <Baralho.hpp>

class Usuario
{
public:

    Usuario();
    Usuario(std::string nome);
    ~Usuario();

    std::string getNome();
    int getVitorias();
    int getDerrotas();
    std::vector<Baralho> getBaralhos();
    void setVitorias(int vitorias);
    void setDerrotas(int derrotas);
    void setBaralhos(Baralho baralhos);
    std::string toString();

private:

    std::string nome;
    int vitorias;
    int derrotas;
    std::vector<Baralho> baralhos;
};

#endif
