#ifndef __PAIS_H

#include "varGlob.h"

struct ALTA{
	char nombre[TAM];
	char sexo;
	double sueldo;
	int id;
	bool ocupado;
}ALTA[TAM];

struct Pais{
	char pais[20];
	int clientes;
	struct ALTA alta[TAM];
}Pais[TAM];
#endif
