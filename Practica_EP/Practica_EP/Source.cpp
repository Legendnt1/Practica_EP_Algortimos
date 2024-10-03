//#include"ContadorVocales.h"
#include"Banco.h"

void main()
{
	/*int vocales[5] = {};
	string texto;
	cout << "Ingrese texto: "; getline(cin, texto);
	texto = texto.substr(0, texto.find('.'));
	
	contarVocales(texto, 0, vocales);
	char vocal = determinarVocal(vocales);
	cout << "\nLa vocales que aparece mas veces es: " << vocal;*/

	Banco* banco = new Banco();
	banco->menu();


	system("pause>>null");
}