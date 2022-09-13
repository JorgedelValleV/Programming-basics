// Nombre del alumno .....Jorge del Valle
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>


// función que resuelve el problema
unsigned long long int resolver(std::vector<int> v) {
	unsigned long long int n = 0; unsigned long long int pot = 1;
	for (int i = v.size(); i > 0; --i) {
		n += (v[i - 1]-int('0')) * pot;
		pot *= 2;
	}
	return n;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	std::string str = "";
	std::cin >> str;
	std::vector<int> num(str.size());
	for (int i = 0; i < str.size(); ++i)
		num[i] = str.at(i);
	unsigned long long int sol = resolver(num);
	// escribir sol
	std::cout << sol << '\n';

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