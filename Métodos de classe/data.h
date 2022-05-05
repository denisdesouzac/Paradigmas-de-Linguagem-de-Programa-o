#ifndef DATA_H
#define DATA_H

#include <string>

class Instante {
    public:
        Instante (unsigned dia, unsigned mes, unsigned ano);
        Instante (unsigned dia, unsigned mes, unsigned ano,
                  unsigned hora, unsigned minuto, unsigned segundo);
        Instante (std::string str);

        // Verifica se um ano é bissexto. Método da classe.
        static bool Bissexto(unsigned ano);

    protected:
        // Retorna a quantidade de anos bissextos até dado ano. Método de classe.
        static unsigned Bissextos(unsigned ano);
        // Dias passados até a data informada.
        static unsigned DiasAte(unsigned dia, unsigned mes, unsigned ano);

        // Verifica a quantidade de dias em um mês de um ano. Método da classe.
        static unsigned DiasEm(unsigned mes, unsigned ano);
        unsigned long mSegundos; // segundos desde 1/1/1970 0:0:0
};

#endif
