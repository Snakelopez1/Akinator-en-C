#include"ArbolB.c"
#include<conio.h>
//#include<string.h>

void akinator();
void adivina(ArbolBinario *raiz);
void cambio(ArbolBinario *raiz,char *cad1,char *cad2,char opc);

main()
{
	printf("Bienvenido humano, tratare de adivinar lo que piensas, estas listo?\n");
	system("pause");
	akinator();
	return 0;
}
void akinator()
{
	char oc;
	ArbolBinario raiz=NULL;
	char ini1[20]="Tiene pelaje",ini2[20]="perro",ini3[20]="elefante";
	raiz=CrearNodo(ini1);
	raiz->izq=CrearNodo(ini2);
	raiz->der=CrearNodo(ini3);
	do
	{
		adivina(&raiz);
		printf("Deseas Jugar de nuevo? (si/no)\n");
		fflush(stdin);
		scanf("%c",&oc);
		fflush(stdin);
		system("cls");
	}while(oc=='s'|| oc=='S');
}
void adivina(ArbolBinario *raiz)
{
	char cad1[20],cad2[20],opc;
	if((*raiz)->izq && (*raiz)->der)
	{
		printf("%s?\n",(*raiz)->dato);
		fflush(stdin);
		scanf("%c",&opc);
		if(opc=='n'|| opc=='N')
			adivina(&(*raiz)->der);
		if(opc=='s'|| opc=='S')
			adivina(&(*raiz)->izq);
	}
	else if(!(*raiz)->izq && !(*raiz)->der)
	{
		printf("Tu respuesta es %s? (si/no)\n",(*raiz)->dato);
		fflush(stdin);
		scanf("%c",&opc);
		if(opc=='s'|| opc=='S')
		{
			printf("Impresionado?\n");
		}
		else if(opc=='n'|| opc=='N')
		{
			printf("Que animal era?\n");
			fflush(stdin);
			gets(cad1);
			printf("Que diferencia hay entre %s y %s (No agregues signo de interrogacion)\n",(*raiz)->dato,cad1);
			gets(cad2);
			printf("Si fuera %s cual seria la respuesta? (si/no)\n",cad1);
			scanf("%c",&opc);
			cambio(raiz,cad1,cad2,opc);
			printf("Mis conocimientos han sido actualizados, la proxima vez adivinare\n");
		}
	}
}
void cambio(ArbolBinario *raiz,char *cad1,char *cad2,char opc)
{
	char cadaux[20];
	strcpy(cadaux,(*raiz)->dato);
	strcpy((*raiz)->dato,cad2);
	fflush(stdin);
	if(opc=='n'||opc=='N')
	{
		(*raiz)->der=CrearNodo(cad1);
		(*raiz)->izq=CrearNodo(cadaux);
	}
	else if(opc=='s'||opc=='S')
	{
		(*raiz)->der=CrearNodo(cadaux);
		(*raiz)->izq=CrearNodo(cad1);
	}
}
 
