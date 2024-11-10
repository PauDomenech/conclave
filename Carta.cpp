#include "Carta.h"
#include <iostream>

using namespace std;

const char Carta::a_magia[] = {'b','o','p','r','t','v',' '};
const int Carta::a_influencia[] = {1,2,3,4,5};
const char Carta::a_germandat[] = {'c','g','s'};

Carta::Carta()
{
    magia = a_magia[7];
    influencia = a_influencia[0];
    germandat = a_germandat[0];
}

Carta::~Carta()
{
    //dtor
}

Carta::Carta(const int i, int k, int j){
    magia = a_magia[i];
    influencia = a_influencia[k];
    germandat = a_germandat[j];
}

void Carta::mostrar(){
    cout << "[" << magia << influencia << germandat << "]";
}

void Carta::mostrar_revers(){
    cout << "[" << magia << "]";
}

bool Carta::igual_magia_germandat(Carta c){
    return (c.magia==magia or c.germandat == germandat);
}

bool Carta::igual_germandat(Carta c){
    return (c.germandat == germandat);
}

bool Carta::igual_magia(char c){
    return (magia == c);
}

bool Carta::igual_magia_carta(Carta c){
    return (magia == c.magia);
}

bool Carta::magia_superior(Carta c){
    return(magia > c.magia);
}

int Carta::retornar_influencia(){
    return (influencia);
}

bool Carta::influencia_superior(Carta c){
    return (influencia > c.influencia);
}

bool Carta::influencia_igual(Carta c){
    return (influencia == c.influencia);
}

bool Carta::germandat_superior(Carta c){
    return (germandat > c.germandat);
}

bool Carta::igual(Carta c){
    return (magia == c.magia and influencia == c.influencia and germandat == c.germandat);
}
