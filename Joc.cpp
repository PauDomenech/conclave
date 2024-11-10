#include "Joc.h"
#include "Baralla.h"
#include <iostream>
#include "Tauler.h"
#include "PilaCartes.h"
#include "Seguidors.h"

using namespace std;
const int MAX_J = 4;

typedef Jugador Jugadors[MAX_J];

Joc::Joc()
{
    //ctor
}

Joc::~Joc()
{

}

Joc::Joc(unsigned llavor){
    x = llavor;
}

void Joc::preparar(){
    int jugador_actual = 0;
    Baralla baralla(x);
    baralla.barrejar();
    retirar_baralla(baralla);
    agafar_cartes(baralla);
    Tauler tauler(baralla);
    tauler.omplir(baralla);
    PilaCartes pila_dreta(baralla), pila_esquerra(baralla);
    pila_dreta.omplir(baralla);
    pila_esquerra.omplir(baralla);
    bool acabat = false;
    while (!acabat){
        torn_jugador(jugador_actual, pila_dreta, pila_esquerra, tauler, acabat);
        jugador_actual++;
        if (jugador_actual == num_jugadors) {
            jugador_actual=0;
        }
        else if(pila_dreta.buida() and pila_esquerra.buida()){
            jugador_actual=0;
            for(int i = 0; i<4; i++){
                torn_jugador(jugador_actual, pila_dreta, pila_esquerra, tauler, acabat);
                jugador_actual++;
            }
            jugador_actual = 0;
            final_joc(tauler, jugador_actual, acabat);
        }
    }
}


void Joc::introduir_jugador(Jugador jug){
    Taula_j[num_jugadors] = jug;
    num_jugadors++;
}

void Joc::final_joc(Tauler& tauler, int n, bool& acabat){
    cout << "RESULTAT FINAL" << endl;
    cout << string(14, '=') << endl << endl;
    mostrar_seguidors();
    resum_seguidors(n);
    obtenir_puntuacio();
    mostrar_puntuacio();
    acabat = true;
}

void Joc::obtenir_puntuacio(){
    for (int i = 0; i<6; i++){
        for (int j = 0; j<num_jugadors; j++){
            int k = 0;
            bool superior = false;
            int valor = Taula_s[j].retorna_influencia(i);
            while(k<4 and !superior){
                int valor_k = Taula_s[k].retorna_influencia(i);
                if (valor<valor_k)
                    superior = true;
                k++;
            }
            if (superior)
                Taula_j[j].introduir_puntuacio(valor);
        }
    }
}

void Joc::mostrar_puntuacio(){
    cout << endl << "PUNTS DE DECEPCIO:" << endl;
    for(int i = 0; i < num_jugadors; i++){
        int valor = Taula_j[i].retornar_puntuacio();
        string nom = Taula_j[i].retornar_nom();
        cout << " " << valor << " " << nom << endl;
    }
    bool superior = true;
    string nom_guanyador;
    for (int j = 0; j<num_jugadors; j++){
        int k = 0;
        int valor = Taula_j[j].retornar_puntuacio();
        while(k<num_jugadors and superior){
            int valor_k = Taula_j[k].retornar_puntuacio();
            if (valor<valor_k)
                superior = false;
                nom_guanyador = Taula_j[j].retornar_nom();
            k++;
        }
    }
    if (!superior){
        cout << endl << "ENHORABONA " << nom_guanyador << "! HAS GUANYAT LA PARTIDA!" << endl;
    }
}

void Joc::mostrar_seguidors(){
    cout << "TOTS ELS SEGUIDORS:" << endl;
    for (int i = 0; i<num_jugadors; i++){
        string nom = Taula_j[i].retornar_nom();
        Taula_s[i].ordenar_cartes();
        cout << i+1 << " " << nom << endl;
        cout << " ";
        Taula_s[i].mostrar_cartes();
        cout << endl;
    }
}

