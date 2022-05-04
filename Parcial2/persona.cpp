#pragma once
#include <iostream>
using namespace std;
class Persona
{
    //atributos
protected: string nombres, apellido, direccion , telefono, fecha_nacimiento;


protected:
    Persona() {

    }
    //constructor
    Persona(string nom, string ape, string dir, string tel, string fn) {
        nombres = nom;
        apellido = ape;
        direccion = dir;
        telefono = tel;
        fecha_nacimiento = fn;
    }
};

