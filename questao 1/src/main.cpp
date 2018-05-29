#include <iostream> /**< Inclusão da biblioteca iostream*/
#include <string.h> /**< Inclusão da biblioteca string*/
#include "../include/palindromo.h" /**< Inclusão da classe palindromo*/

using namespace std;
/**
* @brief Método de inicio do projeto
* @return 0
*/
int main(){
	cout << "VERIFICADOR DE PALINDROMOS" << endl;
	string conteudo;
	cout << "INFORME A PALAVRA QUE DESEJA TESTAR: ";
	getline(cin, conteudo);
	cout << endl;

	Palindromo palindromo;

	if(palindromo.verificar(conteudo)){
		cout << "--RESULTADO--" << endl;
		cout << "É PALINDROMO";
	}else{
		cout << "--RESULTADO--" << endl;
		cout << "NÃO É PALINDROMO";
	}
	cout << endl;
	return 0;
}
