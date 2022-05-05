// Este programa é um exemplo de passagem de subprogramas como parâmetros. O recurso
// usado aqui é o uso de ponteiro para subprograma. Existem duas outras formas de se
// fazer isso em C++, com maior legibilidade, porém essas outras formas dependem de
// bibliotecas ou orientação a objetos.

// Este programa também contém exemplo de sobrecarga de operador e subprograma genérico.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Funcionario {
    string nome;
    float salario;
};

// Sobrecarga do operador de escrita para escrever funcionarios.
ostream& operator<< (ostream& saida, const Funcionario& func) {
    return saida << "[" << func.nome << ", " << func.salario << "]";
}

// Comparação de funcionarios pelo nome
bool MenorNome(const Funcionario& f1, const Funcionario& f2) {
    return f1.nome < f2.nome;
}

// Comparação de funcionarios pelo salario
bool MenorSalario(const Funcionario& f1, const Funcionario& f2) {
    return f1.salario < f2.salario;
}

// Ordenação de vetor de qualquer coisa (subprograma genérico) que recebe um critério
// de ordenação que é uma função. O parâmetro "Menor" é uma função que recebe dois
// parâmetros do tipo "Tipo" por referência constante e retorna um bool.
template <typename Tipo>
void Ordenar(vector<Tipo>& vetor, bool (*Menor)(const Tipo&, const Tipo&)) {
    unsigned tamanho = unsigned(vetor.size());
    for (unsigned i = 1; i < tamanho; ++i) {
        Tipo aux = vetor[i]; // numero que sera inserido na parte ordenada
        int j = i-1;
        while (j >= 0 and Menor(aux, vetor[j])) {
            vetor[j+1] = vetor[j];
            --j;
        }
        vetor[j+1] = aux;
    }
}

int main() {
    vector<Funcionario> funcionarios = {
        {"Joao da Silva", 2012}, {"Jose Santos", 1930}, {"Carlos Oliveira", 2420}};

    Ordenar(funcionarios, MenorSalario);
    cout << "Funcionarios ordenados por salario:\n";
    for (Funcionario& func: funcionarios)
        cout << func << ' ';
    cout << endl;

    Ordenar(funcionarios, MenorNome);
    cout << "Funcionarios ordenados por nome:\n";
    for (Funcionario& func: funcionarios)
        cout << func << ' ';
    cout << endl;

    return 0;
}

