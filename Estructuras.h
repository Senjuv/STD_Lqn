#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

enum estado {
    Registrado = 1,
    EN_ESPERA = 2,
    JUGANDO = 3,
    FINALIZADO = 4
};

typedef struct Participante {
    int ID;
    char nombre[60];
    char Alias[30];
    char Carrera[60];
    int Puntuacion;
    enum estado Estado;
    struct Participante *sig;
} Participante;

typedef struct Lista {
    struct Participante *inicio;
    struct Participante *final;
    struct Lista *sig;
    int contador;
} Lista;

typedef struct Nodo {
    int id;
    struct Nodo *sig;
}Nodo;
typedef struct Cola {
    struct Nodo *frente;
    struct Nodo *final;
    struct Cola *sig;
} Cola;

#endif
