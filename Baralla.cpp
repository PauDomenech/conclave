#include "Baralla.h"
#include <iostream>

using namespace std;

Baralla::Baralla()
{
    a_n=0;
    a_max = 89;
    reserva();
}

Baralla::Baralla(int llavor)
{
    x=llavor;
    a_n=0;
    a_max=89;
    reserva();
    for (int i=0; i<6; i++){
        for (int s=0; s<3; s++){
            for (int j=0; j<5; j++) {
                Carta carta = Carta(i,j,s);
                afegir(carta);
            }
        }
    }
}

Baralla::Baralla(const Baralla& t)
{
    copia(t);
}

Baralla::~Baralla()
{
    allibera();
}

Baralla &Baralla::operator=(const Baralla& t){
    if (this != &t){
        allibera();
        copia(t);
    }
    return *this;
}

void Baralla::mostrar(){
    // Pre:--; Post: mostra la llista
    if (a_n!=0){
        int i = 0;
        while (i!=a_n){
            t[i].mostrar();
            cout << " ";
            i++;
        }
        cout << endl;
    }
    else cout << "NO HI HA CAP CARTA" << endl;
}


void Baralla::afegir(Carta c){
    if (a_n == a_max) expandeix();
    t[a_n] = c;
    if (a_n!=a_max) a_n++;
}

unsigned Baralla::aleatori(int n){
    x = 1103515245*x+12345;
    unsigned b_aleatori = ((x/32)%32768)%n;
    return b_aleatori;
}

void Baralla::intercanvi(Carta& a, Carta& b){
    Carta aux = a; a=b; b=aux;
}

void Baralla::barrejar(){
    for(int i=a_n-1; i>0; i--){
        int pos = aleatori(i+1);
        intercanvi(t[pos], t[i]);
    }
}

void Baralla::copia(const Baralla& b){
    a_n = b.a_n;
    a_max = b.a_max;
    reserva();
    for (int i = 0; i<a_n; i++)
        t[i] = b.t[i];
}

void Baralla::allibera(){
    delete[] t;
}

void Baralla::reserva(){
    t = new Carta[a_max];
}

void Baralla::expandeix(){
    Carta *aux = t;
    a_max = 2*a_max;
    reserva();
    for (int i = 0; i<a_n; i++)
        t[i] = aux[i];
    delete[] aux;
}

void Baralla::buidar(int n){
    for (int i = n; a_n>n+1; i--){
            t[i] = t[a_n-1];
            a_n--;
    }
}

int Baralla::retorna_max(){
    return a_n;
}

Carta Baralla::carta(int i){
    return t[i];
}

void Baralla::retirar_cartes(int n){
    for (int i = 0; i<n; i++){
        for (int j = a_n-n; j>a_n; j--){
            t[j] = t[j+1];
        }
        a_n--;
    }
}

void Baralla::retirar_cartes_pila(int n){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<a_n; j++){
            t[j] = t[j+1];
        }
        a_n--;
    }
}

Carta Baralla::retorn_carta(int n){
    return t[a_n-n];
}
