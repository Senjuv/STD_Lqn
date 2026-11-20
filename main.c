#include <stdio.h>
#include "Actions.h"
#include "Estructuras.h"
#include "Faces.h"
#include "Listas.h"

Lista l;

void Acciones(int opt) {
    switch (opt) {
        case 1:
            printf("\nBienvenido al registro de usuarios\n");
            Participante p;
            printf("Ingrese el ID :");
            scanf("%d", &p.ID);
            printf("Ingrese el nombre del participante: ");
            scanf(" %30[^\n]", &p.nombre);
            printf("Ingrese el alias: ");
            scanf(" %30[^\n]", &p.Alias);
            printf("Ingrese la carrera: ");
            scanf(" %30[^\n]", &p.Carrera);
            enlistar(&l, &p);
            break;
        case 2:
            printf("\nBienvenido al desregistro de usuarios\n");
            int i;
            printf("Ingrese el ID : ");
            scanf(" %d", &i);
            desenlistar(&l, i);
            break;
        case 3:
            showLista(&l);
            break;
        case 4:
            OrdB(&l, 1);
            break;
        case 5:
            printf("Saliendo del programa\n");
            break;
        default:
            printf("\nEsa opcion no se encuentra disponible\n");
            break;
    }
}

int main() {
    inicializarLista(&l);
    int opt;
    do {
        opt = Menu();
        Acciones(opt);
    }while (opt != 5);
    return 0;
}