void mostrar(cond rem, tab prim){
	FILE *momen;
	momen=fopen("Historial.txt","a");

	if(rem.sucesion=='C'){
		Sleep(100);
		system("CLS");
		for(int i=0; i<prim.tam; i++){
			for(int j=0; j<prim.tam; j++)
				printf("%c ",prim.cel[i][j]);
			printf("\n");
		}
	}
	else{
		system("PAUSE");
		system("CLS");
		for(int i=0; i<prim.tam; i++){
			for(int j=0; j<prim.tam; j++)
				printf("%c ",prim.cel[i][j]);
			printf("\n");
		}
	}

	for(int i=0; i<prim.tam; i++){
		for(int j=0; j<prim.tam; j++)
			fprintf(momen, "%c ",prim.cel[i][j]);
		fprintf(momen, "\n");
	}
	fprintf(momen, "INSTANTE: %d\n\n", prim.inst_act);
	fclose(momen);
}

void vida_muerte(cond revm, tab privm){
	tab aux;

	aux.cel=(celus **) malloc(privm.tam*sizeof(celus *));
	for(int i=0; i<privm.tam; i++)
		aux.cel[i]=(celus *) malloc(privm.tam*sizeof(celus));

	for(int i=0; i<privm.tam; i++)
		for(int j=0; j<privm.tam; j++)
				aux.cel[i][j]=privm.cel[i][j];

	for(privm.inst_act=0; privm.inst_act<privm.inst+1; privm.inst_act++){
	mostrar(revm, privm);
	printf("INSTANTE : %d\n", privm.inst_act);
		for(int prin=0; prin<privm.tam; prin++){
			for(int sec=0; sec<privm.tam; sec++){
				privm.cel[prin][sec].amis=0;
				if(privm.cel[prin][sec].estado=='o')
					privm.cel[prin][sec].amis--;
				if((prin==0 && sec==0)){
					for(int in_p=prin; in_p<prin+2; in_p++){
						for(int in_s=sec; in_s<sec+2; in_s++){
							if(privm.cel[in_p][in_s].estado=='o')
								privm.cel[prin][sec].amis++;
						}
					}
				}
				if(prin==0 && sec==privm.tam-1){
					for(int in_p=prin; in_p<prin+2; in_p++){
						for(int in_s=sec-1; in_s<sec+1; in_s++){
							if(privm.cel[in_p][in_s].estado=='o')
								privm.cel[prin][sec].amis++;
						}
					}
				}
				if(prin==privm.tam-1 && sec==0){
					for(int in_p=prin-1; in_p<prin+1; in_p++){
						for(int in_s=sec; in_s<sec+2; in_s++){
							if(privm.cel[in_p][in_s].estado=='o')
								privm.cel[prin][sec].amis++;
						}
					}
				}
				if(prin==privm.tam-1 && sec==privm.tam-1){
					for(int in_p=prin-1; in_p<prin+1; in_p++){
						for(int in_s=sec-1; in_s<sec+1; in_s++){
							if(privm.cel[in_p][in_s].estado=='o')
								privm.cel[prin][sec].amis++;
						}
					}
				}
				if(prin==0 && (sec!=0 && sec!=privm.tam-1)){
					for(int in_p=prin; in_p<prin+2; in_p++){
						for(int in_s=sec-1; in_s<sec+2; in_s++){
							if(privm.cel[in_p][in_s].estado=='o')
								privm.cel[prin][sec].amis++;
						}
					}
				}
				if(prin==privm.tam-1 && (sec!=0 && sec!=privm.tam-1)){
					for(int in_p=prin-1; in_p<prin+1; in_p++){
						for(int in_s=sec-1; in_s<sec+2; in_s++){
							if(privm.cel[in_p][in_s].estado=='o')
								privm.cel[prin][sec].amis++;
						}
					}
				}
				if((prin!=0 && prin!=privm.tam-1) && sec==0){
					for(int in_p=prin-1; in_p<prin+2; in_p++){
						for(int in_s=sec; in_s<sec+2; in_s++){
							if(privm.cel[in_p][in_s].estado=='o')
								privm.cel[prin][sec].amis++;
						}
					}
				}
				if((prin!=0 && prin!=privm.tam-1) && sec==privm.tam-1){
					for(int in_p=prin-1; in_p<prin+2; in_p++){
						for(int in_s=sec-1; in_s<sec+1; in_s++){
							if(privm.cel[in_p][in_s].estado=='o')
								privm.cel[prin][sec].amis++;
						}
					}
				}
				if((prin!=0 && prin!=privm.tam-1) && (sec!=0 && sec!=privm.tam-1)){
					for(int in_p=prin-1; in_p<prin+2; in_p++){
						for(int in_s=sec-1; in_s<sec+2; in_s++){
							if(privm.cel[in_p][in_s].estado=='o')
								privm.cel[prin][sec].amis++;
						}
					}
				}

				if(privm.cel[prin][sec].estado=='o'){
					if(privm.cel[prin][sec].amis<2 || privm.cel[prin][sec].amis>3)
						aux.cel[prin][sec].estado='-';
				}
				if(privm.cel[prin][sec].estado=='-'){
					if(privm.cel[prin][sec].amis==3)	
						aux.cel[prin][sec].estado='o';
				}
			}
		}

		for(int i=0; i<privm.tam; i++)
			for(int j=0; j<privm.tam; j++)
				privm.cel[i][j].estado=aux.cel[i][j].estado;
	}
}

