/**
* @file   FormulaInfixa.h
* @brief  Classe que retorna o resultado da formula pós-fixada 
* @author Claudio da Cruz Silva Junior
* @since  20/05/2018
* @date   20/05/2018
*/

#ifndef _FORMULAINFIXA_H_ /**< Verifica se a variável _FORMULAINFIXA_H_ foi definida*/
#define _FORMULAINFIXA_H_ /**< Define a variável _FORMULAINFIXA_H_*/

#include <iostream> /**< Inclusão da biblioteca iostream*/
#include <string.h> /**< Inclusão da biblioteca string*/
#include "../../teobaldo_tad/pilha.h" /**< Inclusão da classe pilha*/

using namespace std;

class FormulaInfixa {
private:
	string operadores; /**< Variável para armazenar os operadores*/
	Pilha<string> pilha; /**< Variável para armazenar armazenar a pilha*/
	double valor_final; /**< Variável para armazenar o resutado final*/

public:
	FormulaInfixa(); /**< Construtor padrão da Classe*/
	virtual ~FormulaInfixa(); /**< Destrutor da Classe*/
	/**
	* @brief Método que recebe a formula pós-fixada e retorna o resultado
	* @return resultado
	*/
	double resultado(string formula);
	/**
	* @brief Método para somar os valores da pilha
	* @return 
	*/
	void somar_valores_pilha();
	/**
	* @brief Método para subtrair os valores da pilha
	* @return 
	*/
	void subtrair_valores_pilha();
	/**
	* @brief Método para multiplicar os valores da pilha
	* @return 
	*/
	void multipicar_valores_pilha();
	/**
	* @brief Método para dividir os valores da pilha
	* @return 
	*/
	void dividir_valores_pilha();

};

#endif /* QUESTAO_2_INCLUDE_FORMULAINFIXA_H_ */
