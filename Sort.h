#ifndef SORT_H
#define SORT_H

#include "Lista.h"

class Sort {
    private:
        //merge sort
        Nodo* merge(Nodo* lista1, Nodo* lista2) const;

        //quick sort
        void unirListas(Lista* listaMenor, Nodo* pivote, Lista* listaMayor);

        //bubble
        void intercambiar(Nodo* nodoA, Nodo* nodoB);

    public:
        void mergeSort(Lista* lista);
        void quickSort(Lista* lista);
        void bubbleSort(Lista* lista);
};

#endif