#include <sstream>
#include <iomanip>
#include "item.h"

using namespace std;

std::ostream& operator<< (std::ostream& saida, const Item& item) {
    return saida << "Operador de escrita para Item";
}

Item::Item(const std::string& descricao, float preco)
    : descricao(descricao), preco(preco) {
}

std::string Item::Descricao() const {
    return descricao;
}

float Item::Preco() const {
    return preco;
}

// Transforma um item numa string formatada. Virtual.
string Item::ComoString() const {
    ostringstream oss;
    oss << setw(60) << left << descricao.substr(0, 60)
        << "R$ " << right << setw(7) << fixed << setprecision(2) << preco;
    return oss.str();
}
