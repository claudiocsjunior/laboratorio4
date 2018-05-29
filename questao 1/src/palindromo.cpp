/**
* @file   palindromo.cpp
* @brief  Métodos de funcinalidades da classe palindromo
* @author Claudio da Cruz Silva Junior
* @since  20/05/2018
* @date   20/05/2018
*/

#include "../include/palindromo.h" /**< Inclusão da classe palindromo*/
#include <string.h> /**< Inclusão da biblioteca string*/
#include <cctype> /**< Inclusão da biblioteca cctype*/
#include <algorithm> /**< Inclusão da biblioteca algorithm*/


using namespace std;
/**
* @brief Construtor padrão do objeto
*/
Palindromo::Palindromo() {
	// TODO Auto-generated constructor stub

}
/**
* @brief Destrutor do objeto
*/
Palindromo::~Palindromo() {
	// TODO Auto-generated destructor stub
}
/**
* @brief Método que verifica se o conteúdo é palindromo
* @return booleano
*/
bool Palindromo::verificar(string conteudo) {
	Pilha pilha;
	this->conteudo_recebido = conteudo;
	retirar_formatacao_string();
	reverte_conteudo(pilha);
	return compara_conteudos();
}
/**
* @brief retira formatação da string fornecida
* @return 
*/
void Palindromo::retirar_formatacao_string() {
	//retira espaçamentos
	string caracteres = "' '!@#$%&*().;.~^,|\?/+=-_";
	for(int i = 0; i < (int)caracteres.size(); i++){
		this->conteudo_recebido.erase(remove(this->conteudo_recebido.begin(),
		this->conteudo_recebido.end(), caracteres[i]), this->conteudo_recebido.end());

	}

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
/**
* @brief reverte o conteudo recebendo a pilha de preenchimento
* @return 
*/
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
/**
* @brief Método que compara o conteudo fornecido com o conteúdo invertido
* @return booleano
*/
bool Palindromo::compara_conteudos() {
	if(conteudo_recebido == conteudo_inverso)
		return true;
	return false;
}
