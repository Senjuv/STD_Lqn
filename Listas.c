#include "Estructuras.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarLista(Lista *l) {
    l->inicio = NULL;
    l->final = NULL;
}

int listaVacia(Lista *l) {
    return (l->inicio == NULL);
}

void enlistar(Lista *l, Participante *p) {
    Participante *nvo = (Participante*)malloc(sizeof(*nvo));
    if (nvo == NULL) {
        printf("Ocurrio un error al reservar la memoria");
        return;
    }
    nvo->ID = p->ID;
    strcpy(nvo->nombre, p->nombre);
    strcpy(nvo->Carrera, p->Carrera);
    strcpy(nvo->Alias, p->Alias);
    nvo->Puntuacion = 0;
    nvo->Estado = 1;
    nvo->sig = NULL;
    if (l->inicio == NULL) {
        l->final = nvo;
        l->inicio = nvo;
    }else {
        l->final->sig = nvo;
        l->final = nvo;
    }
    l->contador++;
    printf("El participante se registro con exito.\n");
}