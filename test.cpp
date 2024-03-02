#include <iostream>
#include <limits>
#include <chrono>
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
        Nodo* nuevoNodo = new Nodo(personaGenerada);
        lista.agregar(nuevoNodo);
    }

    // Mostrar la lista desordenada
    /*std::cout << "Lista de personas generadas aleatoriamente (desordenada):" << std::endl;
    lista.listar();
    std::cout << std::endl;*/

    // Ordenar la lista con MergeSort
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    sort.mergeSort(&lista);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_merge = end - start;

    // Ordenar la lista con quickSort
    std::chrono::steady_clock::time_point start2 = std::chrono::steady_clock::now();
    sort.quickSort(&lista);
    std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_quick = end2 - start;

    // Ordenar la lista con bubbleSort
    /*std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    sort.bubbleSort(&lista);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_bubble = end - start;*/

    // Mostrar la lista ordenada
    std::cout << "Tiempos de ordenamiento" << std::endl;
    std::cout << "Merge sort : ";
    std::cout << elapsed_merge.count() << std::endl;
    std::cout << "Quick sort : ";
    std::cout << elapsed_quick.count() << std::endl;
    /*std::cout << "Bubble sort : ";
    std::cout << elapsed_bubble.count() << std::endl;*/

    std::cout << "presiona ENTER para salir...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    return 0;
}
