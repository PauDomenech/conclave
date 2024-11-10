#ifndef SEGUIDORS_H
#define SEGUIDORS_H
#include "Carta.h"

class Seguidors
{
    public:
        Seguidors();
        Seguidors(Seguidors& o);
        ~Seguidors();
        Seguidors & operator=(const Seguidors &s);
        void mostrar();
        void introduir_influencia(int m, int valor);
        bool igual_magia(Carta c, int m);
        int posicio_magia(char m);
        int retorna_influencia(int posicio_magia);
        void afagir_carta(Carta c);
        void introduir_cartes(Seguidors s[], char magia, int n);
        void ordenar_cartes();
        void mostrar_cartes();

    protected:
        static const char a_magia[];
        int valor[6] = {0,0,0,0,0,0};
        Carta cartes[45];
        int num_cartes = 0;


    private:
};

#endif // SEGUIDORS_H
