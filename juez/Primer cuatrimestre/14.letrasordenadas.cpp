// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// función que resuelve el problema
bool resolver(std::string str) {
	size_t aux = str.size();
	char c = str.front();
	for (size_t i = 1; i < aux; ++i) {
		str = str.substr(1, str.size() - 1);
		int n = int(c);
		c = str.front();
		if (n >= int(c))return false;
	}
	return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string palabra = "";
	std::cin >> palabra;
	if (palabra == "XXX")
		return false;

	bool sol = resolver(palabra);

	// escribir sol
	if (sol)std::cout << "SI" << '\n';
	else std::cout << "NO" << '\n';
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