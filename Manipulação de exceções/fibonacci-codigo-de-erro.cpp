// Este programa ilustra o uso de códigos de erro para detectar situações incomuns
// de execução do código.
#include <iostream>

using namespace std;

enum CodErro { NENHUM, OVERFLOW, UNDERFLOW, PARAM_INVALIDO };

struct MetaInteiro {
    long valor;
    CodErro erro;
};

MetaInteiro Fibonacci(int n) {
    // Resultados esperados: 1->1; 2->1; 3->2; etc.
    // Nem sempre é possível calcular o n-ésimo termo da sequência de Fibonacci.
    // Esta função testa se o parâmetro n está dentro do intervalo válido e retorna
    // um código de erro e um valor resultado. Foi decidido não usar Objetos
    // porque os alunos de PLP ainda não têm experiência com OO.
    // Note que o cálculo da sequência de Fibonacci fica meio perdido no meio do
    // controle de erros, o que deixa o código maior e com manutenção mais complicada.
    // Foi decidido não reaproveitar o resultado da função para sinalizar condições
    // incomuns usando valores especiais (negativos neste caso) porque nem sempre
    // é possível usar valores especiais.
    MetaInteiro resultado;
    if (n < 1) { // erro porque os indices começam em 1
        resultado.erro = PARAM_INVALIDO;
    }
    else if (n > 92) {
        // erro porque o resultado seria muito grande para inteiro de 64 bits com sinal
        resultado.erro = OVERFLOW;
    }
    else { // situação normal
        resultado.erro = NENHUM;
        long penultimo = 0;
        long ultimo = 1;
        long termo = 1;
        while (n > 1) {
            termo = ultimo + penultimo;
            penultimo = ultimo;
            ultimo = termo;
            --n;
        }
        resultado.valor = termo;
    }
    return resultado;
}

int main() {
    int n = 1;
    MetaInteiro resultado = Fibonacci(n);
    // Ao usar a função Fibonacci, podemos testar se o resultado é válido ou não.
    while (resultado.erro == NENHUM) {
        cout << "Fibonacci(" << n << ") = " << resultado.valor << endl;
        ++n;
        resultado = Fibonacci(n);
    }
    return 0;
}

