#ifndef PRATO_H
#define PRATO_H

#include "item.h"

class Prato;

std::ostream& operator<< (std::ostream& saida, const Prato& prato);

class Prato : public Item {
    friend std::ostream& operator<< (std::ostream& saida, const Prato& prato);
    public:
        enum Tamanho { PEQUENO, MEDIO, GRANDE };
        Prato(const std::string& descricao, float preco);
        Prato(const std::string& descricao, float preco, Tamanho tamanho);
        ~Prato();
        std::string ComoString();
    protected:
        Tamanho* ptTamanho;
};

#endif
