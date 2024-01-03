#include "./Diccionario.h"
#include <string.h>
#include <stdio.h>

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
        printf("Palabra anyadida.\n");
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

    //(*T)->e.n = strcmp(Parent(&(*T))->e.palabra, (*T)->e.palabra);
    e.n = strcmp(Parent(&(*T), *T)->e.palabra, e.palabra);

    if (e.n >= (*T)->e.n){
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
