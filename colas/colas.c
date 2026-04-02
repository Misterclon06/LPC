#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "colas.h"

// crea una nueva cola vacía
void cola_crear(cola *x) {

    x->inicio = (nodo*)malloc(sizeof(nodo));

    if (x->inicio != NULL) {
        x->inicio->siguiente = NULL;
        
        x->final = x->inicio;
        
        x->longitud = 0;
    }
}

// agrega un nuevo elemento al final de la cola
void cola_encolar(cola *x, dato dato) {
    nodo *nuevo = crearNodo(dato);

    x->final->siguiente = nuevo; 
    x->final = nuevo;   
    x->longitud++;         
}

// elimina el elemento al frente de la cola y devuelve su valor
dato cola_desencolar(cola *x) {
    if (x->inicio == x->final){printf("la cola esta vacia, no se puede desencolar \n"); return -1;} 

    nodo *a_eliminar = x->inicio;       
    x->inicio = a_eliminar->siguiente;  
    dato dato = x->inicio->dato;         
    
    free(a_eliminar); 
    x->longitud--;                  
    return dato;
}

// devuelve el número de elementos en la cola
int cola_size(cola *x){
    return x->longitud;
}

// verifica si la cola está vacía
bool cola_esVacia(cola *x){
    return x->longitud == 0;
}

// cuenta cuántas veces aparece un valor específico en la cola
int cola_count(cola *x, dato dato){

    int contador = 0;
    nodo *nodo_sig = x->inicio;

    for(int i = 0; i < x->longitud; i++){
        
        nodo_sig = nodo_sig->siguiente;

        if (nodo_sig->dato == dato)
        {
            contador++;
        }
    }

    return contador;
}

// devuelve la posición de la primera aparición de un valor específico en la cola, o -1 si no se encuentra
int cola_posicion(cola *x, dato dato){

    int posicion = 0;
    bool encontrado = false;
    nodo *nodo_sig = x->inicio;

    while(nodo_sig->siguiente != NULL && !encontrado && 0 < x->longitud){

        nodo_sig = nodo_sig->siguiente;

        if (nodo_sig->dato == dato)
        {   
            encontrado = true;
        }
        posicion++;
    }

    if (encontrado)
    {
        return posicion;
    }else{
        return -1;
    }
    

}

// libera la cola completamente, eliminando todos sus elementos
void cola_destruir(cola *x){

    nodo *nodo_sig = x->inicio;
    
    while(nodo_sig->siguiente != NULL && x->longitud > 0)
    {
        nodo_sig = x->inicio->siguiente;
        cola_desencolar(x);
    }
}



// rota los elementos de la cola n posiciones hacia adelante
void cola_rotacionar(cola *x, int n){

    n = n % x->longitud; 

    for (int i = 0; i < n; i++) {
        dato dato_rotado = cola_desencolar(x);
        cola_encolar(x, dato_rotado);
    }
}

// devuelve el valor del elemento al frente de la cola sin eliminarlo
dato cola_frente(cola *x){
    if (x->inicio == x->final){printf("la cola esta vacia, no se puede obtener el frente \n"); return -1;} 
    return x->inicio->siguiente->dato;
}

// devuelve el valor del elemento al final de la cola sin eliminarlo
dato cola_final(cola *x){
    if (x->inicio == x->final){printf("la cola esta vacia, no se puede obtener el final \n"); return -1;} 
    return x->final->dato;
}

bool cola_contiene(cola *x, dato dato){

    bool encontrado = false;
    nodo *nodo_sig = x->inicio;

    while(nodo_sig->siguiente != NULL && !encontrado && 0 < x->longitud){

        nodo_sig = nodo_sig->siguiente;

        if (nodo_sig->dato == dato)
        {   
            encontrado = true;
        }
    }

    if (encontrado)
    {
        return encontrado;
    }else{
        return false;
    }

}

// concatena dos colas y devuelve una nueva cola con los elementos de ambas
cola cola_concatenar(cola *x, cola *y){
    cola resultado;
    cola_crear(&resultado);

    nodo *nodo_sig_x = x->inicio;
    nodo *nodo_sig_y = y->inicio;

    for(int i = 0; i < x->longitud; i++){
        nodo_sig_x = nodo_sig_x->siguiente;
        cola_encolar(&resultado, nodo_sig_x->dato);
    }

    for(int i = 0; i < y->longitud; i++){
        nodo_sig_y = nodo_sig_y->siguiente;
        cola_encolar(&resultado, nodo_sig_y->dato);
    }

    return resultado;
}

// crea una copia de la cola dada
void cola_copiar(cola *origen, cola *copia){

    if (copia->longitud > 0)
    {
        cola_destruir(copia);
        printf("cola copia destruida \n");
    }
    
    nodo *nodo_sig = origen->inicio->siguiente;

    while(nodo_sig->siguiente != NULL){
        cola_encolar(copia, nodo_sig->dato);
        nodo_sig = nodo_sig->siguiente;
    }
}

// encola los elementos de un array en la cola destino
void cola_encolar_array(cola *destino, dato array[], int tam){
    for (int i = 0; i < tam; i++)
    {
        cola_encolar(destino, array[i]);
    }
}

// imprime los elementos de la cola desde el frente hasta el final
void cola_print(cola *x){

    nodo *nodo_sig = x->inicio;

    printf("<= ");

    for(int i = 0; i < x->longitud; i++){
        nodo_sig = nodo_sig->siguiente;
        printf("%d ", nodo_sig->dato);
    }

    printf("<=\n");

}