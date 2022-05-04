#pragma once
#include "persona.h"
#include <iostream>
#include <string>
#include "ConexionDB.h"
class estudiante :
    public Persona
{
private: string mail, carne,v,genero;

public:
    estudiante() {

    }
    estudiante(string nom, string ape, string dire, string tel, string fn, string gen, string m, string car,string v) : Persona(nom, ape, dir, tel, fn) {
        genero = gen;
        mail = m;
        carnet = ct;
        var = v;
    }

    void setNom(string nom) { nombres = nom; }
    void setApe(string ape) { apellido = ape; }
    void setTel(string tel) { telefono = tel; }
    void setDir(string dire) { direccion = dire; }
    void setFN(string fn) { fecha_nacimiento = fn; }
    void setGen(string gen) { genero = gen; }
    void setEmail(string em) { mail = em; }
    void setCarne(string car) { carne = car; }

    string getNom() { return nombres; }
    string getApe() { return apellido; }
    string getTel () { return telefono; }
    string getDir() { return direccion; }
    string getFN() { return fecha_nacimiento; }
    string getGen() { return genero; }
    string getEmail() { return mail; }
    string getCarne() { return carnet; }


    void leer() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();
        if (cn.getConectar()) {
            cout << "Datos" << endl;
            string consulta = "select * from parcial_2";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
                }

            }
            else {
                cout << "Error" << endl;
            }

        }
        else {
            cout << "No leer" << endl;
            system("pause");
        }
        cn.cerrar_conexion();

    }

    void crear() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
    
            string insert = "INSERT INTO estudiantes(carne,nombres,apellidos,direccion,telefono,genero,mail,fecha_nacimiento)VALUES('" + carne + "','" + nombres + "','" + apellido + "','" + direccion + "','" + telefono + "','" + genero + "','" + mail + "','" + fecha_nacimiento + "'); ";
    
            const char* i = insert.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "La informacion se agrego correctamente" << endl;
            }
            else {
                cout << "No se pudo agregar la informacion, revise" << endl;
            }

        }
        else {
            cout << "Error al leer" << endl;
            system("pause");
        }
        cn.cerrar_conexion();
    }

    void borrar() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
           
            string insert = "DELETE FROM estudiantes WHERE idEstudiantes='" + v + "';";
            const char* i = insert.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Delete Exitoso" << endl;
            }
            else {
                cout << "Error en Delete" << endl;
            }

        }
        else {
            cout << "Error al leer" << endl;
            system("pause");
        }
        cn.cerrar_conexion();

    }

    void actualizar() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
        
            string insert = "UPDATE estudiantes\
                             SET carne='" + carne + "',nombres='" + nombres + "', apellidos= '" + apellido + "',direccion='" + direccion + "', telefono = '" + telefono + "', genero = '" + genero + "', mail = '" + mail + "', fecha_nacimiento = '" + fecha_nacimiento + "'\
                             WHERE idEstudiantes='" + v + "';";
            const char* i = insert.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Se ingreso correctamente la informacion" << endl;
                system("pause");
            }
            else {
                cout << "Error al insertar informacion" << endl;
                system("pause");
            }

        }
        else {
            cout << "Error al leer" << endl;
            system("pause");
        }
        cn.cerrar_conexion();
        system("pause");

    }




};
