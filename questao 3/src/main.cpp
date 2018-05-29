#include <iostream>
#include "../include/ListaCircularEncadeada.h"
#include "../include/Fila.h"
/**
* @brief Método de inicio do projeto
* @return 0
*/
using namespace std;
int main(){
	Fila<int> *fila = new Fila<int>;

	cout << " FILA APLICAÇÃO " << endl;
	int num;

	do{
		cout << endl;
		num = 0;
		cout << "1 - ADICIONAR VALOR" << endl;
		cout << "2 - REMOVER VALOR" << endl;
		cout << "3 - IMPRIMIR VALOR DA PONTA" << endl;
		cout << "4 - IMPRIMIR TODOS OS VALORES" << endl;
		cout << "5 - APAGAR TODOS OS VALORES" << endl;
		cout << "0 - EXIT" << endl;
		cin >> num;

		switch (num) {
			case 1:
				cout << "INFORME O VALOR QUE SERÁ ADICIONADO: ";
				int valor;
				cin >> valor;
				cout << endl;
				if(fila->enqueue(valor))
					cout << "VALOR ADICIONADO COM SUCESSO" << endl;
				else
					cout << "ERRO AO TENTAR ADICIONAR. TENTE NOVAMENTE!" << endl;

				break;
			case 2:
				if(fila->dequeue())
					cout << "REMOVIDO COM SUCESSO" << endl;
				else
					cout << "ERRO AO TENTAR REMOVER. TENTE NOVAMENTE!" << endl;
				break;
			case 3:
				fila->front();
				break;
			case 4:
				cout << "VALORES" << endl;
				fila->print();
				break;
			case 5:
				if(fila->clear())
					cout << "TODOS OS VALORES FORAM APAGADOS" << endl;
				else
					cout << "ERRO AO TENTAR APAGAR OS VALORES. TENTE NOVAMENTE" << endl;
				break;
			default:
				break;
		}
	}while(num != 0);

}
