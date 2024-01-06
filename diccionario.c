#include "Diccionario.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void LeerArchivo(Arbol *T, char dir[]){
    printf("Cargando glosario.\n");

    FILE *glosario;
    glosario = fopen(dir, "r");

    if (!glosario){
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char linea[353];
    // poner un contador para el nivel del arbol
    int cont = 0;

    while (fgets(linea, sizeof(linea), glosario)){
        element e;

        //char palabra[101];
        //char definicion[251];
        char *aux;
        char *rest = linea;

        aux = strtok_r(rest, ":", &rest);
        strcpy(e.palabra, aux);

        aux = strtok_r(NULL, ":", &rest);
        strcpy(e.definicion, aux);

        AgregarElemento(&(*T), e);
        cont++;

    }

    fclose(glosario);
    printf("Glosario cargado. %d palabras anyadidas, nya~\n", cont);

}

void AgregarElemento(Arbol *T, element e){
    if (IsEmpty(T)){
        NewLeftSon(T, *T, e);
        (*T)->e.n = 0;
    }

    e.n = strcmp(Parent(&(*T), *T)->e.palabra, e.palabra);

    if (e.n >= (*T)->e.n){
        // agregar caso donde las palabras sean iguales
        if ((*T)->derecha)
            AgregarElemento(&((*T)->derecha), e);
        else{
            NewRightSon(T, *T, e);
        }
    }

    else if (e.n < (*T)->e.n){
        if ((*T)->izquierda)
            AgregarElemento(&((*T)->izquierda), e);
        else{
            NewLeftSon(T, *T, e);
        }
            
    }   
}

element BuscarPalabra(Arbol *T, element e){
    // caso vacio

    e.n = strcmp(Parent(T, *T)->e.palabra, e.palabra);

    if (e.n >= (*T)->e.n){
        if (!((*T)->derecha)){
            element undef;
            strcpy(undef.definicion, "Palabra no encontrada.");
            return undef;
        }

        if ((strcmp((*T)->derecha->e.palabra, e.palabra)))
            return BuscarPalabra(&((*T)->derecha), e);
        else 
            return (*T)->derecha->e;
    }

    else if (e.n < (*T)->e.n){
        if (!((*T)->izquierda)){
            element undef;
            strcpy(undef.definicion, "Palabra no encontrada.");
            return undef;
        }
        
        if ((strcmp((*T)->izquierda->e.palabra, e.palabra)))
            return BuscarPalabra(&((*T)->izquierda), e);
        else 
            return (*T)->izquierda->e; 
    }
}

void ModificarElemento(Arbol *T, element e){
    // caso vacio
    e.n = strcmp(Parent(T, *T)->e.palabra, e.palabra);

    if ((e.n >= (*T)->e.n)){
        if (!((*T)->derecha)){
            printf("Palabra no encontrada.\n");
            return;
        }
        
        if ((strcmp((*T)->derecha->e.palabra, e.palabra))){
            ModificarElemento(&((*T)->derecha), e);
        }
        else {
            memset((*T)->derecha->e.definicion, 0, sizeof((*T)->derecha->e.definicion));
            strcpy((*T)->derecha->e.definicion, e.definicion);
            return;
        }
    }
    else if ((e.n < (*T)->e.n)){
        if (!((*T)->izquierda)){
            printf("Palabra no encontrada.\n");
            return;
        }

        if ((strcmp((*T)->izquierda->e.palabra, e.palabra))){
            ModificarElemento(&((*T)->izquierda), e);
        }
        else {
            memset((*T)->izquierda->e.definicion, 0, sizeof((*T)->derecha->e.definicion));
            strcpy((*T)->izquierda->e.definicion, e.definicion);
            return;
        }
        
    }

}

nodo *EncontrarNMI(Arbol *T){
    nodo *p;

    p = *T;
    while (p->izquierda){
        p = p->izquierda;
    }

    return p;
}


void EliminarElemento(Arbol *T, element e){

    e.n = strcmp(Parent(T, *T)->e.palabra, e.palabra);

    if ((e.n >= (*T)->e.n)){
        if (!((*T)->derecha)){
            printf("Palabra no encontrada.\n");
            return;
        }
        
        if ((strcmp((*T)->derecha->e.palabra, e.palabra))){
            EliminarElemento(&((*T)->derecha), e);
        }
        else {
            if (!((*T)->derecha->derecha) && !((*T)->derecha->izquierda)){
                free((*T)->derecha);
            }
            // Si el nodo tiene un solo hijo, se sustituye por el hijo
            else if ((*T)->derecha->derecha && !((*T)->derecha->izquierda)){
                nodo *aux = (*T)->derecha;
                (*T)->derecha = (*T)->derecha->derecha;
                free(aux);
            }
            else if (!((*T)->derecha->derecha) && (*T)->derecha->izquierda){
                nodo *aux = (*T)->derecha;
                (*T)->derecha = (*T)->derecha->izquierda;
                free(aux);
            }
            else {
                // si tengo un nodo a la izquierda, seguir buscando
                nodo *aux = EncontrarNMI(&((*T)->derecha));
                (*T)->derecha->e = aux->e;
                EliminarElemento(&aux, e);
            }
        }
    }
    else if ((e.n < (*T)->e.n)){
        if (!((*T)->izquierda)){
            printf("Palabra no encontrada.\n");
            return;
        }
        
        if ((strcmp((*T)->izquierda->e.palabra, e.palabra))){
            EliminarElemento(&((*T)->izquierda), e);
        }
        else {
            if (!((*T)->izquierda->derecha) && !((*T)->izquierda->izquierda)){
                free((*T)->izquierda);
            }
            // Si el nodo tiene un solo hijo, se sustituye por el hijo
            else if ((*T)->izquierda->derecha && !((*T)->izquierda->izquierda)){
                nodo *aux = (*T)->izquierda;
                (*T)->izquierda = (*T)->izquierda->derecha;
                free(aux);
            }
            else if (!((*T)->izquierda->derecha) && (*T)->izquierda->izquierda){
                nodo *aux = (*T)->izquierda;
                (*T)->izquierda = (*T)->izquierda->izquierda;
                free(aux);
            }
            else {
                // si tengo un nodo a la izquierda, seguir buscando
                nodo *aux = EncontrarNMI(&((*T)->izquierda));
                (*T)->izquierda->e = aux->e;
                EliminarElemento(&aux, e);
            }
        }
    }
}

void PreOrden(Arbol *a){
    //
    element e;
    strcpy(e.palabra, ReadNode(a, *a).palabra);

    printf("%s - ", e.palabra);

    if ((*a)->izquierda)
        PreOrden(&((*a)->izquierda));

    if ((*a)->derecha)
        PreOrden(&((*a)->derecha));

    return;
}

void InOrden(Arbol *a){
    //
    if ((*a)->izquierda)
        InOrden(&((*a)->izquierda));

    element e;
    strcpy(e.palabra, ReadNode(a, *a).palabra);

    printf("%s - ", e.palabra);

    if ((*a)->derecha)
        InOrden(&((*a)->derecha));

    return;
}

void PostOrden(Arbol *a){
    //
    if ((*a)->izquierda)
        PostOrden(&((*a)->izquierda));

    if ((*a)->derecha)
        PostOrden(&((*a)->derecha));

    element e;
    strcpy(e.palabra, ReadNode(a, *a).palabra);

    printf("%s - ", e.palabra);

    return;
}