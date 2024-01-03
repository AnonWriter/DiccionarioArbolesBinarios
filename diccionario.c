#include "./TADArbol_bin.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hacer un árbol binario de búsqueda
// Usar strcmp para ubicar palabras mayores y menores
// Guardar la información con espacios, crear un lector
// ...

void LeerArchivo();
void AgregarElemento();

int main(int argn, char args[]){
    Arbol nose;
    Initialize(&nose);

    LeerArchivo(&nose, "Glosario_MATEMATICAS.txt");
}

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
        return;
    }

    //(*T)->e.n = strcmp(Parent(&(*T))->e.palabra, (*T)->e.palabra);
    e.n = strcmp(Parent(&(*T), *T)->e.palabra, (*T)->e.palabra);


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
