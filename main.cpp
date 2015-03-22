/* 
 * File:   main.cpp
 * Author: alvaro
 *
 * Created on 19 de marzo de 2015, 01:47 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <time.h>

using namespace std;

/*
 * 
 */
//imprime integrantes y fecha de compilacion

void ImprimirIntegrantes() {
    cout << "Integrantes del grupo de trabajo : " << endl << endl;
    cout << " 1.- Alvaro Cabedo Vasquez" << endl;
    cout << " 2.- Fabian Castillo Salgado" << endl;
    cout << " 3.- Alexis Muñoz Acuña" << endl;
    cout << " Fecha de compilacion : " << __DATE__ << endl << endl;
}


// Funcion disponible; indica si el numero ya ha salido
bool Disponible(int vector[], int num, int index) {
    for (int i = 0; i <= index; i++) {
        if (vector[i] == num) {
            return false;
        }
    }
    return true;
}

// Funcion que pasa de int a string
string IntString(int entero){
    string cadena;
    int aux;
    while(entero / 10 != 0){
        aux = entero%10;
        entero = entero / 10;
        aux += 48;
        cadena = (char)aux + cadena;
    }
    entero += 48;
    cadena = (char)entero + cadena;
    return cadena;    
}

//Funcion que llena con un cero a la izquierda numeros de un solo digito para cumplir formato ISO
string LlenarCeros(int numero){
    string cadena;
    if(numero <10){
        cadena = "0";        
    }
    cadena += IntString(numero);
    return cadena;
}

//Funcion retorna la fecha y hora actuales como un string
string HoraActual(){
    string cadena;
    time_t now = time(0);
    struct tm tstruct;
    tstruct = *localtime(&now);
    cadena += IntString(tstruct.tm_year + 1900) + "-";
    cadena += LlenarCeros(tstruct.tm_mon) + "-";
    cadena += LlenarCeros(tstruct.tm_mday) + " ";
    cadena += LlenarCeros(tstruct.tm_hour) + ":";
    cadena += LlenarCeros(tstruct.tm_min) + ":";
    cadena += LlenarCeros(tstruct.tm_sec);
    return cadena;
}


int main(int argc, char** argv) {

    switch (argc) {
        case 1://si no entran parametros
            cout << "Debe Ingresar Argumentos\n";
            break;
        case 2://si entra 1 parametro
            if (strcmp(*(argv + 1), "-v") == 0) { //si el parametro es "-v" muestra integrantes y fecha compilacion
                ImprimirIntegrantes();
            } else if (strcmp(*(argv + 1), "-g") == 0) { //si el parametro es "-g" realiza sorteo de Qno
                srand(time(NULL));
                int sorteo[14];
                int i = 0;
                while (i < 14) {
                    int t = 1 + rand() % 25;
                    if (Disponible(sorteo, t, i)) {
                        sorteo[i] = t;
                    } else {
                        i = i - 1;
                    }
                    i++;
                }
                ofstream archivo("qno.csv", ios::app);
                archivo << HoraActual() << ";";
                for(int i = 0; i < 14; i++){
                    archivo << IntString(sorteo[i]) << ";";
                }
                archivo << endl;
                archivo.close();

            } else { //sino muestra mensaje error
                cout << "Argumento no valido\n";
            }
    }
    return 0;
}

