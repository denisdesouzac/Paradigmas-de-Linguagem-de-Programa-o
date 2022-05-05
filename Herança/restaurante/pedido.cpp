#include <iomanip>
#include "pedido.h"

using namespace std;

Pedido::Pedido() {
}

// Adiciona uma quant de item ao pedido. O valor padrão de "quant" é 1.
void Pedido::Adicionar(const Item& item, unsigned quant) {
    if (quant > 99) throw string("Quantidade inválida para o pedido");
    vetItens.push_back(item);
    vetQuantidades.push_back(quant);
}

ostream& operator<< (ostream& saida, const Pedido& pedido) {
    float total = 0;
    long unsigned nroItens = pedido.vetItens.size();
    for (long unsigned i = 0; i < nroItens; ++i) {
        const unsigned& quantidade = pedido.vetQuantidades.at(i);
        const Item& item = pedido.vetItens.at(i);
        saida << setw(2) << quantidade << ' '
              << item.ComoString() << endl;
        total += float(quantidade) * item.Preco();
    }
    return saida << string(56, ' ') << "Total: R$ " << setw(7) << total << endl;
}
