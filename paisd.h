#ifndef __PAISD_H
#include<string.h>
#include <stdlib.h>
#include "Pais.h"
#include "Menu.h"

void ActualizarC(){
		printf("\n Introducir nombre del pais: ");
        printf("---- Menú Actualizar ----\n");
        printf(" 0 Mostrar menu.\n");
        printf(" 1 Actualizar Nombre.\n");
        printf(" 2 Actualizar Sexo.\n");
        printf(" 3 Regresar a ménu principal.\n");
        printf("-------------------------------");
}


void paisd(){
	int i,j,cont;
	char pais[50];
	printf("\n Introduce el numero de paises: ");
	scanf("%i",&NumeroPaises);
	
	for(i = 0; i < NumeroPaises; i++){
		fflush(stdin);
		printf("\n Introduce el nombre del Pais [%i]: ",i);
		gets(Pais[i].pais);

		printf("\n troduce el total de clientes del pais %i:",i);
		scanf("%i",&Pais[i].clientes);
    }
	
	for(i=0;i<NumeroPaises;i++){
		printf("\n Del pais  %s , existen %i clientes",Pais[i].pais,Pais[i].clientes);
	}
	
	int opciones,opcionesAc;
	Menu();
	printf("\n Elige una opcion: ");
	scanf("%d",&opciones);
	while(opciones != 15){
		switch(opciones){
			case 0:Menu();
				break;
			case 1:printf("\n --- Opcion alta ---");
				printf("\n Introduce el nombre del pais: ");
				fflush(stdin);
				gets(pais);
				for(i=0;i<NumeroPaises;i++){
					if(strcmp(pais,Pais[i].pais)==0){
						for(j=0;j<Pais[i].clientes;j++){
							if(Pais[i].alta[j].ocupado!=true){
								printf("\n Introducir nombre del cliente: ");
								gets(Pais[i].alta[j].nombre);
								printf("\n Introducir el Sexo: ");
								scanf("%c",&Pais[i].alta[j].sexo);
								printf("\n Introducir el Sueldo: ");
								scanf("%d",&Pais[i].alta[j].sueldo);
								Pais[i].alta[j].id=j;
								Pais[i].alta[j].ocupado=true;
								break;
							}
						}
					}
				}break;
				
			case 2:
				printf("\n --- Opcion baja ---");
				fflush(stdin);
				printf("\n Introducir el nombre del pais: ");
				gets(pais);
				int cliente;
				for(i=0;i<NumeroPaises;i++){
					if(strcmp(pais,Pais[i].pais)==0){
						printf("\n Introduce el indice del cliente: ");
						scanf("%i",&cliente);
						for(j=0;j<Pais[i].clientes;j++){
							if (cliente==Pais[i].alta[j].id){
							printf("\n --> Cliente %s dado de baja.",Pais[i].alta[j].nombre,Pais[i].alta[j].id);
							int k;
							int x = sizeof(Pais[i].alta[j].nombre)/sizeof(*Pais[i].alta[j].nombre);
							for(k=0;k<x;k++){
								Pais[i].alta[j].nombre[k]='\0';
							}
							Pais[i].alta[j].sexo=' ';
							Pais[i].alta[j].sueldo=0;
							Pais[i].alta[j].ocupado=false;
							}
						}
					}
				}
				break;
			case 3:
				printf("\n --- Opcion mostrar todo ---");
				for(i=0;i<NumeroPaises;i++){
					printf("\n Del pais %s",Pais[i].pais);
			        for(j= 0; j< Pais[i].clientes; j++){
			            printf("\n El cliente [%i] es: ",Pais[i].alta[j].id);
			            printf("\n -->Nombre: %s -->Sexo: %c  -->Saldo: %d -->Ocupado: %s",Pais[i].alta[j].nombre, 
						Pais[i].alta[j].sexo, Pais[i].alta[j].sueldo, Pais[i].alta[j].ocupado?"true":"false");
			        }
				}
				break;
			case 4:
				printf("\n --- Opcion mostrar especifico ---");
				fflush(stdin);
				printf("\n Introduce el nombre del pais: ");
				gets(pais);
				cliente=0;
				for(i=0;i<NumeroPaises;i++){
					if(strcmp(pais,Pais[i].pais)==0){
						printf("\n Introduce el id del cliente: ");
						scanf("%i",&cliente);
						for(j=0;j<Pais[i].clientes;j++){
							if (cliente==Pais[i].alta[j].id){
							printf("\n El cliente %i es: ",Pais[i].alta[j].id);
			            	printf("\n -->Nombre: %s -->Sexo: %c -->Saldo: %d -->Ocupado: %s\n",Pais[i].alta[j].nombre, 
							Pais[i].alta[j].sexo, Pais[i].alta[j].sueldo, Pais[i].alta[j].ocupado?"true":"false");
							}
							else{
								printf("\n ---> No existen clientes que mostrar...");
							}
						}
					}
				}
				break;
			case 5:
				printf("\n --- Opcion mostrar solo ocupados ---");
				fflush(stdin);
				cliente=0;
				for(i=0;i<NumeroPaises;i++){
					for(j=0;j<Pais[i].clientes;j++){
						if (true==Pais[i].alta[j].ocupado){
							printf("\n Del pais %s",Pais[i].pais);
							printf("\n El cliente %i es: ",Pais[i].alta[j].id);
			            	printf("\n -->Nombre: %s -->Sexo: %c  -->Saldo: %d -->Ocupado: %s\n",Pais[i].alta[j].nombre, 
							Pais[i].alta[j].sexo, Pais[i].alta[j].sueldo, Pais[i].alta[j].ocupado?"true":"false");
						}
						else{
							printf("\n ---> No existen clientes que mostrar...");
						}
					}
				}
				break;
			case 6:
				printf("\n --- Opcion abonar---");
				fflush(stdin);
				printf("\n Introduce el nombre del pais: ");
				gets(pais);
				cliente=0;
				Abono=0;
				for(i=0;i<NumeroPaises;i++){
					if(strcmp(pais,Pais[i].pais)==0){
						printf("\n Introduce el id del cliente: ");
						scanf("%i",&cliente);
						for(j=0;j<Pais[i].clientes;j++){
							if (cliente==Pais[i].alta[j].id){
							printf("\n Ingresa la cantidad que quieres abonar: ");
							scanf("%d",&Abono);
							Pais[i].alta[j].sueldo = Pais[i].alta[j].sueldo + Abono;
							}
							else{
								printf("\n -->La estructura esta toda vacia.");
							}
						}
					}
				}
				break;
			case 7:
				printf("\n --- Opcion retirar---");
				fflush(stdin);
				printf("\n Introduce el nombre del pais: ");
				gets(pais);
				cliente=0;
				Abono=0;
				for(i=0;i<NumeroPaises;i++){
					if(strcmp(pais,Pais[i].pais)==0){
						printf("\n Introduce el id del cliente: ");
						scanf("%i",&cliente);
						for(j=0;j<Pais[i].clientes;j++){
							if (cliente==Pais[i].alta[j].id){
							printf("\n Ingresa la cantidad que quieres retirar: ");
							scanf("%d",&Abono);
							if(Abono<=Pais[i].alta[j].sueldo){
								Pais[i].alta[j].sueldo = Pais[i].alta[j].sueldo - Abono;
							}else{
								printf("\n Imposible cantidad insuficiente para retirar %d. \n",Abono);
							}
							}
							else{
								printf("\n -->La estructura esta toda vacia.");
							}
						}
					}
				}
				break;
			case 8:
				printf("\n--- Opcion buscar id vacio en toda estructura ---");
				for(i=0;i<NumeroPaises;i++){
					for(j=0;j<Pais[i].clientes;j++){
						if(false==Pais[i].alta[j].ocupado){
							printf("\nEl pais  %s tiene el cliente [%i] vacio.",Pais[i].pais,Pais[i].alta[j].id);
						}
					}
				}
				break;
				
			case 9:
				cont=0;
				lleno=false;
				printf("\n --- Opcion esta llena toda la estructura ---\n");
				for(i=0;i<NumPaises;i++){
					for(j=0;j<Pais[i].clientes;j++){
						if(Pais[i].alta[j].ocupado==true){
							cont++;
						}
					}
					if(Lleno==cont){
						lleno=true;
					}
				}
				if(lleno==true){
					printf("\n\tLa estructura esta llena.\n");
				}else{
					printf("\n\tLa estructura no esta toda llena.\n");
				}
				break;
			case 10:
				printf("\n --- Opcion esta vacia toda la estructura ---\n");
				cont=0;
				lleno=false;
				for(i=0;i<NumPaises;i++){
					for(j=0;j<Pais[i].clientes;j++){
						if(Pais[i].alta[j].ocupado==false){
							cont++;
						}
					}
					if(Lleno==cont){
						lleno=true;
					}
				}
				if(lleno==true){
					printf("\n-------------------------------");
					printf("\n La estructura esta vacia\n");
					printf("\n-------------------------------");
				}else{
					printf("\n-----------------------------------");
					printf("\n La estructura no esta toda vacia.\n");
					printf("\n-----------------------------------");
				}
				break;
			case 11:
				for(i=0;i<NumeroPaises;i++){
				printf("\n Pais [%i]  %s\n ",i,Pais[i].pais);
			}
				break;
			case 12:
				for(i=0;i<NumeroPaises;i++){
				printf("\n Del pais %s, existen %i clientes ",Pais[i].pais,Pais[i].clientes);
			}
				break;
			case 13:
		printf("\n --- Opcion actualizar ---");
		fflush(stdin);
		printf("\n Introducir el nombre del pais: ");
		gets(pais);
		cliente=0;
		for(i=0;i<NumeroPaises;i++){
			if(strcmp(pais,Pais[i].pais)==0){
				printf("\n Introduce el id del cliente: ");
				scanf("%i",&cliente);
				for(j=0;j<Pais[i].clientes;j++){
					if (cliente==Pais[i].alta[j].id){
		
        fflush(stdin);
        printf("\n Eligue una opcion: ");
        scanf("%d",&opcionesAc);
        	switch(opcionesAc){
        		case 0:ActualizarC();
        		break;
        		case 1:
        			printf("--- Opcion actualizar nombre ---");
        			fflush(stdin);
					gets(pais);
							printf("\n Introduce nuevo nombre del cliente:");
							gets(Pais[i].alta[j].nombre);	
							printf("\n Nombre: %s Sexo: %c  Saldo: %d Ocupado: %s",Pais[i].alta[j].nombre, 
							Pais[i].alta[j].sexo, Pais[i].alta[j].sueldo, Pais[i].alta[j].ocupado?"true":"false");
			
        		break;
				case 2:
					printf("\n Introduce el sexo: ");
					fflush(stdin);
					scanf("%c",&Pais[i].alta[j].sexo);
					break;
				break;
				case 3:
				Menu();
				break;	
				}
				printf("\n Eligue una opcion: ");
        		scanf("%d",&opcionesAc);
			}
		}
	}
}
        
				break;
			case 14:
			break;
		}
		printf("\n Elige una opcion: ");
		scanf("%d",&opciones);
	}
}
#endif
