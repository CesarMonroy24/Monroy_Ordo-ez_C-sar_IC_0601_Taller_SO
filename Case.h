#ifndef __CASE_H
#include<stdio.h>
#include "Pais.h"
#include "Menu.h"
#include "paisd.h"
#include "varGlob.h"

paisd();
void Case(){
	int i,j;
	char pais[50];
	int opciones,opcionesAc;
	Menu();
	printf("\nElige una opcion: ");
	scanf("%d",&opciones);
	while(opciones != 15){
		switch(opciones){
			case 0:Menu();
				break;
			case 1:printf("\n --- Opcion alta ---");
				printf("\nIntroduce el nombre del pais: ");
				fflush(stdin);
				gets(pais);
				for(i=0;i<NumPaises;i++){
					if(strcmp(pais,Pais[i].pais)==0){
						for(j=0;j<Pais[i].clientes;j++){
							if(Pais[i].alta[j].ocupado!=true){
								printf("\nIntroduce el nombre del cliente: ");
								gets(Pais[i].alta[j].nombre);
								printf("\nIntroduce el sexo F/M: ");
								scanf("%c",&Pais[i].alta[j].sexo);
								printf("\nIntroduce el sueldo: ");
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
				printf("\nIntroduce el nombre del pais: ");
				gets(pais);
				int cliente;
				for(i=0;i<NumPaises;i++){
					if(strcmp(pais,Pais[i].pais)==0){
						printf("\nIntroduce el id del cliente: ");
						scanf("%i",&cliente);
						for(j=0;j<Pais[i].clientes;j++){
							if (cliente==Pais[i].alta[j].id){
							printf("\nCliente %s con el id %i fue dado de baja.",Pais[i].alta[j].nombre,Pais[i].alta[j].id);
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
				for(i=0;i<NumPaises;i++){
					printf("\t\nDel pais %s",Pais[i].pais);
			        for(j= 0; j< Pais[i].clientes; j++){
			            printf("\n\tEl cliente %i es: ",Pais[i].alta[j].id);
			            printf("\n\t\tNombre: %s \tSexo: %c \t Saldo: %d \tOcupado: %s\n",Pais[i].alta[j].nombre, 
						Pais[i].alta[j].sexo, Pais[i].alta[j].sueldo, Pais[i].alta[j].ocupado?"true":"false");
			        }
				}
				break;
			case 4:
				printf("\n --- Opcion mostrar especifico ---");
				fflush(stdin);
				printf("\nIntroduce el nombre del pais: ");
				gets(pais);
				cliente=0;
				for(i=0;i<NumPaises;i++){
					if(strcmp(pais,Pais[i].pais)==0){
						printf("\nIntroduce el id del cliente: ");
						scanf("%i",&cliente);
						for(j=0;j<Pais[i].clientes;j++){
							if (cliente==Pais[i].alta[j].id){
							printf("\n\tEl cliente %i es: ",Pais[i].alta[j].id);
			            	printf("\n\t\tNombre: %s \tSexo: %c \t Saldo: %d \tOcupado: %s\n",Pais[i].alta[j].nombre, 
							Pais[i].alta[j].sexo, Pais[i].alta[j].sueldo, Pais[i].alta[j].ocupado?"true":"false");
							}
						}
					}
				}
				break;
			case 5:
				printf("\n --- Opcion mostrar solo ocupados ---");
				fflush(stdin);
				cliente=0;
				for(i=0;i<NumPaises;i++){
					for(j=0;j<Pais[i].clientes;j++){
						if (true==Pais[i].alta[j].ocupado){
							printf("\t\nDel pais %s",Pais[i].pais);
							printf("\n\tEl cliente %i es: ",Pais[i].alta[j].id);
			            	printf("\n\t\tNombre: %s \tSexo: %c \t Saldo: %d \tOcupado: %s\n",Pais[i].alta[j].nombre, 
							Pais[i].alta[j].sexo, Pais[i].alta[j].sueldo, Pais[i].alta[j].ocupado?"true":"false");
						}
					}
				}
				break;
			case 6:
				printf("\n\n --- Opción abonar---");
				fflush(stdin);
				printf("\nIntroduce el nombre del pais: ");
				gets(pais);
				cliente=0;
				Abono=0;
				for(i=0;i<NumPaises;i++){
					if(strcmp(pais,Pais[i].pais)==0){
						printf("\nIntroduce el id del cliente: ");
						scanf("%i",&cliente);
						for(j=0;j<Pais[i].clientes;j++){
							if (cliente==Pais[i].alta[j].id){
							printf("\n\tIngresa la cantidad que quieres abonar: ");
							scanf("%d",&Abono);
							Pais[i].alta[j].sueldo = Pais[i].alta[j].sueldo + Abono;
							}
						}
					}
				}
				break;
			case 7:
				printf("\n\n --- Opción retirar---");
				fflush(stdin);
				printf("\n\tIntroduce el nombre del pais: ");
				gets(pais);
				cliente=0;
				Abono=0;
				for(i=0;i<NumPaises;i++){
					if(strcmp(pais,Pais[i].pais)==0){
						printf("\n\tIntroduce el id del cliente: ");
						scanf("%i",&cliente);
						for(j=0;j<Pais[i].clientes;j++){
							if (cliente==Pais[i].alta[j].id){
							printf("\n\t\tIngresa la cantidad que quieres retirar: ");
							scanf("%d",&Abono);
							if(Abono<=Pais[i].alta[j].sueldo){
								Pais[i].alta[j].sueldo = Pais[i].alta[j].sueldo - Abono;
							}else{
								printf("\n\t\tImposible, el saldo es insuficiente para retirar %d. \n",Abono);
							}
							}
						}
					}
				}
				break;
			case 8:
				printf("\n\n --- Opción buscar id vacio en toda estructura ---\n");
				for(i=0;i<NumPaises;i++){
					for(j=0;j<Pais[i].clientes;j++){
						if(false==Pais[i].alta[j].ocupado){
							printf("\t\nEl pais  %s tiene el cliente [%i] vacio.",Pais[i].pais,Pais[i].alta[j].id);
						}/*else{
							printf("\n\t\tImposible, el saldo es insuficiente para retirar %d. \n",Abono);
						}*/
					}
				}
				break;
				
			case 9:
				
				break;
			case 10:
				break;
			case 11:
				for(i=0;i<NumPaises;i++){
				printf("\n Pais [%i]  %s\n ",i,Pais[i].pais);
			}
				break;
			case 12:
				for(i=0;i<NumPaises;i++){
				printf("\nDel pais %s, existen %i clientes.\n ",Pais[i].pais,Pais[i].clientes);
			}
				break;
			case 13:
		printf("\n --- Opción actualizar ---");
		fflush(stdin);
		printf("\n Introducir el nombre del pais: ");
		gets(pais);
		cliente=0;
		for(i=0;i<NumPaises;i++){
			if(strcmp(pais,Pais[i].pais)==0){
				printf("\nIntroduce el id del cliente: ");
				scanf("%i",&cliente);
				for(j=0;j<Pais[i].clientes;j++){
					if (cliente==Pais[i].alta[j].id){
		printf("\n Introducir nombre del pais: ");
        printf("---- Menú Actualizar ----\n");
        printf(" 0 Mostrar menu.\n");
        printf(" 1 Actualizar Nombre.\n");
        printf(" 2 Actualizar Sexo.\n");
        printf(" 3 Regresar a ménu principal.\n");
        printf("-------------------------------");
        fflush(stdin);
        printf("\n Eligue una opcion: ");
        scanf("%d",&opcionesAc);
        	switch(opcionesAc){
        		case 0:Menu();
        		break;
        		case 1:
        			printf("--- Opcion actualizar nombre ---");
        			fflush(stdin);
					gets(pais);
							printf("\n Introduce nuevo nombre del cliente:");
							gets(Pais[i].alta[j].nombre);	
							printf("\n\t\tNombre: %s \tSexo: %c \t Saldo: %d \tOcupado: %s\n",Pais[i].alta[j].nombre, 
							Pais[i].alta[j].sexo, Pais[i].alta[j].sueldo, Pais[i].alta[j].ocupado?"true":"false");
			
        		break;
				case 2:
					printf("\n\t\t\tIntroduce el sexo F/M: ");
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
		printf("\nElige una opcion: ");
		scanf("%d",&opciones);
	}
}
#endif
