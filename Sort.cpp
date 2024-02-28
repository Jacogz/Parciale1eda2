#include "Sort.h"
#include <iostream>

Nodo* Sort::merge(Nodo* lista1, Nodo* lista2) const{

    Nodo* mayor = nullptr;

    if(lista1 == nullptr){
        return lista2;
    }else if(lista2 == nullptr){
        return lista1;
    }

    if(lista1->data > lista2->data){
        mayor = lista1;
        mayor->siguiente = merge(lista1->siguiente, lista2);
    }else{
        mayor = lista2;
        mayor->siguiente = merge(lista1, lista2->siguiente);
    }

    return mayor;
}

void Sort::mergeSort(Lista* lista){
    if(lista->cabeza == nullptr || lista->cabeza->siguiente == nullptr){
        return;
    }
    
    Lista* mitad1;
    Lista* mitad2;

    lista->bisecar(&mitad1, &mitad2);


    mergeSort(mitad1);
    mergeSort(mitad2);

    lista->cabeza = merge(mitad1->getCabeza(), mitad2->getCabeza());
}