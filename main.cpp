#include "arvore.h"

int main () {
	no_dado* nd = new no_dado(3);
	
	nd->esquerda = new no_dado(2);
	nd->direita = new no_dado(4);
		
	arvore* arv = new arvore();
	
	arv->raiz = nd;

	if(arv->busca(arv->raiz, 4)){
		cout << "here";
	}

	cout << nd->valor;
	
	return 0;
}
