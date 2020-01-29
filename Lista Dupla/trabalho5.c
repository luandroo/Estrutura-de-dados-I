#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct _produto{
int codigo;
char nome[20];
float preco;
} TpProduto;

typedef struct _nodo{
TpProduto info;
struct _nodo *next;
struct _nodo *prev;
} TpNodo;

typedef struct _lista{
int nItens;
TpNodo *first;
TpNodo *last;
} TpLista;

TpLista *inicia(TpLista*a){
	TpLista *novo =(TpLista*)malloc(sizeof(TpLista));
	novo->nItens = 0;
	novo->first = NULL;
	novo->last =NULL;
	return novo;
}
void criar(TpLista *a){
	 TpNodo *entrada =(TpNodo*) malloc (sizeof(TpNodo));
	 if(a->nItens == 0){
	 entrada->next = NULL;
	 entrada->prev = NULL;
	 a->first = entrada;
	 a->last = entrada;
	 printf("Digite o codigo do produto\n");
	 scanf("%d",&entrada->info.codigo);
	 printf("Digite o nome do produto\n");
	 __fpurge(stdin);
	 fgets(entrada->info.nome,20,stdin);
	 printf("Digite o preço do produto\n");
	 scanf("%f",&entrada->info.preco);
	a->nItens++;
}
	else{
	a->last->next=entrada;
	entrada->prev=a->last;
	a->last=entrada;
	printf("Digite o codigo do produto\n");
	 scanf("%d",&entrada->info.codigo);
	 printf("Digite o nome do produto\n");
	 __fpurge(stdin);
	 fgets(entrada->info.nome,20,stdin);
	 printf("Digite o preço do produto\n");
	 scanf("%f",&entrada->info.preco);
	a->nItens++;	
	}
}
void imprimir(TpLista*a){
	TpNodo*percorrer;
	for(percorrer=a->first;percorrer!=NULL;percorrer=percorrer->next){
		printf("o codigo do produto e :%d\n",percorrer->info.codigo);
		printf("O nome do produto e :%s",percorrer->info.nome);
		printf("O preco do produto e :%2.f\n",percorrer->info.preco);
		printf("\n");
}	
}
void remover(TpLista*a){
	int numcodigo;
	TpNodo *percorrer;
	if(a->nItens==0){
			printf("Lista vazia!");
			return;
	}
	printf("Digite o codigo do produto que vai ser excluido\n");
	scanf("%d",&numcodigo);
	for(percorrer=a->first;percorrer!=NULL;percorrer=percorrer->next){
		if(numcodigo == percorrer->info.codigo){
			printf("Achou um codigo igual\n"); 
				break;
			}
	}
	if(percorrer==NULL){
		printf("Elemento não encontrado\n");
	}else if((percorrer->prev == NULL) && (percorrer->next==NULL)){
		a->first = NULL;
		a->last = NULL;
		a->nItens=0;
	}else if (percorrer->prev == NULL){
		a->first = a->first->next;
		a->first->prev = NULL;
		a->nItens--;
	}else if(percorrer->next == NULL){
		a->last= a->last->prev;
		a->last->next = NULL;
		a->nItens--;
		}else{
		percorrer->next->prev = percorrer->prev;
		percorrer->prev->next = percorrer->next;
		a->nItens--;
	}
}

int main(){
	int num;
	TpLista *lista=NULL;
	lista = inicia(lista);
	do{
		printf("\t\t OPCOES DO MENU\t\t\n");
        printf("1- Para inserir um prduto na lista\n");
        printf("2- Para excluir um elemento da lista\n");
        printf("3- Para listar todos os campos dos elementos\n");
        printf("0- Para finalizar o programa.\n");
        scanf("%d",&num);
        if(num==1){
			criar(lista);
			system("clear");
		}
		if(num==2){
			remover(lista);
			system("clear");
		}
		if(num==3){
			imprimir(lista);
		}
	}while(num!=0);
	return 0;
}

