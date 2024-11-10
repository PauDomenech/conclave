#ifndef JOC_H
#define JOC_H
#include "Baralla.h"
#include "Jugador.h"
#include "PilaCartes.h"
#include "Tauler.h"
#include "Seguidors.h"

class Joc
{
    public:
        Joc();
        Joc(unsigned llavor);
        ~Joc();
        Joc &operator=(const Joc &j);
        void preparar();
        void retirar_baralla(Baralla& baralla);
        void introduir_jugador(Jugador jugador);
        void reserva(int n);
        void agafar_cartes(Baralla &baralla);
        void torn_jugador(int& n,  PilaCartes &pila_dreta, PilaCartes& pila_esquerra, Tauler& tauler, bool& acabat);
        void mostrar_opcions(int& n,  PilaCartes &pila_dreta, PilaCartes& pila_esquerra, Tauler& tauler, bool& acabat);
        void cedint_influencia(int n, PilaCartes& pila_dreta, PilaCartes& pila_esquerra, Tauler& tauler);
        void no_cedint_influencia(int n, PilaCartes& pila_dreta, PilaCartes& pila_esquerra, Tauler& tauler);
        void mostrar_piles(int n, PilaCartes pila_dreta, PilaCartes pila_esquerra);
        void comprobar_influencia(int n, Tauler& tauler, int i, int j, char pila, PilaCartes& dreta, PilaCartes& esquerra);
        void final_joc(Tauler& tauler, int n, bool &acabat);
        void mostrar_seguidors();
        void resum_seguidors(int n);
        void obtenir_puntuacio();
        void mostrar_puntuacio();

    protected:

    private:
        static const int MAX_J = 4;
        unsigned x;
        int num_jugadors = 0;
        Jugador Taula_j[4];
        Seguidors Taula_s[4];

        void copia(const Joc &j);
};

#endif // JOC_H
