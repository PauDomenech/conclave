#ifndef PILACARTES_H
#define PILACARTES_H
#include "Baralla.h"
#include "Carta.h"

class PilaCartes
{
    public:
        PilaCartes(Baralla b);
        PilaCartes(PilaCartes &o);
        ~PilaCartes();
        void omplir(Baralla& b);
        void invertir();
        void mostrar();
        bool buida() const;
        void mostrar_revers_cim();
        Carta retorna_primera_carta();
        void eliminar();



    protected:

    private:
        struct Node{
            Carta dada;
            Node *seg;
        };

        Node *pila;
        int a_n;
        int a_max;

        void copia(PilaCartes &o);
        void allibera();
};

#endif // PILACARTES_H
