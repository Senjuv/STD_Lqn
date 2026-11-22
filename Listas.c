#include "Estructuras.h"
#include "Actions.h"
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
        printf("Ocurrio un error al reservar la memoria\n");
        return;
    }
    if (idUnique(l, p->ID)) {
        printf("Pruebe con un id diferente\n");
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
    printf("Con un total de %d participantes.\n", l->contador);
}

void desenlistar(Lista *l, int id) {
    if (listaVacia(l)) {
        printf("La lista esta vacia\n");
    }
    Participante *Anterior = NULL, *Siguiente = NULL, *tmp = l->inicio;
    while (tmp != NULL && tmp->ID != id) {
        Anterior = tmp;
        Siguiente = tmp->sig;
        tmp = tmp->sig;
    }
    if (tmp->Estado != 1) {
        printf("En este momento no se puede desregistrar el participante\n");
        return;
    }
    if (tmp == l->inicio) {
        free(tmp);
        Siguiente = tmp->sig;
        l->inicio = Siguiente;
    }else if(tmp == l->final){
        free(tmp);
        l->final = Anterior;
        l->final->sig = NULL;
    }else{
        Anterior->sig = tmp->sig;
        free(tmp);
    }
    l->contador--;
    printf("Usuarios desregistrados con exito\n");
    printf("Con un total de %d participantes.\n", l->contador);
}
