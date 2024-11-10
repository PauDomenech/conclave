/************************************************************************
 * Exercici de la Sessió 10
 *
 * Falta l'especificació
 ************************************************************************/
#include <iostream>
#include "Joc.h"
#include <limits>
#include "Jugador.h"
using namespace std;

void entrada_jugadors(Joc& joc)
{
    int jugadors = 0;
    while (jugadors < 2 or jugadors > 4){
        cout << "ENTRA EL NUMERO DE JUGADORS (2-4): " << endl;
        cin >> jugadors;
        if (jugadors < 2 or jugadors > 4)
            cout << "NUMERO DE JUGADORS INCORRECTE" << endl;
    }
    string nom;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    for (int i = 0; i < jugadors; i++){
        cout << "ENTRA EL NOM DEL JUGADOR " << i+1 << ": " << endl;
        getline(cin, nom);
        Jugador jugador(nom);
        joc.introduir_jugador(jugador);
    }
}

int main()
{
	unsigned llavor;

    cout << "ENTRA LA LLAVOR:" << endl;
    cin >> llavor;

    Joc joc(llavor);

    entrada_jugadors(joc);
    joc.preparar();

    return 0;
}
