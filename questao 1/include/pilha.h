/**
* @file   pilha.h
* @brief  Classe de funcinalidades da pilha
* @author Claudio da Cruz Silva Junior
* @since  20/05/2018
* @date   20/05/2018
*/

#ifndef _PILHA_H_  /**< Verifica se a variável _PILHA_H_ foi definida*/
#define _PILHA_H_	 /**< Define a variável _PILHA_H_*/

#include <iostream> /**< Inclusão da biblioteca iostream*/
#include "../../teobaldo_tad/lista.h" /**< Inclusão da classe lista.h*/
#include <string.h> /**< Inclusão da biblioteca string*/

using namespace std;
class Pilha:ListaLigada<string>{
public:
	Pilha(); /**< Construtor padrão da Classe*/
	~Pilha(); /**< Destrutor da Classe*/
	/**
	* @brief Método que retorna o valor do topo da pilha
	* @return valor do topo da pilha
	*/
	char top();
	/**
	* @brief Método que retira o valor do topo da pilha
	* @return 
	*/
	void pop();
	/**
	* @brief Método que adiciona um novo valor no top da pilha
	* @return 
	*/
	void push(char* letra);

};

#endif