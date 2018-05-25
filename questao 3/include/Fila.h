/*
 * Fila.h
 *
 *  Created on: 22/05/2018
 *      Author: claudio
 */

#ifndef QUESTAO_3_INCLUDE_FILA_H_
#define QUESTAO_3_INCLUDE_FILA_H_

#include <iostream>
#include "ListaCircularEncadeada.h"

using namespace std;

template <typename T>
class Fila {
private:
	ListaCircularEncadeada<T> *lista_circular;
public:
	Fila();
	virtual ~Fila();
	bool enqueue(T valor);
	bool dequeue();
	void front();
	bool clear();
	bool IsEmpty();
	void print();
};

template<typename T>
inline Fila<T>::Fila() {
	this->lista_circular = new ListaCircularEncadeada<T>;
}

template<typename T>
inline Fila<T>::~Fila() {
}

template<typename T>
inline bool Fila<T>::enqueue(T valor) {
	return lista_circular->InsereNoFinal(valor);
}

template<typename T>
inline bool Fila<T>::dequeue() {
	return lista_circular->RemoveNoInicio();
}

template<typename T>
void Fila<T>::front() {
	return lista_circular->printPrimeiroElemento();
}

template<typename T>
inline bool Fila<T>::clear() {
	while(!lista_circular->IsEmpty())
		lista_circular->RemoveNoInicio();

	return lista_circular->IsEmpty();
}

template<typename T>
inline bool Fila<T>::IsEmpty() {
	return lista_circular->IsEmpty();
}

template<typename T>
inline void Fila<T>::print() {
	lista_circular->Print();
}

#endif /* QUESTAO_3_INCLUDE_FILA_H_ */
