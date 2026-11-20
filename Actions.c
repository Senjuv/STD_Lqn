#include <stdio.h>
#include "Estructuras.h"
#include "Faces.h"

int Menu() {
    printf("---- Bienvenido al ArcadeChallenge ---- \n\n");
    int i;
    printf("[1] Registrar participante\n");
    printf("[2] Desregistrar usuario\n");
    printf("[3] Mostrar todos los usuarios\n");
    printf("[4] Salir del programa\n");
    printf("Seleccione una de las opciones: ");
    scanf("%d", &i);
    return i;
}

int fRango(int n) {
    return (n>=0);
}

int SecuencialL(Lista *l, int id, int f) {
    Participante *nvo = l->inicio;

    while (nvo !=  NULL) {
        if (nvo->ID == id) {
            if (f==0) {
                printf("---------------------------------------\n");
                printf("Usuario encontrado: \n");
                printf("Nombre: %s\n", nvo->nombre);
                printf("Alias: %s\n", nvo->Alias);
                printf("Carrera %s\n", nvo->Carrera);
                printf("Puntuaciones: %d\n", nvo->Puntuacion);
                printf("Estado: %d\n", nvo->Estado);
            }
            return 0;
        }
        nvo = nvo->sig;
    }
    return 1;
}

int idUnique(Lista *l, int id) {
    if (!fRango(id)) {
        printf("El id no existe, debe ser mayor o igual a 0\n");
        return 1;
    }
    if (!SecuencialL(l, id, 1)) {
        printf("El id ya se encuentra registrado\n ");
        return 1;
    }
    return 0;
}