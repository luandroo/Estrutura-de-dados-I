#include <stdio.h>
#include <stdlib.h>

typedef struct{
char nome[50];
char endereco[100];
int matricula;
}estudante;

int main(){
	int i,num;
	estudante *vet;
	printf("Digite a quantidade de alunos que vai ser cadastrado :\n");
	scanf("%d",&num);
	vet=(estudante*)malloc(num*sizeof(estudante));
	for(i=0;i<num;i++){
		__fpurge(stdin);
		printf("Digite o nome deste aluno\n");
		fgets((vet+i)->nome,30,stdin);
		__fpurge(stdin);
		printf("Digite o endereco do aluno\n");
		fgets((vet+i)->endereco,30,stdin);
		printf("Digite o numero da matricula\n");
		scanf("%d",&(vet+i)->matricula);
	}
	printf("\t\tEstudantes Cadastrados\t\t\n");
	for(i=0;i<num;i++){
		printf("o nome deste aluno e : %s\n", (vet+i)->nome);
		printf("o endereco do aluno e : %s\n",(vet+i)->endereco);
		printf("A matricula deste estudante e : %d\n",(vet+i)->matricula);
		printf("\n");
	}
	return 0;
}
