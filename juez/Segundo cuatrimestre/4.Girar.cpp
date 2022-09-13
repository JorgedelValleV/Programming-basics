// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tmatriz = std::vector <std::vector<int>>;

std::ostream & operator<<(std::ostream& salida, tmatriz const& m) {
	for (int f = 0; f < m.size(); ++f) {
		for (int c = 0; c < m[f].size(); ++c) {
			std::cout << m[f][c] << ' ';
		}
		std::cout << '\n';
	}
	return salida;
}

void leer(tmatriz & matriz) {
	for (int f = 0; f < matriz.size(); ++f)
		for (int c = 0; c < matriz[f].size(); ++c)
			std::cin >> matriz[f][c];
}
void girar(tmatriz & m) {
	for (int f = 0; f < (m.size() / 2); ++f) {
		for (int c = f; c < m.size() - 1 - f; ++c) {
			int aux = m[f][c];
			m[f][c] = m[m.size() - 1 - c][f];
			m[m.size() - 1 - c][f] = m[m.size() - 1-f ][m.size() - 1 - c];
			m[m.size() - 1 - f][m.size() - 1 - c] = m[c][m.size() - 1 - f];
			m[c][m.size() - 1 - f] = aux;
		}
	}
}
// funcio?n que resuelve el problema
void resolver(tmatriz & a,int n) {
	int i=0;
	while (i < n) {
		int giro = 0;
		std::cin >> giro;
		int j = 0;
		while (j < giro / 90) {
			girar(a);
			++j;
		}
		++i;
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int f1 = 0; int c1 = 0;
	std::cin >> f1 >> c1;
	tmatriz m1(f1, std::vector<int>(c1));
	leer(m1);

	if (!std::cin)
		return false;
	int numGiro = 0;
	std::cin >> numGiro;
	resolver(m1, numGiro);

	// escribir sol
	std::cout << m1;

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