void llenar(cond regl, tab prinl){
	int aux, fila, columna, uni=0;
	char opc;
	bool b=true;
	srand(time(NULL));
	
	if(regl.llenado=='A'){
		for(int i=0; i<prinl.tam; i++){
			for(int j=0; j<prinl.tam; j++){
				aux=rand()%2;
				
				if(aux==0)
					prinl.cel[i][j].estado='-';
				else
					prinl.cel[i][j].estado='o';
			}
		}
	}

	else{
		for(int i=0; i<prinl.tam; i++)
			for(int j=0; j<prinl.tam; j++)
				prinl.cel[i][j].estado='-';

		mostrar(regl, prinl);
		printf("\n\tEste es su tablero actual\n");
			printf("\n%cDesea agregar una celula viva? (S/N): ",168);
			fflush(stdin);
			scanf("%c",&opc);
			opc=toupper(opc);
			if(opc=='N')
				b=false;

		while(b==true){
			if(opc=='S'){
				printf("\nIngrese el numero de fila y columna donde la agregara (Separados por un espacio): ");
				scanf("%d %d",&fila, &columna);
				if(fila<=prinl.tam && fila>0 && columna<=prinl.tam && columna>0){
					if(prinl.cel[fila-1][columna-1].estado=='o')
						printf("\nEsa celula ya esta viva\n");
					else{
						prinl.cel[fila-1][columna-1].estado='o';
						uni++;
					}
					mostrar(regl, prinl);
					printf("\n\tEste es su tablero actual\n");
			
					if(uni==1){
						printf("\nLa celula se siente muy sola en el universo");
						printf("\n%cDesea agregarle una amiga? (S/N): ",168);
					}
					else
						printf("\n%cDesea agregar otra celula viva? (S/N): ",168);
					fflush(stdin);
					scanf("%c",&opc);
					opc=toupper(opc);
				}
				else
					printf("\nEsa celula se encuentra en otra galaxia");
			}
			if(opc!='S' && opc!='N'){
				printf("\nOpcion no valida.\nVuelva a ingresarla: ");
				fflush(stdin);
				scanf("%c",&opc);
				opc=toupper(opc);
			}
			if(opc=='N')
				b=false;
		}

		if(uni==0){
			printf("\nNo hay nada de vida en este universo, busquemos en otro\n");
			system("PAUSE");
		}
		if(uni!=0){
			b=true;
			printf("\n%cDesea matar alguna celula? (S/N): ",168);
			fflush(stdin);
			scanf("%c",&opc);
			opc=toupper(opc);
			if(opc=='N')
				b=false;

			while(b==true){
				if(opc=='S'){
					printf("\nIngrese el numero de fila y columna de la celula a matar (Separados por un espacio): ");
					scanf("%d %d",&fila,&columna);
					if(fila<=prinl.tam && fila>0 && columna<=prinl.tam && columna>0){
						if(prinl.cel[fila-1][columna-1].estado=='-'){
							printf("\nEsta celula ya esta muerta\n");
							system("PAUSE");
						}
						else{
							prinl.cel[fila-1][columna-1].estado='-';
							uni--;
						}
						mostrar(regl, prinl);
						printf("\n\tEste es su tablero actual\n");
			
						if(uni!=0)
							printf("\n%cDesea matar a otra? (S/N): ",168);
						else{
							printf("\nFelicidades, acaba de matar a un universo entero\n");
							system("PAUSE");
							break;
						}
						fflush(stdin);
						scanf("%c",&opc);
						opc=toupper(opc);

					}
					else
						printf("\nNo tenemos poder en esa galaxia");  
					
				}
				if(opc!='S' && opc!='N'){
					printf("\nOpcion no valida.\nVuelva a ingresarla: ");
					fflush(stdin);
					scanf("%c",&opc);
					opc=toupper(opc);
				}
				if(opc=='N')
					b=false;
			}
		}
	}
}

void liberar(tab prinli){
	for(int i=0; i<prinli.tam; i++)
		free(prinli.cel[i]);
	free(prinli.cel);
}