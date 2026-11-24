
#ifndef ACTIONS_H
#define ACTIONS_H

#include "Estructuras.h"

int Menu();

int idUnique(Lista *l, int id);

void OrdB(Lista *l, int op);

int SecuencialL(Lista *l, int id, int f);

Participante **BusquedaPJ(Lista *l, int id, int f);

void MostarCola(Cola *c, int i);

void finalizarP(Pila *pila, Participante **p);

Participante **BuqusquedaFP(Lista *l);

#endif
