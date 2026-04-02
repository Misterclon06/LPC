#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"


// Crea una pila vacía
void pila_crear(pila *x){

	x->cabecera = NULL;
	x->longitud = 0;
}

// Agrega un elemento al tope de la pila
void pila_apilar(pila *x, dato dato){

	nodo *nodo_ant = x->cabecera;

	nodo *nodo_agregado = crearNodo(dato);

	x->cabecera = nodo_agregado;

	x->cabecera->siguiente = nodo_ant;
	x->longitud++;
}

// desapila el elemento en el tope de la pila y lo devuelve
dato pila_desapilar(pila *x){

	if (x->longitud == 0)
	{
		printf("la pila esta vacia \n");

		return -1;
	}else{

		nodo *nodo_ant = x->cabecera->siguiente;
		dato dato_eliminado = x->cabecera->dato;

		eliminarNodo(x->cabecera);

		x->cabecera = nodo_ant;

		x->longitud--;

		return dato_eliminado;
	}
}

// devuelve el elemento en el tope de la pila sin desapilarlo
dato pila_top(pila *x){

	if (x->longitud == 0)
	{
		printf("la pila esta vacia \n");
		return -1; 
	}else{
		return x->cabecera->dato;
	}
}

// devuelve el número de elementos en la pila
int pila_size(pila *x){
	return x->longitud;
}

// extiende la pila x con los elementos de la pila y (la pila y queda vacía)
void pila_extender(pila *x, pila *y){

	if (y->longitud == 0)
	{
		printf("la pila a extender esta vacia \n");
	}else{
		
		while (y->longitud > 0){
			pila_apilar(x, pila_desapilar(y));
		}

	}
}

// limpia la pila eliminando todos sus elementos
void pila_clear(pila *x){

	while (x->longitud > 0)
	{
		pila_desapilar(x);
	}
}

// transfiere todos los elementos de la pila origen a la pila destino (la pila origen queda vacía)
void pila_transferir(pila *origen, pila *destino) {
	while (!pila_esVacia(origen)) {
		pila_apilar(destino, pila_desapilar(origen));
	}
}

// cuenta cuántas veces aparece un valor específico en la pila
int pila_count(pila *x, dato valor) {
	int count = 0;
	pila pila_auxiliar;
	pila_crear(&pila_auxiliar);

	pila_transferir(x, &pila_auxiliar);
	while (!pila_esVacia(&pila_auxiliar)) {
		dato elemento = pila_desapilar(&pila_auxiliar);
		if (elemento == valor) {
			count++;
		}
		pila_apilar(x, elemento); 
	}
	return count;
}

// devuelve la posicion de la primera aparición de un valor específico en la pila, o -1 si no se encuentra
int pila_posicion(pila *x, dato valor) {
	int index = 0;
	bool encontrado = false;
	pila pila_auxiliar;
	pila_crear(&pila_auxiliar);

	pila_transferir(x, &pila_auxiliar);
	while (!pila_esVacia(&pila_auxiliar) && !encontrado) {
		dato elemento = pila_desapilar(&pila_auxiliar);
		if (elemento == valor) {
			encontrado = true;
		}
		pila_apilar(x, elemento); 
		index++;
	}
	if (!encontrado) {
		printf("el elemento no se encuentra en la pila \n");
		return -1; 
	}
	return index;
}

// devuelve true si la pila contiene un valor específico, false en caso contrario
bool pila_contiene(pila *x, dato valor) {
	bool encontrado = false;
	pila pila_auxiliar;
	pila_crear(&pila_auxiliar);

	pila_transferir(x, &pila_auxiliar);
	while (!pila_esVacia(&pila_auxiliar) && !encontrado) {
		dato elemento = pila_desapilar(&pila_auxiliar);
		if (elemento == valor) {
			encontrado = true;
		}
		pila_apilar(x, elemento); 
	}
	return encontrado;
}

// devuelve una nueva pila que es una copia de la pila original
pila pila_copy(pila *original) {
    pila aux, nueva;
	dato dato;
    pila_crear(&aux);
    pila_crear(&nueva);

	nodo *nodo_actual = original->cabecera;

	while (nodo_actual != NULL)
	{
		dato = nodo_actual->dato;
		nodo_actual = nodo_actual->siguiente;
		pila_apilar(&aux, dato);
	}
	
	pila_transferir(&aux, &nueva); 

    return nueva;
}

// invierte el orden de los elementos en la pila
void pila_reverse(pila *x){

	if (x->longitud == 0)
	{
		printf("la pila esta vacia \n");
	}else{
		
		pila pila_auxiliar1, pila_auxiliar2;
		pila_crear(&pila_auxiliar1);
		pila_crear(&pila_auxiliar2);
		
		pila_transferir(x, &pila_auxiliar1);
		pila_transferir(&pila_auxiliar1, &pila_auxiliar2);
		pila_transferir(&pila_auxiliar2, x);

	}
}

// apila los elementos de un array en la pila
void pila_apilar_array(pila *x, dato array[], int size){

	for (int i = 0; i < size; i++)
	{
		pila_apilar(x, array[i]);
	}
}

// crea una nueva pila a partir de un array de elementos
pila array_to_pila(dato array[], int size){

	pila nueva_pila;

	pila_crear(&nueva_pila);

	for (int i = 0; i < size; i++)
	{
		pila_apilar(&nueva_pila, array[i]);
	}

	return nueva_pila;
}

// devuelve true si la pila está vacía, false en caso contrario
bool pila_esVacia(pila *x) {
	return x->longitud == 0;
}

// imprime los elementos de la pila desde el tope hasta el fondo
void pila_print(pila *x){

	nodo *nodo_ant = x->cabecera;

	printf("/ ");

	while(nodo_ant != NULL){
		printf("%d ", nodo_ant->dato);
		nodo_ant = nodo_ant->siguiente;
	}

	printf("| \n");

}
