#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista {
    public:
        Nodo* cabeza;

        Lista();
        ~Lista();
        
        Nodo* getCabeza() const;
        void agregar(const Persona& persona);
        void listar() const;

        Nodo* encontrarMitad() const;
        void dividir(Lista** lista1, Lista** lista2, Nodo* corte);
        void bisecar(Lista** lista1, Lista** lista2);
};

#endif