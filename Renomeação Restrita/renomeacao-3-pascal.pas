{ Este programa mostra o uso da estrutura "with ... do" que permite omitir a
  parte invariante dos identificadores. }

Program EstatisticasFuncionarios;

const CAP_FUNCIONARIOS = 100;

type
    Funcionario = record
        nome: String;
        idade: Integer;
        genero: Char;
        salario: Real;
        nroFilhos: Integer;
    end;

var 
    qtdFuncionarios: Integer;
    vetFuncionarios: array [1..CAP_FUNCIONARIOS] of Funcionario;
    somaSalarios: Real;
    somaFilhos: Integer;
    i: Integer;
    mediaSalarios: Real;
    mediaNroFilhos: Real;

begin
    readLn(qtdFuncionarios);
    somaSalarios := 0;
    somaFilhos := 0;
    for i := 1 to qtdFuncionarios do
        with vetFuncionarios[i] do
            begin
                readLn(nome);
                readLn(idade);
                readLn(genero, salario, nroFilhos);
                somaSalarios := somaSalarios + salario;
                somaFilhos := somaFilhos + nroFilhos;
            end;
    mediaSalarios := somaSalarios / qtdFuncionarios;
    mediaNroFilhos := somaFilhos / qtdFuncionarios;

    for i := 1 to qtdFuncionarios do
        with vetFuncionarios[i] do
            if (salario < mediaSalarios) and (Real(nroFilhos) > mediaNroFilhos)
                then writeln(nome);
end.

