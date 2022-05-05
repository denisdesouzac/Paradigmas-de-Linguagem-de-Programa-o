#include "sobremesa.h"

using namespace std;


Sobremesa::Sobremesa(const std::string& descricao, float preco)
    : Item(descricao, preco) {
}

ostream& operator<< (ostream& saida, const Sobremesa& s) {
    return saida << s.Descricao() << " R$ " << s.Preco() << endl;
}
