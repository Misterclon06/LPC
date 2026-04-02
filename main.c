#include <stdio.h>
#include <stdlib.h>
#include "./pilas/pilas.h"
#include "./colas/colas.h"
#include "./lista/listas.h"

// Declaraciones de funciones de prueba
void pruebas_listas();
void pruebas_pilas();
void pruebas_colas();
void pruebas_combinadas();

int main() {
    printf("========== INICIO DE PRUEBAS ==========\n\n");
    
    printf("--- PRUEBAS DE LISTAS ---\n");
    pruebas_listas();
    
    printf("\n--- PRUEBAS DE PILAS ---\n");
    pruebas_pilas();
    
    printf("\n--- PRUEBAS DE COLAS ---\n");
    pruebas_colas();
    
    printf("\n--- PRUEBAS COMBINADAS ---\n");
    pruebas_combinadas();
    
    printf("\n========== FIN DE PRUEBAS ==========\n");
    
    return 0;
}

// Pruebas de listas
void pruebas_listas() {
    lista mi_lista;
    lista_crear(&mi_lista);
    
    // Agregar elementos
    printf("Agregando elementos: 10, 20, 30, 40, 50\n");
    lista_agregar(&mi_lista, 10);
    lista_agregar(&mi_lista, 20);
    lista_agregar(&mi_lista, 30);
    lista_agregar(&mi_lista, 40);
    lista_agregar(&mi_lista, 50);
    lista_print(&mi_lista);
    
    // Insertar en posición
    printf("Insertar 25 en posición 2: ");
    lista_insert(&mi_lista, 25, 2);
    lista_print(&mi_lista);
    
    // Obtener elemento por índice
    printf("Elemento en posición 3: %d\n", lista_get(&mi_lista, 3));
    
    // Tamaño de la lista
    printf("Tamaño de la lista: %d\n", lista_size(&mi_lista));
    
    // Verificar si contiene un elemento
    printf("¿Contiene 30? %s\n", lista_pertenece(&mi_lista, 30) ? "Sí" : "No");
    printf("¿Contiene 100? %s\n", lista_pertenece(&mi_lista, 100) ? "Sí" : "No");
    
    // Eliminar elemento
    printf("Eliminar 30: ");
    lista_remove(&mi_lista, 30);
    lista_print(&mi_lista);
    
    // Pop (eliminar último)
    printf("Pop (eliminar último): %d\n", lista_pop(&mi_lista));
    lista_print(&mi_lista);
    
    // Pop por índice
    printf("Pop en índice 1: %d\n", lista_popIndex(&mi_lista, 1));
    lista_print(&mi_lista);
    
    // Intercambiar posiciones
    printf("Intercambiar posiciones 0 y 2: ");
    lista_intercambiar(&mi_lista, 0, 2);
    lista_print(&mi_lista);
    
    // Reverse
    printf("Invertir lista: ");
    lista_reverse(&mi_lista);
    lista_print(&mi_lista);
    
    // Sort
    printf("Ordenar lista: ");
    lista_sort(&mi_lista);
    lista_print(&mi_lista);
    
    // Min y Max
    printf("Mínimo: %d\n", lista_min(&mi_lista));
    printf("Máximo: %d\n", lista_max(&mi_lista));
    printf("Suma: %d\n", lista_sum(&mi_lista));
    
    // Clear
    printf("Limpiar lista: ");
    lista_clear(&mi_lista);
    printf("Lista vacía? %s\n", lista_EsVacia(&mi_lista) ? "Sí" : "No");
}

// Pruebas de pilas
void pruebas_pilas() {
    pila mi_pila;
    pila_crear(&mi_pila);
    
    // Apilar elementos
    printf("Apilando elementos: 100, 200, 300, 400, 500\n");
    pila_apilar(&mi_pila, 100);
    pila_apilar(&mi_pila, 200);
    pila_apilar(&mi_pila, 300);
    pila_apilar(&mi_pila, 400);
    pila_apilar(&mi_pila, 500);
    pila_print(&mi_pila);
    
    // Top
    printf("Top de la pila: %d\n", pila_top(&mi_pila));
    
    // Tamaño
    printf("Tamaño de la pila: %d\n", pila_size(&mi_pila));
    
    // Desapilar
    printf("Desapilar: %d\n", pila_desapilar(&mi_pila));
    pila_print(&mi_pila);
    
    // Contiene
    printf("¿Contiene 300? %s\n", pila_contiene(&mi_pila, 300) ? "Sí" : "No");
    printf("¿Contiene 600? %s\n", pila_contiene(&mi_pila, 600) ? "Sí" : "No");
    
    // Count
    printf("apilar 300 nuevamente\n");
    pila_apilar(&mi_pila, 300);
    printf("Contar 300: %d ocurrencias\n", pila_count(&mi_pila, 300));
    pila_print(&mi_pila);
    
    // Reverse
    printf("Invertir pila: ");
    pila_reverse(&mi_pila);
    pila_print(&mi_pila);
    
    // Apilar array
    dato array[] = {1000, 2000, 3000};
    printf("Apilar array [1000, 2000, 3000]: ");
    pila_apilar_array(&mi_pila, array, 3);
    pila_print(&mi_pila);
    
    // Clear
    printf("Limpiar pila: ");
    pila_clear(&mi_pila);
    printf("Pila vacía? %s\n", pila_esVacia(&mi_pila) ? "Sí" : "No");
}

