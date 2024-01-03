#include "./TADArbol_bin.h"
#include "./Diccionario.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hacer un árbol binario de búsqueda
// Usar strcmp para ubicar palabras mayores y menores
// Guardar la información con espacios, crear un lector
// ...



int main(int argn, char args[]){
    Arbol nose;
    Initialize(&nose);

    LeerArchivo(&nose, "Glosario_MATEMATICAS.txt");

    element e;
    strcpy(e.palabra, "Sucesión convergente");
    element def = BuscarPalabra(&nose, e);
    printf("Definicion: %s\n", def.definicion);

    return 0;
}

