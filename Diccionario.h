#ifndef _DICCIONARIO_H_
#define _DICCIONARIO_H_

#include "./TADArbol_bin.h"

void LeerArchivo(Arbol *T, char dir[]);
void AgregarElemento(Arbol *T, element e);

void ModificarElemento(Arbol *T, element e);
void EliminarElemento(Arbol *T, element e);

element BuscarPalabra(Arbol *T, element e);

#endif