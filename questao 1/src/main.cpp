#include <iostream>
#include <string.h>
#include "../include/palindromo.h"

using namespace std;

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
