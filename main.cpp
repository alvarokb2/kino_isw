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
    cout << " Fecha de compilacion : " << __DATE__ << endl;
}

//Imprimir sorteo
void ImprimirSorteo(int sorteo[]){
    for(int i = 0 ; i < 14; i++){
        cout << sorteo[i] << " ";
    }
}

//Funcion disponible
bool Disponible(int vector[], int num, int index){
    for(int i = 0; i <= index; i++){
        if(vector[i] == num){
            return false;
        }        
    }
    return true;
}

void NuevoSorteo() {
    srand(time(NULL));
    int sorteo[14];
    int i = 0;
    while(i <14){
        int t =1 + rand() % 25;
        if(Disponible(sorteo,t,i)){
            sorteo[i] = t;
        }
        else{
            i = i - 1;
        }
        i++;
    }
    ImprimirSorteo(sorteo);
}

int main(int argc, char** argv) {

    switch (argc) {
        case 1://si no entran parametros
            cout << "Debe Ingresar Argumentos\n";
            break;
        case 2://si entra 1 parametro
            if (strcmp(*(argv + 1), "-v") == 0) { //si el parametro es "-v" muestra integrantes y fecha compilacion
                ImprimirIntegrantes();
            }
            else if (strcmp(*(argv + 1), "-g") == 0) { //si el parametro es "-g" realiza sorteo de Qno
                //llenado de arreglos
                int universo[25];
                int sorteo[14];
                for (int i = 0; i < 25; i++) {
                    universo[i] = i + 1;
                }
                cout << endl;
                NuevoSorteo();
            }
            else { //sino muestra mensaje error
                cout << "Argumento no valido\n";
            }
    }
    return 0;
}
