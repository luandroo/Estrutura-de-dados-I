#include <stdio.h>
#include <stdlib.h>
int main(){
	int *p,i;
	int num;
	printf("Digite um numero que vai ser alcado a memoria\n");
	scanf("%d",&num);
	p =(int*)malloc(num*sizeof(int));
	for(i=0;i<num;i++){
		printf("Digite o conteudo dessa variavel\n");
		scanf("%d",&*(p+i));
	}
	for(i=0;i<num;i++){
		printf("Posicao :%d\n",i);
		printf("conteudo :%d\n",*(p+i));
		printf(" Endereço de memoria : %p\n",p+i);
	}
	return 0;
}
