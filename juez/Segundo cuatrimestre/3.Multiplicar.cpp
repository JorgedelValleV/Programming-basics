// Nombre del alumno .....Jorge del valle
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tmatriz = std::vector <std::vector<int>>;
tmatriz operator* (tmatriz const& a, tmatriz const& b) {
	tmatriz sol(a.size(), std::vector<int>(b[0].size()));
	for (int f = 0; f < sol.size(); ++f) {
		for (int c = 0; c < sol[f].size(); ++c) {
			int suma = 0;
			for (int k = 0; k < b.size(); ++k) {
				suma += a[f][k] * b[k][c];
			}
			sol[f][c] = suma;
		}
	}
	return sol;
}
// funcio?n que resuelve el problema
tmatriz resolver(tmatriz const & a, tmatriz const & b) {
	return  a*b;
}
void leer(tmatriz & matriz) {
	for (int f = 0; f < matriz.size(); ++f)
		for (int c = 0; c < matriz[f].size(); ++c)
			std::cin >> matriz[f][c];
}
void mostrar(tmatriz const& matriz) {
	for (int f = 0; f < matriz.size(); ++f) {
		for (int c = 0; c < matriz[f].size(); ++c) {
			std::cout << matriz[f][c] << '	';
		}
		std::cout << '\n';
	}
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
	int f2 = 0; int c2 = 0;
	std::cin >> f2 >> c2;
	tmatriz m2(f2, std::vector<int>(c2));
	leer(m2);

	tmatriz sol = resolver(m1, m2);

	// escribir sol
	mostrar(sol);

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