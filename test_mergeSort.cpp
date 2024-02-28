#include <iostream>
#include "Persona.h"
#include "Lista.h"
#include "Sort.h"
#include "Generador.h" // Asumo que tienes una clase Generador para generar personas aleatorias

int main(int argc, char* argv[]) {
    // Verificar que se haya proporcionado el número de elementos como argumento
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <numero_de_elementos>" << std::endl;
        return 1; // Salir con código de error
    }

    // Obtener el número de elementos desde el argumento
    int numElementos = std::atoi(argv[1]);

    // Crear un generador con archivos de nombres y apellidos
    Generador generadorNombres("nombres.txt", "apellidos.txt");

    //Crear un objeto Sort
    Sort sort = Sort();

    // Crear una lista e insertar personas generadas aleatoriamente
    Lista lista;

    for (int i = 0; i < numElementos; ++i) {
        Persona personaGenerada = generadorNombres.generarPersona();
        lista.agregar(personaGenerada);
    }

    // Mostrar la lista desordenada
    std::cout << "Lista de personas generadas aleatoriamente (desordenada):" << std::endl;
    lista.listar();
    std::cout << std::endl;

    // Ordenar la lista con MergeSort
    sort.mergeSort(&lista);

    // Mostrar la lista ordenada
    std::cout << "Lista ordenada por MergeSort:" << std::endl;
    lista.listar();

    return 0;
}
