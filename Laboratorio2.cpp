/*--------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓN
* CC3086 Programación de microprocesadores
* Semana 06: Laboratorio 2
* 
* Laboratorio2.cpp
* Creado por: Pedro Gablo Guzmán Mayen 22111, Javier Andres Chen Gonzalez 22153
* 
* Fecha: 16/07/2023
* Descripción: Parelización de la multiplicación de una matrriz y un vector.
* --------------------------------------------------------*/
#include <stdio.h>
#include <omp.h>
#include <iostream>

#include <random>
using namespace std;


int main() {
    random_device rd;
    uniform_int_distribution<int> dist(0, 5); //Generar números random 

    int rows = 0; //Número de fillas
    int columns = 0;  //Número de columnas
    int num_threads =0;
    cout <<"Selecciona el numero de filas que quieras para la matriz: ";
    cin >> rows; //Pedir al usuario las columnas y filas 
    cout << "Selecciona el numero de columnas que quieres para la matriz: ";
    cin >> columns;
    cout << "Selecciona el numero de hilos: ";
    cin >> num_threads;

    int matriz[rows][columns]; //Matriz
    int vector[rows][1];   //Vector 
    int result[rows][1]; //Resultado de la operación
    int i = 0;
    int j = 0;
    int k = 0;
    int u = 0;
    
    //Generar la matriz
    for (int i = 0; i<rows; i++){
        for (int j = 0; j<columns; j++){
            matriz[i][j] = dist(rd);
        }
    }

    //Generar el vector
    for (int i = 0; i<rows; i++){
        for (j = 0; j<1; j++){
            vector[i][j] = dist(rd);
        }
    }

    //Generar resultado
    for (int i = 0; i < rows; i++) {
    result[i][0] = 0;
    }
    cout << "La matriz es: " << "\n";
    //Imprimir la matriz
    for (int i = 0; i<rows; i++){
        for (j = 0; j<columns; j++){
            cout << matriz[i][j] <<" ";
        }
        cout << "\n";
    }

    cout << "El vector es: " << "\n";
    for (int i = 0; i<rows; i++){
        for (j = 0; j<1; j++){
            cout << vector[i][j] <<" ";
        }
        cout << "\n";
    }

    //Multiplicar la matriz por el vector
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < rows; i++) {
        #pragma omp parallel for
        for (int j = 0; j < columns; j++) {
            result[i][0] += matriz[i][j] * vector[j][0];
        }
        #pragma omp barrier
    }

    //Imprimir el resultado
    cout << "El resultado de la multiplicación es: " << "\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 1; j++) {
            cout << result[i][j] <<" ";
        }
        cout << "\n";
    }



    return 0;
}