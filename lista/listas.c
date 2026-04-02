#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listas.h"


// crea una lista vacia
void lista_crear(lista *x){

	x->cabecera = (nodo*)malloc(sizeof(nodo));

	if(x->cabecera != NULL){
		x->cabecera->siguiente = NULL;
		x->longitud = 0;
	}

}

// agrega en la ultima posicion un dato
nodo* lista_agregar(lista *x, dato dato){
	
	nodo* nuevo_nodo = lista_insert(x, dato, x->longitud);

	return nuevo_nodo;
}

// Extiende una lista con un arreglo
void lista_extend(lista *x,dato arr[], int tam){

	nodo *nodo_sig = lista_agregar(x, arr[0]);

	for (int i = 1; i < tam; i++)
	{
		nodo_sig->siguiente = crearNodo(arr[i]);
		nodo_sig = nodo_sig->siguiente;
		x->longitud++;
	}
	
}

// inserta un elemento en una posicion
nodo* lista_insert(lista *x, dato dato, int pos){

	if((pos > x->longitud) || (pos < 0)){

		printf("posicion excede la lista");

		return NULL;

	}else{

		nodo *nodo_sig = x->cabecera;

		nodo *nodo_agregado = crearNodo(dato);

		for(int i = 0; i < pos; i++){
			nodo_sig = nodo_sig->siguiente;
		}

		nodo_agregado->siguiente = nodo_sig->siguiente;
		nodo_sig->siguiente = nodo_agregado;
		
		x->longitud = x->longitud + 1;

		return nodo_agregado;
	}

}

// Elimina la primera ocurrencia del valor especificado
void lista_remove(lista *x, dato dato){

	lista_popIndex(x, lista_index(x, dato));

}

// Elimina y retorna el ultimo elemento
dato lista_pop(lista *x){
	return lista_popIndex(x, x->longitud - 1);
}

// Elimina y retorna el elemento en la posición dada
dato lista_popIndex(lista *x, int pos){

	dato eliminado;

	if ((pos > x->longitud) || (pos < 0))
	{
		printf("posicion a eliminar es invalida \n");
		return -1;
	}
	
	nodo *nodo_sig = x->cabecera;

	for(int i = 0; i < pos; i++){
		nodo_sig = nodo_sig->siguiente;
	}

	nodo *auxiliar = nodo_sig->siguiente;
	nodo_sig->siguiente = nodo_sig->siguiente->siguiente;
	x->longitud = x->longitud - 1; 

	eliminado = auxiliar->dato;

	eliminarNodo(auxiliar);

	return eliminado;

}

lista lista_slice(lista *x, int inicio, int fin){

	lista nueva;
	lista_crear(&nueva);

	if ((inicio > x->longitud) || (inicio < 0) || (fin > x->longitud) || (fin < 0) || (inicio > fin))
	{
		printf("posicion a eliminar es invalida \n");
		return nueva;
	}
	
	nodo *nodo_sig = x->cabecera;

	for(int i = 0; i < inicio; i++){
		nodo_sig = nodo_sig->siguiente;
	}

	nodo *nueva_sig = nueva.cabecera;

	for(int i = inicio; i < fin; i++){
		nueva_sig->siguiente = crearNodo(nodo_sig->siguiente->dato);
		nueva_sig = nueva_sig->siguiente;
		nueva.longitud = nueva.longitud + 1;
		nodo_sig = nodo_sig->siguiente;
	}

	return nueva;

}

// retorna el indice del dato a consultar
int lista_index(lista *x, dato dato){

		nodo *nodo_sig = x->cabecera;
		int index = -1;
		bool encontrado = false;

		while((nodo_sig->siguiente != NULL) && (encontrado == false)){

			index++;

			if(nodo_sig->siguiente->dato == dato)
			{
				encontrado = true;
			}
			
			nodo_sig = nodo_sig->siguiente;
		}
	
		if (encontrado)
		{
			return index;
		}else
		{	
			printf("no se encontro el elemento");
			return -1;
		}
			
}

// ordena el arreglo con bubble sort
void lista_sort(lista *x) {

    int i, j;
	nodo *nodo_sig;


    for (i = 0; i < x->longitud - 1; i++) {
		nodo_sig = x->cabecera;
		for (j = 0; j < x->longitud - i - 1; j++) {

			nodo_sig = nodo_sig->siguiente;

			if (nodo_sig->dato > nodo_sig->siguiente->dato) {
				swapNodo_dato(nodo_sig, nodo_sig->siguiente);
			}
		}
    }

}

// copiar una lista
void lista_copy(lista *origen, lista *copia) {

	if (!(copia == NULL))
	{
		lista_clear(copia);
	}

    nodo *actual_origen = origen->cabecera->siguiente;
    nodo *actual_copia = copia->cabecera;
    
    while (actual_origen != NULL) {
        actual_copia->siguiente = crearNodo(actual_origen->dato);
        actual_copia = actual_copia->siguiente;
        copia->longitud++;
        actual_origen = actual_origen->siguiente;
    }
}

// concatenar dos listas y regresa una nueva
lista lista_concat(lista *x, lista *y) {

    lista nueva;
	lista_crear(&nueva);
    nodo *actual_nueva = nueva.cabecera;

    nodo *sig_x = x->cabecera->siguiente;
    while (sig_x != NULL) {
        actual_nueva->siguiente = crearNodo(sig_x->dato);
        actual_nueva = actual_nueva->siguiente;
        nueva.longitud++;
        sig_x = sig_x->siguiente;
    }

    nodo *sig_y = y->cabecera->siguiente;
    while (sig_y != NULL) {
        actual_nueva->siguiente = crearNodo(sig_y->dato);
        actual_nueva = actual_nueva->siguiente;
        nueva.longitud++;
        sig_y = sig_y->siguiente;
    }

    return nueva;
}

