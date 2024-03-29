#include "./TADArbol_bin.h"
#include "./Diccionario.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(int argn, char args[]){
    Arbol diccionario;
    Initialize(&diccionario);

    char command[121] = "";

    printf(">> Diccionario con arboles binarios, version 1.1.\n");

    while (strcmp(command, "salir")){
        fgets(command, 121, stdin);
        command[strcspn(command, "\n")] = 0;

        char *func = command;
        char *argument;
        argument = strtok_r(command, " ", &func);

        if (!(strcmp(command, "cargar"))){
            LeerArchivo(&diccionario, func);
            printf("\n");
        }
        else if (!(strcmp(command, "agregar"))){
            char nueva_definicion[251];

            printf("Definicion: ");
            fgets(nueva_definicion, 250, stdin);
            nueva_definicion[strcspn(nueva_definicion, "\n")] = 0;

            element aux;
            strcpy(aux.palabra, func);
            strcpy(aux.definicion, nueva_definicion);

            AgregarElemento(&diccionario, aux);
            printf("Palabra agregada.\n\n");
        }
        if (IsEmpty(&diccionario) && strcmp(command, "salir")){
            printf("No se puede realizar esta operacion sobre un arbol vacio.\n");
            printf("\n");
        }
        else if (!(strcmp(command, "buscar"))){
            element aux;

            strcpy(aux.palabra, func);

            element def = BuscarPalabra(&diccionario, aux);

            printf("%s\n", def.definicion);
            printf("\n");
        }
        else if (!(strcmp(command, "modificar"))){
            char nueva_definicion[251];

            printf("Nueva definicion: ");
            fgets(nueva_definicion, 250, stdin);
            nueva_definicion[strcspn(nueva_definicion, "\n")] = 0;

            element aux;

            strcpy(aux.definicion, nueva_definicion);
            strcpy(aux.palabra, func);


            ModificarElemento(&diccionario, aux);
            printf("Definición modificada.\n");
            printf("\n");
            //...
        }
        else if (!(strcmp(command, "eliminar"))){
            element aux;
            strcpy(aux.palabra, func);
            EliminarElemento(&diccionario, aux);
            printf("Elemento eliminado.\n");
            printf("\n");
        }
        else if (!(strcmp(command, "preorden"))){
            PreOrden(&diccionario);
            printf("\n");
            printf("\n");
        }
        else if (!(strcmp(command, "inorden"))){
            InOrden(&diccionario);
            printf("\n");
            printf("\n");
            //
        }
        else if (!(strcmp(command, "postorden"))){
            PostOrden(&diccionario);
            printf("\n");
            printf("\n");
            //
        }
        else if (!(strcmp(command, "stat"))){
            int n_nodos;
            int altura;
            

            printf("Estadisticas del árbol: \n");
            printf("Número total de nodos: %d\n", Count(&diccionario, Root(&diccionario)));
            printf("Altura: %d\n", GetHeight(&diccionario));
            printf("\n");
        }

    }

    Destroy(&diccionario);
    return 0;
}