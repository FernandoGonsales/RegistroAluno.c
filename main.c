#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

int main() {
	int x,y;
	struct aluno dados_aluno;
	dados_aluno.matricula =1;
	strcpy(dados_aluno.nome, "Fernando");
	dados_aluno.n1 = 6.1;
	dados_aluno.n2 = 5.3;
	dados_aluno.n3 = 8.5;
	Lista *li;
	struct aluno *al;
	li = cria_lista();
	x = tamanho_lista(li);
	printf("Tamanho da lista %d \n", x);
	y = insere_lista_final(li, dados_aluno);
	printf("Inserido 1 ou 0 %d \n", y);
	x = tamanho_lista(li);
	printf("Tamanho da lista %d \n", x);
	y = busca_lista_pos(li, 0, al);
	printf("Busca Pos 1 ou 0 %d \n", y);
	y = busca_lista_mat(li, 1, al);
	printf("Busca Mat 1 ou 0 %d \n", y);
	x = tamanho_lista(li);
	printf("Tamanho da lista: %d \n", x);
	libera_lista(li);
	return 0;
}