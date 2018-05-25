/*
 * ListaCircularEncadeada.h
 *
 *  Created on: 21/05/2018
 *      Author: claudio
 */

#ifndef LISTACIRCULARENCADEADA_H_
#define LISTACIRCULARENCADEADA_H_

#include <iostream>
#include "../../teobaldo_tad/lista.h"

using namespace std;

template <typename T> class ListaCircularEncadeada; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, ListaCircularEncadeada<T> const & );

template <typename T>
class ListaCircularEncadeada:public ListaLigada<T> {
public:
	ListaCircularEncadeada();
	virtual ~ListaCircularEncadeada();

	bool IsEmpty();
	bool InsereNoInicio(T _valor);
	bool InsereNoFinal(T _valor);
	bool RemoveNoInicio();
	bool RemoveNoFinal();
	bool InsereNaPosicao(int pos, T _valor);
	bool RemoveNaPosicao(int pos);
	void printPrimeiroElemento();
	void Print();

	friend std::ostream& operator<< <T>( std::ostream&, ListaCircularEncadeada<T> const &l);
};

template<typename T>
inline ListaCircularEncadeada<T>::ListaCircularEncadeada() {
}

template<typename T>
inline ListaCircularEncadeada<T>::~ListaCircularEncadeada() {
}

template<typename T>
bool ListaCircularEncadeada<T>::IsEmpty() {
	if(this->tamanho == 0)
		return true;
	return false;
}

template <typename T>
bool ListaCircularEncadeada<T>::InsereNoInicio(T _valor) {
	auto novo = make_shared<Node<T>>(_valor);
	if (!novo) return false;

	if(IsEmpty())
		this->cauda = novo;

	novo->setNext(this->cauda->getNext());
	this->cauda->setNext(novo);
	this->tamanho++;
	return true;
}

template <typename T>
bool ListaCircularEncadeada<T>::InsereNoFinal(T _valor) {
	if (this->tamanho == 0) {
		return InsereNoInicio(_valor);
	} else {
		auto atual = this->cauda->getNext();
		while (atual->getNext() != this->cauda)
			atual = atual->getNext();

		auto novo = make_shared<Node<T>>(_valor);
		if (!novo) return false;
		//atual->aux->novo->cabeca


		auto aux = this->cauda;
		this->cauda = novo;
		this->cauda->setNext(aux->getNext());

		atual->setNext(aux);
		aux->setNext(this->cauda);
		this->tamanho++;
	}
	return true;
}

template <typename T>
bool ListaCircularEncadeada<T>::RemoveNoInicio() {
	if (this->tamanho == 0) return false;
	this->cauda->setNext(this->cauda->getNext()->getNext());
	this->tamanho--;
	return true;
}

template <typename T>
bool ListaCircularEncadeada<T>::RemoveNoFinal() {
	if (this->tamanho == 0) return false;

	if (this->cauda->getNext()->getNext()==this->cauda) {
		this->cauda->setNext(this->cauda);
		this->tamanho--;
		return true;
	}

	auto atual = this->cauda->getNext();
	while (atual->getNext()->getNext() != this->cauda)
		atual = atual->getNext();

	auto aux = this->cauda;
	this->cauda = atual->getNext();
	atual->setNext(this->cauda);

	this->cauda->setNext(aux->getNext());
	this->tamanho--;

	return true;
}


template <typename T>
void ListaCircularEncadeada<T>::Print() {
	int count = 0;
	if(this->tamanho > 0){
		auto atual = this->cauda->getNext();
		while (count < this->tamanho) {
			cout << atual->getValor() << " ";
			atual = atual->getNext();
			count++;
		}
	}else{
		cout << "Lista vazia.";
	}
	cout << endl;

}

template <typename T>
bool ListaCircularEncadeada<T>::InsereNaPosicao(int pos, T _valor) {
	if (pos<0) return false;
	if (pos==0)	return InsereNoInicio(_valor);
	if(pos >= this->tamanho) return InsereNoFinal(_valor);

	auto atual = this->cauda->getNext();;
	int posAtual = 0;
	while (atual->getNext() != this->cauda && posAtual < pos-1) {
		atual = atual->getNext();
		posAtual++;
	}
	auto novo = make_shared<Node<T>>(_valor);
	if (!novo) return false;

	novo->setNext(atual->getNext());
	atual->setNext(novo);
	this->tamanho++;

	return true;
}

template <typename T>
bool ListaCircularEncadeada<T>::RemoveNaPosicao(int pos) {
	if (pos<0) return false;
	if (pos==0)	return RemoveNoInicio();
	if(pos >= this->tamanho) return RemoveNoFinal();

	auto atual = this->cauda->getNext();
	int posAtual = 0;
	while (atual->getNext()->getNext() != this->cauda && posAtual < (pos-1)) {
		atual = atual->getNext();
		posAtual++;
	}

	atual->setNext(atual->getNext()->getNext());
	this->tamanho--;

	return true;
}

template <typename T>
void ListaCircularEncadeada<T>::printPrimeiroElemento() {
	if(this->tamanho > 0){
		auto atual = this->cauda->getNext();
		cout << atual->getValor() << " ";
	}else{
		cout << "Lista vazia.";
	}
	cout << endl;

}


#endif /* QUESTAO_3_INCLUDE_LISTACIRCULARENCADEADA_H_ */
