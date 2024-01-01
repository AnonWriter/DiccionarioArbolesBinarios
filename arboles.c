/* arboles.c
código de prueba para las actividades de implementación de estructura de árboles binarios

Código original: Edgardo Adrián Franco Martínez
Modificaciones: Carlos Adiel González Gutiérrez
*/
#include<stdio.h> 
#include"TADArbol_bin.h"
//                               A
//                           /        \ 
//                        B              C
//                     /    \         /    \
//                   J       K     D          E
//                              F     G    H      I

void PreOrden(Arbol *a);
void InOrden(Arbol *a);
void PostOrden(Arbol *a);

int main (void)
{
	Arbol a;
	element e;
	position p;
	
	Initialize(&a);	
	
	//Insertar A como ráiz
	e.c='A';
	NewRightSon(&a,p,e);
	//Posicionarse en A
	p=Root(&a);//A
	e.c='C';
	NewRightSon(&a,p,e);
	e.c='B';
	NewLeftSon(&a,p,e);
	
	//Posicionarse en C	
	p=RightSon(&a,p);//C	
	e.c='D';
	NewLeftSon(&a,p,e);
	e.c='E';
	NewRightSon(&a,p,e);
	
	//Posicionarse en D
	p=LeftSon(&a,p);//D
	e.c='F';
	NewLeftSon(&a,p,e);
	e.c='G';
	NewRightSon(&a,p,e);
	//Posicionarse en E
	p=Parent(&a,p);//C
	p=RightSon(&a,p);//E
	e.c='H';
	NewLeftSon(&a,p,e);
	e.c='I';
	NewRightSon(&a,p,e);	
	
	//Posicionarse en B
	p=Parent(&a,p); //C
	p=Parent(&a,p); //A
	p=LeftSon(&a,p);//B
	e.c='J';
	NewLeftSon(&a,p,e);
	e.c='K';
	NewRightSon(&a,p,e);

    printf("Recorrido PreOrden: ");
    PreOrden(&a);
    printf("\n");
    printf("Recorrido InOrden: ");
    InOrden(&a);
    printf("\n");
    printf("Recorrido PostOrden: ");
    PostOrden(&a);
	
	Destroy(&a);

    printf("\nProceso terminado.\n");
	
	return 0;	
}

void PreOrden(Arbol *a){
    //
    element e;
    e.c = ReadNode(a, *a).c;

    printf("%c ", e.c);

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
    e.c = ReadNode(a, *a).c;

    printf("%c ", e.c);

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
    e.c = ReadNode(a, *a).c;

    printf("%c ", e.c);

    return;
}