#include "Seguidors.h"
#include <iostream>
#include <iomanip>

using namespace std;

const char Seguidors::a_magia[] = {'b','o','p','r','t','v'};

Seguidors::Seguidors()
{
    //ctor
}

Seguidors::~Seguidors()
{
    //dtor
}

void Seguidors::mostrar(){
    for (int i = 0; i<6; i++){
        cout << "[" << setfill(' ') << setw(2);
        if (valor[i]>0) cout << valor[i]; // si la suma > 0
        else cout << ' '; // si la suma = 0
        cout << a_magia[i] << "] ";
    }
}

void Seguidors::introduir_influencia(int m, int val){
    valor[m] += val;
}

bool Seguidors::igual_magia(Carta c, int m){
    return (c.igual_magia(a_magia[m]));
}

int Seguidors::posicio_magia(char m){
    int posicio = 0;
    for (int i = 0; i<6; i++){
        if(a_magia[i] == m) posicio = i;
    }
    return posicio;
}

int Seguidors::retorna_influencia(int posicio_magia){
    int valor_retorn = valor[posicio_magia];
    valor[posicio_magia] = 0;
    return valor_retorn;
}

void Seguidors::afagir_carta(Carta c){
    cartes[num_cartes] = c;
    num_cartes++;
}

void Seguidors::introduir_cartes(Seguidors s[], char magia, int n){
    for (int i = 0; i<s[n].num_cartes; i++){
        if(s[n].cartes[i].igual_magia(magia))
            afagir_carta(s[n].cartes[i]);
    }
}

void Seguidors::mostrar_cartes(){
    for (int i = 0; i<num_cartes; i++){
        cartes[i].mostrar();
    }
}

void Seguidors::ordenar_cartes(){
    Carta temp;
    for (int i = 0; i<num_cartes-1; i++){
        for(int j = 0; j<num_cartes-1; j++){
            if (cartes[j].magia_superior(cartes[j+1])){
                temp = cartes[j];
                cartes[j] = cartes[j+1];
                cartes[j+1] = temp;
            }
            if (cartes[j].igual_magia_carta(cartes[j+1])){
                if (cartes[j].influencia_superior(cartes[j+1])){
                    temp = cartes[j];
                    cartes[j] = cartes[j+1];
                    cartes[j+1] = temp;
                }
                if (cartes[j].influencia_igual(cartes[j+1])){
                    if(cartes[j].germandat_superior(cartes[j+1])){
                        temp = cartes[j];
                        cartes[j] = cartes[j+1];
                        cartes[j+1] = temp;
                    }
                }
            }
        }
    }
}
