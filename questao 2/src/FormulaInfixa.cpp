/*
 * FormulaInfixa.cpp
 *
 *  Created on: 20/05/2018
 *      Author: claudio
 */

#include "../include/FormulaInfixa.h"
#include <string.h>
#include <algorithm>

using namespace std;

FormulaInfixa::FormulaInfixa() {
	this->operadores = "+-/*";
	this->valor_final = 0;

}

FormulaInfixa::~FormulaInfixa() {
	// TODO Auto-generated destructor stub
}

double FormulaInfixa::resultado(string formula) {
	//retirar espaços
	int tamanho_formula = formula.size();
	int qtd_operador = this->operadores.size();
	int contador;
	string valor = "";
	for(int i = 0; i < tamanho_formula; i++){
		contador = 0;
		for(int j = 0; j < qtd_operador; j++){
			if(formula[i] == this->operadores[j]){
				contador++;
			}
		}

		if(contador == 0){
			if(formula[i] != ' '){
				valor = valor + formula[i];
			}else{
				cout << valor << endl;
				this->pilha.push(valor);
				valor = "";
			}
		}else{
			switch (formula[i]) {
				case '+':
					somar_valores_pilha();
					break;
				case '-':
					subtrair_valores_pilha();
					break;
				case '*':
					multipicar_valores_pilha();
					break;
				case '/':
					dividir_valores_pilha();
					break;
				default:
					break;
			}
			valor = "";
		}
	}
	return this->valor_final;
}

void FormulaInfixa::somar_valores_pilha(){
	int tamanho_pilha = this->pilha.size();
	for(int i = 0; i < tamanho_pilha; i++){
		if(!this->pilha.empty()){
			string num = this->pilha.top();
			if(num.size() != 0)
				this->valor_final = this->valor_final + atof(num.c_str());
			this->pilha.pop();
		}
	}
}

void FormulaInfixa::subtrair_valores_pilha(){

	int tamanho_pilha = this->pilha.size();
	for(int i = 0; i < tamanho_pilha; i++){
		if(!this->pilha.empty()){
			string num = this->pilha.top();
			if(num.size() != 0)
				this->valor_final = atof(num.c_str()) - this->valor_final;
			this->pilha.pop();
		}
	}
}
void FormulaInfixa::multipicar_valores_pilha(){
	int tamanho_pilha = this->pilha.size();
	for(int i = 0; i < tamanho_pilha ; i++){
		if(!this->pilha.empty()){
			string num = this->pilha.top();
			if(this->valor_final == 0){
				this->valor_final = atof(num.c_str());
			}else{
				if(num.size() != 0){
					this->valor_final = this->valor_final * atof(num.c_str());
				}
			}
			this->pilha.pop();
		}
	}
}
void FormulaInfixa::dividir_valores_pilha(){

	int tamanho_pilha = this->pilha.size();
	for(int i = 0; i < tamanho_pilha ; i++){
		if(!this->pilha.empty()){
			string num = this->pilha.top();
			if(this->valor_final == 0){
				this->valor_final = atof(num.c_str());
			}else{
				if(num.size() != 0){
					this->valor_final = this->valor_final / atof(num.c_str());
				}
			}
			this->pilha.pop();
		}
	}

}
