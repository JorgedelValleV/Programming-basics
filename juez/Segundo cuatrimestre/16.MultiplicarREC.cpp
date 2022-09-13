// Nombre del alumno .....JORGE DEL VALLE
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>



// función que resuelve el problema
long long int prod(long long int a, long long int b) {
	if (b == 0)return 0;
	else if (b == 1)return a;
	else if (b >1 && b % 2 == 0)return prod(2 * a, b / 2);
	else if (b >1 && b % 2 == 1)return prod(2 * a, b / 2)+a;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long long int a, b;
	std::cin >> a >> b;
	if (!std::cin)
		return false;

	long long int sol = prod(a,b);

	// escribir sol

	std::cout << sol << '\n';
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