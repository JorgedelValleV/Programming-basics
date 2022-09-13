// Nombre del alumno .....Jorge del Valle Vazquez
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// funcion que resuelve el problema
int resolver(std::string const& str,int &iniMax) {
	int lon = 1; int longMax = 1; iniMax = 0;
	for (int i = 1; i < str.size(); ++i) {
		if (str[i-1]<str[i]) { 
			++lon;
			if (lon > longMax) {
				longMax = lon; 
				iniMax = i - lon + 1;
			}
		}
		else lon = 1;
	}
	return longMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string palabra = "";
	std::cin >> palabra;
	if (palabra == "XXX")
		return false;
	int ini = 0;
	int sol = resolver(palabra, ini);

	// escribir sol
	std::cout << palabra.size() << ' ' << sol << ' ' <<palabra.substr(ini,sol)<< '\n';
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