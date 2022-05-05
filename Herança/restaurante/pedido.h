#ifndef PEDIDO_H
#define PEDIDO_H

#include <vector>
#include <iostream>
#include "item.h"

class Pedido;

std::ostream& operator<< (std::ostream&, const Pedido&);

class Pedido {
    friend std::ostream& operator<< (std::ostream&, const Pedido&);
    public:
        Pedido();
        void Adicionar(const Item& item, unsigned quant=1);
        const std::vector<Item>&& ItensRhv();
        const std::vector<Item>& Itens();
    protected:
        std::vector<Item> vetItens;
        std::vector<unsigned> vetQuantidades;
};

#endif
