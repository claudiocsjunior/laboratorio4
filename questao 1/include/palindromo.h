/**
* @file   palindromo.h
* @brief  Classe que verifica que um conteúdo é palindromo 
* @author Claudio da Cruz Silva Junior
* @since  20/05/2018
* @date   20/05/2018
*/

#ifndef _PALINDROMO_H_  /**< Verifica se a variável _PALINDROMO_H_ foi definida*/
#define _PALINDROMO_H_	 /**< Define a variável _PALINDROMO_H_*/

#include "pilha.h" /**< Inclusão da classe pilha*/
#include <string.h> /**< Inclusão da biblioteca string*/

using namespace std;
class Palindromo {
	string conteudo_inverso; /**< Variável para armazenar o conteúdo inverso*/
	string conteudo_recebido; /**< Variável para armazenar o conteúdo recebido*/
public:
	Palindromo();  /**< Construtor padrão da Classe*/
	virtual ~Palindromo();  /**< Destrutor da Classe*/
	/**
	* @brief Método que verifica se o conteúdo é palindromo
	* @return booleano
	*/
	bool verificar(string conteudo); 
	/**
	* @brief retira formatação da string fornecida
	* @return 
	*/
	void retirar_formatacao_string();
	/**
	* @brief reverte o conteudo recebendo a pilha de preenchimento
	* @return 
	*/
	void reverte_conteudo(Pilha &pilha);
	/**
	* @brief Método que compara o conteudo fornecido com o conteúdo invertido
	* @return booleano
	*/
	bool compara_conteudos();
};

#endif /* QUESTAO_1_INCLUDE_PALINDROMO_H_ */
