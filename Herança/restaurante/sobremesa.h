#ifndef SOBREMESA_H
#define SOBREMESA_H

#include <iostream>
#include "item.h"

class Sobremesa;

std::ostream& operator<< (std::ostream& saida, const Sobremesa& sobremesa);

class Sobremesa : public Item {
    friend std::ostream& operator<< (std::ostream& saida, const Sobremesa& sobremesa);
    public:
        Sobremesa(const std::string& descricao, float preco);
};

#endif
