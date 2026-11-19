#include <stdio.h>
#include <string.h>
#include "Listas.h"
#include "Estructuras.h"

void showLista(Lista *l) {
    if (listaVacia(l)) {
        printf("La lista se encuentra vacia w\n");
    }
    printf("---- Participantes registrados -----\n");
    Participante *nvo = l->inicio;
    while (nvo != NULL) {
        printf("---------------------------------------\n");
        printf("Nombre: %s\n", nvo->nombre);
        printf("Alias: %s\n", nvo->Alias);
        printf("Carrera %s\n", nvo->Carrera);
        printf("Puntuaciones: %d\n", nvo->Puntuacion);
        printf("Estado: %d\n", nvo->Estado);
        nvo = nvo->sig;
    }
}
