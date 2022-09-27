#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define TAMMAX 10000

typedef char itemA;

typedef struct nodoA
{
	itemA dato[TAMMAX];
	struct nodoA *izq,*der;
}ElemAB;
typedef ElemAB *ArbolBinario;

ArbolBinario CrearNodo(itemA x[TAMMAX]);
void NuevoArbol(ArbolBinario *r, itemA x[TAMMAX], ArbolBinario ramaizq , ArbolBinario ramader);
void Liberar(ArbolBinario raiz);
void imprimirA(ArbolBinario raiz);
int profundidad(ArbolBinario raiz);
void ContarHojas(ArbolBinario raiz, int *nh);
void preorden(ArbolBinario raiz);
void enorden(ArbolBinario raiz);
void postorden(ArbolBinario raiz);
