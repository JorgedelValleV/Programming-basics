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
	for (int f = 0; f < matriz.size(); ++f) {
		std::cin >> matriz[f][f];
	}
	for (int i = 0; i < (matriz.size() - 1); ++i) {
		std::cin >> matriz[i + 1][i];
	}
	for (int j = 0; j < (matriz.size() - 1); ++j) {
		std::cin >> matriz[j][j + 1];;
	}
}

// funcio?n que resuelve el problema
int resolver(tmatriz const & a, int & filDiag) {
	int sol = a[0][0]; int suma = a[0][0];
	if (a.size() != 1){
		int i = 0;
		while (i < incF.size() - 2) {
			suma += a[incF[i]][incC[i]];
			++i;
		}
		sol = suma;//sol toma el primer valor
		for (int f = 1; f < (a.size() - 1); ++f) {
			int suma = a[f][f];			 
			int i = 0;
			while (i < incF.size()) {
				suma += a[f + incF[i]][f + incC[i]];
				++i;
			}
			if (suma > sol) {
				filDiag = f;
				sol = suma;
			}
		}
		int j = 2;
		suma = a[a.size() - 1][a.size() - 1];
		while (j < incF.size()) {
			suma += a[a.size() - 1 + incF[j]][a.size() - 1 + incC[j]];
			++j;
		}
		if (suma > sol) {
			filDiag = a.size() - 1;
			sol = suma;
		}
	}
	return sol;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int dim = 0;
	std::cin >> dim;
	if (!std::cin)
		return false;
	tmatriz m1(dim, std::vector<int>(dim));
	if (dim != 0)leer(m1);

	if (dim != 0) {

		int filaSol = 0;
		int sol = resolver(m1, filaSol);

		// escribir sol
		std::cout << filaSol << ' ' << sol << '\n';
	}

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