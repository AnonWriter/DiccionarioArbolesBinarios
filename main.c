#include "./TADArbol_bin.h"
#include "./Diccionario.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Hacer un árbol binario de búsqueda
// Usar strcmp para ubicar palabras mayores y menores
// Guardar la información con espacios, crear un lector
// ...



int main(int argn, char args[]){
    setlocale(LC_ALL, "es_MX.utf8");

    Arbol diccionario;
    Initialize(&diccionario);

    char command[10];

    while (strcmp(command, "salir")){
        fgets(command, 100, stdin);
        command[strcspn(command, "\n")] = 0;

        if (!(strcmp(command, "cargar"))){
            char dir[100];
            printf("Nombre del archivo a leer: ");
            fgets(dir, 100, stdin);
            dir[strcspn(dir, "\n")] = 0;
            LeerArchivo(&diccionario, dir);
        }
        else if (!(strcmp(command, "agregar"))){
            //
        }
        else if (!(strcmp(command, "buscar"))){
            char busqueda[101];
            fgets(busqueda, 100, stdin);
            busqueda[strcspn(busqueda, "\n")] = 0;
            element aux;
            strcpy(aux.palabra, busqueda);
            element def = BuscarPalabra(&diccionario, aux);
            printf("%s\n", def.definicion);
        }
        else if (!(strcmp(command, "modificar"))){
            //
        }
        else if (!(strcmp(command, "eliminar"))){
            //
        }
        else if (!(strcmp(command, "no se"))){
            //
        }
        else if (!(strcmp(command, "help"))){
            //
        }
    }


    /*
    Arbol nose;
    Initialize(&nose);

    LeerArchivo(&nose, "Glosario_MATEMATICAS.txt");

    element e;
    strcpy(e.palabra, "Sucesión convergente");
    element def = BuscarPalabra(&nose, e);
    printf("Definicion: %s\n", def.definicion);
    */

    return 0;
}

