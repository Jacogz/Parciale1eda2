#ifndef SORT_H
#define SORT_H

#include "Lista.h"

class Sort {
    private:
        //merge sort
        Nodo* merge(Nodo* lista1, Nodo* lista2) const;

        //quick sort
        Nodo* unirListas(Nodo* listaMenor, Nodo* pivote, Nodo* listaMayor);

        //bubble


    public:
        void mergeSort(Lista* lista);
        Nodo* quickSort(Nodo* cabeza);
        void bubbleSort(Lista* lista);
};

#endif