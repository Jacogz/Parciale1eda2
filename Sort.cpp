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

void Sort::quickSort(Lista* lista){
    // Caso base
    if (lista->cabeza == nullptr || lista->cabeza->siguiente == nullptr) {
        return;
    }

    Lista* listaMayor = new Lista(); 
    Lista* listaMenor = new Lista();

    Nodo* cabeza = lista->cabeza;
    Nodo* pivote = cabeza;
    Nodo* actual = cabeza->siguiente; 

    while(actual != nullptr){

        Nodo* siguiente = actual->siguiente;

        if(actual->data < pivote->data){
            listaMenor->agregar(actual);
        }else{
            listaMayor->agregar(actual);
        }
        actual = siguiente;
    }

    /*std::cout << "Split" << std::endl;

    std::cout << "Lista mayor" << std::endl;
    listaMayor->listar();
    std::cout << std::endl;
    std::cout << "Lista menor" << std::endl;
    listaMenor->listar();*/

    quickSort(listaMenor);
    quickSort(listaMayor);

    // Se debe ligar el final de los menores con el pivote y este a su vez se debe ligar con la cabeza de mayores
    unirListas(listaMenor, pivote, listaMayor);
    lista->cabeza = listaMenor->cabeza != nullptr? listaMenor->cabeza : pivote;

    //listaMayor->~Lista();
    //listaMenor->~Lista();
}


void Sort::unirListas(Lista* listaMenor, Nodo* pivote, Lista* listaMayor) {

    Nodo* colaMenor = listaMenor->cabeza;

    if(colaMenor != nullptr){
        while(colaMenor->siguiente != nullptr){
            colaMenor = colaMenor->siguiente;
        }
        colaMenor->siguiente = pivote;
    }
    pivote->siguiente = listaMayor->cabeza;
}

void Sort::bubbleSort(Lista* lista){

    int intercambio;

    Nodo* actual;
    Nodo* anterior = nullptr;

    if(lista->cabeza == nullptr){
        return;
    }

    do
    {
        intercambio = 0;
        actual = lista->cabeza;

        while(actual->siguiente != anterior){
            if(actual->data < actual->siguiente->data){
                Nodo* temp = actual->siguiente;
                anterior->siguiente = actual->siguiente;
                temp->siguiente = actual;
                actual->siguiente = temp->siguiente->siguiente;
                intercambio = 1;
            }
            actual = actual->siguiente;
        }
        anterior = actual;
    } while (intercambio);
    
}