#include <iostream> /**< Inclusão da biblioteca iostream*/
#include <string.h> /**< Inclusão da biblioteca string*/
#include "../include/FormulaInfixa.h" /**< Inclusão da classe formulaInfixa*/

using namespace std;
/**
* @brief Método de inicio do projeto
* @return 0
*/
int main(){
	cout << "CALCULADORA PÓS-FIXA" << endl;
	string formula;
	cout << "INFORME A FORMULA QUE DESEJA OBTER O RESULTADO: ";
	getline(cin, formula);
	cout << endl;

	FormulaInfixa form_inf;
	double result = form_inf.resultado(formula);

	cout << "O resultado é: " << result <<endl;
	return 0;
}
