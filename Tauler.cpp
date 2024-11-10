#include "Tauler.h"
#include <iostream>
#include <iomanip>
#include "Seguidors.h"

const int MIDA_TAULER = 4;

using namespace std;

Tauler::Tauler()
{
}

Tauler::~Tauler()
{
    allibera();
}

Tauler::Tauler(Baralla &baralla){
    n_files = 4;
    n_columnes = 4;
    tauler = new Carta*[MIDA_TAULER];
    for (int i = 0; i<MIDA_TAULER; i++){
        tauler[i] = new Carta[MIDA_TAULER];
    }
}

Tauler & Tauler::operator=(const Tauler &t){
    if(this!=&t){
        allibera();
    }
    return *this;
}

void Tauler::omplir(Baralla &baralla){
    int n = 0;
    for (int i = 0; i<n_files; i++){
        for (int j = 0; j<n_columnes; j++){
            if ((i == 0 or i == 3) or (j == 0 or j == 3)){
                tauler[i][j] = baralla.retorn_carta(n+1);
                n++;
            }
        }
    }
    baralla.retirar_cartes(12);
}

void Tauler::introduir_carta(Carta c, int i, int j){
    tauler[i][j] = c;
}

bool Tauler::comprobar_tauler_ple(){
    Carta c(7,0,0);
    bool ple = true;
    for (int i = 0; i<MIDA_TAULER; i++){
        for (int j = 0; j<MIDA_TAULER; j++){
            if(tauler[i][j].igual(c)) ple = false;
        }
    }
    return (ple);
}

void Tauler::remplenar(PilaCartes& pila){
    int contador = 0;
    Carta c(7, 0, 0);
    for (int i = 0; i<MIDA_TAULER; i++){
        for (int j = 0; j<MIDA_TAULER; j++){
            if(tauler[i][j].igual(c)) contador++;
        }
    }
    if (contador>4){
        for (int i = 0; i<MIDA_TAULER; i++){
            for (int j = 0; j<MIDA_TAULER; j++){
                if(tauler[i][j].igual(c) and contador>4){
                    tauler[i][j] = pila.retorna_primera_carta();
                    pila.eliminar();
                    contador--;
                }
            }
        }
    }
}

void Tauler::comprobar_tauler(int n, int i, int j, Seguidors Taula_s[]){
    Carta c(7,0,0);
    int valor = 0;
    int suma_i = 0;
    int suma_j = 0;
    int k=0;
    bool buit_i = false;
    bool buit_j = false;
    while (k<MIDA_TAULER and !buit_i){
        if(tauler[k][j].igual(c)) buit_i = true;
        suma_i += tauler[k][j].retornar_influencia();
        k++;
    }
    k = 0;
    while (k<MIDA_TAULER and !buit_j){
        if(tauler[i][k].igual(c)) buit_j = true;
        suma_j += tauler[i][k].retornar_influencia();
        k++;
    }
    bool ple = comprobar_tauler_ple();
    if(suma_i>=10 and !buit_i and !ple){
        for(int k=0; k<MIDA_TAULER; k++){
            if(tauler[i][j].igual_magia_germandat(tauler[k][j])and !tauler[i][j].igual(tauler[k][j])){
                for(int m = 0; m<6; m++){
                    if (Taula_s[n].igual_magia(tauler[k][j], m)){
                        Taula_s[n].afagir_carta(tauler[k][j]);
                        valor = tauler[k][j].retornar_influencia();
                        Taula_s[n].introduir_influencia(m, valor);
                        tauler[k][j] = c;
                    }
                }
            }

        }
    }
    else if (ple){
        for(int k=0; k<MIDA_TAULER; k++){
            if(!tauler[i][j].igual_germandat(tauler[k][j])and !tauler[i][j].igual(tauler[k][j])){
                for(int m = 0; m<6; m++){
                    if (Taula_s[n].igual_magia(tauler[k][j], m)){
                        Taula_s[n].afagir_carta(tauler[k][j]);
                        valor = tauler[k][j].retornar_influencia();
                        Taula_s[n].introduir_influencia(m, valor);
                        tauler[k][j] = c;
                    }
                }
            }

        }
    }
    if(suma_j>=10 and !buit_j and !ple){
        for(int l=0; l<MIDA_TAULER; l++){
            if(tauler[i][j].igual_magia_germandat(tauler[i][l]) and !tauler[i][j].igual(tauler[i][l])){
                for(int m = 0; m<6; m++){
                    if (Taula_s[n].igual_magia(tauler[i][l], m)){
                        Taula_s[n].afagir_carta(tauler[i][l]);
                        valor = tauler[i][l].retornar_influencia();
                        Taula_s[n].introduir_influencia(m, valor);
                        tauler[i][l] = c;
                    }
                }
            }

        }
    }
    else if (ple){
        for(int l=0; l<MIDA_TAULER; l++){
            if(!tauler[i][j].igual_germandat(tauler[i][l])and !tauler[i][j].igual(tauler[i][l])){
                for(int m = 0; m<6; m++){
                    if (Taula_s[n].igual_magia(tauler[i][l], m)){
                        Taula_s[n].afagir_carta(tauler[i][l]);
                        valor = tauler[i][l].retornar_influencia();
                        Taula_s[n].introduir_influencia(m, valor);
                        tauler[i][l] = c;
                    }
                }
            }

        }
    }

}

bool Tauler::comprobar_buit(int i, int j){
    Carta c(7,0,0);
    return (tauler[i][j].igual(c));
}

void Tauler::mostrar(PilaCartes pila_dreta, PilaCartes pila_esquerre){
    Carta c(7,0,0);
    cout << string(5, ' ');
    for (int i = 0; i < MIDA_TAULER; i++) {
        cout << setfill(' ') << setw(6) << i;
    }
    cout << endl;

    for (int i = 0; i < MIDA_TAULER; i++) {
        if (i == 1) pila_esquerre.mostrar_revers_cim();
        else cout << "   ";

        cout << setfill(' ') << setw(3) << i << " ";
        for (int j = 0; j < MIDA_TAULER; j++) {
            cout << " ";
            if (tauler[i][j].igual(c))cout << "[   ]";
            else tauler[i][j].mostrar();
        }

        if (i == 1) {
            cout << "  ";
            pila_dreta.mostrar_revers_cim();
        }

        cout << endl;
    }
}

void Tauler::allibera(){
    for(int i=0;i<n_files; i++) // alliberament de cadascuna de les files
        delete [] tauler[i];
    delete [] tauler;
}
