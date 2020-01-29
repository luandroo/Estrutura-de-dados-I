#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#define TAM 50
 typedef struct produto{
    int codigo;
    char nome [TAM];
    float preco;

 }tp_produto;
 typedef struct nodo{
    tp_produto produto;
    struct nodo*prox;
}tp_nodo;

tp_nodo *adicionar_nodo(tp_nodo *antigo){
    tp_nodo *entrada =(tp_nodo*) malloc (sizeof(tp_nodo));
    printf("Digite o codigo do produto\n");
    scanf("%d",&entrada->produto.codigo);
    printf("Digite o nome do produto\n");
    __fpurge(stdin);
    fgets(entrada->produto.nome,TAM,stdin);
    printf("Digite o preco do produto\n");
    scanf("%f",&entrada->produto.preco);
    entrada->prox =antigo;
    return entrada;
}
void mostrar_nodo(tp_nodo *atual){
    for(atual =atual;atual!=NULL;atual=atual->prox){
        printf("O codigo do produto e : %d\n",atual->produto.codigo);
		printf("O nome do produto e :%s",atual->produto.nome);
        printf("O preco do produto e :%2.f\n",atual->produto.preco);
        printf("\n");

    }
}
tp_nodo*excluir_lista(tp_nodo *atual){
	int numcodigo;
	tp_nodo *anterior = NULL;
	tp_nodo *percorre;
	printf("Digite o codigo do produto que vai ser excluido\n");
	scanf("%d",&numcodigo);
	for(percorre =atual;percorre!=NULL;percorre=percorre->prox){
		if(numcodigo == percorre->produto.codigo){
			printf("Achou o igual");
			break;
				
		}
		anterior=percorre;
	}
	if(percorre==NULL){
			printf("Elemento não exiiste");
			return atual;
	
	}else if(anterior == NULL){
		percorre=percorre->prox;
		return percorre;
	}else{ 
		anterior->prox=percorre->prox;
		return atual;
	}
}



 int main(){
    int num;
    tp_nodo *b = NULL;

    do{
		printf("\t\t OPCOES DO MENU\t\t\n");
        printf("1- Insirir os produtos da lista\n");
        printf("2- Para excluir um elemento da lista\n");
        printf("3- Para listar todos os campos dos elementos\n");
        printf("0- Para finalizar o programa.\n");
        scanf("%d",&num);
        if(num==1){
            b = adicionar_nodo(b);
            system("clear");
		}else if(num==2){
			b=excluir_lista(b);
			system("clear");
        }else if(num==3){
            mostrar_nodo(b);
         }
    }while(num!=0);

 }
