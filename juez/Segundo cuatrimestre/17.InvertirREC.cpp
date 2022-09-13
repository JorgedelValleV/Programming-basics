// Nombre del alumno .....JORGE DEL VALLE
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
void invertir(std::vector<int> & v, size_t ini, size_t fin) {
	if (fin-ini > 1) {
		std::swap(v[ini], v[fin - 1]);
		--fin; ++ini;
		invertir(v, ini, fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	std::cin >> tam;
	if (!std::cin)
		return false;
	std::vector<int> v(tam);
	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];
	invertir(v,0,v.size());

	// escribir sol
	for (int i = 0; i < tam; ++i)
		std::cout << v[i] << ' ';
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