// Nombre del alumno .....JORGE DEL VALLE
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
long long int numcifras(long long int n) {
	long long int tam = 0;
	if (n < 10)return 1;
	else return numcifras(n / 10) + 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long long int n;
	long long int tam;
	std::cin >> n;
	if (!std::cin)
		return false;
	tam = numcifras(n);

	// escribir sol
	
	std::cout << tam << '\n';
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