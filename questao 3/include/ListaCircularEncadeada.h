/**
* @file   ListaCircularEncadeada.h
* @brief  Classe responsável por criar uma lista encadeada 
* @author Claudio da Cruz Silva Junior
* @since  20/05/2018
* @date   20/05/2018
*/

#ifndef LISTACIRCULARENCADEADA_H_  /**< Verifica se a variável LISTACIRCULARENCADEADA_H_ foi definida*/
#define LISTACIRCULARENCADEADA_H_	 /**< Define a variável LISTACIRCULARENCADEADA_H_*/

#include <iostream> /**< Inclusão da biblioteca iostream*/
#include "../../teobaldo_tad/lista.h" /**< Inclusão da classe lista*/

using namespace std;

template <typename T> class ListaCircularEncadeada; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, ListaCircularEncadeada<T> const & );

template <typename T>
class ListaCircularEncadeada:public ListaLigada<T> {
public:
	ListaCircularEncadeada(); /**< Construtor padrão da Classe*/
	virtual ~ListaCircularEncadeada(); /**< Destrutor da Classe*/
	/**
	* @brief Método que verifica se a lista está vazia
	* @return booleano
	*/
	bool IsEmpty(); 
	/**
	* @brief Método que insere no inicio da lista circular
	* @param[in] valor a ser adicionado
	* @return booleano
	*/
	bool InsereNoInicio(T _valor);
	/**
	* @brief Método que insere no final da lista circular
	* @param[in] valor a ser adicionado
	* @return booleano
	*/
	bool InsereNoFinal(T _valor);
	/**
	* @brief Método que remove no inicio da lista circular
	* @return booleano
	*/
	bool RemoveNoInicio();
	/**
	* @brief Método que remove no final da lista circular
	* @return booleano
	*/
	bool RemoveNoFinal();
	/**
	* @brief Método que insere na posição fornecida da lista circular
	* @param[in] posição a ser adicionado
	* @param[in] valor a ser adicionado
	* @return booleano
	*/
	bool InsereNaPosicao(int pos, T _valor);
	/**
	* @brief Método que remove na posição fornecida da lista circular
	* @param[in] posição a ser removido
	* @return booleano
	*/
	bool RemoveNaPosicao(int pos);
	/**
	* @brief Método que imprime o primeiro elemento
	* @return 
	*/
	void printPrimeiroElemento();
	/**
	* @brief Método que imprime todos os objetos da lista
	* @return booleano
	*/
	void Print();

	friend std::ostream& operator<< <T>( std::ostream&, ListaCircularEncadeada<T> const &l);
};
/**
* @brief Construtor padrão do objeto
*/
template<typename T>
inline ListaCircularEncadeada<T>::ListaCircularEncadeada() {
}
/**
* @brief Destrutor do objeto
*/
template<typename T>
inline ListaCircularEncadeada<T>::~ListaCircularEncadeada() {
}
/**
* @brief Método que verifica se a lista está vazia
* @return booleano
*/
template<typename T>
bool ListaCircularEncadeada<T>::IsEmpty() {
	if(this->tamanho == 0)
		return true;
	return false;
}

/**
* @brief Método que insere no inicio da lista circular
* @param[in] valor a ser adicionado
* @return booleano
*/
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

/**
* @brief Método que insere no final da lista circular
* @param[in] valor a ser adicionado
* @return booleano
*/
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

/**
* @brief Método que remove no inicio da lista circular
* @return booleano
*/
template <typename T>
bool ListaCircularEncadeada<T>::RemoveNoInicio() {
	if (this->tamanho == 0) return false;
	this->cauda->setNext(this->cauda->getNext()->getNext());
	this->tamanho--;
	return true;
}

/**
* @brief Método que remove no final da lista circular
* @return booleano
*/
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

/**
* @brief Método que imprime todos os objetos da lista
* @return booleano
*/
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

/**
* @brief Método que insere na posição fornecida da lista circular
* @param[in] posição a ser adicionado
* @param[in] valor a ser adicionado
* @return booleano
*/
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

/**
* @brief Método que remove na posição fornecida da lista circular
* @param[in] posição a ser removido
* @return booleano
*/
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

/**
* @brief Método que imprime o primeiro elemento
* @return 
*/
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
