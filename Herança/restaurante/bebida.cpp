#include <iomanip>
#include <sstream>
#include "bebida.h"

using namespace std;

std::ostream& operator<< (std::ostream& saida, const Bebida& bebida);

Bebida::Bebida(const std::string& descricao, float preco, int mVolume)
    : Item(descricao, preco), mVolume(mVolume) {
}

string Bebida::ComoString() const {
    cout << "Bebida::ComoString()" <<endl;
    ostringstream oss;
    oss << setw(4) << mVolume << " ml";
    return Item::ComoString() + oss.str();;
}
