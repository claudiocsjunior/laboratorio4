/**
* @file   pilha.cpp
* @brief  Métodos de funcinalidades da pilha
* @author Claudio da Cruz Silva Junior
* @since  20/05/2018
* @date   20/05/2018
*/

#include "../include/pilha.h" /**< Inclusão da classe pilha*/
#include <string.h> /**< Inclusão da biblioteca string*/
#include <vector> /**< Inclusão da biblioteca vector*/
/**
* @brief Construtor padrão do objeto
*/
Pilha::Pilha() {
}
/**
* @brief Destrutor do objeto
*/
Pilha::~Pilha() {
}
/**
* @brief Método que retorna o valor do topo da pilha
* @return valor do topo da pilha
*/
char Pilha::top() {
	auto atual = this->cabeca;
		while (atual->getNext() != this->cauda){
			atual = atual->getNext();
			}
	//cout << atual->getValor()[0] << endl;
	return atual->getValor()[0];
}
/**
* @brief Método que retira o valor do topo da pilha
* @return 
*/
void Pilha::pop() {
	this->RemoveNoFinal() ? cout << "removido com sucesso!" : cout << "erro na remoção";
	cout << endl;

}
/**
* @brief Método que adiciona um novo valor no top da pilha
* @return 
*/
void Pilha::push(char* letra) {
	this->InsereNoFinal(letra) ? cout << "Adicionado com sucesso!" : cout << "erro na inserção";
	cout << endl;

}
