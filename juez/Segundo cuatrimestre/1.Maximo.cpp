// Nombre del alumno .....Jorge del valle
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tmatriz = std::vector <std::vector<int>>;

// funcio?n que resuelve el problema
int resolver(tmatriz const & a, int & fila, int & columna) {
	fila = 0; columna = 0;
	int max = a[0][0];
	for (int f = 0; f < a.size(); ++f) {
		for (int c = 0; c < a[f].size(); ++c) {
			if (a[f][c] > max) {
				max = a[f][c];
				fila = f;
				columna = c;
			}
		}
	}
	return max;
}
void leer(tmatriz & matriz) {
	for (int f = 0; f < matriz.size(); ++f)
		for (int c = 0; c < matriz[f].size(); ++c)
			std::cin >> matriz[f][c];
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int f1 = 0; int c1 = 0;
	std::cin >> f1;
	if (!std::cin)
		return false;
	std::cin >> c1;
	tmatriz m1(f1, std::vector<int>(c1));
	leer(m1);

	if (!std::cin)
		return false;
	int col = 0; int fil = 0;
	int sol = resolver(m1, fil, col);

	// escribir sol
	std::cout << sol << ' ' << fil << ' ' << col << '\n';

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	//std::ifstream in("datos1.txt");
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