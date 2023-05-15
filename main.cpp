#include "arvore.h"

void menu(){
	
	int op;
	arvore* arv = new arvore();

	cout << "Operacoes " << "\n";
	cout << "";
}

int main () {
	no_dado* nd = new no_dado(3);
	
	nd->esquerda = new no_dado(2);
	nd->direita = new no_dado(4);
		
	nd->direita->direita = new no_dado(5);

	arvore* arv = new arvore();
	
	arv->raiz = nd;

	//if(arv->busca(arv->raiz, 4)){
	//	cout << "here";
	//}

	cout << "\nniveis: " << arv->niveis(arv->raiz);

	//cout << nd->valor;
	
	return 0;
}
