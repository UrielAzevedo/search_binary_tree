#include <stdlib.h>
#include <iostream>
#include <locale.h>

using namespace std;

class no_dado {

	public:
		int valor;
		no_dado* esquerda;
		no_dado* direita;

	public:	
		no_dado(int valor);
		no_dado();

};
