#include <stdio.h>
#include "Estructuras.h"
#include "Faces.h"
#include <string.h>
#include <stdlib.h>
#include "Colas.h"
#include "Pilas.h"

//funcion que muestra el menu de opciones
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
    printf("[9] Terminar el juego\n");
    printf("[10] Salir del programa\n");
    printf("Seleccione una de las opciones: ");
    scanf(" %d", &i);
    return i;
}
//funcion para verificar que el id ingresado sea mayor o igual a 0
int fRango(int n) {
    return (n>=0);
}
//funcion que muestra el menu de modificaciones, aparece cuando buscamos un participante, nos permite modificar los datos del participante
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
//funcion para modificar participantes, nos permite modificar algunas cosas, sin regresar al menu
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
//para modificar los participantes, espera un participante como puntero doble y uno como puntero, de esta forma, podemos modificar el valor del primero con el del segundo, en su misma direccion de mmria
void ModificadordeParticipantes(Participante **p, Participante *p2) {
    *p = p2;
    return;
};
//funcion de busqueda secuencial, para trabajar con colas, pilas y listas, la forma mas facil de encontrar elementos es una busqueda secuencial, aunque no es tan eficiente, es mas sencillo
//por lo tanto, en este programa tiene varias funciones, con validaciones
int SecuencialL(Lista *l, int id, int f) {
    //declaramos e inicializamos un puntero con el puntero al inico de la lista
    Participante *nvo = l->inicio;
    if (nvo == NULL) {
        //notificamos si hay errores
        printf("Ocurrio un error.\n");
        return 0;
    }
    // declaramos un puntero temporal;
    Participante *tmp = NULL;
    int i;
    //recorre toda la lista, participante por participante
    while (nvo !=  NULL) {
        //si encuentra un id igual al que se ingreso, nos retorna 0, true en booleano, para utilizar la funcion en ifs
        if (nvo->ID == id) {
            //para mostrar los datos, ponemos una comprobacion, si la variable f es igual a 0, esto tiene el proposito de encontrar participantes para modificar observarlos o poder modificar sus valoress
            if (f==0) {
                printf("---------------------------------------\n");
                printf("Usuario encontrado: \n");
                printf("Nombre: %s\n", nvo->nombre);
                printf("Alias: %s\n", nvo->Alias);
                printf("Carrera %s\n", nvo->Carrera);
                printf("Puntuaciones: %d\n", nvo->Puntuacion);
                printf("Estado: %d\n\n", nvo->Estado);
                //minimenu de modificacopmes
                    printf("--- [1] Modificar informacion ----\n");
                    printf("--- [2] Salir ---\n");
                    scanf(" %d", &i);
                    switch (i) {
                        case 1:
                            //funciones utilizadas anteriormente
                            tmp = Mod(nvo);
                            //funcion que ambia los valores de los punteros
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
//funcion que valida que un id ingresado sea unico, junta la funcionalidad de dos funciones, para ahorrarnos un paso jaja
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
//funcion de ordenamiento burbuja (si modifica el orden de la lista)
void OrdB(Lista *l, int op){
    //validamos si la lista esta vacia
    if (listaVacia(l)) {
        printf("la lista esta vacia\n");
        return;
    }
    //generamos 2 punteros, para almacenar los valores
    Participante *aux;
    Participante *sig;
    Participante temp;
    //variable pra guardar los cambios en las iteraciones
    int camb;
    //do, para recorrer el bucle almenos unavez
    do{
        //en cada iteracion ponemos los movimietnos en 0
        camb = 0;
        //uno de los punteros almacena el valor del inicio de la lista
        aux = l -> inicio;
        //while para recorrer toda la lista
        while (aux->sig !=NULL){
            //En cada iteracion guardamos el valor siguiente al que estamos posicionados
            sig = aux->sig;
            //si el valor dle id en el que estamos posicionados es mayor que el id siguiente, hacemos un cambio
            if (aux->ID > sig->ID){
                //guardamos dato por dato, los datos de la poscion en la que estamos se guardan en una estructura normal.
                temp.ID = aux->ID;
                aux->ID = sig->ID;
                //a la posicion siguiente se le ingresan los datos
                sig->ID = temp.ID;
                //esto mismo por cada atributo
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
//busqueda de participantes jugando
Participante **BusquedaPJ(Lista *l, int id, int f) {
    //validamos que la lista no este vacia
    if (listaVacia(l)) {
        printf("la lista esta vacia\n");
        return NULL;
    }
    //buscamos que el id exista
    if (SecuencialL(l, id, 1)) {
        printf("El id no existe.\n");
        return NULL;
    }
    //guardamos un doble puntero que almacena la direccion de memoria de del puntero de inicio en la lista
    Participante **aux = &l->inicio;
    //while para recorrer los elementos
    while (aux != NULL) {
        //si encontramos un elemento con id diferente al que buscamos y ya tiene el estado 3, nos retorna
         if ((*aux)->ID != id && (*aux)->Estado == 3) {
             printf("Ya hay un usuario jugando.\n");
             return NULL;
             //sirve para retornar el puntero del participante buscado, por eso la validacion f. nos ayuda a la funcion de desencolamiento
         }else if ((*aux)->ID == id && (*aux)->Estado == 2 && f==0) {
            return aux;
             //sirve para verificar si el participante ya se encuentra jugando
         }else if ((*aux)->ID == id && (*aux)->Estado == 2) {
            printf("El participante ya esta en la cola de espera\n");
            return NULL;
             //sirve para retornar el valor del participante, es para la encolar el participante
         }else if ((*aux)->ID == id && (*aux)->Estado == 1) {
            return aux;
         }
        //guardamos el valor almacenado en la siguiente direccion de memoria
        aux = &((*aux)->sig);
    }
    //retorno NULL por si acaso, un caso especial que no retorne en ninguna de las anteriores
    return NULL;
}
//Busqueda que nos ayuda a encontrar al participante que esta jugando, ayuda la funcion de finalizar partida
Participante **BuqusquedaFP(Lista *l) {
    //validacioens
    if (listaVacia(l)) {
        printf("La lista esta vacia.\n");
        return NULL;
    }
    //declaramos e inicializamos un doble puntero, para modificar sus atributos
    Participante **aux = &l->inicio;
    if ((*aux) == NULL) {
        printf("Ocurrio un error\n");
        return NULL;
    }
    //encuentra al participante jugando
    while (aux != NULL) {
        if ((*aux)->Estado == 3) {
            return aux;
        }
        aux = &((*aux)->sig);
    }
    //return por casos especiales
    return NULL;
}
//funcion para mostrar la cola de elementos en espera
void MostarCola(Cola *c, int i) {
    //validacioens
    if (colaVacia(c)) {
        printf("La cola esta vacia.\n");
        return;
    }
    //puntero al nodo del frente
    Nodo *nvo = c->frente;
    if (nvo == NULL) {
        printf("Ocurrio un error\n");
        return;
    }
    //switch para todos los casos
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
    return;
}
//funcion de finalizr partida, recibe una pila y un participante
void finalizarP(Pila *pila, Participante **p) {
    //si el participante da un valor nulo, nos retorna
    if((*p) == NULL){
        printf("El participante esta vacio\n");
        return;
    }
    //psuh para ingresar a la pila el siguiente participante,
    push(pila, (*p)->ID, (*p)->Puntuacion, (*p)->Estado);
    //una vez agregado a la pila modificamos el valor del participante
    (*p)->Estado = 4;
}