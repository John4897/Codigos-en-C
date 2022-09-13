typedef struct Condiciones{
	char llenado;
	char sucesion;
}cond;

typedef struct Celulas{
	char estado;
	int amis;
}celus;

typedef struct Tablero{
	celus **cel;
	int tam;
	int inst;
	int inst_act;
}tab;

void mostrar(cond rem, tab prim);
void vida_muerte(cond revm, tab privm);
void llenar(cond regl, tab prinl);
void liberar(tab prinli);

#include "vidamuerte.c"