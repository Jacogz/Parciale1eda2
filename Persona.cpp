#include "Persona.h"

Persona::Persona(const std::string& nombre, int edad) : nombre(nombre), edad(edad){}; 

std::string Persona::getNombre() const{
    return nombre;
};

int Persona::getEdad() const{
    return edad;
};

bool Persona::operator==(const Persona& otra) const {
    return (nombre == otra.nombre) && (edad == otra.edad);
}

bool Persona::operator!=(const Persona& otra) const {
    return !(*this == otra);
}

bool Persona::operator<(const Persona& otra) const {
    if (nombre == otra.nombre) {
        return edad < otra.edad;
    }
    return nombre < otra.nombre;
}

bool Persona::operator<=(const Persona& otra) const {
    return (*this < otra) || (*this == otra);
}

bool Persona::operator>(const Persona& otra) const {
    return !(*this <= otra);
}

bool Persona::operator>=(const Persona& otra) const {
    return !(*this < otra);
}

std::ostream& operator<<(std::ostream& os, const Persona& persona) {
    os << "Nombre: " << persona.nombre << ", Edad: " << persona.edad;
    return os;
}

std::string Persona::to_string() const {
    return "ObjPersona [Nombre: " + nombre + ", Edad: " + std::to_string(edad) + " años ]";
}