// Nombre del alumno .....JORGE DEL VALLE
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
void binario(int n) {
	//caso base n==0
	if(n>0) {
		binario(n / 2);
		std::cout << n % 2;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	if (!std::cin)
		return false;
	binario(n);
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