// invertir lista
void lista_reverse(lista *x){

	nodo *anterior = NULL, *actual = x->cabecera->siguiente, *siguiente = NULL;
		while (actual != NULL) {
			siguiente = actual->siguiente;
			actual->siguiente = anterior;
			anterior = actual;
			actual = siguiente;
		}
		x->cabecera->siguiente = anterior;

}

// intercambia dos elementos de la lista
void lista_intercambiar(lista *x, int pos1, int pos2){
	if ((pos1 > x->longitud) || (pos1 < 0) || (pos2 > x->longitud) || (pos2 < 0))
	{
		printf("posicion a eliminar es invalida \n");
	}else{

		nodo *nodo_sig = x->cabecera;

		for(int i = 0; i < pos1; i++){
			nodo_sig = nodo_sig->siguiente;
		}

		nodo *nodo_pos1 = nodo_sig->siguiente;

		nodo_sig = x->cabecera;

		for(int i = 0; i < pos2; i++){
			nodo_sig = nodo_sig->siguiente;
		}

		nodo *nodo_pos2 = nodo_sig->siguiente;

		swapNodo_dato(nodo_pos1, nodo_pos2);
		
	}
	
}

// cuenta la cantidad de dato con concurrencias del dato a consultar
int lista_count(lista *x, dato dato){
	
		nodo *nodo_sig = x->cabecera;
		int concurrencias = 0;

		while(nodo_sig->siguiente != NULL){
	
			if(nodo_sig->siguiente->dato == dato)
			{
				concurrencias++;
			}
			
			nodo_sig = nodo_sig->siguiente;

		}
	
		return concurrencias;
}

// busca el valor maximo de la lista
dato lista_max(lista *x){

	dato maximo = x->cabecera->siguiente->dato;
	nodo *nodo_sig = x->cabecera->siguiente;

	while(nodo_sig != NULL){

		if(nodo_sig->dato > maximo)
		{
			maximo = nodo_sig->dato;
		}
		
		nodo_sig = nodo_sig->siguiente;

	}
	return maximo;

}

// busca el valor minimo de la lista
dato lista_min(lista *x){

	dato minimo = x->cabecera->siguiente->dato;
	nodo *nodo_sig = x->cabecera->siguiente;

	while(nodo_sig != NULL){

		if(nodo_sig->dato < minimo)
		{
			minimo = nodo_sig->dato;
		}
		
		nodo_sig = nodo_sig->siguiente;

	}
	return minimo;

}

// suma los elementos de la lista
dato lista_sum(lista *x){

	dato suma = 0;
	nodo *nodo_sig = x->cabecera->siguiente;

	while(nodo_sig != NULL){

		suma = suma + nodo_sig->dato;
		
		nodo_sig = nodo_sig->siguiente;

	}
	return suma;

}

// convierte un arreglo a una lista
lista arreglo_a_lista(dato arr[], int tam){

	lista nueva;
	lista_crear(&nueva);
	
	lista_extend(&nueva, arr, tam);

	return nueva;
	
}

// limpia la lista
void lista_clear(lista *x) {
    if (x == NULL) return;
    
    nodo *actual = x->cabecera->siguiente;
    nodo *siguiente;
    
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    
    x->cabecera->siguiente = NULL;
    x->longitud = 0;
}

// confirma si la lista esta vacia
bool lista_EsVacia(lista *x){

	if ((x->longitud == 0) || (x == NULL))
	{
		return true;
	}
	
	return false;
}

// muestra por pantalla el tamaño de la lista
int lista_size(lista *x){
	
	if (x == NULL)
	{
		return 0;
	}
	
	return x->longitud;
}

// confirma si un dato pertenece a la lista
bool lista_pertenece(lista *x, dato dato){

	nodo *nodo_sig = x->cabecera;

	while(nodo_sig->siguiente != NULL){

		if(nodo_sig->siguiente->dato == dato)
		{
			return true;
		}
		
		nodo_sig = nodo_sig->siguiente;

	}

	return false;
}

// confirma si dos listas son iguales
bool lista_igual(lista *x, lista *y){

	if (x->longitud != y->longitud)
	{
		return false;
	}

	nodo *nodo_sig_x = x->cabecera;
	nodo *nodo_sig_y = y->cabecera;

	while(nodo_sig_x->siguiente != NULL){

		if(nodo_sig_x->siguiente->dato != nodo_sig_y->siguiente->dato)
		{
			return false;
		}
		
		nodo_sig_x = nodo_sig_x->siguiente;
		nodo_sig_y = nodo_sig_y->siguiente;

	}

	return true;
}

// consulta el dato en la posicion dada
dato lista_get(lista *x, int pos){
	
	if ((pos > x->longitud) || (pos < 0))
	{
		printf("posicion a consultar es invalida \n");
		return -1;
	}
	
	nodo *nodo_sig = x->cabecera;

	for(int i = 0; i < pos; i++){
		nodo_sig = nodo_sig->siguiente;
	}

	return nodo_sig->siguiente->dato;
}


// muestra la lista por pantalla
void lista_print(lista *x){

	nodo *nodo_sig = x->cabecera;

	printf("[ ");

	while(nodo_sig->siguiente != NULL){
		printf("%d ", nodo_sig->siguiente->dato);
		nodo_sig = nodo_sig->siguiente;
	}

	printf("]\n");

}


