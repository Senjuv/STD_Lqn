#include "Estructuras.h"
#include "Actions.h"
#include "Listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void incializarCola(Cola *c) {
     c->frente = NULL;
     c->final = NULL;
     c->contador = 0;
 }

 int colaVacia(Cola *c) {
     return (c->frente == NULL);
 }

 void enqueue(Lista *l, Cola *c, int id) {
     if (listaVacia(l)) {
        printf("La lista esta vacia");
         return;
     }
     Participante **tmp = BusquedaPJ(l,id, 1);
     if (tmp == NULL) {
        printf("No existe ningun participante con ese id.\n");
         return;
     };
     Nodo *nvo = (Nodo*)malloc(sizeof(*nvo));
     if (nvo == NULL) {
         printf("Ocurrio un error al preparar la memoria\n");
         return;
     }
     nvo->id = id;
     nvo->sig = NULL;
     if (c->frente == NULL) {
         c->frente = nvo;
         c->final = nvo;
     }else {
         c->final->sig = nvo;
         c->final = nvo;
     }
    (*tmp)->Estado = 2;
     c->contador++;
     printf("El participante fue encolado con exito...\n");
 }

 void dequeue(Lista *l, Cola *c) {
     if (listaVacia(l)) {
         printf("La lista esta vacia\n");
         return;
     }
     if (colaVacia(c)) {
         printf("La cola esta vacia\n");
         return;
     }
     Participante **tmp = BusquedaPJ(l,c->frente->id, 0);
     if (tmp == NULL) {
         printf("No existe ningun participante con ese id.\n");
         return;
     }
     Nodo *nvo = c->frente;
     Nodo *temporal = nvo->sig ;
     free(nvo);
     c->frente = temporal;
     (*tmp)->Estado = 3;
     printf("El participante %s comenzo a jugar.\n", (*tmp)->nombre);
 }



