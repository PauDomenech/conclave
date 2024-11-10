#ifndef CARTA_H
#define CARTA_H


class Carta
{
    public:
        Carta();
        virtual ~Carta();
        Carta(const int i, int k, int j);
        void mostrar();
        void mostrar_revers();
        bool igual(Carta c);
        bool igual_magia_germandat(Carta c);
        int retornar_influencia();
        bool igual_magia(char c);
        bool igual_germandat(Carta c);
        bool igual_magia_carta(Carta c);
        bool magia_superior(Carta c);
        bool influencia_superior(Carta c);
        bool influencia_igual(Carta c);
        bool germandat_superior(Carta c);


    protected:

    private:
        static const char a_magia[];
        static const int a_influencia[];
        static const char a_germandat[];

        char magia;
        int influencia;
        char germandat;
};

#endif // CARTA_H

