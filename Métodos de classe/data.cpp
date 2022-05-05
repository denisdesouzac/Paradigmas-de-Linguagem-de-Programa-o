#include "data.h"

using namespace std;

// Método da classe
bool Instante::Bissexto(unsigned ano) {
    return (ano % 400 == 0) or ((ano % 4 == 0) and (ano % 100 != 0));
}

// Quantidade de anos bissextos antes de dado ano. Método privado de classe.
unsigned Instante::Bissextos(unsigned ano) {
    return (ano-1969)/4;
}

// Quantidade de dias até dado dia. Método privado de classe.
unsigned Instante::DiasAte(unsigned dia, unsigned mes, unsigned ano) {
    // 365 dias para cada ano desde 1970 mais um dia para cada ano bissexto
    unsigned dias = 365*(ano-1970)+Bissextos(ano);
    // Somar os dias dos meses anteriores
    for (unsigned i = 1; i < mes; ++i)
        dias += DiasEm(i-1, ano);
    // Somar os dias deste mes
        dias += (dia-1);
    // Se o ano for bissexto e já passou de fevereiro, então mais um dia
    if (Bissexto(ano) and (mes > 2))
        dias += 1;
    return dias;
}

// Quantidade de dias passados nos meses anteriores a "mes" no "ano". Método de classe.
unsigned Instante::DiasEm(unsigned mes, unsigned ano) {
    // vetor local e de vinculação estática ao armazenamento:
    static unsigned dias[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (mes == 2 and Bissexto(ano))
        return 29;
    return dias[mes];
}

Instante::Instante (unsigned dia, unsigned mes, unsigned ano) {
    if (ano < 1970) throw string("Somente datas após 1970 são representáveis");
    if (mes < 1 or mes > 12) throw string("Mês inválido para criação de data");
    if (dia == 0 or dia > DiasEm(mes, ano)) throw string("Dia inválido para criação de data");
    mSegundos = static_cast<unsigned long>(DiasAte(dia, mes, ano)) * 86400ul;
}

Instante::Instante (unsigned dia, unsigned mes, unsigned ano,
                    unsigned hora, unsigned minuto, unsigned segundo) {
    mSegundos = static_cast<unsigned long>(DiasAte(dia, mes, ano)) * 86400ul;
    mSegundos += hora*3600 + minuto*60 + segundo;
}

Instante::Instante (std::string str) {
    string data = "\\d\\d/\\d\\d/\\d\\d";
    
}
