#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

// crea un nuevo nodo con el dato dado
nodo* crearNodo(dato dato){

	nodo* nuevo_nodo = (nodo*)malloc(sizeof(nodo));

	if(nuevo_nodo != NULL){
		nuevo_nodo->siguiente = NULL;
		nuevo_nodo->dato = dato;
	}

	return nuevo_nodo;

}

// Libera la memoria de un nodo dado
void eliminarNodo(nodo *n) { 
    if (n != NULL) {
        free(n); 
    }
}

// intercambia los datos de dos nodos
void swapNodo_dato(nodo *x, nodo *y) {
	if (x != NULL && y != NULL) {
		dato temp = x->dato;
		x->dato = y->dato;
		y->dato = temp;
	}
}


