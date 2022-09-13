//Jorge del Valle Vazquez DG206

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

//Declarar aqui los tipos enumerados
enum tColor { R, Z, V, A, M, B };

//Declarar aqui las constantes
const int TAM_CODIGO = 4;
const int VALORMAX = 6;
const std::string OPCIONES = "1. Jugar con un codigo sin colores repetidos\n2. Jugar con un codigo con colores repetidos\n\n0. Salir\n\nElige una opcion: ";
const std::string mensajeERROR = "\nOpcion incorrecta. Prueba otra vez:\n";
const std::string INTRODUCECODIGO = "Introduce el codigo (palabra de 4 letras con alguna de R, Z, V, A, M o B): ";
using	tCodigo = std::vector<tColor>;

//Declarar aqui las funciones que pasan de un tipo a otro
char color2char(tColor a) {
	switch (a) {
	case R:	return 'R';
	case Z:	return 'Z';
	case V:	return 'V';
	case A:	return 'A';
	case M:	return 'Z';
	case B:	return 'B';
	}
}

tColor char2color(char c) {
	tColor elemento;
	if (c == 'R'|| c == 'r')elemento = R;
	else if (c == 'Z')elemento = Z;
	else if (c == 'V')elemento = V;
	else if (c == 'A')elemento = A;
	else if (c == 'M')elemento = M;
	else if (c == 'B')elemento = B;
	return elemento;
}

// funcio?n que resuelve el problema

void compararCodigos(tCodigo const& codigo, tCodigo const & hipotesis, int&	colocados, int&	descolocados) {
	std::vector<bool> aux(TAM_CODIGO, true);
	for (int i = 0; i < TAM_CODIGO; ++i) {
		if (hipotesis[i] == codigo[i]) {
			++colocados;
			aux[i] = false;
		}
	}
	for (int i = 0; i < TAM_CODIGO; ++i) {
		int j = 0; bool parar = false;
		while (j < TAM_CODIGO && !parar) {
			if (aux[j] && codigo[i] == hipotesis[j] && hipotesis[i]!= hipotesis[j]) {
				++descolocados;
				parar = true;
				aux[j] = false;
			}
			++j;
		}
	}
}


bool introducirCodigo(tCodigo& codigo) {
	char c = ' ';
	std::cin >> c;
	c = toupper(c);
	if (c != 'X') {
		codigo[0] = char2color(c);
		for (size_t i = 1; i < TAM_CODIGO; ++i) {
			char c = ' ';
			std::cin >> c;
			c = toupper(c);
			codigo[i] = char2color(c);
		}
		return true;
	}
	else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
bool resuelveCaso() {
	bool ok, ok2;
	// leer los datos de la entrada
	tCodigo	codigoSecreto(TAM_CODIGO);
	tCodigo hipotesisCodigo(TAM_CODIGO);
	ok = introducirCodigo(codigoSecreto);
	ok2 = introducirCodigo(hipotesisCodigo);

	if (!ok && !ok2)
		return false;

	int col = 0, descol = 0;
	compararCodigos(codigoSecreto, hipotesisCodigo, col, descol);

	// escribir sol
	std::cout << col << " " << descol << '\n';
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	//std::ifstream in("datos.txt");
	//auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}