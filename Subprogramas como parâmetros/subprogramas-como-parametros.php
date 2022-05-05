<?php
# Em PHP, uma variável contendo uma string pode ser usada para ativar
# um subprograma. Para passar um subprograma como parâmetro, basta passar
# uma string com o nome do subprograma.

# Operações de comparação entre funcionários.
function MenorNome($func1, $func2) {
    return $func1['nome'] < $func2['nome'];
}
function MenorSalario($func1, $func2) {
    return $func1['salario'] < $func2['salario'];
}

function Ordenar(&$vetor, $criterio) {
    # Insertionsort com critério de ordenação.
    # $criterio é uma função que retorna verdadeiro se o primeiro parâmetro
    #     é menor que o segundo.
    $tamanho = count($vetor);
    for ($i = 1; $i < $tamanho; ++$i) {
        $aux = $vetor[$i]; // numero que sera inserido na parte ordenada
        $j = $i-1;
        while ($j >= 0 and $criterio($aux, $vetor[$j])) {
            $vetor[$j+1] = $vetor[$j];
            --$j;
        }
        $vetor[$j+1] = $aux;
    }
}

function EscreverFuncionario($func) {
    echo "(${func['nome']}, ${func['salario']})";
}

function EscreverFuncionarios($vetor) {
    echo "[";
    $ultimo = count($vetor)-1;
    for ($i = 0; $i < $ultimo; ++$i) {
        EscreverFuncionario($vetor[$i]);
        echo ", ";
    }
    if ($ultimo >= 0)
        EscreverFuncionario($vetor[$ultimo]);
    echo "]";
}

# Criar 3 funcionários
# Em PHP não precisamos de registros porque temos vetores associativos.
$funcionario1 = array('nome' => 'Joao da Silva', 'salario' => 2012.0);
$funcionario2 = array('nome' => 'Jose Santos', 'salario' => 1930.0);
$funcionario3 = array('nome' => 'Carlos Oliveira', 'salario' => 2420.0);

# Criar um vetor de funcionários
$funcionarios = array($funcionario1, $funcionario2, $funcionario3);

Ordenar($funcionarios, 'MenorSalario');
echo "Ordenado por salario:\n";
EscreverFuncionarios($funcionarios);
Ordenar($funcionarios, 'MenorNome');
echo "\nOrdenado por nome:\n";
EscreverFuncionarios($funcionarios);
?>

