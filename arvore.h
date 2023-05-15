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

};
