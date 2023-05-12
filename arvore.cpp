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
