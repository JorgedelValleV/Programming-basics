// Nombre del alumno .....JORGE DEL VALLE
// Usuario del Juez ......DG206


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// funcioÅn que resuelve el problema
int par(int n) {
	if (n % 2 == 0)return 1;
	else return 0;
}
int pares1(std::vector<int> const & v, size_t ini, size_t fin) {
	if (ini == fin-1) {
		return par(v[ini]);
	}
	else if (fin - ini > 1) {
		return  (v[ini] % 2 == 0) + pares1(v, ini+1, fin);
	}
}
int pares2(std::vector<int> const & v, size_t ini, size_t fin) {
	if (ini == fin-1) {
		return par(v[ini]);
	}
	else if (fin - ini > 1) {
		return pares2(v, ini, fin-1)+(v[fin-1] % 2 == 0);
	}
}
int pares3(std::vector<int> const & v, size_t ini, size_t fin) {
	if (ini == fin - 1) {
		return par(v[ini]);
	}
	else if (fin - ini > 1) {
		size_t mitad = (ini + fin - 1) / 2;
		return pares3(v, ini, mitad+1)+pares3(v,mitad+1,fin);
		
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÃÅn, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam, numpar;
	std::cin >> tam;
	if (!std::cin)
		return false;
	std::vector<int> v(tam);
	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];
	
	// escribir sol
	numpar = pares1(v, 0, v.size());
	std::cout << numpar << '\n';
	numpar = pares2(v, 0, v.size());
	std::cout << numpar << '\n';
	numpar = pares3(v, 0, v.size());
	std::cout << numpar <<'\n';
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