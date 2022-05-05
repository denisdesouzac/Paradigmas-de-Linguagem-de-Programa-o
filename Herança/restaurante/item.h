#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item;

std::ostream& operator<< (std::ostream& saida, const Item& item);

class Item {
    friend std::ostream& operator<< (std::ostream& saida, const Item& item);
    public:
        Item(const std::string& descricao, float preco);
        virtual std::string ComoString() const;
        std::string Descricao() const;
        float Preco() const;
    protected:
        std::string descricao;
        float preco;
};

#endif