// Pruebas de colas
void pruebas_colas() {
    cola mi_cola;
    cola_crear(&mi_cola);
    
    // Encolar elementos
    printf("Encolando elementos: 1, 2, 3, 4, 5\n");
    cola_encolar(&mi_cola, 1);
    cola_encolar(&mi_cola, 2);
    cola_encolar(&mi_cola, 3);
    cola_encolar(&mi_cola, 4);
    cola_encolar(&mi_cola, 5);
    cola_print(&mi_cola);
    
    // Frente y final
    printf("Frente de la cola: %d\n", cola_frente(&mi_cola));
    printf("Final de la cola: %d\n", cola_final(&mi_cola));
    
    // Tamaño
    printf("Tamaño de la cola: %d\n", cola_size(&mi_cola));
    
    // Desencolar
    printf("Desencolar: %d\n", cola_desencolar(&mi_cola));
    cola_print(&mi_cola);
    
    // Contiene
    printf("¿Contiene 3? %s\n", cola_contiene(&mi_cola, 3) ? "Sí" : "No");
    printf("¿Contiene 10? %s\n", cola_contiene(&mi_cola, 10) ? "Sí" : "No");
    printf("donde esta 1? %d\n", cola_posicion(&mi_cola, 1));
    
    // Count
    printf("encolar 3 nuevamente\n");
    cola_encolar(&mi_cola, 3);
    printf("Contar 3: %d ocurrencias\n", cola_count(&mi_cola, 3));
    cola_print(&mi_cola);
    
    // Rotacionar
    printf("Rotar 2 posiciones: ");
    cola_rotacionar(&mi_cola, 2);
    cola_print(&mi_cola);
    
    // Encolar array
    dato array[] = {100, 200, 300};
    printf("Encolar array [100, 200, 300]: ");
    cola_encolar_array(&mi_cola, array, 3);
    cola_print(&mi_cola);
    
    // Destruir
    printf("Destruir cola: ");
    cola_destruir(&mi_cola);
    printf("Cola vacía? %s\n", cola_esVacia(&mi_cola) ? "Sí" : "No");
}

// Pruebas combinadas usando listas, pilas y colas juntas
void pruebas_combinadas() {
    printf("\n1. Invertir cola usando pila (como en tu ejemplo):\n");
    cola cola_test;
    cola_crear(&cola_test);
    pila pila_test;
    pila_crear(&pila_test);
    
    cola_encolar(&cola_test, 10);
    cola_encolar(&cola_test, 20);
    cola_encolar(&cola_test, 30);
    cola_encolar(&cola_test, 40);
    cola_encolar(&cola_test, 50);
    
    printf("Cola original: ");
    cola_print(&cola_test);
    
    int tam = cola_size(&cola_test);
    for(int i = 0; i < tam; i++) {
        pila_apilar(&pila_test, cola_desencolar(&cola_test));
    }
    
    while(!pila_esVacia(&pila_test)) {
        cola_encolar(&cola_test, pila_desapilar(&pila_test));
    }
    
    printf("Cola invertida: ");
    cola_print(&cola_test);
    cola_destruir(&cola_test);
    pila_clear(&pila_test);
    
    printf("\n2. Convertir lista a pila y a cola:\n");
    lista lista_original;
    lista_crear(&lista_original);
    
    lista_agregar(&lista_original, 5);
    lista_agregar(&lista_original, 15);
    lista_agregar(&lista_original, 25);
    lista_agregar(&lista_original, 35);
    lista_agregar(&lista_original, 45);
    
    printf("Lista original: ");
    lista_print(&lista_original);
    
    // Copiar lista a pila
    pila pila_desde_lista;
    pila_crear(&pila_desde_lista);
    for(int i = 0; i < lista_size(&lista_original); i++) {
        pila_apilar(&pila_desde_lista, lista_get(&lista_original, i));
    }
    printf("Pila desde lista: ");
    pila_print(&pila_desde_lista);
    
    // Copiar lista a cola
    cola cola_desde_lista;
    cola_crear(&cola_desde_lista);
    for(int i = 0; i < lista_size(&lista_original); i++) {
        cola_encolar(&cola_desde_lista, lista_get(&lista_original, i));
    }
    printf("Cola desde lista: ");
    cola_print(&cola_desde_lista);
    
    lista_clear(&lista_original);
    pila_clear(&pila_desde_lista);
    cola_destruir(&cola_desde_lista);
    
    printf("\n3. Verificar palíndromo usando pila y cola:\n");
    cola cola_palindromo;
    cola_crear(&cola_palindromo);
    pila pila_palindromo;
    pila_crear(&pila_palindromo);
    
    dato numeros[] = {1, 2, 3, 2, 1};
    for(int i = 0; i < 5; i++) {
        cola_encolar(&cola_palindromo, numeros[i]);
        pila_apilar(&pila_palindromo, numeros[i]);
    }
    
    bool es_palindromo = true;
    for(int i = 0; i < 5; i++) {
        if(cola_desencolar(&cola_palindromo) != pila_desapilar(&pila_palindromo)) {
            es_palindromo = false;
            break;
        }
    }
    
    printf("La secuencia {1,2,3,2,1} %s un palíndromo\n", es_palindromo ? "es" : "no es");
    
    cola_destruir(&cola_palindromo);
    pila_clear(&pila_palindromo);
}