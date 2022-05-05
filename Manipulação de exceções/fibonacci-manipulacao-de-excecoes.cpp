// Este programa ilustra o uso de manipulação de exceções para detectar situações incomuns
// de execução do código.
#include <iostream>
#include <string>

using namespace std;

long Fibonacci(int n) {
    // Resultados esperados: 1->1; 2->1; 3->2; etc.
    // Nem sempre é possível calcular o n-ésimo termo da sequência de Fibonacci.
    // Esta função testa se o parâmetro n está dentro do intervalo válido e 
    // "levanta exceções" caso o resultado não possa ser corretamente calculado.
    // Note que o código fica menor que o uso de códigos de erro e mais focado
    // na solução do problema do que na sinalização de exceções.
    if (n < 1) { // erro porque os indices começam em 1
        throw string("Não existe posição menor que 1 na sequência de Fibonacci.");
    }
    if (n > 92) {
        // erro porque o resultado seria muito grande para inteiro de 64 bits com sinal
        throw string("Overflow aritmético no cálculo de Fibonacci.");
    }
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
    int n = 1;
    try {
        // Ao usar a função Fibonacci, podemos testar se o resultado é válido ou não.
        long resultado;
        while (true) { // repetir até dar erro:
            resultado = Fibonacci(n);
            cout << "Fibonacci(" << n << ") = " << resultado << endl;
            ++n;
        }
    }
    catch (string& msgExcecao) {
        cerr << "Não é possível calcular Fibonacci(" << n << "): " << msgExcecao << endl;
    }
    return 0;
}

