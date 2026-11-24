#include "Estructuras.h"
#include "Actions.h"
#include "Listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//funcion para incializar la cola
 void incializarCola(Cola *c) {
     //inicializamos todo en NULL para no guardar basura
     c->frente = NULL;
     c->final = NULL;
     //almacenamos el contador en 0, para poder llear cuenta de cuantas personas se han registrado
     c->contador = 0;
 }

 int colaVacia(Cola *c) {
     //funcion para validar si la cola esta vacia
     return (c->frente == NULL);
 }
//funcion para agregar a los jugadores a la cola e espera
 void enqueue(Lista *l, Cola *c, int id) {
     //valida si la cola esta vacia
     if (listaVacia(l)) {
        printf("La lista esta vacia");
         return;
     }
     //generamos el participante como un puntero doble, este participante viene de una funcion, que valida si no hay otro registro del participante
     Participante **tmp = BusquedaPJ(l,id, 1);
     //validamos que los datos no sean nulos
     if (tmp == NULL) {
        printf("No existe ningun participante con ese id.\n");
         return;
     };
     //generamos un nodo, para la col
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
     //con participante que teniamos antes, modificamos el valor de su estado a 2
    (*tmp)->Estado = 2;
     //aumentamos en uno el contador de la col
     c->contador++;
     printf("El participante fue encolado con exito...\n");
 }
// Desencolamiento, para los participante que comienzan a jugar
 void dequeue(Lista *l, Cola *c) {
     //validaciones
     if (listaVacia(l)) {
         printf("La lista esta vacia\n");
         return;
     }
     if (colaVacia(c)) {
         printf("La cola esta vacia\n");
         return;
     }
     //esperamos nuevamente que la funcion busque el participante deseado y lo guardamos en un doble puntero
     Participante **tmp = BusquedaPJ(l,c->frente->id, 0);
     //validacion
     if (tmp == NULL) {
         printf("No existe ningun participante con ese id.\n");
         return;
     }
     //guardamos temporalmente el nodo que vamos a eliminar
     Nodo *nvo = c->frente;
     //guardamos el nodo siguiente al que eliminaremos
     Nodo *temporal = nvo->sig ;
     //eliminamos el nodo del frente
     free(nvo);
     //reasignamos el valor del frente como el nodo que le seguia
     c->frente = temporal;
     //cambiamos el estado a 3 (jugando)
     (*tmp)->Estado = 3;
     printf("El participante %s comenzo a jugar.\n", (*tmp)->nombre);
 }



