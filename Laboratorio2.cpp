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
using namespace std;

int main() {

    int rows = 0;
    int columns = 0; 
    cout <<"Selecciona el numero de filas que quieras para la matriz: ";
    cin >> rows;
    cout << "Selecciona el numero de columnas que quieres para la matriz: ";
    cin >> columns;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }
    
    for (int i = 0; i<rows; i++){
        cout << matrix[i][i];
    }



}

