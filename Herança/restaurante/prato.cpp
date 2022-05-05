#include <sstream>
#include <iomanip>
#include "prato.h"

using namespace std;

std::ostream& operator<< (std::ostream& saida, const Prato& prato) {
    return saida << "Operador de escrita da classe Prato";
}

Prato::Prato(const std::string& descricao, float preco)
    : Item(descricao, preco), ptTamanho(nullptr) {
}

Prato::Prato(const std::string& descricao, float preco, Tamanho tamanho)
    : Item(descricao, preco), ptTamanho(new Tamanho) {
    *ptTamanho = tamanho;
}

Prato::~Prato() {
    delete ptTamanho;
}

string Prato::ComoString() {
    ostringstream oss;
    oss << setw(7);
    if (ptTamanho == nullptr)
        oss << "PADRÃO";
    else if (*ptTamanho == PEQUENO)
        oss << "PEQUENO";
    else if (*ptTamanho == MEDIO)
        oss << "MÉDIO";
    else
        oss << "GRANDE";
    return Item::ComoString() + oss.str();
}
