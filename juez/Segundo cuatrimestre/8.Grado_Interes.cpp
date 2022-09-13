// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using tmatriz = std::vector <std::vector<int>>;
const std::vector<int> incDiag1{ 1, 1, -1, -1 };
const std::vector<int> incDiag2{ 1, -1, -1, 1 };
struct tPos {
	int fila;
	int columna;
};

void leer(tmatriz & matriz) {
	for (int f = 0; f < matriz.size(); ++f)
		for (int c = 0; c < matriz[f].size(); ++c)
			std::cin >> matriz[f][c];
}
int gradoInteres(tmatriz const & a, tPos ini) {
	int suma = 0;
	//suma de la fila
	for (int c = 0; c < a[ini.fila].size(); ++c) {
		suma += a[ini.fila][c];
	}
	// suma de la columna
	for (int f = 0; f < a.size(); ++f) {
		suma += a[f][ini.columna];
	}
	//primera diagonal
	int f = ini.fila;
	int c = ini.columna;
	while(f < a.size() && c < a[f].size()){
			suma -= a[f][c];
			f += incDiag1[0];
			c += incDiag1[1];
	}
	f = ini.fila + incDiag1[2];
	c = ini.columna + incDiag1[3];
	while (f >=0 && c >=0) {
		suma -= a[f][c];
		f += incDiag1[2];
		c += incDiag1[3];
	}
	//segunda diagonal
	int f2 = ini.fila;
	int c2 = ini.columna;
	while (f2 < a.size() && c2 >=0) {
		suma -= a[f2][c2];
		f2 += incDiag2[0];
		c2 += incDiag2[1];
	}
	f2 = ini.fila + incDiag2[2];
	c2 = ini.columna + incDiag2[3];
	while (f2 >=0 && c2 < a[f2].size()) {
		suma -= a[f2][c2];
		f2 += incDiag2[2];
		c2 += incDiag2[3];
	}
	return suma;
}
// funcio?n que resuelve el problema
std::vector<int> resolver(tmatriz const & a) {
	std::vector<int> sol;
	tPos pos;
	for (int f = 0; f < a.size(); ++f) {
		for (int c = 0; c < a[f].size(); ++c) {
			pos.fila = f;
			pos.columna = c;
			int n = gradoInteres(a, pos);
			sol.push_back(n);
		}
	}
	return sol;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int f1 = 0; int c1 = 0;
	std::cin >> f1 >> c1;
	if (!std::cin)
		return false;
	tmatriz m1(f1, std::vector<int>(c1));
	leer(m1);
	std::vector<int> g = resolver(m1);
	sort(g.begin(), g.end());
	// escribir sol
	for (int i = 0; i < g.size(); ++i)std::cout << g[i] << ' ';
	std::cout << '\n';
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