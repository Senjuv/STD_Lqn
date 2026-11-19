// #include "Estructuras.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
//
// typedef struct Cola {
//     struct Cola *sig;
//     struct Participante *frente;
//     struct Participante *final;
// } Cola;
//
// void incializar(Cola *c) {
//     c->frente = NULL;
//     c->final = NULL;
// }
//
// int colaVacia(Cola *c) {
//     return (c->frente == NULL);
// }
//
// void enqueue(Cola *c, Participante p) {
//     Participante *nvo = (Participante*)malloc(sizeof(nvo));
//     if (nvo != NULL) {
//         printf("Ocurrio un error al preparar la memoria");
//     }
//
//     nvo->ID = p.ID;
//     strcpy(nvo->nombre, p.nombre);
//     strcpy(nvo->Alias, p.Alias);
//     strcpy(nvo->Carrera, p.Carrera);
//     nvo->Puntuacion = p.Puntuacion;
//     nvo->Estado  = 1;
//     nvo->sig = NULL;
//
//     if (colaVacia(c)) {
//         c->frente = nvo;
//         c->final = nvo;
//     }else {
//         c->final->sig = nvo;
//         c->final = nvo;
//     }
//     printf("El participante fue encolado con exito...");
// }
//
//
//
