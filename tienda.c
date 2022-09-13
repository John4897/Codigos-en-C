#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

typedef struct Productos{
	char desc[20];
	int ID;
	float pre_uni;
	int ex;
}pro;

void lectura(FILE *Archivo, pro *pro_tienda);
void menu(pro *pro_tienda, int cant_prod);

int main(){
	int cant_prod;
	FILE *Archivo;
	pro *pro_tienda;
	
	Archivo=fopen("Productos.txt","r");

	if (Archivo==NULL){
		printf("No se pudo abrir el archivo \n");
		exit(0);
	}
	
	fscanf(Archivo,"%d", &cant_prod);

	pro_tienda=(pro *)malloc(sizeof(pro)*cant_prod);
	
	lectura(Archivo, pro_tienda);
	menu(pro_tienda, cant_prod);
	
	fclose(Archivo);

	
	free(pro_tienda);
	
	return 0;
}

void lectura(FILE *Archivo, pro *pro_tienda){
	int i=0;
	
	while(!feof(Archivo)){
		fscanf(Archivo, "%s %d %f %d", pro_tienda[i].desc, &pro_tienda[i].ID, &pro_tienda[i].pre_uni, &pro_tienda[i].ex);	
		i++;
	}	
}

void menu(pro *pro_tienda, int cant_prod){
	int i=0, opc, tam_car=0, ID_p, cantidad, marcador;
	float total=0;
	char conf;
	pro *carrito=NULL, *aux;
	bool x=true, y, z;
	
	while(x==true){
		system("CLS");
		y=true;
		z=true;
		printf("\n\tBienvenido al menu!\n\n1-Mostrar carrito\n2-Agregar productos al carrito \n3-Vaciar el carrito\n4-Hacer la compra\n5-Salir\n\nSeleccione una opcion: ");
		scanf("%d", &opc);
		
		switch(opc){
			case 1:
				system("CLS");
				if(carrito==NULL)
					printf("Su carrito esta vacio\n");
				else{
					printf("Descripcion\tCantidad");
					for(i=0; i<tam_car; i++)
						printf("\n%s\t\t%d", carrito[i].desc, carrito[i].ex);
				}
				system("PAUSE");
			break;
			case 2:
				while(y==true){	
					system("CLS");
					
					printf("\nEstos son los productos de nuestra tienda\n\nID\tDescripcion\n");
					for(i=0; i<15; i++)
						printf("%d (%d)\t%s\n", pro_tienda[i].ID, pro_tienda[i].ex, pro_tienda[i].desc);	
					printf("\nSeleccione el ID del producto que desea comprar o presione 15 para salir: ");
					scanf("%d", &ID_p);
					if(ID_p!=15){
						printf("Cuantas unidades desea agregar a su carrito?: ");
						scanf("%d", &cantidad);
					}
					if(ID_p==15)
						y=false;
					if(ID_p>15)
						printf("Ese producto y cantidad no existen");
					
					if(ID_p!=15 && pro_tienda[ID_p].ex>=cantidad){
						if(carrito==NULL){
							carrito=(pro *)malloc(sizeof(pro)*cant_prod);
					
							strcpy(carrito[0].desc, pro_tienda[ID_p].desc);
							carrito[0].ID=pro_tienda[ID_p].ID;
							carrito[0].pre_uni=pro_tienda[ID_p].pre_uni;
							carrito[0].ex=cantidad;
							pro_tienda[ID_p].ex=pro_tienda[ID_p].ex-cantidad;
							tam_car++;	

						}
						else{
							for(i=0; i<tam_car; i++){
								if(ID_p==carrito[i].ID)
									carrito[i].ex=carrito[i].ex+cantidad;
								
								else
									z=false;
							}
							
							if(z==false){
								aux=(pro *)malloc(sizeof(pro)*tam_car);
								
								for(i=0; i<tam_car; i++){
									strcpy(aux[i].desc, carrito[i].desc);
									aux[i].ID=carrito[i].ID;	
									aux[i].pre_uni=carrito[i].pre_uni;
									aux[i].ex=carrito[i].ex;
								}

								carrito=(pro *)malloc(sizeof(pro)*cant_prod);
					
								strcpy(carrito[0].desc, pro_tienda[ID_p].desc);
								carrito[0].ID=pro_tienda[ID_p].ID;
								carrito[0].pre_uni=pro_tienda[ID_p].pre_uni;
								carrito[0].ex=cantidad;
								pro_tienda[ID_p].ex=pro_tienda[ID_p].ex-cantidad;
								tam_car++;
								
								for(i=0; i<tam_car; i++){
									strcpy(carrito[i+1].desc, aux[i].desc);
									carrito[i+1].ID=aux[i].ID;	
									carrito[i+1].pre_uni=aux[i].pre_uni;
									carrito[i+1].ex=aux[i].ex;
								}
								
								free(aux);
							}
						}				
					}
					//system("PAUSE");
					if(cantidad>pro_tienda[ID_p].ex && ID_p<15)
						printf("No contamos con esa cantidad");
				}
				system("PAUSE");
			break;
			case 3:
				system("CLS");
				if(carrito==NULL)
					printf("Su carrito ya esta vacio\n");
				else{
					free(carrito);
					carrito=NULL;
					tam_car=0;
					printf("Su carrito se ha vaciado\n");
					for(i=0; i<tam_car; i++){
								marcador=carrito[i].ID;
								pro_tienda[marcador].ex=pro_tienda[marcador].ex+carrito[i].ex;
							}
				}
				system("PAUSE");
			break;
			case 4:
				system("CLS");
				if(carrito==NULL)
					printf("No hay productos en su carrito\n");
				else{
					printf("Descripcion Precio uni Cantidad\tSubtotal");	
					for(i=0; i<tam_car; i++){
						printf("\n%s\t%.2f\t%d\t%.2f", carrito[i].desc, carrito[i].pre_uni, carrito[i].ex, carrito[i].pre_uni*carrito[i].ex);
						total=total+(carrito[i].pre_uni*carrito[i].ex);
					}
					printf("\nTotal\t\t\t\t%.2f", total);
					
					printf("\nSeleccione 'S' para confirmar la compra, o 'N' para cancelar: ");
					fflush(stdin);
					scanf("%c", &conf);
					if(conf!='s' && conf!='S'){
						if(conf=='n' || conf=='N')
							for(i=0; i<tam_car; i++){
								marcador=carrito[i].ID;
								pro_tienda[marcador].ex=pro_tienda[marcador].ex+carrito[i].ex;
							}
						else{
							for(i=0; i<tam_car; i++){
								marcador=carrito[i].ID;
								pro_tienda[marcador].ex=pro_tienda[marcador].ex+carrito[i].ex;
							}
							printf("\nOpcion no valida");
						}
					}
					if(conf=='s' || conf=='S'){
						printf("\nCompra realizada con exito!");
						tam_car=0;
					}
					
					free(carrito);
					carrito=NULL;
					tam_car=0;

				}
				system("PAUSE");
			break;
			case 5:
				x=false;
			break;
			default:
				printf("Opcion no valida\n");
				system("PAUSE");
		}
	}
	free(carrito);
}
