//
// Created by marck on 23/11/2026.
//

#ifndef PILAS_H
#define PILAS_H


#include "Estructuras.h"

void inicializarPila(Pila *p);

int pilaVacia(Pila *p);

void push(Pila *p, int id, int puntuacion, enum estado estado);

void pop(Pila *p);

void mostrarPila(Pila *p);

#endif
