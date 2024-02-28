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

    Nodo* cabezaMayor = nullptr; 
    Nodo* cabezaMenor = nullptr;
    Nodo* pivote = cabeza; 
    Nodo* actual = cabeza->siguiente; 

    
    while (actual != nullptr){

        Nodo* siguiente = actual->siguiente;
        

        
        if (actual->data < pivote->data){
            actual->siguiente = cabezaMenor; 
            cabezaMenor = actual; 
        }
        
        else{
            actual->siguiente = cabezaMayor;
            cabezaMayor = actual;
        }
        
        actual = siguiente;
    }

    
    cabezaMenor = quickSort(cabezaMenor);
    cabezaMayor = quickSort(cabezaMayor);

    // Se debe ligar el final de los menores con el pivote y este a su vez se debe ligar con la cabeza de mayores
    return unirListas(cabezaMenor, pivote, cabezaMayor);


    Nodo* sort::unirListas(Nodo* cabezaMenor, Nodo* pivote, Nodo* cabezaMayor) {
    // Encontrar el último nodo de la lista menor
    Nodo* actual = cabezaMenor;
    while (actual->siguiente != nullptr) {
        actual = actual->siguiente;  

        if (actual != nullptr) {
        actual->siguiente = pivote;
        } else {
        // Si no hay nodos en la lista menor, el pivote se convierte en la nueva cabeza
        cabezaMenor = pivote;
        }
        actual = pivote;
        while (actual != nullptr && actual->siguiente != nullptr) {
        actual = actual->siguiente;
        }
        if (actual != nullptr) {
        actual->siguiente = cabezaMayor;
        }
        return cabezaMenor;

    }
    


}