#include "no_dado.h"

no_dado::no_dado(int valor){
	this->valor = valor;
	this->esquerda = NULL;
	this->direita = NULL;
}

no_dado::no_dado(){
	this->esquerda = NULL;
	this->direita = NULL;
}
