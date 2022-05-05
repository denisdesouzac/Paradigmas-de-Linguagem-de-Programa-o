#ifndef BEBIDA_H
#define BEBIDA_H

#include <iostream>
#include "item.h"

class Bebida;

std::ostream& operator<< (std::ostream& saida, const Bebida& bebida);

class Bebida : public Item {
    friend std::ostream& operator<< (std::ostream& saida, const Bebida& bebida);
    public:
        Bebida& operator= (const Bebida& bebida);
        Bebida(const std::string& descricao, float preco, int mVolume);
        std::string ComoString() const override;
    protected:
        int mVolume; // mililitros
};

#endif
