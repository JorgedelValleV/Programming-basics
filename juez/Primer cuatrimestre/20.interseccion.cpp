// Nombre del alumno .....Jorge del Valle
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include<string>
#include<algorithm>

// funcioÅn que resuelve el problema
std::vector<int> resolver(std::vector<int>const & v1, std::vector<int>const &v2) {
	std::vector<int>solucion;
	int i = 0; int j = 0;
	while (i < v1.size() && j < v2.size()) {
		if (v1.at(i) == v2.at(j)) {
			solucion.push_back(v1.at(i));
			++i; ++j;
		}
		else if (v1.at(i) > v2.at(j)) {
			++j;
		}
		else ++i;
	}
	return solucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÅn, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int valores1 = 0, valores2 = 0;
	std::vector<int>v1; std::vector<int>v2;
	std::cin >> valores1;
	while (valores1 != 0) {
		v1.push_back(valores1);
		std::cin >> valores1;
	}
	std::cin >> valores2;
	while (valores2 != 0) {
		v2.push_back(valores2);
		std::cin >> valores2;
	}
	//ordenar los datos
	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());
	std::vector<int>sol = resolver(v1,v2);
	// escribir sol
	for (int i = 0; i < sol.size(); ++i) {
		std::cout << sol.at(i) << ' ';
	}
	std::cout << '\n';

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	//     std::ifstream in("datos1.txt");
	//     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//     std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}