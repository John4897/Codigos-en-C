#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include "vidamuerte.h"

int main(){
	cond reglas;
	tab princ; 
	bool a=false;
	princ.inst_act=0;

	printf("\n\tBienvenido al juego de la vida!");	
	printf("\n\nIngrese el tama%co del tablero (tomando en cuenta 51 como m%cximo y 3 como el m%cnimo): ",164, 160, 161);
	while(a==false){
		scanf("%d",&princ.tam);
			if(princ.tam>=3 && princ.tam<=51)
				a=true;
			else
				printf("\nEl numero esta fuera del rango.\nVuelva a ingresar otro: ");
	}
	printf("\nIngrese el numero de instantes: ");
	scanf("%d",&princ.inst);
	a=false;
	printf("\n%cDesea llenar el tablero manualmente o aleatoriamente? (M/A): ",168);
	while(a==false){
		fflush(stdin);
		scanf("%c",&reglas.llenado);
		reglas.llenado=toupper(reglas.llenado);
			if(reglas.llenado=='M' || reglas.llenado=='A')
				a=true;
			else
				printf("\nOpcion no valida.\nVuelva a ingresarla: ");
	}
	a=false;
	printf("\n%cDesea que los instantes sean consecutivos o manuales? (C/M): ",168);
	while(a==false){
		fflush(stdin);
		scanf("%c",&reglas.sucesion);
			reglas.sucesion=toupper(reglas.sucesion);
			if(reglas.sucesion=='C' || reglas.sucesion=='M')
				a=true;
			else
				printf("\nOpcion no valida.\nVuelva a ingresarla: ");
	}

	princ.cel=(celus **) malloc(princ.tam*sizeof(celus *));
	for(int i=0; i<princ.tam; i++)
		princ.cel[i]=(celus *) malloc(princ.tam*sizeof(celus));

	llenar(reglas, princ);
	vida_muerte(reglas, princ);
	liberar(princ);

	return 0;
}