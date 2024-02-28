#include "Lista.h"

Lista::Lista() : cabeza(nullptr) {};

Lista::~Lista(){
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

Nodo* Lista::getCabeza() const{
    return cabeza;
};

void Lista::agregar(const Persona& persona) {
    Nodo* nuevoNodo = new Nodo(persona);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

void Lista::listar() const {
    Nodo* actual = cabeza;
    int i=1;
    while (actual != nullptr) {
        std::cout << "["<< std::to_string(i) <<"]::"<< actual->data << " -> "<< actual->siguiente->data << " : "<< actual->data << " " << std::endl;
        actual = actual->siguiente;
        ++i;
    }
    std::cout << std::endl;
}

Nodo* Lista::encontrarMitad() const {
    Nodo* rapido = cabeza->siguiente;
    Nodo* lento = cabeza;

    while(rapido != nullptr && rapido->siguiente != nullptr){
        rapido = rapido->siguiente->siguiente;
        lento = lento->siguiente;
    }
    return lento;
}

void Lista::dividir(Lista** lista1, Lista** lista2, Nodo* corte) {
    if(cabeza == nullptr || cabeza->siguiente == nullptr){
        return;
    }

    (*lista1)->cabeza = cabeza;
    (*lista2)->cabeza = corte->siguiente;

    corte->siguiente = nullptr;
    
}

void Lista::bisecar(Lista** lista1, Lista** lista2) {
    Nodo* corte = encontrarMitad();

    dividir(lista1, lista2, corte);
}