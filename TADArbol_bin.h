/*
TADArbol.h
Librería de funciones para la estructura de datos árbol.

Autor: Carlos Adiel González Gutiérrez
Fecha: 23 de diciembre de 2023.
*/

#ifndef _TADARBOL_BIN_H_
#define _TADARBOL_BIN_H_

#define true 1
#define false 0

// Redefinimos el tipo de datos char a bool para fines de comodidad.
typedef char bool;

// Definimos un elemento como una estructura representando cualquier cosa.
typedef struct element{
    char c;
    int n;
    char palabra[101];
    char definicion[251];
} element;

// Definimos un nodo para el árbol binario como una estructura que contiene punteros a otra estructura de su tipo.
typedef struct nodo{
    struct nodo *izquierda;
    struct nodo *derecha;
    element e;
} nodo;

// Definimos la estructura árbol como la raíz.
/*typedef struct arbol{
    nodo *raiz;
} Arbol;
*/


typedef nodo* Arbol;

// Definimos el puntero a un nodo, que es la dirección de memoria del mismo como una posición.
typedef nodo* position;

// OPERACIONES DE CONSTRUCCION

/* Initialize(Arbol *T): Inicializa la estructura del árbol para su posterior implementación.
    - Arbol *T - Un puntero al árbol que vamos a inicializar.
*/
void Initialize(Arbol *T);

/* Destroy(Arbol *T): Elimina el árbol junto con todas sus ramas hasta la raíz.
    - Arbol *T - Un puntero al árbol que vamos a destruir.
*/
void Destroy(Arbol *T);

// OPERACIONES DE POSICIONAMIENTO Y BUSQUEDA

/* Root(Arbol *T): Retorna la posición de la raíz del árbol.
    - Arbol *T - Un puntero a la estructura del árbol.
*/
position Root(Arbol *T);

/* Parent(Arbol *T, position p): Retorna la posición del padre de un nodo en el árbol T.
    - Arbol *T      - Un puntero a la estructura del árbol.
    - position p    - Una posición que representa la dirección de memoria del nodo.
*/
position Parent(Arbol *T, position p);

/* RigthSon(Arbol *T, position p): Retorna la posición del subárbol derecho de un nodo en el árbol T.
    - Arbol *T      - Un puntero a la estructura del árbol.
    - position p    - Una posición que representa la dirección de memoria del nodo.
*/
position RightSon(Arbol *T, position p);

/* LeftSon(Arbol *T, position p): Retorna la posición del subárbol izquierdo de un nodo en el árbol T.
    - Arbol *T      - Un puntero a la estructura del árbol.
    - position p    - Una posición que representa la dirección de memoria del nodo.
*/
position LeftSon(Arbol *T, position p);

/* LeftSon(Arbol *T, position p): Retorna la posición del nodo que contiene al elemento e.
    - Arbol *T      - Un puntero a la estructura del árbol.
    - element e     - Un elemento a buscar en el árbol.
*/
position Search(Arbol *T, element e);

//OPERACIONES DE CONSULTA

/* IsEmpty(Arbol *T): Retorna falso o verdadero al determinar si el árbol está vacío o no.
    - Arbol *T - Un puntero a la estructura del árbol.
*/
bool IsEmpty(Arbol *T);

/* NullNode(Arbol *T, position p): Determina si el nodo con posición p es válido o es nulo retornando un booleano.
    - Arbol *T      - Un puntero a la estructura del árbol.
    - position p    - Una posición que representa la dirección de memoria del nodo.
*/
bool NullNode(Arbol *T, position p);

/* ReadNode(Arbol *T, position p): Retorna el elemento encontrado en el nodo del árbol T con poisición p.
    - Arbol *T      - Un puntero a la estructura del árbol.
    - position p    - Una posición que representa la dirección de memoria del nodo.
*/
element ReadNode(Arbol *T, position p);

//OPERACIONES DE MODIFICACION

/* NewRightSon(Arbol *T, position p): Crea un nuevo subárbol derecho en el nodo con posición p y le asigna un elemento e.
    - Arbol *T      - Un puntero a la estructura del árbol.
    - position p    - Una posición que representa la dirección de memoria del nodo.
    - element e     - El elemento a ser ingresado en el nodo.
*/
void NewRightSon(Arbol *T, position p, element e);

/* NewLeftSon(Arbol *T, position p, element e): Crea un nuevo subárbol izquierdo en el nodo con posición p y le asigna un elemento e.
    - Arbol *T      - Un puntero a la estructura del árbol.
    - position p    - Una posición que representa la dirección de memoria del nodo.
    - element e     - El elemento a ser ingresado en el nodo.
*/
void NewLeftSon(Arbol *T, position p, element e);

/* DeleteRightSon(Arbol *T, position p, element e): Elimina el subárbol derecho del nodo en la posición p junto con todos sus subárboles.
    - Arbol *T      - Un puntero a la estructura del árbol.
    - position p    - Una posición que representa la dirección de memoria del nodo.
*/
void DeleteRightSon(Arbol *T, position p);

/* DeleteLeftSon(Arbol *T, position p): Elimina el subárbol izquierdo del nodo en la posición p junto con todos sus subárboles.
    - Arbol *T      - Un puntero a la estructura del árbol.
    - position p    - Una posición que representa la dirección de memoria del nodo.
*/
void DeleteLeftSon(Arbol *T, position p);

/* DeleteRightSon(Arbol *T, position p): Elimina el nodo en la posición p junto con todos sus subárboles.
    - Arbol *T      - Un puntero a la estructura del árbol.
    - position p    - Una posición que representa la dirección de memoria del nodo.
*/
void DeleteNode(Arbol *T, position p);

/* ReplaceNode(Arbol *T, position p, element e): Reemplaza el elemento del nodo en la posición p con el nuevo elemento e.
    - Arbol *T      - Un puntero a la estructura del árbol.
    - position p    - Una posición que representa la dirección de memoria del nodo.
    - element e     - El elemento a ser ingresado en el nodo.
*/
void ReplaceNode(Arbol *T, position p, element e);

#endif