#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include "Baralla.h"

using namespace std;

class Jugador
{
    public:
        Jugador();
        ~Jugador();
        Jugador(string nom);
        void reserva();
        void introduir_carta(Baralla& baralla);
        void introduir_carta(Carta c, int i);
        void mostrar();
        string retornar_nom();
        void mostrar_revers();
        Carta retornar_carta(int i);
        void mostrar(int n);
        void introduir_puntuacio(int punts);
        int retornar_puntuacio();

    protected:

    private:
        string a_nom;
        Carta c[4];
        int puntuacio = 0;
};

#endif // JUGADOR_H
