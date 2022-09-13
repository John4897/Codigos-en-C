#include <stdio.h>
	
void figura(int tam, char opc);

int main(){
	char cond='t', opc;
	int tam;
	
	while(cond=='t'){
		printf("Desea guardar la figura(S/N)?: ");
		fflush(stdin);
		scanf("%c", &opc);
		if(opc=='S' || opc=='s'){
			printf("%c", opc);
			cond='f';
		}
		if(opc=='N' || opc=='n')
			cond='f';
		else
			printf("Opcion no valida\n");
	}
	
	while(cond=='f'){
		printf("Ingrese un numero impar entre 5 y 33:");
		scanf("%d", &tam);
		if((tam%2!=0) && (tam>=5)){
			figura(tam, opc);
			cond='t';
		}
		else
			printf("Numero invalido\n");
	}
	
	return 0;
}

void figura(int tam, char opc){
	int aux, aux2;

	if(opc=='N' || opc=='n'){
		for(int altura=0; altura<tam; altura++){ 	//for principal
			aux=0, aux2=0;
		if(altura<(tam/2)){		//parte superior
				for(int flechasi=0; flechasi<tam/2; flechasi++) //inicio de parte superior flecha izquierda
					printf(" ");
				for(int flechasi1=0; flechasi1<=altura; flechasi1++){
					printf("*");
					aux++;
				}
				for(int flechasi2=(tam/2)-aux; flechasi2>=0; flechasi2--){
					printf(" ");		//fin de parte superior flecha izquierda
					aux2++;
				}
			
				for(int rombos=(tam/2)-aux; rombos>=0; rombos--){//inicio de parte superior del rombo
					printf(" ");
					aux2++;
				}
				for(int rombos1=tam-aux2; rombos1>0; rombos1--)	//fin de parte superior del rombo
					printf("*");
			
			
				for(int flechasi2=(tam/2)-aux; flechasi2>=0; flechasi2--)	//se repiten los espacios
					printf(" ");
				for(int rombos=(tam/2)-aux; rombos>=0; rombos--)
					printf(" ");
			
				for(int flechasd=0; flechasd<=altura; flechasd++)	//parte superior flecha derecha
					printf("*");	
			}
		
			if(altura>(tam/2)){		//parte inferior
				for(int flechaii=0; flechaii<tam/2; flechaii++)	//incio de parte inferior flecha izquierda
					printf(" ");
				for(int flechaii1=tam-1; flechaii1>=altura; flechaii1--){
					printf("*");
					aux++;
				}
				for(int flechasi2=(tam/2+1)-aux; flechasi2>0; flechasi2--){
					printf(" ");		//fin de parte inferior flecha izquierda
					aux2++;
				}
			
			
				for(int romboi=(tam/2)-aux; romboi>=0; romboi--){//inicio de parte inferior del rombo
					printf(" ");
					aux2++;
				}
				for(int romboi1=0+aux2; romboi1<tam; romboi1++)	//fin de parte inferior del rombo
					printf("*");
			
				for(int flechasi2=(tam/2+1)-aux; flechasi2>0; flechasi2--)	//se repiten los espacios
					printf(" ");
				for(int romboi=(tam/2)-aux; romboi>=0; romboi--)
					printf(" ");	

				for(int flechaid=tam-1; flechaid>=altura; flechaid--)	//parte inferior flecha derecha
					printf("*");	
			}
		
			if(altura==tam/2)		//parte central
				for(int centro=0; centro<tam*3; centro++)
					printf("*");
			printf("\n");
		}
	}
	else{
		FILE *figu;
		figu=fopen("fig.txt", "w");
		
		for(int altura=0; altura<tam; altura++){ 	//for principal
			aux=0, aux2=0;
		if(altura<(tam/2)){		//parte superior
				for(int flechasi=0; flechasi<tam/2; flechasi++){ //inicio de parte superior flecha izquierda
					printf(" ");
					fprintf(figu, " ");
				}
				for(int flechasi1=0; flechasi1<=altura; flechasi1++){
					printf("*");
					fprintf(figu, "*");
					aux++;
				}
				for(int flechasi2=(tam/2)-aux; flechasi2>=0; flechasi2--){
					printf(" ");		//fin de parte superior flecha izquierda
					fprintf(figu, " ");
					aux2++;
				}
			
				for(int rombos=(tam/2)-aux; rombos>=0; rombos--){//inicio de parte superior del rombo
					printf(" ");
					fprintf(figu, " ");
					aux2++;
				}
				for(int rombos1=tam-aux2; rombos1>0; rombos1--){	//fin de parte superior del rombo
					printf("*");
					fprintf(figu, "*");
				}
			
			
				for(int flechasi2=(tam/2)-aux; flechasi2>=0; flechasi2--){	//se repiten los espacios
					printf(" ");
					fprintf(figu, " ");
				}
				for(int rombos=(tam/2)-aux; rombos>=0; rombos--){
					printf(" ");
					fprintf(figu, " ");
				}
			
				for(int flechasd=0; flechasd<=altura; flechasd++){	//parte superior flecha derecha
					printf("*");	
					fprintf(figu, "*");
				}
			}
		
			if(altura>(tam/2)){		//parte inferior
				for(int flechaii=0; flechaii<tam/2; flechaii++){//incio de parte inferior flecha izquierda
					printf(" ");
					fprintf(figu, " ");
				}
				for(int flechaii1=tam-1; flechaii1>=altura; flechaii1--){
					printf("*");
					fprintf(figu, "*");
					aux++;
				}
				for(int flechasi2=(tam/2+1)-aux; flechasi2>0; flechasi2--){
					printf(" ");		//fin de parte inferior flecha izquierda
					fprintf(figu, " ");
					aux2++;
				}
			
			
				for(int romboi=(tam/2)-aux; romboi>=0; romboi--){//inicio de parte inferior del rombo
					printf(" ");
					fprintf(figu, " ");
					aux2++;
				}
				for(int romboi1=0+aux2; romboi1<tam; romboi1++){	//fin de parte inferior del rombo
					printf("*");
					fprintf(figu, "*");
				}
			
				for(int flechasi2=(tam/2+1)-aux; flechasi2>0; flechasi2--){	//se repiten los espacios
					printf(" ");
					fprintf(figu, " ");
				}
				for(int romboi=(tam/2)-aux; romboi>=0; romboi--){
					printf(" ");	
					fprintf(figu, " ");
				}

				for(int flechaid=tam-1; flechaid>=altura; flechaid--){	//parte inferior flecha derecha
					printf("*");	
					fprintf(figu, "*");
				}
			}
		
			if(altura==tam/2)		//parte central
				for(int centro=0; centro<tam*3; centro++){
					printf("*");
					fprintf(figu, "*");
				}
			printf("\n");
			fprintf(figu, "\n");
		}
		
		
		
		fclose(figu);
	}
		
}