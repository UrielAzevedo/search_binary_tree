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

	return false;
}

bool arvore::busca(no_dado* atual, int v){

	if(atual == NULL){
		return false;
	}

	if(atual->valor == v){
		return true;
	}

	if(v < atual->valor) {
		return busca(atual->esquerda, v);
	}else{
		return busca(atual->direita, v);
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

	cout << nd->valor << " - ";

	pre_ordem(nd->esquerda);
	
	pre_ordem(nd->direita);

}

void arvore::em_ordem(no_dado* nd){
	
	if(nd == NULL) return;

	em_ordem(nd->esquerda);

	cout << nd->valor << " - ";

	em_ordem(nd->direita);

}

void arvore::pos_ordem(no_dado* nd){
	
	if(nd == NULL){
		return;
	}
	
	pos_ordem(nd->esquerda);
	pos_ordem(nd->direita);

	if(nd != NULL){
		cout << nd->valor << " - ";
	}
}

void arvore::em_nivel(no_dado* nd){
		
	if(nd == NULL) return;

	queue<no_dado*> q;
	q.push(nd);

	while(!q.empty()){

		no_dado* atual = q.front();
		cout << atual->valor << " - ";
		
		if(atual->esquerda != NULL){
			q.push(atual->esquerda);
		}

		if (atual->direita != NULL){
			q.push(atual->direita);
		}

		q.pop();
	}

}

no_dado* arvore::min_value(no_dado* nd){

	no_dado* atual = nd;

	while(atual && atual->esquerda != NULL){
		atual = atual->esquerda;
	}

	return atual;

}

no_dado* arvore::remove_nodo(no_dado* nd, int valor){

	if(nd == NULL){ return NULL;}

	if(valor < nd->valor){
		 nd->esquerda = remove_nodo(nd->esquerda, valor);
	}else if(valor > nd->valor){
		 nd->direita = remove_nodo(nd->direita, valor);
	}else{

		if(nd->esquerda == NULL){
			no_dado* tmp = nd->direita;
		    delete(nd);
			return tmp;	
		}else if (nd->direita == NULL){
			no_dado* tmp = nd->esquerda;
			delete nd;
			return tmp;
		}

		no_dado* tmp = min_value(nd->direita);

		nd->valor = tmp->valor;

		nd->direita = remove_nodo(nd->direita, tmp->valor);
	
	}

	return nd;

}

int arvore::num_nodos(no_dado* nd){

	if(nd == NULL) return 0;

	return 1 + num_nodos(nd->esquerda) + num_nodos(nd->direita);

}

no_dado* arvore::insere(no_dado* nd, int valor){

	if(nd == NULL) return new no_dado(valor);

	if(valor < nd->valor){
		nd->esquerda = insere(nd->esquerda, valor);
	}else if(valor > nd->valor){
		nd->direita = insere(nd->direita, valor);
	}

	return nd;

}

int arvore::altura(no_dado* nd){

	if(nd == NULL) return 0;

	return std::max(altura(nd->esquerda), altura(nd->direita)) + 1;
}

no_dado* arvore::rotacionar_direita(no_dado* nd){

	no_dado* novo = nd->esquerda;
	nd->esquerda = novo->direita;
	novo->direita = nd;

	return novo;

}

no_dado* arvore::rotacionar_esquerda(no_dado* nd){

	no_dado* novo = nd->direita;
	nd->direita = novo->esquerda;
	novo->esquerda = nd;

	return novo;
}

no_dado* arvore::balanciar(no_dado* nd){

	int fator_balanco = altura(nd->esquerda) - altura(nd->direita);

	if(fator_balanco > 1 && altura(nd->esquerda->esquerda) >= altura(nd->esquerda->direita)) return rotacionar_direita(nd);

	if(fator_balanco < -1 && altura(nd->direita->direita) >= altura(nd->direita->esquerda)) return rotacionar_esquerda(nd);

	if(fator_balanco > 1 && altura(nd->esquerda->esquerda) < altura(nd->esquerda->direita)){
		nd->esquerda = rotacionar_esquerda(nd->esquerda);
		return rotacionar_direita(nd);
	}

	if(fator_balanco < -1 && altura(nd->direita->direita) < altura(nd->direita->esquerda)){
		nd->direita = rotacionar_direita(nd->direita);
		return rotacionar_esquerda(nd);
	}

	return nd;
}
