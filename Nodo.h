#ifndef NODO_H
#define NODO_H

#include "Persona.h"

class Nodo {
    public:
        Persona data;
        Nodo* siguiente;

        Nodo(const Persona& data);
};

#endif