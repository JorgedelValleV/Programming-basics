// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// funcion que resuelve el problema
std::string resolver(std::string palabra) {
	int maxAct = 1; int maxTot = 1;
	std::string str = palabra;
	std::string cadena = "";
	size_t aux = str.size();
	char c = str.front();
	char auxiliar = c;
	cadena = c;
	for (size_t i = 1; i < aux; ++i) {
		str = str.substr(1, str.size() - 1);
		int n = int(c);
		c = str.front();
		if (n < int(c)) {
			maxAct += 1;
			cadena += c;
		}
		else if (n>=int(c)){
			maxAct = 1;
			cadena = c;
		}
		if (maxTot < maxAct) {
			maxTot = maxAct;
			palabra = cadena;
		}
		else if (n >=int(c) && maxTot==1 && int(c)<=int(auxiliar)){
			palabra = auxiliar;
		}
	}
	return palabra;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string palabra = "";
	std::cin >> palabra;
	std::string cadena = palabra;
	if (palabra == "XXX")
		return false;

	std::string sol = resolver(palabra);

	// escribir sol
	std::cout << cadena.size() << ' ' << sol.size() << ' ' << sol << '\n';
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