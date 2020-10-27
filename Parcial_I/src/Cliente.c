/*
 * Cliente.c
 *
 *  Created on: 9 oct. 2020
 *      Author: Nahuel
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Cliente.h"
#include "Menu.h"
#include "Gets.h"
#define FREE 1
#define FULL 0

sCliente* Cliente_NuevoCliente(void)
{
	sCliente* pCliente;
	pCliente=(sCliente*)malloc(sizeof(sCliente));
	if(pCliente!=NULL)
	{
		pCliente->idCliente=0;
		pCliente->nombre[0]='\0';
		pCliente->apellido[0]='\0';
		pCliente->cuit[0]='\0';
	}
	return pCliente;
}

sCliente* Cliente_NuevoClienteconParametros(int id, char* nombre,char* apellido,char* cuit)
{
	sCliente* retorno=NULL;
	sCliente* pCliente;
	pCliente=(sCliente*)malloc(sizeof(sCliente));
	if(pCliente!=NULL && id>0 && nombre!=NULL && apellido!=NULL && cuit!=NULL)
	{
		pCliente->idCliente=id;
		strncpy(pCliente->nombre,nombre,sizeof(pCliente->nombre));
		strncpy(pCliente->apellido,apellido,sizeof(pCliente->apellido));
		strncpy(pCliente->cuit,cuit,sizeof(pCliente->cuit));
		retorno=pCliente;
	}
	return retorno;
}

int Cliente_InitArrayPunteros(sCliente* array[],int len)
{
	int retorno=-1;
	int i;
	if(array!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			array[i]=NULL;
			retorno=0;
		}
	}
	return retorno;
}

void Cliente_Hardcodeo(sCliente* list[],int len)
{
    char nombre[5][51]= {"Ivan","Antonella","Eliana","Veronica","Kirk"};
    char apellido[5][51]= {"Ghigliotti","Tilbes","Barboza","Soria","Hammett"};
    char cuit[5][51]= {"20-41026881-8","27-41563668-1","27-2463559-0","27-12254336-5","20-1056998-7"};
    int idCliente[5]= {100,101,102,103,104};
    int i;
    sCliente* pCliente;
	for(i=0; i<5; i++)
	{
		pCliente=Cliente_NuevoCliente();
		if(pCliente!=NULL)
		{
			pCliente->idCliente=idCliente[i];
			strcpy(pCliente->nombre,nombre[i]);
			strcpy(pCliente->apellido,apellido[i]);
			strcpy(pCliente->cuit,cuit[i]);
			list[i]=pCliente;
		}
	}
}

int Cliente_BuscarLibre(sCliente* list[],int len,int* pIndex)
{
	int retorno=-1;
	int i;
	if(list!=NULL && len>0 && pIndex!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i]==NULL)
			{
				*pIndex=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int Cliente_GenerarId(void)
{
	static int id=104;
	id++;
	return id;
}

int Cliente_BuscarPorId(sCliente* list[],int len,int id,int* pIndex)
{
	int retorno=-1;
	int i;
	if(list!=NULL &&  len>0 && id>0 && pIndex!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i]!=NULL && list[i]->idCliente==id)
			{
				*pIndex=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int Cliente_Imprimir(sCliente* list[],int len)
{
    int i;
    int retorno=-1;

	if(list!=NULL && len>0)
	{
		printf("%5s %15s %15s %15s\n_____________________________________________________\n","ID","NOMBRE","APELLIDO","CUIT");
		for(i=0; i<len; i++)
		{
			if(list[i]!=NULL)
			{
				printf("%5d %15s %15s %15s\n",list[i]->idCliente,list[i]->nombre,list[i]->apellido,list[i]->cuit);
				retorno=0;
			}
		}
	}
    printf("\n\n");
    return retorno;
}

int Cliente_Alta(sCliente* list[],int len,int index)
{
	int retorno=-1;
	sCliente buffer;
	sCliente* pCliente;
	if(list!=NULL && len>0 && index>0)
	{
		if(GetString("Ingrese su nombre: ","Ingrese un dato valido!\n",buffer.nombre,sizeof(buffer.nombre),2)==0
	       && GetString("Ingrese su apellido: ","Ingrese un dato valido!\n",buffer.apellido,sizeof(buffer.apellido),2)==0
		   && GetCuit("Ingrese su cuit xx-xxxxxxxx-x: ","Ingrese un dato valido o coloque los guiones donde se le indica!\n",buffer.cuit,2)==0)
		{
			buffer.idCliente=Cliente_GenerarId();
			pCliente=Cliente_NuevoCliente();
			if(pCliente!=NULL)
			{
				*pCliente=buffer;
				list[index]=pCliente;
				printf("#Su id es: %d\n",list[index]->idCliente);
			}
			retorno=0;
		}
	}
	return retorno;
}

int Cliente_Modificar(sCliente* list[],int len)
{
    int retorno=-1;
    int flag=0;
    int option;
    int index;
    int goBack=0;
    sCliente buffer;


    if(list!=NULL && len>0 && GetInt("\nIngrese el ID del cliente a modificar: ", "No se encontro ese ID, ingrese un dato valido\n",&buffer.idCliente,2)==0
    		&& Cliente_BuscarPorId(list,len,buffer.idCliente,&index)==0)
    {
    	do
    	{
    	            printf("*********************************\n");
    	            printf("Id: %d\nNombre: %s\nApellido: %s\nCuit: %s\n",list[index]->idCliente,
    	            	   list[index]->nombre,
    	                   list[index]->apellido,
    	                   list[index]->cuit);
    	            printf("*********************************\n");
    	            if(GetOption("(1).Nombre\n(2).Apellido\n"
    	            		"(3).Cuit\n(4).Volver al menu principal\nQue desea modificar?: ", "Ingrese un dato valido!\n",&option,2,1,4)==0)
    	            {
						switch(option)
						{
						case 1:
							if(GetString("Ingrese nuevo nombre: ","Ingrese un dato valido!\n",buffer.nombre,sizeof(buffer.nombre),2)==0)
							{
								strncpy(list[index]->nombre,buffer.nombre,sizeof(buffer.nombre));
								flag=1;
							}
							break;
						case 2:
							if(GetString("Ingrese nuevo apellido: ","Ingrese un dato valido!\n",buffer.apellido,sizeof(buffer.apellido),2)==0)
							{
								strncpy(list[index]->apellido,buffer.apellido,sizeof(buffer.apellido));
								flag = 1;
							}
							break;
						case 3:
							if(GetCuit("Ingrese nuevo cuit xx-xxxxxxxx-x: ","Ingrese un dato valido o coloque los guiones donde se le indica!\n",buffer.cuit,2)==0)
							{
								strncpy(list[index]->cuit,buffer.cuit,sizeof(buffer.cuit));
								flag=1;
							}
							break;
						case 4:
							if(flag==1)
							{
								retorno=0;
							}
							else
							{
								retorno=1;
							}
							goBack=1;
							break;
						}
    	            }
    	            system("pause");
    	            system("cls");
    	        }
    	        while(goBack!=1);
    }
    return retorno;
}


