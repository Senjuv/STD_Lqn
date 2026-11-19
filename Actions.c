#include <stdio.h>
#include "Estructuras.h"
#include "Faces.h"

int Menu() {
    printf("---- Bienvenido al ArcadeChallenge ---- \n\n");
    int i;
    printf("[1] Registrar participante\n");
    printf("[2] Mostrar todos los usuarios\n");
    printf("[3] Salir del programa\n");
    printf("Seleccione una de las opciones: ");
    scanf("%d", &i);
    return i;
}

int fRango(int n) {
    return (!n>=0);
}

void SecuencialL(Lista *l, int id) {
    Participante *nvo = l->inicio;
    if (nvo == NULL) {
        printf("Ocurrio un error\n");
    }
    while (nvo !=  NULL) {
        if (nvo->ID == id) {
            printf("---------------------------------------\n");
            printf("Usuario encontrado: \n");
            printf("Nombre: %s\n", nvo->nombre);
            printf("Alias: %s\n", nvo->Alias);
            printf("Carrera %s\n", nvo->Carrera);
            printf("Puntuaciones: %d\n", nvo->Puntuacion);
            printf("Estado: %d\n", nvo->Estado);
            return;
        }
        nvo = nvo->sig;
    }
}

int idUnique(Lista *l, int id) {
    if (listaVacia(l)) {
        printf("La lista esta vacia\n");
    }
    if (fRango(id)) {
        printf("El id no existe, debe ser mayor o igual a 0\n");
    }
    Participante *nvo = l->inicio;
    if (nvo == NULL) {
        printf("Ocurrio un error\n");
    }
    while (nvo  !=  NULL) {

    }
}