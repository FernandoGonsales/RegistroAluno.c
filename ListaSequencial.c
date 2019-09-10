#include <stdlib.h>
#include <stdio.h>
#include "ListaSequencial.h"

struct lista {
	int qtd;
	struct aluno dados[MAX];
};

//Criar lista
Lista* cria_lista(){
		Lista* li;
		li = (Lista*)malloc(sizeof(struct lista));
		if(li != NULL)
			li -> qtd = 0;
		return li;
}

//Destruir lista
void libera_lista(Lista* li) {
	free(li);
}

//Tamanho da lista
int tamanho_lista(Lista* li) {
	if(li == NULL)
		return -1;
	else
		return li -> qtd;
}

//Lista cheia
int lista_cheia(Lista* li) {
	if(li == NULL)
		return -1;
	else return (li -> qtd == MAX);
}

//Lista vazia
int Lista_Vazia(Lista * li) {
	if(li == NULL)
		return -1;
	else return (li -> qtd == 0);
}

//Inserir no inicio da lista
int insere_lista_inicio(Lista* li, struct aluno al) {
	if(li == NULL)
		return 0;
	if(lista_cheia(li))
		return 0;
	int i;
	for(i = li -> qtd -1; i > 0; i--)
		li -> dados[i+1] = li -> dados[i];
	li -> dados[0] = al;
	li -> qtd++;
	return 1;	
}

//Inserir no final da lista
int insere_lista_final(Lista* li, struct aluno al) {
	if(li == NULL)
		return 0;
	if(lista_cheia(li))
		return 0;
	li -> dados[li -> qtd] = al;
	li -> qtd++;
	return 1;	
}

//Inserir de forma ordenada
int Inserir_lista_ordenada(Lista* li, struct aluno al) {
	if(li == 0)
		return 0;
	if(lista_cheia(li))
		return 0;
	int k, i = 0;
	while (i < li -> qtd && li -> dados[i].matricula < al.matricula)
		i++;
	for(k = li -> qtd-1; k >= i; k--)
		li -> dados[k+1] = li -> dados[k];
	li -> dados[i] = al;
	li -> qtd++;	
	return 1;	
}

//Remover do inicio da lista
int remove_lista_inicio(Lista* li){
	if(li == NULL)
		return 0;
	if(lista_cheia(li))
		return 0;
	int k;
	for(k = 0; k < li -> qtd-1; k++)
		li -> dados[k] = li -> dados[k+1];
	li -> qtd--;
	return 1;
}

//Remover do final da lista
int remove_lista_final(Lista* li) {
	if(li == NULL)
		return 0;
	if(lista_cheia(li))
		return 0;
	li -> qtd--;
	return 1;
}

//Remover elemento especifico da lista
int remove_lista(Lista* li, int mat) {
	if(li == NULL)
		return 0;
	if(lista_cheia(li))
		return 0;
	int k, i = 0;
	while(i < li -> qtd && li -> dados[i].matricula != mat)
		i++;
	if(i == li -> qtd)
		return 0;
	for(k = i; k < li -> qtd-1; k++)
		li -> dados[k] = li -> dados[k+1];
	li -> qtd--;
	return 1;
}

//Buscar por posicao
int busca_lista_pos(Lista* li, int pos, struct aluno *al) {
	if(li == NULL || pos < 0 || pos > li -> qtd)
		return 0;
	*al = li -> dados[pos-1];
	return 1;
}

//Buscar por valor
int busca_lista_mat(Lista* li, int mat, struct aluno* al) {
	if(li == NULL)
		return 0;
	int i = 0;
	while(i < li -> qtd && li -> dados[i].matricula != mat)
		i++;
	if(i == li -> qtd)
		return 0;
	*al = li -> dados[i];
	return 1;
}