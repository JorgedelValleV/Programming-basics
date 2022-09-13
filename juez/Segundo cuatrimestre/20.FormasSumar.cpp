// Nombre del alumno .....JORGE DEL VALLE
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int numformas(std::vector<int> const & v,int ini, int val) {
	if (ini == v.size())return 0;
	else if (v[ini] == val){
		if (ini == v.size() - 1)return 1;
		else return 1 + numformas(v, ini + 1, val);
	}
	else return numformas(v, ini + 1, val) + numformas(v, ini + 1, val - v[ini]);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int valor;
	int tam;
	std::cin >> valor;
	if (!std::cin)
		return false;
	std::cin >> tam;
	std::vector<int>v(tam);
	for (int i = 0; i < tam ; ++i){
		std::cin >> v[i];
	}
	int sol = numformas(v,0,valor);
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