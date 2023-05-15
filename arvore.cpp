#include "arvore.h"

arvore::arvore(){
	this->raiz = NULL;
}

arvore::~arvore(){
	this->raiz = NULL;
}

bool arvore::vazia(){
	if(this->raiz == NULL){
		return true;
	}else{
		return false;
	}
}

bool arvore::busca(no_dado* atual, int v){

	if(atual == NULL){
		return false;
	}

	if(atual->valor == v){
		return true;
	}

	if(v < atual->valor) {
		busca(atual->esquerda, v);
	}

	if(v > atual->valor){
		busca(atual->direita, v);
	}
}

int arvore::niveis(no_dado* nd){

	if (nd == NULL) return 0;

	int nivel_esquerda = niveis(nd->esquerda);
	int nivel_direita = niveis(nd->direita);

	return std::max(nivel_esquerda, nivel_direita) + 1;

}

void arvore::pre_ordem(no_dado* nd){

	if(nd == NULL) return;

	cout << nd->valor;

	pre_ordem(nd->esquerda);
	
	pre_ordem(nd->direita);

}

void arvore::em_ordem(no_dado* nd){
	
	if(nd == NULL) return;

	em_ordem(nd->esquerda);

	cout << nd->valor;

	em_ordem(nd->direita);

}

void arvore::pos_ordem(no_dado* nd){

	pos_ordem(nd->esquerda);
	pos_ordem(nd->direita);

	cout << nd->valor;

}

void arvore::em_nivel(no_dado* nd){

	

}
