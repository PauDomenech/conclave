#include "Jugador.h"
#include "Baralla.h"

Jugador::Jugador()
{
    //ctor
}

Jugador::~Jugador()
{

}

Jugador::Jugador(string nom){
    a_nom = nom;
}


void Jugador::introduir_carta(Baralla& baralla){
    for (int i = 0; i<4; i++){
        c[i] = baralla.retorn_carta(i+1);
    }
    baralla.retirar_cartes(4);
}

void Jugador::introduir_carta(Carta ca, int i){
    c[i] = ca;
}

void Jugador::mostrar(){
    cout << "MA DE " << a_nom << ":" << endl;
    for (int i = 0; i<4; i++){
        cout << i << ":";
        c[i].mostrar();
        cout << " ";
    }
}

void Jugador::mostrar_revers(){
    for (int i = 0; i<4; i++){
        c[i].mostrar_revers();
        cout << " ";
    }
}

Carta Jugador::retornar_carta(int i){
    return c[i];
}

void Jugador::mostrar(int n){
    c[n].mostrar();
}

string Jugador::retornar_nom(){
    return a_nom;
}

void Jugador::introduir_puntuacio(int punts){
    puntuacio = punts;
}

int Jugador::retornar_puntuacio(){
    return puntuacio;
}
