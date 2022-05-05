// Este programa ilustra uma implementação em que não há verificação de erros.

#include <iostream>

using namespace std;

long Fibonacci(int n) {
    // Resultados esperados: 1->1; 2->1; 3->2; etc.
    // Note que o código é curto e vai direto ao ponto. Na manutenção, o programador
    // se preocupa apenas com a solução do problema, porém os resultados nem sempre
    // são válidos.
    long penultimo = 0;
    long ultimo = 1;
    long termo = 1;
    while (n > 1) {
        termo = ultimo + penultimo;
        penultimo = ultimo;
        ultimo = termo;
        --n;
    }
    return termo;
}

int main() {
    for (int n = 0; n < 94; ++n) {
    // Ao usar uma função sem verificação de erros, nem sempre é possível saber
    // se o resultado pode ser realmente calculado.
        cout << "Fibonacci(" << n << ") = " << Fibonacci(n) << endl;
    }
    return 0;
}

