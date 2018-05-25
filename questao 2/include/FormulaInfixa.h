/*
 * FormulaInfixa.h
 *
 *  Created on: 20/05/2018
 *      Author: claudio
 */

#ifndef QUESTAO_2_INCLUDE_FORMULAINFIXA_H_
#define QUESTAO_2_INCLUDE_FORMULAINFIXA_H_

#include <iostream>
#include <string.h>
#include "../../teobaldo_tad/pilha.h"

using namespace std;


class FormulaInfixa {
private:
	string operadores;
	Pilha<string> pilha;
	double valor_final;

public:
	FormulaInfixa();
	virtual ~FormulaInfixa();

	double resultado(string formula);
	void somar_valores_pilha();
	void subtrair_valores_pilha();
	void multipicar_valores_pilha();
	void dividir_valores_pilha();

};

#endif /* QUESTAO_2_INCLUDE_FORMULAINFIXA_H_ */
