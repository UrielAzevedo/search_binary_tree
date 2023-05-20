#include "no_dado.h"

class arvore {

	public:
		no_dado* raiz;

	public:
		arvore();
		~arvore();
		bool vazia();
		bool busca(no_dado* atual, int v);		
		int niveis(no_dado* nd);
		void pre_ordem(no_dado* nd);
		void em_ordem(no_dado* nd);
		void pos_ordem(no_dado* nd);
		void em_nivel(no_dado* nd);
		no_dado* min_value(no_dado* nd);
		no_dado* remove_nodo(no_dado* nd, int valor);
		int num_nodos(no_dado* nd);
		no_dado* insere(no_dado* nd, int valor);
		no_dado* balanciar(no_dado* nd);

	private:
		int altura(no_dado* nd);
		no_dado* rotacionar_esquerda(no_dado* nd);
		no_dado* rotacionar_direita(no_dado* nd);	
};
