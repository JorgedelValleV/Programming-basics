// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

const std::vector<int> incF = { 1, 0, -1, 0 };
const std::vector<int> incC = { 0, 1, 0, -1 };

using tmatriz = std::vector <std::vector<int>>;

void leer(tmatriz & matriz) {
	for (int f = 0; f < matriz.size(); ++f)
		for (int c = 0; c < matriz[f].size(); ++c)
			std::cin >> matriz[f][c];
}

bool maximoFila(tmatriz const & a, int f, int c) {
	bool maximo = true;
	for (int i = 0; i < a[f].size() && maximo; ++i) {
		if (a[f][c]<a[f][i])maximo = false;
	}
	return maximo;
}
bool minimoFila(tmatriz const & a, int f, int c) {
	bool minimo = true;
	for (int i = 0; i < a[f].size() && minimo; ++i) {
		if (a[f][c]>a[f][i])minimo = false;
	}
	return minimo;
}
bool maximoColumna(tmatriz const & a, int f, int c) {
	bool maximo = true;
	for (int i = 0; i < a.size() && maximo; ++i) {
		if (a[f][c]<a[i][c])maximo = false;
	}
	return maximo;
}
bool minimoColumna(tmatriz const & a, int f, int c) {
	bool minimo = true;
	for (int i = 0; i < a.size() && minimo; ++i) {
		if (a[f][c]>a[i][c])minimo = false;
	}
	return minimo;
}
// funcio?n que resuelve el problema
bool resolver(tmatriz const & a) {
	bool puntosillaencontrado = false;
	for (int f = 0; f < a.size() && !puntosillaencontrado; ++f) {
		for (int c = 0; c < a[f].size() && !puntosillaencontrado; ++c) {
			if ((maximoFila(a, f, c) && minimoColumna(a, f, c)) || (maximoColumna(a, f, c) && minimoFila(a, f, c)))puntosillaencontrado = true;
		}
	}
	return puntosillaencontrado;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int filas = 0; int columnas = 0;
	std::cin >> filas >> columnas;
	if (filas == 0 || columnas == 0)
		return false;
	tmatriz m1(filas, std::vector<int>(columnas));
	leer(m1);
	bool sol = resolver(m1);

	// escribir sol
	if (sol)std::cout << "SI\n";
	else std::cout << "NO\n";
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}