void Joc::torn_jugador(int& n,  PilaCartes &pila_dreta, PilaCartes& pila_esquerra, Tauler& tauler, bool& acabat){
    string nom_jugador = Taula_j[n].retornar_nom();
    cout << "TORN DE " << nom_jugador << endl;
    cout << string(8 + nom_jugador.size(), '=') << endl;
    cout << endl;
    tauler.mostrar(pila_dreta, pila_esquerra);
    cout << endl;
    Taula_j[n].mostrar();
    cout << endl << endl;
    cout << "MANS DELS OPONENTS:" << endl;
    for(int i = 0; i<num_jugadors; i++){
        if (i != n){
            string nom = Taula_j[i].retornar_nom();
            Taula_j[i].mostrar_revers();
            cout << "  " << i+1 << " " << nom << endl;
        }
    }
    resum_seguidors(n);
    mostrar_opcions(n, pila_dreta, pila_esquerra, tauler, acabat);
}

void Joc::resum_seguidors(int n){
    cout << endl << "RESUM DELS SEGUIDORS:" << endl;
    string nom = Taula_j[n].retornar_nom();
    Taula_s[n].mostrar();
    cout << "  " << n+1 << " " << nom << endl;
    for(int i = 0; i<num_jugadors; i++){
        if (i!=n){
            string nom = Taula_j[i].retornar_nom();
            Taula_s[i].mostrar();
            cout << "  " << i+1 << " " << nom << endl;
        }
    }
}

void Joc::comprobar_influencia(int n, Tauler& tauler, int i, int j, char pila, PilaCartes& dreta, PilaCartes& esquerra){
    tauler.comprobar_tauler(n, i, j, Taula_s);
    if(pila == 'd')
        tauler.remplenar(dreta);
    if(pila == 'e')
        tauler.remplenar(esquerra);
}

void Joc::mostrar_opcions(int& n,  PilaCartes& pila_dreta, PilaCartes& pila_esquerra, Tauler& tauler, bool& acabat){
    cout << endl << "OPCIONS:" << endl << "(I) FER JUGADA CEDINT INFLUENCIA" << endl << "(J) FER JUGADA SENSE CEDIR INFLUENCIA" << endl << "(P) MOSTRAR PILES" << endl << "(F) ABANDONAR PARTIDA" << endl << endl;
    cout << "ENTRA UNA OPCIO:" << endl;
    char opcio;
    cin >> opcio;
    if (opcio=='I') cedint_influencia(n, pila_dreta, pila_esquerra, tauler);
    else if (opcio=='J') no_cedint_influencia(n, pila_dreta, pila_esquerra, tauler);
    else if (opcio=='P') {
        mostrar_piles(n, pila_dreta, pila_esquerra);
        n--;
    }
    else if (opcio=='F') {
        cout << "PARTIDA ABANDONADA" << endl;
        bool acabat = true;
    }
    else {
        cout << "OPCIO NO DEFINIDA" << endl << endl;
        torn_jugador(n, pila_dreta, pila_esquerra, tauler, acabat);
    }
}

void Joc::cedint_influencia(int n, PilaCartes& pila_dreta, PilaCartes& pila_esquerra, Tauler& tauler){
    cout << "ENTRA LA MAGIA QUE VOLS CEDIR:" << endl;
    char magia;
    cin >> magia;
    cout << "ENTRA EL JUGADOR A QUI LA VOLS CEDIR:" << endl;
    int pos;
    cin >> pos;
    if(pos<=num_jugadors-1){
        int posicio_magia = Taula_s[n].posicio_magia(magia);
        int valor = Taula_s[n].retorna_influencia(posicio_magia);
        Taula_s[pos-1].introduir_influencia(posicio_magia, valor);
        Taula_s[pos-1].introduir_cartes(Taula_s, magia, n);
        no_cedint_influencia(n,  pila_dreta, pila_esquerra, tauler);
    }
    else {
        cout << "MOVIMENT NO VALID" << endl << "ENCARA T'INTERESSA CEDIR INFLUENCIA? (s/n)" << endl;
        char opcio;
        cin >> opcio;
        if (opcio == 's')
            cedint_influencia(n, pila_dreta, pila_esquerra, tauler);
        else
            no_cedint_influencia(n,  pila_dreta, pila_esquerra, tauler);
    }

}
void Joc::mostrar_piles(int n, PilaCartes pila_dreta, PilaCartes pila_esquerra){
    cout << endl << "PILA ESQUERRA:" << endl;
    pila_esquerra.mostrar();
    cout << endl << "PILA DRETA:" << endl;
    pila_dreta.mostrar();
    cout << endl;
}

