#include "no_dado.h"

class arvore {

	public:
		no_dado* raiz;

	public:
		arvore();
		~arvore();
		bool vazia();
		bool busca(no_dado* atual, int v);		

};
