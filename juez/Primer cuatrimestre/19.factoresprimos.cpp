// Nombre del alumno .....Jorge
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// funcio?n que resuelve el problema

std::vector <int> criba(int n) {
	std::vector <int> primos;
	std::vector <bool> v(n + 1, true);
	for (int i = 2; i <= n + 1 / 2; ++i) {
		if (v[i]) {
			for (int j = 2; i*j < n + 1; ++j) {
				v[i*j] = false;
			}
		}
	}
	for (int i = 2; i < n + 1; ++i) {
		if (v[i]) {
			primos.push_back(i);
		}
	}
	return primos;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	if (n == 0)
		return false;

	std::vector <int> sol = criba(n);

	// escribir sol
	
	for (int i = 0; i < sol.size(); ++i) {
		while (n%sol[i] == 0) {
			std::cout << sol[i] << ' ';
			n /= sol[i];
		}
	}
	
	std::cout << '\n';
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