// Nombre del alumno .....Jorge del Valle V�zquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


// función que resuelve el problema
std::string resolver(std::string str) {
	int n = str.size();
	std::string frase = "";
	while (n > 0) {
		frase.push_back(toupper(str.at(n - 1)));
		--n;
	}
	return frase;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	std::string frase = "";
	getline(std::cin, frase);

	std::string sol = resolver(frase);
	// escribir sol
	std::cout << sol.size() << ' ' << sol << '\n';
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
	char aux;
	std::cin.get(aux);
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//     std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}