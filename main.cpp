#include "arvore.h"

void operacoes(){

	cout << "operacoes(0 para sair) : \n";
	cout << "1 - insirir nodo \n";
	cout << "2 - remover nodo \n";
	cout << "3 - buscar nodo \n";
	cout << "4 - quantidade niveis \n";
	cout << "5 - travesia pre order \n";
	cout << "6 - travesia em ordem  \n";
	cout << "7 - travesia pos ordem \n";
	cout << "8 - travesia em nivel \n";
	cout << "9 - balenciar arvore \n";
	cout << "operacao: ";

}

void menu(){

	arvore* arv = new arvore();

	int op;
	int valor;
	
	operacoes();

	cin >> op;

	while(op > 0 && op < 10){
		
		switch (op){
			case 1:
				cout << "valor a ser inserido: ";
				cin >> valor;
				arv->raiz = arv->insere(arv->raiz, valor);			
			break;

			case 2:
				cout << "valor a ser removido: ";
				cin >> valor;
				arv->raiz = arv->remove_nodo(arv->raiz, valor);							
			break;

			case 3:
				cout << "valor a ser buscado: ";
				cin >> valor;
				if(arv->busca(arv->raiz, valor)){
					cout << "\nvalor encontrado\n";
				}else{
					cout << "valor nao encontrado";
				}
			break;

			case 4:
				cout << "\n" << arv->niveis(arv->raiz) << "\n";
			break;

			case 5:
				arv->pre_ordem(arv->raiz);
			break;

			case 6:
				arv->em_ordem(arv->raiz);
			break;

			case 7:
				arv->pos_ordem(arv->raiz);
			break;

			case 8:
				arv->em_nivel(arv->raiz);
			break;

			case 9:
				arv->raiz = arv->balanciar(arv->raiz);
			break;
		}

		cout << "\n";
		operacoes();
		cin >> op;
	}
}

int main () {

	menu();

	return 0;
}
