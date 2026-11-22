
#ifndef LISTAS_H
#define LISTAS_H

#include "Estructuras.h"

void inicializarLista(Lista *l);

void enlistar(Lista *l, Participante *p);

int listaVacia(Lista *l);

void desenlistar(Lista *l, int id);

#endif
