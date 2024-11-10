#ifndef TAULER_H
#define TAULER_H
#include "Carta.h"
#include "Baralla.h"
#include "PilaCartes.h"
#include "Seguidors.h"

class Tauler
{
    public:
        Tauler();
        ~Tauler();
        Tauler(Baralla &baralla);
        Tauler & operator=(const Tauler &t);
        void omplir(Baralla &baralla);
        void mostrar(PilaCartes pila_dreta, PilaCartes pila_esquerre);
        void introduir_carta(Carta c, int i, int j);
        void comprobar_tauler(int n, int i, int j, Seguidors Taula_s[]);
        bool comprobar_tauler_ple();
        void remplenar(PilaCartes& pila);
        bool comprobar_buit(int i, int j);

    protected:

    private:
        Carta** tauler;
        int n_files;
        int n_columnes;

        void allibera();
};

#endif // TAULER_H
