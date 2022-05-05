#include <iostream>
#include "bebida.h"
#include "prato.h"
#include "sobremesa.h"
#include "pedido.h"

using namespace std;

int main() {
    Bebida b1("Guarana", 4.5f, 310);
    Prato p1("Salada com peito de frango", 30.42f, Prato::GRANDE);
    Sobremesa s1("Bombom Coco e Chocolate", 1.9f);
    Pedido pedido;
    pedido.Adicionar(b1);
    pedido.Adicionar(p1);
    pedido.Adicionar(s1, 2);
    cout << "O pedido é:\n" << pedido << endl;
    return 0;
}

