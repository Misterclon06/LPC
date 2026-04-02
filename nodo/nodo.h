#include <stdio.h>
#include <stdlib.h>

#ifndef nodo_h
#define nodo_h

typedef int dato;

typedef struct nodo {

	dato dato;
	struct nodo *siguiente;

}nodo;

nodo* crearNodo(dato dato);

void eliminarNodo(nodo *n);

void swapNodo_dato(nodo *x, nodo *y);

#endif
