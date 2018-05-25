/*
 * palindromo.h
 *
 *  Created on: 18/05/2018
 *      Author: claudio
 */

#ifndef QUESTAO_1_INCLUDE_PALINDROMO_H_
#define QUESTAO_1_INCLUDE_PALINDROMO_H_

#include "pilha.h"
#include <string.h>

using namespace std;
class Palindromo {
	string conteudo_inverso;
	string conteudo_recebido;
public:
	Palindromo();
	virtual ~Palindromo();

	bool verificar(string conteudo);
	void retirar_formatacao_string();
	void reverte_conteudo(Pilha &pilha);
	bool compara_conteudos();
};

#endif /* QUESTAO_1_INCLUDE_PALINDROMO_H_ */
