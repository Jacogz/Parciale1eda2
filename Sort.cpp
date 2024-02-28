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

    Lista* mitad1 = new Lista();
    Lista* mitad2 = new Lista();

    lista->bisecar(&mitad1, &mitad2);


    mergeSort(mitad1);
    mergeSort(mitad2);

    lista->cabeza = merge(mitad1->getCabeza(), mitad2->getCabeza());
}

Nodo* Sort::quickSort(Nodo* cabeza){
    // Caso base
    if (cabeza == nullptr || cabeza->siguiente == nullptr) {
        return cabeza;
    }

    Nodo* cabezaMayor = nullptr; // Lista para los mayores al pivote
    Nodo* cabezaMenor = nullptr; // Lista para los menores al pivote
    Nodo* pivote = cabeza; // El pivote es el primer elemento de la lista original
    Nodo* actual = cabeza->siguiente; // Se empieza a comparar a partir del segundo elemento

    // Ciclo para recorrer toda la lista
    while (actual != nullptr){

        Nodo* siguiente = actual->siguiente;
        // Se guarda el proximo nodo porque el actual->siguiente hay que desligarlo de la lista principal

        // Verificar si actual es menor al pivote
        if (actual->data < pivote->data){
            actual->siguiente = cabezaMenor; // Se pone el actual de primero en la lista de menores, desligandolo a la vez de la lista ppal
            cabezaMenor = actual; // Se mueve el puntero de la cabeza de menores al nodo actual
        }
        // Lógica para los mayores
        else{
            actual->siguiente = cabezaMayor;
            cabezaMayor = actual;
        }
        // Se cambia el actual para seguir el ciclo while
        actual = siguiente;
    }

    // Se debe hacer recursión sobre la lista de menores y mayores
    cabezaMenor = quickSort(cabezaMenor);
    cabezaMayor = quickSort(cabezaMayor);

    // Se debe ligar el final de los menores con el pivote y este a su vez se debe ligar con la cabeza de mayores
    return unionListas(cabezaMenor, pivote, cabezaMayor);
}