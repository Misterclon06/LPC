#include <stdio.h>
#include <stdlib.h>
#include "../nodo/nodo.h"
#include <stdbool.h>

#ifndef pila_h
#define pila_h

typedef struct {

	nodo *cabecera;
	int longitud;

}pila;

// Operaciones básicas de la pila
void pila_crear(pila *x);
void pila_apilar(pila *x, dato dato);
dato pila_desapilar(pila *x);
dato pila_top(pila *x);
bool pila_esVacia(pila *x);
int pila_size(pila *x);
void pila_clear(pila *x);

// Operaciones de impresión y copia
void pila_print(pila *x);
pila pila_copy(pila *x);
void pila_reverse(pila *x);

// Operaciones con arrays
void pila_apilar_array(pila *x, dato array[], int size);
pila array_to_pila(dato array[], int size);

// Operaciones entre pilas
void pila_extender(pila *x, pila *y);
void pila_transferir(pila *origen, pila *destino);

// Operaciones de búsqueda y conteo
int pila_count(pila *x, dato valor);
int pila_posicion(pila *x, dato valor);
bool pila_contiene(pila *x, dato valor);

#endif
