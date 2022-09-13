// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <stdio.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <algorithm>

using tMatriz = std::vector<std::vector<int>>;


std::ostream & operator<<(std::ostream & flujo, tMatriz const& mat) {
	for (int i = 0; i < mat.size(); ++i) {
		flujo << mat[i][0];
		for (int j = 1; j < mat[i].size(); ++j) {
			flujo << ' ' << mat[i][j];
		}
		flujo << '\n';
	}
	return flujo;
}


void intercambiarFilas(tMatriz & mat, int arg1, int arg2) {
	for (int j = 0; j < mat[0].size(); ++j)
		std::swap(mat[arg1 - 1][j], mat[arg2 - 1][j]);
}
void intercambiarCols(tMatriz & mat, int arg1, int arg2) {
	for (int i = 0; i < mat.size(); ++i)
		std::swap(mat[i][arg1 - 1], mat[i][arg2 - 1]);
}
void cruz(tMatriz & m, int arg1, int arg2, int arg3) {
	int i = arg1 - 1;
	int j = arg2 - 1;
	m[i][j] = arg3;
	//bajo en diagonal normal, sumo 1 a la fila y 1 a la columna cada vez
	for (int a = 0; ((i + a) < m.size()) && ((j + a) < m[0].size()); ++a)
		m[i + a][j + a] = arg3;
	//subo en diagonal normal, resto 1 a la fila y 1 a la columna cada vez
	for (int a = 0; ((i - a) >= 0) && ((j - a) >= 0); ++a)
		m[i - a][j - a] = arg3;
	//subo en diagonal inversa, resto 1 a la fila y 1 sumo a la columna cada vez
	for (int a = 0; ((i - a) >= 0) && ((j + a) <m[0].size()); ++a)
		m[i - a][j + a] = arg3;
	//bajo en diagonal inversa, sumo 1 a la fila y resto 1 a la columna cada vez
	for (int a = 0; ((i + a)<m.size()) && ((j - a) >= 0); ++a)
		m[i + a][j - a] = arg3;
}
void rotarFilaDerecha(tMatriz & m, int arg1) {
	int i = arg1 - 1;
	int aux = m[i][m[0].size() - 1];
	for (int j = m[0].size() - 1; j > 0; --j)
		m[i][j] = m[i][j - 1];
	m[i][0] = aux;
}
void rotarFilaIzquierda(tMatriz & m, int arg1) {
	int i = arg1 - 1;
	int aux = m[i][0];
	for (int j = 0; j < m[0].size() - 1; ++j)
		m[i][j] = m[i][j + 1];
	m[i][m[0].size() - 1] = aux;
}
void rotarColAbajo(tMatriz & m, int arg1) {
	int j = arg1 - 1;
	int aux = m[m.size() - 1][j];
	for (int i = m.size() - 1; i > 0; --i)
		m[i][j] = m[i - 1][j];
	m[0][j] = aux;
}
void rotarColArriba(tMatriz & m, int arg1) {
	int j = arg1 - 1;
	int aux = m[0][j];
	for (int i = 0; i < m.size() - 1; ++i)
		m[i][j] = m[i + 1][j];
	m[m.size() - 1][j] = aux;
}
bool resuelveCaso() {
	int N, M;  // Dimensiones de la matriz
	std::cin >> N >> M;
	if (N == 0 && M == 0) return false;
	tMatriz mat(N, std::vector<int>(M));
	// leer matriz
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cin >> mat[i][j];
		}
	}
	// transformaciones
	int T;  // Numero de transformaciones
	std::cin >> T;
	std::string trans; int arg1, arg2, arg3;
	for (int t = 0; t < T; ++t) {
		std::cin >> trans;
		if (trans == "filas") {
			// Numeros de las filas a intercambiar. Numeradas del 1..N
			std::cin >> arg1 >> arg2;
			intercambiarFilas(mat, arg1, arg2);
		}
		else if (trans == "columnas") {
			// Numero de las columnas a intercambiar. Numeradas del 1 ..M
			std::cin >> arg1 >> arg2;
			intercambiarCols(mat, arg1, arg2);
		}
		else if (trans == "cruz") {
			// arg1, arg2: Numero de fila y columna del elemento. Numeradas del 1..N y del 1..M
			// arg3: Valor con el que debe rellenarse la cruz
			std::cin >> arg1 >> arg2 >> arg3;
			cruz(mat, arg1, arg2, arg3);
		}
		else if (trans == "rotarFila") {
			// Numero de fila a rotar. Numeradas del 1..N
			std::cin >> arg1;
			if (arg1 > 0) {
				rotarFilaDerecha(mat, arg1);
			}
			else {
				rotarFilaIzquierda(mat, -arg1);
			}
		}
		else if (trans == "rotarCol") {
			// Numero de columna a rotar. Numerada del 1..M
			std::cin >> arg1;
			if (arg1 > 0) {
				rotarColAbajo(mat, arg1);
			}
			else {
				rotarColArriba(mat, -arg1);
			}
		}
	}
	std::cout << mat;
	std::cout << "---\n";
	return true;
}


int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());
	;

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