void Joc::no_cedint_influencia(int n, PilaCartes& pila_dreta, PilaCartes& pila_esquerra, Tauler& tauler){
    bool posicio_correcte = false;
    int posicio_carta;
    while(!posicio_correcte){
        cout << "ENTRA LA POSICIO DE LA CARTA QUE VOLS COL.LOCAR:" << endl;
        cin >> posicio_carta;
        if(posicio_carta>=4 or posicio_carta<=-1){
            cout << "POSICIO NO VALIDA" << endl;
        }
        else posicio_correcte = true;
    }
    posicio_correcte = false;
    int i, j;
    Carta c = Taula_j[n].retornar_carta(posicio_carta);
    while (!posicio_correcte){
        cout << "ENTRA LA POSICIO DEL TAULER ON VOLS COL.LOCAR LA CARTA:" << endl;
        cin >> i >> j;
        if (i<=-1 or i>=4 or j<=-1 or j>=4)
            cout << "POSICIO NO VALIDA" << endl;
        else posicio_correcte = true;
    }
    if(!tauler.comprobar_buit(i, j)){
        cout << "JUGADA NO PERMESA" << endl << "TORNA A INDICAR LA JUGADA" << endl;
        no_cedint_influencia(n,  pila_dreta, pila_esquerra, tauler);
    }
    else{
        tauler.introduir_carta(c, i, j);
        bool pila_correcte = false;
        while(!pila_correcte){
            cout << "DE QUINA PILA VOLS ROBAR LA CARTA? (e/d)" << endl;
            char pila;
            cin >> pila;
            if (pila=='e'){
                if(!pila_esquerra.buida()){
                    Carta e = pila_esquerra.retorna_primera_carta();
                    Taula_j[n].introduir_carta(e, posicio_carta);
                    pila_esquerra.eliminar();
                }
                else {
                    Carta e = pila_dreta.retorna_primera_carta();
                    Taula_j[n].introduir_carta(e, posicio_carta);
                    pila_dreta.eliminar();
                }
                comprobar_influencia(n, tauler, i, j, pila, pila_dreta, pila_esquerra);
                pila_correcte = true;
            }
            else if (pila=='d'){
                if(!pila_dreta.buida()){
                    Carta d = pila_dreta.retorna_primera_carta();
                    Taula_j[n].introduir_carta(d, i);
                    pila_dreta.eliminar();
                }
                else {
                    Carta d = pila_esquerra.retorna_primera_carta();
                    Taula_j[n].introduir_carta(d, i);
                    pila_esquerra.eliminar();
                }
                comprobar_influencia(n, tauler, i, j, pila, pila_dreta, pila_esquerra);
                pila_correcte = true;
            }
            else {
                cout << "AQUESTA PILA NO EXISTEIX" << endl;
            }
        }
        cout << endl;
    }
}

void Joc::retirar_baralla(Baralla& baralla){
    int n = 6*4+6*(4-num_jugadors);
    baralla.retirar_cartes(n);
    cout << endl;
}

void Joc::agafar_cartes(Baralla &baralla){
    for(int i = 0; i<num_jugadors; i++){
        Taula_j[i].introduir_carta(baralla);
    }
}
