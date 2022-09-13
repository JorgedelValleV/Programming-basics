// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// funcio?n que resuelve el problema
bool resolver(std::string const& str) {
	int i = 0;
	for (i = 0; i < str.size() - 1 && str[i]<str[i+1]; ++i);
	return i == str.size() - 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
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