#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"

void inicializarPila(Pila *p){
	p->tope = NULL;
}

int pilaVacia(Pila *p){
	return (p->tope == NULL);
}

void push(Pila *p, int id, int puntuacion, enum estado estado){

Resul *nvo = (Resul*)
malloc(sizeof(Resul));

	if(nvo == NULL){
		printf("Error\n");
		return;
	}
	
	nvo->ID = id;
	nvo->Puntuacion = puntuacion;
	nvo->EstadoAnterior = estado;
	
	nvo->sig = p->tope;
	p->tope = nvo;
	
}

void pop(Pila *p){
	Resul *tmp;
	
	if(pilaVacia(p)){
		printf("La pila esta vacia\n");
		return;
	}
	
	tmp = p->tope;
	p->tope = tmp->sig;
	
	free(tmp);
}

void mostrarPila(Pila *p){
	Resul *aux = p->tope;
	
	if(pilaVacia(p)){
		printf("La pila se encuentra vacia\n");
		return;
	}
	
	while(aux !=NULL){
		
		printf("ID: %d\n",aux->ID);
		printf("Puntuacion: %d\n",aux->Puntuacion);
		printf("Estado anterior: %d\n",aux->EstadoAnterior);
		printf("------------------\n"); 
		
		aux = aux->sig;
	}

}
	
	

