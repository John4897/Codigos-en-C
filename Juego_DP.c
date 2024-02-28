#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

void llenar();
void mostrar();
void mostrar_cam();
void solucion();

typedef struct Celda{
	int valor;
	int valor_camino;
	char camino;
}cel;

typedef struct Tablero{
	cel **celus;
}tab;

int main(){
	int i, n, seguir=0;
	tab Tab;	
	
	do{
		switch(seguir){
			case 0:
				do{
					printf("\nIngrese el tamano del tablero (mayor de 2): ");
					scanf("%d", &n);
					
					if(n <= 2){
						printf("\nEl tablero es demasiado pequeno\n");
						system("PAUSE");
						system("CLS");
					}
				}while(n <= 2);
				
				if(n > 2){
					Tab.celus = (cel **) malloc (n * sizeof(cel*));
					for(i=0; i<n; i++)
					Tab.celus[i] =  (cel *) malloc (n * sizeof(cel));
		
					llenar(Tab, n);
					solucion(Tab, n);
				}
			break;
			
			case 1:
				printf("\n");
				mostrar(Tab, n);
			break;
			
			case 2:
				printf("\n");
				mostrar_cam(Tab, n);
			break;
			
			case 3:
			break;
			
			case 4:
				free(Tab.celus);
				seguir=4;
			break;
			
			default:
				printf("\nOpcion invalida");
		}
		printf("\n1 - Mostrar tablero\n2 - Mostrar mejor camino\n3 - Nuevo juego\n4 - Salir\nSeleccione una opcion: ");
		scanf("%d", &seguir);
		
		if(seguir == 3){
			free(Tab.celus);
			seguir=0;
			system("CLS");
		}		
	}while(seguir != 4);
	
	return 0;
}

void llenar(tab Tab, int n){
	int x, i, j;
	srand(time(NULL));
	
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			Tab.celus[i][j].valor = rand()%20-10;
}

void mostrar(tab Tab, int n){
	int i, j;
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			printf("%d \t| ", Tab.celus[i][j].valor);
		printf("\n--\n");
	}
}

void mostrar_cam(tab Tab, int n){
	int i, j;
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%c \t| ", Tab.celus[i][j].camino);
		}
		printf("\n--\n");
	}
}

void solucion(tab Tab, int n){
	int i, j, mayor, x, y;
	mayor=0;
	
	for(i=n-1; i>=0; i--)
		for(j=n-1; j>=0; j--){
			if(i==n-1 && j==n-1){
				Tab.celus[i][j].valor_camino = Tab.celus[i][j].valor;
				Tab.celus[i][j].camino = 'v';
			}
			
			else if(i==n-1){
				if(Tab.celus[i][j+1].valor_camino >= Tab.celus[i][j].valor){
					Tab.celus[i][j].valor_camino = Tab.celus[i][j].valor + Tab.celus[i][j+1].valor_camino;
					Tab.celus[i][j].camino = '>';
				}
				else{
					Tab.celus[i][j].valor_camino = Tab.celus[i][j].valor;
					Tab.celus[i][j].camino = 'v';
				}	
			}
			
			else if(j==n-1){
				if(Tab.celus[i+1][j].valor_camino >= Tab.celus[i][j].valor){
					Tab.celus[i][j].valor_camino = Tab.celus[i][j].valor + Tab.celus[i+1][j].valor_camino;
					Tab.celus[i][j].camino = 'v';
				}
				else{
					Tab.celus[i][j].valor_camino = Tab.celus[i][j].valor;
					Tab.celus[i][j].camino = '>';
				}	
			}
			
			else{
				if(Tab.celus[i+1][j].valor_camino >= Tab.celus[i][j+1].valor_camino){
					Tab.celus[i][j].valor_camino = Tab.celus[i][j].valor + Tab.celus[i+1][j].valor_camino;
					Tab.celus[i][j].camino = 'v';	
				}
				else{
					Tab.celus[i][j].valor_camino = Tab.celus[i][j].valor + Tab.celus[i][j+1].valor_camino;
					Tab.celus[i][j].camino = '>';
				}
			}
		}
		
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(Tab.celus[i][j].valor_camino >= mayor){
				mayor = Tab.celus[i][j].valor_camino;
				x = i;
				y = j;
			}
			
	if(Tab.celus[x+1][y].valor_camino >= Tab.celus[x][y+1].valor_camino)
		Tab.celus[x][y].camino = '|';
	else
		Tab.celus[x][y].camino = '-';

	printf("\nEl puntaje maximo que puedes alcanzar es: %d\n", Tab.celus[x][y].valor_camino);		
	
	for(i=0; i<n; i++)
		for(j=0; j<n; j++){
			if(x==i && y==j){
				if(Tab.celus[x][y].camino == '|'){
					Tab.celus[x][y].camino = 'x';
					x++;
				}
				if(Tab.celus[x][y].camino == '-'){
					Tab.celus[x][y].camino = 'x';
					y++;
				}
				if(Tab.celus[i][j].camino == 'v')
					x++;
				if(Tab.celus[i][j].camino == '>')
					y++;	
			}
			else
				Tab.celus[i][j].camino = '-';
		}
}
