#include <stdio.h>
#include "Estructuras.h"
#include "Faces.h"
#include <string.h>
#include <stdlib.h>
#include "Colas.h"

int Menu() {
    printf("---- Bienvenido al ArcadeChallenge ---- \n\n");
    int i;
    printf("[1] Registrar participante\n");
    printf("[2] Desregistrar usuario\n");
    printf("[3] Mostrar todos los usuarios\n");
    printf("[4] Ordenar participante por ID\n");
    printf("[5] Buscar participante\n");
    printf("[6] Solicitar turno para jugar\n");
    printf("[7] Cola de participantes\n");
    printf("[8] Pasar a jugar al siguiente participante\n");
    printf("[9] Salir del programa\n");
    printf("Seleccione una de las opciones: ");
    scanf(" %d", &i);
    return i;
}

int fRango(int n) {
    return (n>=0);
}

int MenuMod() {
    printf("\n---------- Menu de modificacion------------\n");
    int opt;
    printf("[1] Modificar nombre\n");
    printf("[2] Modificar alias\n");
    printf("[3] Modificar carrera\n");
    printf("[4] Salir del menu de modificacion\n");
    fflush(stdin);
    scanf(" %d", &opt);
    return opt;
}

Participante *Mod(Participante *p) {
    int opt = 0;
    do{
        opt = MenuMod();
        switch (opt) {
            case 1:
                printf("Ingrese el nombre del usuario: ");
                scanf(" %30[^\n]", p->nombre);
                break;
            case 2:
                printf("Ingrese el alias del usuario: ");
                scanf(" %30[^\n]", p->Alias);
                break;
            case 3:
                printf("Ingrese el carrera del usuario: ");
                scanf(" %30[^\n]", p->Carrera);
                break;
            case 4:
                printf("Saliendo al menu principal\n");
                break;
            default:
                printf("Seleccione unas de las opciones disponibles: ");
                break;
        }
    }while (opt !=4);
    return p;
}

void ModificadordeParticipantes(Participante **p, Participante *p2) {
    *p = p2;
    printf("\nsi\n");
};

int SecuencialL(Lista *l, int id, int f) {
    Participante *nvo = l->inicio;
    Participante *tmp;
    int i;
    while (nvo !=  NULL) {
        if (nvo->ID == id) {
            if (f==0) {
                printf("---------------------------------------\n");
                printf("Usuario encontrado: \n");
                printf("Nombre: %s\n", nvo->nombre);
                printf("Alias: %s\n", nvo->Alias);
                printf("Carrera %s\n", nvo->Carrera);
                printf("Puntuaciones: %d\n", nvo->Puntuacion);
                printf("Estado: %d\n\n", nvo->Estado);
                    printf("--- [1] Modificar informacion ----\n");
                    printf("--- [2] Salir ---\n");
                    scanf(" %d", &i);
                    switch (i) {
                        case 1:
                            tmp = Mod(nvo);
                            ModificadordeParticipantes(&nvo, tmp);
                            break;
                        case 2:
                            printf("Regresando al menu principal \n");
                            break;
                        default:
                            printf("Esa opcion no esta disponible.\n");
                            break;
                    }
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

void OrdB(Lista *l, int op){
    Participante *aux;
    Participante *sig;
    Participante temp;
    int camb;
    if (listaVacia(l)) {
        printf("la lista esta vacia\n");
        return;
    }
    do{
        camb = 0;
        aux = l -> inicio;
        while (aux->sig !=NULL){
            sig = aux->sig;
            if (aux->ID > sig->ID){
                temp.ID = aux->ID;
                aux->ID = sig->ID;
                sig->ID = temp.ID;

                strcpy(temp.nombre, aux->nombre);
                strcpy(aux->nombre, sig->nombre);
                strcpy(sig->nombre, temp.nombre);

                strcpy(temp.Alias, aux->Alias);
                strcpy(aux->Alias, sig->Alias);
                strcpy(sig->Alias, temp.Alias);

                strcpy(temp.Carrera, aux->Carrera);
                strcpy(aux->Carrera, sig->Carrera);
                strcpy(sig->Carrera, temp.Carrera);

                temp.Puntuacion = aux->Puntuacion;
                aux->Puntuacion = sig->Puntuacion;
                sig->Puntuacion = temp.Puntuacion;

                temp.Estado = aux->Estado;
                aux->Estado = sig->Estado;
                sig->Estado = temp.Estado;

                camb = 1;

            }
            aux = aux->sig;
        }
    } while (camb);
}

Participante **BusquedaPJ(Lista *l, int id, int f) {
    if (SecuencialL(l, id, 1)) {
        printf("El id no existe.\n");
        return NULL;
    }
    Participante **aux = &l->inicio;
    while (aux != NULL) {
        if ((*aux)->ID == id && (*aux)->Estado == 2 && f==0) {
            return aux;
        }else if ((*aux)->ID == id && (*aux)->Estado == 2) {
            printf("El participante ya esta en la cola de espera\n");
            return NULL;
        }else if ((*aux)->ID == id && (*aux)->Estado == 1) {
            return aux;
        }
        aux = &((*aux)->sig);
    }
}

void MostarCola(Cola *c, int i) {
    if (colaVacia(c)) {
        printf("La cola esta vacia.\n");
        return;
    }
    Nodo *nvo = c->frente;
    switch (i) {
        case 1:
            printf("El siguiente participante en jugar es: %d \n",nvo->id);
            break;
        case 2:
            printf("Cola total de participantes\n");
            while (nvo != NULL) {
                printf("Participante: %d\n", nvo->id);
                nvo = nvo->sig;
            }
            break;
        case 3:
            printf("total de personas en la cola: %d \n", c->contador);
            break;
        default:
            printf("Elija una opcion valida.\n");
            break;
    }
    free(nvo);
    return;
}