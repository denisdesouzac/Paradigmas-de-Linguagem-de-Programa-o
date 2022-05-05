// Este subprograma busca um valor numa matriz.
// Entradas: matriz, nLin, nCol e valor.
// Saídas: A linha e coluna em que o elemento foi encontrado são armazenadas
//         respectivamente na variável apontada por ptLin e ptCol. Caso o valor
//         não esteja na matriz, os valores para a linha e a coluna são inválidos.
//         Foi usado passagem de ponteiros ao invés de passagem por referência
//         para aumentar a legilidade, destacando as posições de resposta na
//         ativação do subprograma.
void Buscar(int** matriz, int nLin, int nCol, int valor, int* ptLin, int* ptCol) {
    for (*ptLin = 0; *ptLin < nLin; *ptLin += 1)
        for (*ptCol = 0; *ptCol < nCol; *ptCol += 1)
            if (matriz[*ptLin][*ptCol] == valor)
                return;
}

// Esta versão também usa os ponteiros para retornar os valores do resultado,
// mas faz uso de apelidos para simplificar o código.
void Buscar(int** matriz, int nLin, int nCol, int valor, int* ptLin, int* ptCol) {
    int& lin = *ptLin; // parte linha do resultado
    int& col = *ptCol; // parte coluna do resultado
    for (lin = 0; lin < nLin; ++lin)
        for (col = 0; col < nCol; ++col)
            if (matriz[lin][col] == valor)
                return;
}

