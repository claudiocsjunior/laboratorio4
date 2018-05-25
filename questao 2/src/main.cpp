#include <iostream>
#include <string.h>
#include "../include/FormulaInfixa.h"

using namespace std;

int main(){
	cout << "CALCULADORA PÓS-FIXA" << endl;
	string formula;
	cout << "INFORME A FORMULA QUE DESEJA OBTER O RESULTADO: ";
	getline(cin, formula);
	cout << endl;

	FormulaInfixa form_inf;
	double result = form_inf.resultado(formula);

	cout << result <<endl;
	return 0;
}
