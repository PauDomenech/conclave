#ifndef BARALLA_H
#define BARALLA_H
#include "Carta.h"


class Baralla
{
    public:
        Baralla();
        Baralla(const Baralla &t);
        Baralla(int llavor);
        Baralla &operator=(const Baralla& t);
        virtual ~Baralla();
        void mostrar();
        void barrejar();
        void afegir(Carta c);
        unsigned aleatori(int n);
        void intercanvi(Carta& a, Carta& b);
        void buidar(int n);
        Carta carta(int i);
        void retirar_cartes(int n);
        Carta retorn_carta(int n);
        int retorna_max();
        void retirar_cartes_pila(int n);

        bool buida() const;

        void seguent();


    protected:

        unsigned x;
        int a_n;
        int a_max;
        Carta *t;

        void copia(const Baralla& t);
        void allibera();
        void reserva();
        void expandeix();

    private:

};

#endif // BARALLA_H
