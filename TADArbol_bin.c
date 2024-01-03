/* TADArbol.c
Implementación de las funciones para la estructura de datos del árbol binario.

Autor: Carlos Adiel González Gutiérrez
Fecha: 23 de dicimebre de 2023.
*/
#include "TADArbol_bin.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Initialize(Arbol *T){
    (*T) = NULL;
    return;
}

void Destroy(Arbol *T){
    if (((*T)->derecha))
        Destroy(&((*T)->derecha));
    
    if (((*T)->izquierda))
        Destroy(&((*T)->izquierda));

    free(*T);

    return;
}

// OPERACIONES DE POSICIONAMIENTO Y BUSQUEDA
position Root(Arbol *T){
    return (*T);
}

position Parent(Arbol *T, position p){
    if ((*T)->derecha == p || (*T)->izquierda == p || (*T) == p){
        return (*T);
    }
    else {
        if ((*T)->izquierda)
            Parent(&((*T)->izquierda), p);
        
        if ((*T)->derecha)
            Parent(&((*T)->derecha), p);
    }
}

position RightSon(Arbol *T, position p){
    if (NullNode(T, p)){
        printf("ERROR RightSon(T,p): Posición inválida.\n");
        exit(1);
    }
    
    return p->derecha;
}

position LeftSon(Arbol *T, position p){
    if (NullNode(T, p)){
        printf("ERROR LeftSon(T,p): Posición inválida.\n");
        exit(1);
    }
    
    return p->izquierda;
}

position Search(Arbol *T, element e){
    if (!memcmp(&(*T)->e, &e, sizeof(element))){
        return (*T);
    }
    else {
        if ((*T)->izquierda)
            Search(&((*T)->izquierda), e);
        if ((*T)->derecha)
            Search(&((*T)->derecha), e);
    }
    
    printf("El elemento no fue encontrado en el arbol.\n");
    return NULL;
}

//OPERACIONES DE CONSULTA
bool IsEmpty(Arbol *T){
    return (!(*T)) ? true : false;
}

bool NullNode(Arbol *T, position p){
    bool r, l;

    if (!p)
        r = true;

    if ((*T) == p)
        r = false;

    if ((*T)->izquierda)
        r = NullNode(&((*T)->izquierda), p);

    if ((*T)->derecha)
        l = NullNode(&((*T)->derecha), p);

    return r && l; 
}

element ReadNode(Arbol *T, position p){
    if (NullNode(T, p)){
        printf("ERROR ReadNode(T,p): Posición inválida.\n");
        exit(1);
    }

    return p->e;
}

//OPERACIONES DE MODIFICACION
void NewRightSon(Arbol *T, position p, element e){
    if (IsEmpty(T)){
        *T = (Arbol)malloc(sizeof(nodo));
        (*T)->e = e;
        (*T)->derecha = NULL;
        (*T)->izquierda = NULL;
    }
    else {
        
        if (NullNode(T, p)){
            printf("ERROR NewRightSon(T,p,e): Posición inválida.\n");
            exit(1);
        }
        

        p->derecha = (nodo*)malloc(sizeof(nodo));
        p->derecha->e = e;
        p->derecha->derecha = NULL;
        p->derecha->izquierda = NULL;
    }

    return;
        
}

void NewLeftSon(Arbol *T, position p, element e){
    if (IsEmpty(T)){
        *T = (Arbol)malloc(sizeof(nodo));
        (*T)->e = e;
        (*T)->derecha = NULL;
        (*T)->izquierda = NULL;
    }
    else {
        
        if (NullNode(T, p)){
            printf("ERROR NewLeftSon(T,p,e): Posición inválida.\n");
            exit(1);
        }
        

        p->izquierda = (nodo*)malloc(sizeof(nodo));
        p->izquierda->e = e;
        p->izquierda->derecha = NULL;
        p->izquierda->izquierda = NULL;
    }

    return;
}

void DeleteRightSon(Arbol *T, position p){
    if (NullNode(T, p)){
        printf("ERROR DeleteRightSon(T,p,e): Posición inválida.\n");
        exit(1);
    }

    Arbol *A;
    (*A) = p->derecha;

    Destroy(A);
    return;
}

void DeleteLeftSon(Arbol *T, position p){
    if (NullNode(T, p)){
        printf("ERROR DeleteLeftSon(T,p,e): Posición inválida.\n");
        exit(1);
    }

    Arbol *A;
    (*A) = p->izquierda;

    Destroy(A);
    return;
}

void DeleteNode(Arbol *T, position p){
    if (NullNode(T, p)){
        printf("ERROR DeleteNode(T,p,e): Posición inválida.\n");
        exit(1);
    }

    Arbol *A;
    (*A) = p;

    Destroy(A);
    return;
}

void ReplaceNode(Arbol *T, position p, element e){
    if (NullNode(T, p)){
        printf("ERROR ReplaceNode(T,p,e): Posición inválida.\n");
        exit(1);
    }

    p->e = e;

    return;
}

