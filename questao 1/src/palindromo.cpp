/*
 * palindromo.cpp
 *
 *  Created on: 18/05/2018
 *      Author: claudio
 */

#include "../include/palindromo.h"
#include <string.h>
#include <cctype>
#include <algorithm>


using namespace std;
Palindromo::Palindromo() {
	// TODO Auto-generated constructor stub

}

Palindromo::~Palindromo() {
	// TODO Auto-generated destructor stub
}

bool Palindromo::verificar(string conteudo) {
	Pilha pilha;
	this->conteudo_recebido = conteudo;
	retirar_formatacao_string();
	reverte_conteudo(pilha);
	return compara_conteudos();
}

void Palindromo::retirar_formatacao_string() {
	//retira espaçamentos
	this->conteudo_recebido.erase(remove(this->conteudo_recebido.begin(),
			this->conteudo_recebido.end(), ' '), this->conteudo_recebido.end());

	//retirar espaçamento
	/*string com_acento = "àâêôûãõáéíóúçüÀÂÊÔÛÃÕÁÉÍÓÚÇÜ";
	string sem_acento = "aaeouaoaeioucuAAEOUAOAEIOUCU";
	int com_acento_tamanho = sem_acento.size();
	int tamanho_string = this->conteudo_recebido.size();
	cout << com_acento_tamanho <<endl;
	cout << tamanho_string <<endl;
	cout << this->conteudo_recebido << endl;
	for(int i = 0; i < tamanho_string; i++){
		for(int j = 0; j < com_acento_tamanho; j++){
			if(this->conteudo_recebido[i] == com_acento[j]){
				cout << "J : "<< j << endl;
				cout << "I: "<< i << endl;
				cout << "conteudo : "<< this->conteudo_recebido[i] << endl;
				//cout << "com acento: " << com_acento[j] << endl;
				//cout << "sem acento: " << sem_acento[j] << endl;
				this->conteudo_recebido[i] = sem_acento[j];
			}

		}
	}
	cout << this->conteudo_recebido <<endl;*/

	//transformando em maiuscula
	int tamanho_string = this->conteudo_recebido.size();
	for(int i = 0; i < tamanho_string; i++){
		this->conteudo_recebido[i] = toupper(this->conteudo_recebido[i]);
	}
}

void Palindromo::reverte_conteudo(Pilha &pilha) {
	int tamanho_string = this->conteudo_recebido.size();
	for(int i = 0; i < tamanho_string; i++){
		//cout << this->conteudo_recebido << endl;
		pilha.push(&this->conteudo_recebido[i]);
	}
	for(int j = 0; j < tamanho_string; j++){

		this->conteudo_inverso = this->conteudo_inverso + pilha.top();
		pilha.pop();

	}
}

bool Palindromo::compara_conteudos() {
	if(conteudo_recebido == conteudo_inverso)
		return true;
	return false;
}
