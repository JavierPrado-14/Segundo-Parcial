// tarea_super.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <mysql.h>
#include "estudiante.h"
#include <string>
using namespace std;


void crearPrograma();
void menuprograma();
void borrarPrograma();
void actualizarPrograma();
void leerPrograma();

int main() {

    menuprograma();



}







void menuprograma() {
    do
    {
        int switch_on = 0;
        cout << "1. agregar" << endl;
        cout << "2. leer" << endl;
        cout << "3. actualizar" << endl;
        cout << "4. borrar " << endl;
        cout << "0. salir programa" << endl;
        cin >> switch_on;
        switch (switch_on)
        {
        case 1: crearPrograma(); break;

        case 2: leerPrograma(); break;

        case 3: actualizarPrograma(); break;

        case 4: borrarPrograma(); break;

        case 0: exit(-1);

        default: cout << "Este caracter no es valido, ingresa uno de la lista" << endl;
            break;
        }


    } while (1==1);
 

}



void crearPrograma() {
    system("cls");
    string nom, ape, dir, tel, fn, gen, m, car, y;
    getline(cin, nom);
    cout << "Ingresamos carne: ";
    getline(cin, car);
    cout << "Ingrese el nombre: ";
    getline(cin, nom);
    cout << "Ingrese los apellido: ";
    getline(cin, ape);
    cout << "Ingrese la direccion: ";
    getline(cin, dir);
    cout << "Ingrese el telefono: ";
    getline(cin, tel);
    cout << "Ingrese tipo de genero: ";
    getline(cin, gen);
    cout << "Ingrese mail: ";
    getline(cin, m);
    cout << "Ingrese la fecha de nacimiento";
    getline(cin, fn);



    estudiante c = estudiante(nom, ape, dir, tel, fn, gen, m, car, y);
    c.crear();




}

void borrarPrograma() {
    string nom, ape, dir, tel, fn, gen, em, ct, y;
    getline(cin, nom);
    cout << "Ingrese id del dato que elimara: ";
    getline(cin, v);

    estudiante c = estudiante(nom, ape, dir, tel, fn, gen, m, car, y);
    c.borrar();
}


void actualizarPrograma() {
    system("cls");
    string nom, ape, dir, tel, fn, gen, m, car, y;
    getline(cin, y);
    cout << "Ingrese id del carne ha actualizar: ";
    getline(cin, y);
    cout << "--------------------------------------------" << endl;
    getline(cin, nom);
    cout << "Ingrese el nuevo Nombre: ";
    getline(cin, nom);
    cout << "Ingrese el nuevo Apellido: ";
    getline(cin, ape);
    cout << "Ingrese la nueva Direccion: ";
    getline(cin, dir);
    cout << "Ingrese el nuevo Telefono: ";
    getline(cin, tel);
    cout << "Ingrese nuevo tipo de Genero: ";
    getline(cin, gen);
    cout << "Ingrese el nuevo mail: ";
    getline(cin, em);
    cout << "ingrese fecha de nacimiento";
    getline(cin, fn);

    estudiante c = estudiante(nom, ape, dir, tel, fn, gen, m, car, y);
    c.actualizar();

}

void leerPrograma() {
    string nom, ape, dir, tel, fn, gen, m, car, y;
    cout << "Datos" << endl;
    estudiante c = estudiante(nom, ape, dir, tel, fn, gen, m, car, y);
    c.leer();
}
