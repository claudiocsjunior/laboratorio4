/**
* @file   FormulaInfixa.cpp
* @brief  Classe que retorna o resultado da formula pós-fixada 
* @author Claudio da Cruz Silva Junior
* @since  20/05/2018
* @date   20/05/2018
*/

#include "../include/FormulaInfixa.h" /**< Inclusão da classe formulaInfixa*/
#include <string.h> /**< Inclusão da biblioteca string*/
#include <algorithm> /**< Inclusão da biblioteca algorithm*/

using namespace std;
/**
* @brief Construtor padrão do objeto
*/
FormulaInfixa::FormulaInfixa() {
	this->operadores = "+-/*";
	this->valor_final = 0;

}
/**
* @brief Destrutor do objeto
*/
FormulaInfixa::~FormulaInfixa() {
	// TODO Auto-generated destructor stub
}
/**
* @brief Método que recebe a formula pós-fixada e retorna o resultado
* @return resultado
*/
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
				//cout << valor << endl;
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
/**
* @brief Método para somar os valores da pilha
* @return 
*/
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
/**
* @brief Método para subtrair os valores da pilha
* @return 
*/
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
/**
* @brief Método para multiplicar os valores da pilha
* @return 
*/
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
/**
* @brief Método para dividir os valores da pilha
* @return 
*/
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
