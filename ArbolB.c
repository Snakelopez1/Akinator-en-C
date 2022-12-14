#include"ArbolB.h"

ArbolBinario CrearNodo(itemA x[TAMMAX])
{
	ArbolBinario r=(ArbolBinario)malloc(sizeof(ArbolBinario));
	strcpy(r->dato,x);
	r->izq=NULL;
	r->der=NULL;
	return r;
}
void NuevoArbol(ArbolBinario *r, itemA x[TAMMAX], ArbolBinario ramaizq, ArbolBinario ramader)
{
	*r=CrearNodo(x);
	(*r)->izq=ramaizq;
	(*r)->der=ramader;
}
int profundidad(ArbolBinario raiz)
{
	if(!raiz)
		return 0;
	else
	{
		int profi,profd;
		profi=profundidad(raiz->izq);
		profd=profundidad(raiz->der);
		if(profi>profd)
			return profi+1;
		else
			return profd+1;
	}
}
void ContarHojas(ArbolBinario raiz, int *nh)
{
	if(raiz)
	{
		ContarHojas(raiz->izq,nh);
		ContarHojas(raiz->der,nh);
		if(raiz->der==NULL && raiz->izq==NULL)
			(*nh)++;
	}
}
void Liberar(ArbolBinario raiz)
{
	if(raiz)
	{
		Liberar(raiz->izq);
		Liberar(raiz->der);
		printf("%c",raiz->dato);
		free(raiz);
	}
}
void imprimirA(ArbolBinario raiz)
{
	printf("%s",raiz->dato);
}
void preorden(ArbolBinario raiz)
{
	if(raiz)
	{
		imprimirA(raiz);
		preorden(raiz->izq);
		preorden(raiz->der);
	}
}
void enorden(ArbolBinario raiz)
{
	if(raiz)
	{
		preorden(raiz->izq);
		imprimirA(raiz);
		preorden(raiz->der);
	}
}
void postorden(ArbolBinario raiz)
{
	if(raiz)
	{
		preorden(raiz->izq);
		preorden(raiz->der);
		imprimirA(raiz);
	}
}
