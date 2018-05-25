#include <iostream>
#include "../../teobaldo_tad/lista.h"
#include <string.h>

using namespace std;
class Pilha:ListaLigada<string>{
public:
	Pilha();
	~Pilha();
	char top();
	void pop();
	void push(char* letra);

};
