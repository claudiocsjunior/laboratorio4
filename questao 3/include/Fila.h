/**
* @file   Fila.h
* @brief  Classe responsável por criar uma fila com lista encadeada do mesmo diretório 
* @author Claudio da Cruz Silva Junior
* @since  20/05/2018
* @date   20/05/2018
*/

#ifndef QUESTAO_3_INCLUDE_FILA_H_  /**< Verifica se a variável QUESTAO_3_INCLUDE_FILA_H_ foi definida*/
#define QUESTAO_3_INCLUDE_FILA_H_	 /**< Define a variável QUESTAO_3_INCLUDE_FILA_H_*/

#include <iostream> /**< Inclusão da biblioteca iostream*/
#include "ListaCircularEncadeada.h" /**< Inclusão da classe lista circular encadeada*/

using namespace std;

template <typename T>
class Fila {
private:
	ListaCircularEncadeada<T> *lista_circular; /**< Variável para armazenar da lista circular*/
public:
	Fila(); /**< Construtor padrão da Classe*/
	virtual ~Fila(); /**< Destrutor da Classe*/
	/**
	* @brief Método que insere na fila
	* @param[in] valor a ser adicionado
	* @return booleano
	*/
	bool enqueue(T valor);
	/**
	* @brief Método que remove da fila
	* @return booleano
	*/
	bool dequeue();
	/**
	* @brief Método que imprime o primeiro elemento da fila
	* @return 
	*/
	void front();
	/**
	* @brief Método que esvazia a fila
	* @return 
	*/
	bool clear();
	/**
	* @brief Método que verifica se a fila está vazia
	* @return booleano
	*/
	bool IsEmpty();
	/**
	* @brief Método que imprime todos os elementos da fila
	* @return 
	*/
	void print();
};

/**
* @brief Construtor padrão do objeto
*/
template<typename T>
inline Fila<T>::Fila() {
	this->lista_circular = new ListaCircularEncadeada<T>;
}
/**
* @brief Destrutor do objeto
*/
template<typename T>
inline Fila<T>::~Fila() {
}

/**
* @brief Método que insere na fila
* @param[in] valor a ser adicionado
* @return booleano
*/
template<typename T>
inline bool Fila<T>::enqueue(T valor) {
	return lista_circular->InsereNoFinal(valor);
}

/**
* @brief Método que remove da fila
* @return booleano
*/
template<typename T>
inline bool Fila<T>::dequeue() {
	return lista_circular->RemoveNoInicio();
}

/**
* @brief Método que imprime o primeiro elemento da fila
* @return 
*/
template<typename T>
void Fila<T>::front() {
	return lista_circular->printPrimeiroElemento();
}

/**
* @brief Método que esvazia a fila
* @return 
*/
template<typename T>
inline bool Fila<T>::clear() {
	while(!lista_circular->IsEmpty())
		lista_circular->RemoveNoInicio();

	return lista_circular->IsEmpty();
}

/**
* @brief Método que verifica se a fila está vazia
* @return booleano
*/
template<typename T>
inline bool Fila<T>::IsEmpty() {
	return lista_circular->IsEmpty();
}

/**
* @brief Método que imprime todos os elementos da fila
* @return 
*/
template<typename T>
inline void Fila<T>::print() {
	lista_circular->Print();
}

#endif /* QUESTAO_3_INCLUDE_FILA_H_ */
