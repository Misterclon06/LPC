#include <stdio.h>
#include <stdlib.h>
#include "../nodo/nodo.h"
#include <stdbool.h>

#ifndef cola_h
#define cola_h

typedef struct {

	nodo *inicio;
    nodo *final;
	int longitud;

}cola;


// Operaciones básicas de la cola
void cola_crear(cola *x);
void cola_encolar(cola *x, dato dato);
dato cola_desencolar(cola *x);
void cola_print(cola *x);
int cola_size(cola *x);
bool cola_esVacia(cola *x);

// Funciones de consulta y búsqueda
int cola_count(cola *x, dato dato);
int cola_posicion(cola *x, dato dato);
bool cola_contiene(cola *x, dato dato);
dato cola_frente(cola *x);
dato cola_final(cola *x);

// Operaciones avanzadas y utilidades
void cola_destruir(cola *x);
void cola_copiar(cola *origen, cola *copia);
cola cola_concatenar(cola *x, cola *y);
void cola_encolar_array(cola *destino, dato array[], int tam);
void cola_rotacionar(cola *x, int n);

#endif