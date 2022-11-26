#ifndef A61B27DE_D312_4C7D_8ADC_7BC7800F8AEB
#define A61B27DE_D312_4C7D_8ADC_7BC7800F8AEB
#include <string>
#include <vector>

class Usuario
{
public:
    Usuario();
    Usuario(std::string nome, int vitorias, int derrotas, std::vector<std::string> baralhos);
    ~Usuario();

    std::string getNome();
    int getVitorias();
    int getDerrotas();
    std::vector<std::string> getBaralhos();
    void setNome(std::string nome);
    void setVitorias(int vitorias);
    void setDerrotas(int derrotas);
    void setBaralhos(std::vector<std::string> baralhos);
    void addVitoria();
    void addDerrota();
    void addBaralho(std::string baralho);
    std::string toString();
   private:
    std::string nome;
    int vitorias;
    int derrotas;
    std::vector<std::string> baralhos;
};
     
#endif 
