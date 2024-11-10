#include "PilaCartes.h"
#include <iostream>

using namespace std;

PilaCartes::PilaCartes(Baralla baralla)
{
    a_n = 0;
    a_max = baralla.retorna_max()/2;
    pila=NULL;
}

PilaCartes::~PilaCartes()
{
    allibera();
}

PilaCartes::PilaCartes(PilaCartes& o){
    pila=NULL;
    copia(o);
}

bool PilaCartes::buida() const{
    return pila==NULL;
}

void PilaCartes::omplir(Baralla& b){
    int i = a_max;
    while (a_n!=a_max){
        Node *nou_node = new Node();
        nou_node->dada = b.carta(i-1);
        nou_node->seg = pila;
        pila = nou_node;
        a_n++;
        i--;
    }
    b.retirar_cartes_pila(a_n);
}

void PilaCartes::mostrar(){
    // Pre:--; Post: mostra la llista
    Node *aux = this->pila;
    while (aux!=NULL){
        aux->dada.mostrar_revers();
        aux = aux->seg;
        cout << " ";
    }
    cout << endl;
}

void PilaCartes::copia(PilaCartes& o){
    if(!o.buida()) {
        Node *p, *q, *aux;
        p = new Node; pila = p;
        aux = o.pila; p->dada = aux->dada; p->seg = NULL;
        q = p;
        aux = aux->seg;
        while (aux!=NULL) {
            p = new Node; q->seg = p;
            p->dada = aux->dada; p->seg = NULL;
            q = p;
            aux = aux->seg;
        }
    }
}

void PilaCartes::mostrar_revers_cim(){
    Node *aux = this->pila;

    aux->dada.mostrar_revers();
}

void PilaCartes::allibera(){
    while (!buida()) {
        Node* aux= pila;
        pila= pila->seg;
        delete aux;
    }
}

void PilaCartes::eliminar() {
    Node* aux = pila;
    pila= pila->seg;
    delete aux;
}

Carta PilaCartes::retorna_primera_carta(){
    Node *aux = this->pila;
    return aux->dada;
}
