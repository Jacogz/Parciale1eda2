#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

class Persona {
    private:
        std::string nombre;
        int edad;
    
    public:
        Persona(const std::string& nombre, int edad);

        std::string getNombre() const;
        int getEdad() const;

        bool operator==(const Persona& otra) const;
        bool operator!=(const Persona& otra) const;
        bool operator<(const Persona& otra) const;
        bool operator<=(const Persona& otra) const;
        bool operator>(const Persona& otra) const;
        bool operator>=(const Persona& otra) const;

        friend std::ostream& operator<<(std::ostream& os, const Persona& persona);

        std::string to_string() const;
};

#endif