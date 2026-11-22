 #include "Estructuras.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 void incializar(Cola *c) {
     c->frente = NULL;
     c->final = NULL;
 }

 int colaVacia(Cola *c) {
     return (c->frente == NULL);
 }

 void enqueue(Cola *c, int id) {
     Nodo *nvo = (Nodo*)malloc(sizeof(*nvo));
     if (nvo != NULL) {
         printf("Ocurrio un error al preparar la memoria");
         return;
     }
     nvo->sig = NULL;
     if (c->frente == NULL) {
         c->frente = nvo;
         c->final = nvo;
     }else {
         c->final = nvo;
         c->frente->sig = nvo;
     }
     printf("El participante fue encolado con exito...");
 }



