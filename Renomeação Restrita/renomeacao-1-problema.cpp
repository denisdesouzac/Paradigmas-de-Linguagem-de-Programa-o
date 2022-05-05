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
        // Aqui vemos como a identificação das informações pode ficar longa e
        // tediosa para escrever.
        cin >> vetFuncionarios[i].nome
            >> vetFuncionarios[i].idade
            >> vetFuncionarios[i].genero
            >> vetFuncionarios[i].salario
            >> vetFuncionarios[i].nroFilhos;
        somaSalarios += vetFuncionarios[i].salario;
        somaFilhos += vetFuncionarios[i].nroFilhos;
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

