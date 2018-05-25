#include "../include/pilha.h"
#include <string.h>
#include <vector>
Pilha::Pilha() {
}

Pilha::~Pilha() {
}

char Pilha::top() {
	auto atual = this->cabeca;
		while (atual->getNext() != this->cauda){
			atual = atual->getNext();
			}
	//cout << atual->getValor()[0] << endl;
	return atual->getValor()[0];
}

void Pilha::pop() {
	this->RemoveNoFinal() ? cout << "removido com sucesso!" : cout << "erro na remoção";
	cout << endl;

}

void Pilha::push(char* letra) {
	this->InsereNoFinal(letra) ? cout << "Adicionado com sucesso!" : cout << "erro na inserção";
	cout << endl;

}
