#include <stdio.h>
#include "Actions.h"
#include "Estructuras.h"
#include "Faces.h"
#include "Listas.h"
#include "Colas.h"

Lista l;
Cola c;

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
            printf("---- Busqueda de participantes ----\n");
            printf("Ingrese el ID: ");
            int id;
            scanf(" %d", &id);
            if (listaVacia(&l)) {
                printf("la lista se encuentra vacia\n");
            }else {
                SecuencialL(&l, id, 0);
            }
            break;
        case 6:
            printf("---- Ingrese el id del participante ----\n");
            int num;
            scanf(" %d", &num);
            enqueue(&l, &c, num);
            break;
        case 7:
            printf("---- Mostrar la cola de participantes ----\n");
            int j;
            printf("[1] Para ver el siguiente turno\n");
            printf("[2] Para ver todos los participantes\n");
            printf("[3] Para ver el total de participantes\n");
            printf("Seleccione una opcion: ");
            scanf(" %d", &j);
            MostarCola(&c, j);
            break;
        case 8:
            dequeue(&l, &c);
            break;
        case 9:
            printf("Saliendo del programa\n");
            break;
        default:
            printf("\nEsa opcion no se encuentra disponible\n");
            break;
    }
}

int main() {
    inicializarLista(&l);
    incializarCola(&c);
    int opt;
    do {
        opt = Menu();
        Acciones(opt);
    }while (opt != 9);
    return 0;
}