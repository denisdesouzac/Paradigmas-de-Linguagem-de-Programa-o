#include <iostream>
using namespace std;

typedef struct {
    char nome[90];
    int idade;
    char genero;
    float salario;
    int nroFilhos;
} Funcionario;

int main() {
    int qtdeFuncionarios;
    cin >> qtdeFuncionarios;
    Funcionario vetFuncionarios[qtdeFuncionarios];
    float somaSalarios = 0;
    int somaFilhos = 0;
    for (int i = 0; i < qtdeFuncionarios; ++i) {
        // Em C++ não é possível omitir a parte invariante dos nomes, mas podemos
        // criar um apelido para reduzir os nomes. A criação de apelidos é feita
        // usando declaração por referência, que cria um novo nome para uma
        // variável que já existe.
        Funcionario& func = vetFuncionarios[i];
        cin >> func.nome
            >> func.idade
            >> func.genero
            >> func.salario
            >> func.nroFilhos;
        somaSalarios += func.salario;
        somaFilhos += func.nroFilhos;
    }
    float mediaSalarios = somaSalarios / static_cast<float>(qtdeFuncionarios);
    float mediaNroFilhos = (float) somaFilhos / (float) qtdeFuncionarios;
    for (int i = 0; i < qtdeFuncionarios; ++i) {
        if ((vetFuncionarios[i].salario < mediaSalarios)
            and (static_cast<float>(vetFuncionarios[i].nroFilhos) > mediaNroFilhos))
            cout << vetFuncionarios[i].nome << endl;
    }
    return 0;
}

